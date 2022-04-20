#include "./asymmetricEncryption.hpp"

BigInt getLowLevelPrime(unsigned len) {
  while (true) {
    BigInt primeCandidate = randomBigInt(len);

    int i = 0;
    for (auto divisor : firstPrimesBigInt) {
      if (primeCandidate % divisor == B_ZERO && divisor * divisor <= primeCandidate)
        break;
      
      i++;
    }

    if (i == firstPrimesBigInt.size())
      return primeCandidate;
  }
};

BigInt modularExponentiation(BigInt base, BigInt exponent, BigInt mod) {
  BigInt x = B_ONE;
  BigInt y = base;

  while (exponent > B_ZERO) {
    if (isOdd(exponent))
      x = (x * y) % mod;
    y = (y * y) % mod;
    exponent /= B_TWO;
  }

  return (x % mod);
};

bool isMillerRabinTestOk(BigInt candidate) {
  if (candidate < B_TWO)
    return false;

  if (candidate != B_TWO && isEven(candidate))
    return false;

  BigInt canditateMinusOne = candidate - B_ONE;
  BigInt s = canditateMinusOne;
  while (isEven(s))
    s /= B_TWO;

  for (int i = 0; i < MILLER_RABIN_TEST_ITERATIONS; i++) {
    cout << "Miller-Rabin test iteration " << i << ":" << endl; 
    clock_t tic1 = clock();
    BigInt a = BigInt(rand()) % canditateMinusOne + B_ONE;
    BigInt temp = s;
    // cout << "here1" << endl; 
    clock_t tic2 = clock();
    BigInt mod = modularExponentiation(a, temp, candidate);
    clock_t tac2 = clock();
    cout << "gap " << (double)(tac2-tic2) << endl;
    // cout << "here2" << endl; 

    while (temp != canditateMinusOne && mod != B_ONE && mod != canditateMinusOne) {
      mod = (mod * mod) % candidate;
      temp *= B_TWO;
    }

    if (mod != canditateMinusOne && isEven(temp))
      return false;
    clock_t tac1 = clock();
    cout << "Large gap " << (double)(tac1-tic1) << endl;
  }

  return true;
};

BigInt getPrime(unsigned len) {
  while (true) {
    BigInt candidate = getLowLevelPrime(len);
    if (!isMillerRabinTestOk(candidate))
      continue;
    
    return candidate;
  }
}

BigInt gcd(BigInt a, BigInt b) {
  if (b == B_ZERO)
    return a;

  return gcd(b, a % b);
};

BigInt steinGCD(BigInt a, BigInt b) {
  if (a == b)
    return a;

  if (a == B_ZERO)
    return b;

  if (b == B_ZERO)
    return a;

  // look for factors of 2
  if (isEven(a)) {
    if (isOdd(b))
      return gcd(a / B_TWO, b);
    else // both a and b are even
      return gcd(a / B_TWO, b / B_TWO) * B_TWO;
  }

  if (isEven(b)) // a is odd, b is even
    return gcd(a, b / B_TWO);

  // reduce larger number
  if (a > b)
    return gcd((a - b) / B_TWO, b);

  return gcd((b - a) / B_TWO, a);
}; 

BezoutResult bezout(BigInt a, BigInt b) {
  if (b == B_ZERO)
    return {B_ONE, B_ZERO, a};

  BezoutResult r = bezout(b, a % b);
  std::swap(r.x, r.y);

  return {r.x, r.y - a / b * r.x, r.gcd};
};

PublicKey::PublicKey() {
  e = B_ZERO;
  n = B_ZERO;
};

PublicKey::PublicKey(BigInt e, BigInt n) {
  this->e = e;
  this->n = n;
};

PrivateKey::PrivateKey() {
  d = B_ZERO;
  n = B_ZERO;
};

PrivateKey::PrivateKey(BigInt d, BigInt n) {
  this->d = d;
  this->n = n;
};

KeyPair::KeyPair() {};

KeyPair::KeyPair(PublicKey publicKey, PrivateKey privateKey) {
  this->publicKey = publicKey;
  this->privateKey = privateKey;
};

PublicKey KeyPair::getPublicKey() {
  return this->publicKey;
};

PrivateKey KeyPair::getPrivateKey() {
  return this->privateKey;
};

BigInt KeysGenerator::getPublicExponent(BigInt φ) {
  BigIntVector variants = defaultPublicExponentValues;

  for (auto v : variants)
    if (steinGCD(v, φ) == B_ONE)
      return v;

  throw (std::invalid_argument("Cant get public exponent (φ has GCD != 1 with every Prime Ferma number)"));
};

BigInt KeysGenerator::multiplicativeInverseElement(BigInt e, BigInt φ) {
  BezoutResult r = bezout(e, φ);
  // Проверка на то что r.gcd == 1 не нужна, e и φ взаимно простые по определению
  return (r.x % φ + φ) % φ;
};

KeysGenerator::KeysGenerator() {
  BigInt p = getPrime(PRIME_LENGTH);
  BigInt q = getPrime(PRIME_LENGTH);
  BigInt n = p * q;
  BigInt φ = (p - B_ONE) * (q - B_ONE);

  cout << "p: ";
  p.logNumber();

  cout << "q: ";
  q.logNumber();

  cout << "n: ";
  n.logNumber();

  cout << "φ: ";
  φ.logNumber();

  BigInt e = getPublicExponent(φ);
  cout << "e: ";
  e.logNumber();
  
  BigInt d = multiplicativeInverseElement(e, φ);
  cout << "d: ";
  d.logNumber();

  PublicKey publicKey(e, n);
  PrivateKey privateKey(d, n);
  this->keys = KeyPair(publicKey, privateKey);
};

KeyPair KeysGenerator::getKeys() {
  return this->keys;
};

AsymmetricEncryption::AsymmetricEncryption() {
  KeysGenerator g;
  this->keys = g.getKeys();
};

Message AsymmetricEncryption::encode(Message m) {
  return this->encode(m, keys.getPublicKey());
};

Message AsymmetricEncryption::encode(Message m, PublicKey key) {
  if (m.isSecure)
    throw (std::invalid_argument("Cant encode message. Message is already encoded!"));

  BigInt plainMsg = m.convertToBigInt();
  cout << "plainMessage: " << endl;
  plainMsg.logNumber();

  if (plainMsg >= key.n)
    throw (std::invalid_argument("Cant encode message. Message is too large! Try bigger RSA."));

  BigInt cipherMsg = modularExponentiation(plainMsg, key.e, key.n);
  string cipherMsgText = bigIntToString(cipherMsg);

  return Message(cipherMsgText, true);
};

Message AsymmetricEncryption::decode(Message m) {
  return this->decode(m, keys.getPrivateKey());
};

Message AsymmetricEncryption::decode(Message m, PrivateKey key) {
  if (!m.isSecure)
    throw (std::invalid_argument("Cant decode message. Message is already decoded!"));

  string cipherMsgText = m.text;
  // BigInt cipherMsg(m.text);
  cout << "cipherMessage: " << endl;
  cout << cipherMsgText << endl;
  
  BigInt cipherMsg = m.convertToBigInt();

  BigInt plainMsg = modularExponentiation(cipherMsg, key.d, key.n);
  string plainMsgText = bigIntToString(plainMsg);

  return Message(plainMsgText, false);
};