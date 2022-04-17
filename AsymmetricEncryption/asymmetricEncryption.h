#include "./../Encryption/encryption.h"

// Необходимая длина простого числа
#define PRIME_LENGTH 20
// Число итераций в тесте Миллера-Рабина
#define MILLER_RABIN_TEST_ITERATIONS 16
// Стандартные значения открытой экспоненты (простые из чисел Ферма)
const BigIntVector defaultPublicExponentValues {
  BigInt(65537),
  BigInt(257),
  BigInt(17),
  BigInt(5),
  BigInt(3)
};

// Type for return value of bezout function
// x, y and gcd(a, b) for Bezout equation: ax + by = gcd(a, b).
struct BezoutResult {
  BigInt x;
  BigInt y;
  BigInt gcd;
};

// Возвращает младшего кандидата на простое число длины len
BigInt getLowLevelPrime(unsigned len);

// Возвращает true, если millerRabinCandidate прошел тест Миллера-Рабина,
// и false - в противном случае
bool isMillerRabinTestOk(BigInt millerRabinCandidate);

// Возвращает старшего кандидата на простое число длины len
BigInt getPrime(unsigned len);

// Возвращает значение выражения base ** exponent % mod
BigInt modularExponentiation(BigInt base, BigInt exponent, BigInt mod);

// Возвращает НОД для a и b
BigInt gcd(BigInt a, BigInt b);
BigInt steinGCD(BigInt a, BigInt b);

// Расширенный алгоритм Евклида
BezoutResult bezout(BigInt a, BigInt b);

class PublicKey {
  public:
    BigInt e;
    BigInt n;

    PublicKey() {
      e = B_ZERO;
      n = B_ZERO;
    };

    PublicKey(BigInt e, BigInt n) {
      this->e = e;
      this->n = n;
    };
};

class PrivateKey {
  public:
    BigInt d;
    BigInt n;

    PrivateKey() {
      d = B_ZERO;
      n = B_ZERO;
    };

    PrivateKey(BigInt d, BigInt n) {
      this->d = d;
      this->n = n;
    };
};

class KeyPair {
  protected:
    PublicKey publicKey;
    PrivateKey privateKey;
  public:
    KeyPair() {};

    KeyPair(PublicKey publicKey, PrivateKey privateKey) {
      this->publicKey = publicKey;
      this->privateKey = privateKey;
    };

    PublicKey getPublicKey() {
      return this->publicKey;
    };

    PrivateKey getPrivateKey() {
      return this->privateKey;
    };
};

class KeysGenerator {
  private:
    // Возвращает открытую экспоненту для φ
    BigInt getPublicExponent(BigInt φ) {
      BigIntVector variants = defaultPublicExponentValues;

      for (auto v : variants)
        if (steinGCD(v, φ) == B_ONE)
          return v;

      throw (std::invalid_argument("Cant get public exponent (φ has GCD != 1 with every Prime Ferma number)"));
    };

    // Возвращает число, мультипликативно обратное к числу e по модулю φ
    BigInt multiplicativeInverseElement(BigInt e, BigInt φ) {
      BezoutResult r = bezout(e, φ);
      // Проверка на то что r.gcd != 0 не нужна, e и φ взаимно простые по определению
      return (r.x % φ + φ) % φ;
    };
  protected:
    KeyPair keys;
  public:
    KeysGenerator() {
      BigInt p = getPrime(PRIME_LENGTH);
      BigInt q = getPrime(PRIME_LENGTH);
      BigInt n = p * q;
      BigInt φ = (p - B_ONE) * (q - B_ONE);

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

    KeyPair getKeys() {
      return this->keys;
    };
};

class AsymmetricEncryption: public Encryption {
  private:
    KeyPair keys;
  public:
    AsymmetricEncryption() {
      KeysGenerator g;
      this->keys = g.getKeys();
    };

    Message encode(Message m) {
      return this->encode(m, keys.getPublicKey());
    };

    Message encode(Message m, PublicKey key) {
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

    Message decode(Message m) {
      return this->decode(m, keys.getPrivateKey());
    };

    Message decode(Message m, PrivateKey key) {
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
};