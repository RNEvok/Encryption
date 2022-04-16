#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <initializer_list>
#include <exception>
#include "./../MyMath/myMath.h"

using namespace std;

// Основание системы счисления
#define NOTATION 10
#define ZERO "0"
#define ONE "1"
// Вектор символов
typedef vector<char> CharVector;
// Вектор целых
typedef vector<int> IntVector;
// Вектор байтов
typedef vector<byte> ByteVector;

// Приведение вектора символов к строке
string charVectorToString(CharVector* a);

// Приведение строки к вектору символов
CharVector stringToCharVector(string s);

// Приведение символа к числу
int charToInt(char c);

// Приведения числа к символу
char intToChar(int a);

// Возвращает true, если число записанное в строке a больше числа в строке b
// Иначе - false
bool bigger(string a, string b);
bool bigger(CharVector a, CharVector b);

// Возвращает true, если число записанное в строке a меньше числа в строке b
// Иначе - false
bool lower(string a, string b);
bool lower(CharVector a, CharVector b);

// Возвращает true, если число записанное в строке a больше или равно числу в строке b
// Иначе - false
bool biggerOrEqual(string a, string b);

// Возвращает true, если число записанное в строке a меньше числа в строке b
// Иначе - false
bool lowerOrEqual(string a, string b);

// Возвращает true, если число записанное в строке a равно числу в строке b
// Иначе - false
bool equal(string a, string b);

// Возвращает строковую запись основания системы счисления в степени p
string getNotationPow(int p);

// Сложение больших чисел
string additionInner(CharVector a, CharVector b, string result, int carry, bool bNegative);

// Умножение больших чисел
string multiplicationInner(CharVector a, CharVector b);

// Деление больших чисел
string divisionInner(string a, string b);

// Удаление нулей из конца вектора
void deleteZerosAtEnd(CharVector* a);

// Удаление нулей из начала вектора
void deleteLeadingZeros(CharVector* a);

class BigInt {
  private:
    CharVector accumulator;
    bool isNegative;
  public:
    // Конструктор по умолчанию
    BigInt(string numberStr = ZERO, bool isNegative = false) {
      accumulator = stringToCharVector(numberStr);
      this->isNegative = isNegative;
    };

    BigInt(long long number, bool isNegative = false) {
      string numberStr = to_string(number);
      accumulator = stringToCharVector(numberStr);
      this->isNegative = isNegative;
    };

    // Вывод числа в консоль
    void logNumber() {
      string s = charVectorToString(&accumulator);

      cout << "\n" << (isNegative? "-": "") << s << endl;
    };

    // Возвращает число цифр в записи числа
    size_t length() {
      return this->accumulator.size();
    };

    // Возвращает число записанное строкой
    string getAccumator() {
      return charVectorToString(&accumulator);
    };

    // Возвращает число записанное строкой (со знаком)
    string getAccumatorWithSign() {
      string sign = isNegative? "-": "";
      return sign + charVectorToString(&accumulator);
    };

    // Возвращает информацию о знаке числа
    bool getIsNegative() {
      return isNegative;
    };

  // Перегрузки операторов
  // Присваивание
  BigInt& operator = (const BigInt& other) {
    // Защита от самоприсваивания
    if (this == &other)
      return *this;

    this->accumulator = other.accumulator;
    this->isNegative = other.isNegative;

    return *this;
  }

  // Проверка на равенство
  friend bool operator == (BigInt a, BigInt b) {
    return (a.isNegative == b.isNegative && equal(a.getAccumator(), b.getAccumator()));
  };

  // Меньше
  friend bool operator < (BigInt left, BigInt right) {
    if (equal(left.getAccumator(), ZERO) && equal(right.getAccumator(), ZERO))
      return false;

    if (left.isNegative && !right.isNegative)
      return true;

    if (!left.isNegative && right.isNegative)
      return false;

    if (left.isNegative && right.isNegative)
      return lower(right.getAccumator(), left.getAccumator());

    return (lower(left.getAccumator(), right.getAccumator()));
  };

  // Больше
  friend bool operator > (BigInt left, BigInt right) {
    return (right < left);
  };

  // Меньше или равно
  friend bool operator <= (BigInt left, BigInt right) {
    return !(left > right);
  };

  // Больше или равно
  friend bool operator >= (BigInt left, BigInt right) {
    return !(left < right);
  };

  // Сложение
  friend BigInt operator + (BigInt a, BigInt b) {
    // a + b
    if (!a.isNegative && !b.isNegative)
      return (
        BigInt(
          additionInner(a.accumulator, b.accumulator, "", 0, false), 
          false
        )
      );
    // a - b
    if (!a.isNegative && b.isNegative)
      return (
        BigInt(
          additionInner(a.accumulator, b.accumulator, "", 0, true), 
          lower(a.getAccumator(), b.getAccumator())
        )
      );
    // -a + b
    if (a.isNegative && !b.isNegative)
      return (
        BigInt(
          additionInner(b.accumulator, a.accumulator, "", 0, true),
          bigger(a.getAccumator(), b.getAccumator())
        )
      );
    // -a - b = -(a + b)
    return (
      BigInt(
        additionInner(a.accumulator, b.accumulator, "", 0, false), 
        true
      )
    );
  };

