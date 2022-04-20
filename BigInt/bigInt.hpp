#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <initializer_list>
#include <exception>
#include <future>
#include </opt/homebrew/opt/libomp/include/omp.h>
#include "./../MyMath/myMath.hpp"

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

// Дописать нули в начало вектора
CharVector shiftRight(CharVector number, long long shiftPower);

// Дописать нули в конец вектора
CharVector shiftLeft(CharVector number, long long shiftPower);

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
    BigInt(string numberStr = ZERO, bool isNegative = false);

    // Конструктор из int
    BigInt(long long number, bool isNegative = false);

    // Вывод числа в консоль
    void logNumber();

    // Возвращает число цифр в записи числа
    size_t length();

    // Возвращает число записанное строкой
    string getAccumator();

    // Возвращает число записанное строкой (со знаком)
    string getAccumatorWithSign();

    // Возвращает информацию о знаке числа
    bool getIsNegative();

    // Перегрузки операторов
    // Присваивание
    BigInt& operator = (const BigInt& other);

    // Проверка на равенство
    bool operator == (BigInt other);

    // Меньше
    bool operator < (BigInt other);

    // Больше
    bool operator > (BigInt other);

    // Меньше или равно
    bool operator <= (BigInt other);

    // Больше или равно
    bool operator >= (BigInt other);

    // Сложение
    BigInt operator + (BigInt b);

    // Инкремент
    BigInt& operator ++ (int);

    // Присваивающее сложение
    BigInt& operator += (const BigInt& other);

    // Вычитание
    BigInt operator - (BigInt b);

    // Дикремент
    BigInt& operator -- (int);

    // Присваивающее вычитание
    BigInt& operator -= (const BigInt& other);

    // Умножение
    BigInt operator * (BigInt b);

    // Присваивающее умножение
    BigInt& operator *= (const BigInt& other);

    // Деление
    BigInt operator / (BigInt bSigned);

    // Присваивающее деление
    BigInt& operator /= (const BigInt& other);

    // Остаток от деления
    BigInt operator % (BigInt b);

    // Присваивающее остаток от деления
    BigInt& operator %= (const BigInt& other);
};

const BigInt B_ZERO(0);
const BigInt B_ONE(1);
const BigInt B_TWO(2);

// Вектор больших чисел
typedef vector<BigInt> BigIntVector;

// Возвращает результат возведения a в степень b
BigInt pow(BigInt a, BigInt b);

// Возвращает случайный BigInt длины len
BigInt randomBigInt(unsigned len);

// Возвращает вектор больших чисел; a - вектор целых
BigIntVector intVectorToBigIntVector(IntVector a);

// Возвращает true, если num - нечетное, и false - в противном случае
bool isOdd(BigInt num);

// Возвращает true, если num - четное, и false - в противном случае
bool isEven(BigInt num);

// Возвращает абсолютную величину a
BigInt abs(BigInt a);

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