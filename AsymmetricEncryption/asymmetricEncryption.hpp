#include "./../Parameters/parameters.hpp"

// Число итераций в тесте Миллера-Рабина
#define MILLER_RABIN_TEST_ITERATIONS 8
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

    PublicKey();

    PublicKey(BigInt e, BigInt n);
};

class PrivateKey {
  public:
    BigInt d;
    BigInt n;

    PrivateKey();

    PrivateKey(BigInt d, BigInt n);
};

class KeyPair {
  protected:
    PublicKey publicKey;
    PrivateKey privateKey;
  public:
    KeyPair();

    KeyPair(PublicKey publicKey, PrivateKey privateKey);

    // Получить открытый ключ
    PublicKey getPublicKey();

    // Получить закрытый ключ
    PrivateKey getPrivateKey();
};

class KeysGenerator {
  private:
    // Возвращает открытую экспоненту для φ
    BigInt getPublicExponent(BigInt φ);

    // Возвращает число, мультипликативно обратное к числу e по модулю φ
    BigInt multiplicativeInverseElement(BigInt e, BigInt φ);
  protected:
    KeyPair keys;
  public:
    KeysGenerator(int primeLength);

    // Получить ключи
    KeyPair getKeys();
};

class AsymmetricEncryption: public Encryption {
  private:
    KeyPair keys;
  public:
    AsymmetricEncryption(Parameters params = Parameters());

    Message encode(Message m);

    Message encode(Message m, PublicKey key);

    Message decode(Message m);

    Message decode(Message m, PrivateKey key);
};