  // Инкремент
  BigInt& operator ++ (int) {
    return (*this = BigInt(ONE) + *this);
  };

  // Присваивающее сложение
  BigInt& operator += (const BigInt& other) {
    return (*this = *this + other);
  };

  // Вычитание
  friend BigInt operator - (BigInt a, BigInt b) {
    BigInt minusB(b.getAccumator(), !b.isNegative);
    return (a + minusB);
  };

  // Дикремент
  BigInt& operator -- (int) {
    return (*this = *this - BigInt(ONE));
  };

  // Присваивающее вычитание
  BigInt& operator -= (const BigInt& other) {
    return (*this = *this - other);
  };

  // Умножение
  friend BigInt operator * (BigInt a, BigInt b) {
    return (
      BigInt(
        multiplicationInner(a.accumulator, b.accumulator),
        a.isNegative != b.isNegative
      )
    );
  };

  // Присваивающее умножение
  BigInt& operator *= (const BigInt& other) {
    return (*this = *this * other);
  };

  friend BigInt operator / (BigInt aSigned, BigInt bSigned) {
    bool resultWillBeNegative = aSigned.isNegative != bSigned.isNegative;

    BigInt a(aSigned.getAccumator());
    BigInt b(bSigned.getAccumator());

    string aStr = a.getAccumator();
    string bStr = b.getAccumator();

    if (equal(bStr, ZERO))
      throw (std::invalid_argument("Деление на ноль!"));

    if (equal(aStr, ZERO) || lower(aStr, bStr))
      return BigInt(ZERO, resultWillBeNegative);

    if (equal(aStr, bStr))
      return BigInt(ONE, resultWillBeNegative);

    // Происходит деление на маленькое число
    if (bStr.length() == 1) {
      int number_second_integer = charToInt(b.accumulator.front());
      long long in_mind = 0;
      long long composition;

      for (long long i = 0; i < a.length(); i++) {
        composition = (long long)charToInt(a.accumulator[i]) + in_mind * (long long)NOTATION;
        a.accumulator[i] = intToChar(composition / number_second_integer);
        in_mind = composition % number_second_integer;
      }

      deleteLeadingZeros(&a.accumulator);
      a.isNegative = resultWillBeNegative;
      return a;
    }

    BigInt result(ZERO, resultWillBeNegative);
    BigInt aPart;

    int quotient, left, middle, right;
    BigInt tmp;
    for (long long i = 0; i < a.length(); i++) {
      aPart.accumulator.push_back(a.accumulator[i]);
      quotient = 0;
      left = 0;
      right = NOTATION;

      while (left <= right) {
        middle = (left + right) / 2;
        tmp = b * BigInt(middle);

        if (lowerOrEqual(tmp.getAccumator(), aPart.getAccumator())) {
          quotient = middle;
          left = middle + 1;
        } else
          right = middle - 1;
      }
      
      aPart -= b * BigInt(quotient);

      if (!result.accumulator.empty() || quotient != 0)
        result.accumulator.push_back(intToChar(quotient));

      if (aPart == 0)
        aPart.accumulator.resize(0);
    }

    deleteLeadingZeros(&result.accumulator);
    return result;
  }

  // Присваивающее деление
  BigInt& operator /= (const BigInt& other) {
    return (*this = *this / other);
  };

  // Остаток от деления
  friend BigInt operator % (BigInt a, BigInt b) {
    return (a - (a / b * b));
  };

  // Присваивающее остаток от деления
  BigInt& operator %= (const BigInt& other) {
    return (*this = *this % other);
  };
};

const BigInt B_ZERO(0);
const BigInt B_ONE(1);
const BigInt B_TWO(2);
const BigInt B_THREE(3);

// Вектор больших чисел
typedef vector<BigInt> BigIntVector;

// Возвращает случайный BigInt длины len
BigInt randomBigInt(unsigned len);

// Возвращает вектор больших чисел; a - вектор целых
BigIntVector intVectorToBigIntVector(IntVector a);

// Возвращает true, если num - нечетное, и false - в противном случае
bool isOdd(BigInt num);

// Возвращает true, если num - четное, и false - в противном случае
bool isEven(BigInt num);

// Приведение байта к целому
int byteToInt(byte b);

// Приведение строки к вектору байтов
ByteVector stringToByteVector(string text);

// Приведение вектора байтов к BigInt
BigInt byteVectorToBigInt(ByteVector bytes);

// Приведение BigInt к вектору байтов
ByteVector bigIntToByteVector(BigInt a);

// Приведение вектора байтов к строке
string byteVectorToString(ByteVector bytes);

// Приведение сообщения записанного в виде числа к строковому виду (читаемый текст)
string bigIntToString(BigInt a);