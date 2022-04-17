#include "./asymmetricEncryption.h"

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

// BigInt modularExponentiation(BigInt base, BigInt exponent, BigInt mod) {
//   BigInt x = B_ONE;
//   BigInt y = base;

//   #pragma omp for
//   for ( ; exponent > B_ZERO ;) {
//     //x.logNumber();
//     if (isOdd(exponent))
//       x = (x * y) % mod;
//     y = (y * y) % mod;
//     // y.logNumber();
//     exponent /= B_TWO;
//   }

//   return (x % mod);
// };

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