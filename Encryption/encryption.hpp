#ifndef Encryption_H
  #define Encryption_H

  #include <map>
  #include "./../BigInt/bigInt.hpp"

  // Первые простые числа
  const IntVector firstPrimes {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67,
    71, 73, 79, 83, 89, 97, 101, 103,
    107, 109, 113, 127, 131, 137, 139,
    149, 151, 157, 163, 167, 173, 179,
    181, 191, 193, 197, 199, 211, 223,
    227, 229, 233, 239, 241, 251, 257,
    263, 269, 271, 277, 281, 283, 293, 
    307, 311, 313, 317, 331, 337, 347, 
    349, 353, 359, 367, 373, 379, 383,
    389, 397, 401, 409, 419, 421, 431,
    433, 439, 443, 449, 457, 461, 463, 
    467, 479, 487, 491, 499, 503, 509,
    521, 523, 541, 547, 557, 563, 569, 
    571, 577, 587, 593, 599, 601, 607, 
    613, 617, 619, 631, 641, 643, 647,
    653, 659, 661, 673, 677, 683, 691,
    701, 709, 719, 727, 733, 739, 743, 
    751, 757, 761, 769, 773, 787, 797,
    809, 811, 821, 823, 827, 829, 839, 
    853, 857, 859, 863, 877, 881, 883, 
    887, 907, 911, 919, 929, 937, 941,
    947, 953, 967, 971, 977, 983, 991,
    997
  };

  const CharVector ENGLISH {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  const DoubleVector ENGLISH_PROBABILITIES {0.0817, 0.0149, 0.0278, 0.0425, 0.127, 0.0223, 0.0202, 0.0609, 0.0697, 0.0015, 0.0077, 0.0403, 0.0241, 0.0675, 0.0751, 0.0193, 0.001, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0005};

  const BigIntVector firstPrimesBigInt = intVectorToBigIntVector(firstPrimes);

  class Message {
    public:
      string text;
      bool isSecure;

      Message(string text, bool isSecure = false);

      // Вывод сообщения в консоль
      void logMessage();

      // Преобразование text в ByteVector
      ByteVector convertToBytes();

      // Преобразование text в BigInt
      BigInt convertToBigInt();
  };

  class Encoder {
    public:
      // Шифрование
      virtual Message encode(Message m) = 0;
  };

  class Decoder {
    public:
      // Дешифрование
      virtual Message decode(Message m) = 0;
  };

  class Encryption: public Encoder, public Decoder {
    public:
      virtual ~Encryption() {};
  };

#endif