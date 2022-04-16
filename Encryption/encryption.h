#include "./../BigInt/bigInt.h"

// Первые простые числа
const IntVector firstPrimes {
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
  31, 37, 41, 43, 47, 53, 59, 61, 67,
  71, 73, 79, 83, 89, 97, 101, 103,
  107, 109, 113, 127, 131, 137, 139,
  149, 151, 157, 163, 167, 173, 179,
  181, 191, 193, 197, 199, 211, 223,
  227, 229, 233, 239, 241, 251, 257
};

const BigIntVector firstPrimesBigInt = intVectorToBigIntVector(firstPrimes);

class Message {
  public:
    string text;
    bool isSecure;

    Message(string text, bool isSecure = false) {
      this->text = text;
      this->isSecure = isSecure;
    };

    void logMessage() {
      cout << this->text << endl;
    };

    ByteVector convertToBytes() {
      return stringToByteVector(text);
    };

    BigInt convertToBigInt() {
      return byteVectorToBigInt(this->convertToBytes());
    };
};

class Encoder {
  protected:
    virtual Message encode(Message m) = 0;
};

class Decoder {
  protected:
    virtual Message decode(Message m) = 0;
};

class Encryption: public Encoder, public Decoder {};