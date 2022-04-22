#ifndef Parameters_H
  #define Parameters_H

  #include "./../Encryption/encryption.hpp"

  class Parameters {
    public:
      // Сдвиг для шифра Цезаря
      int shift;
      // Алфавит
      CharVector alphabet;
      // Вероятности появления символов алфавита для шифра Шеннона-Фано
      DoubleVector probabilities;
      // Размер блока для шифра Шеннона-Фано
      int blockSize;
      // Длина простых чисел p и q для RSA
      int primeLength;

      Parameters();

      void setShift(int shift);

      void setBlockSize(int blockSize);

      void setPrimeLength(int primeLength);
  };

#endif