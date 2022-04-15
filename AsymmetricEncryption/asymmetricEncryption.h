#include "./../Encryption/encryption.h"

// Необходимая длина простого числа
#define PRIME_LENGTH 10
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

// Возвращает младшего кандидата на простое число длины len
BigInt getLowLevelPrime(unsigned len);

// Возвращает true, если millerRabinCandidate прошел тест Миллера-Рабина,
// и false - в противном случае
bool isMillerRabinTestOk(BigInt millerRabinCandidate);

// Возвращает старшего кандидата на простое число длины len
BigInt getPrime(unsigned len);

// Возвращает НОД для a и b
BigInt gcd(BigInt a, BigInt b);
BigInt steinGCD(BigInt a, BigInt b);

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

    // Возвращает число, мультипликативно обратное 
    BigInt multiplicative inverse element() {

    };
  protected:
    KeyPair keys;
  public:
    KeysGenerator() {
      BigInt p = getPrime(PRIME_LENGTH);
      BigInt q = getPrime(PRIME_LENGTH);
      BigInt n = p * q;
      BigInt φ = (p - B_ONE) * (q - B_ONE);

      φ.logNumber();

      BigInt e = getPublicExponent(φ);
      e.logNumber();

      PublicKey publicKey(BigInt(1), BigInt(2));
      PrivateKey privateKey(BigInt(1), BigInt(2));
      this->keys = KeyPair(publicKey, privateKey);
    };
};

class AsymmetricEncryption: public Encryption {
  public:
    AsymmetricEncryption() {

    };
    // Message encode(Message m, )
};