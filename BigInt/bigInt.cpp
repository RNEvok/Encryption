#include "./bigInt.h"

string charVectorToString(CharVector* a) {
  if (!a->size())
    return ZERO;

  string s = "";
  for (auto c : *a)
    s += c;

  return s;
};

CharVector stringToCharVector(string s) {
  CharVector a;

  for (int i = 0; i < s.length(); i++)
    a.push_back(s[i]);

  return a;
};

void deleteZerosAtEnd(CharVector* a) {
  while (a->size() > 0 && a->back() == '0')
    a->pop_back();
};

void deleteLeadingZeros(CharVector* a) {
  reverse(a->begin(), a->end());
  deleteZerosAtEnd(a);
  reverse(a->begin(), a->end());
};

int charToInt(char c) {
  return c - '0';
};

char intToChar(int a) {
  char c = '0' + a;

  return c;
};

CharVector intVectorToCharVector(IntVector* a) {
  CharVector b;

  for (auto x : *a)
    b.push_back(intToChar(x));

  return b;
};

bool bigger(string a, string b) {
  if (a.length() > b.length())
    return true;
  if (a.length() < b.length())
    return false;

  return a.compare(b) > 0;
};

bool bigger(CharVector a, CharVector b) {
  return bigger(charVectorToString(&a), charVectorToString(&b));
};

bool lowerOrEqual(string a, string b) {
  return !bigger(a, b);
};

bool lowerOrEqual(CharVector a, CharVector b) {
  return !bigger(a, b);
};

bool equal(string a, string b) {
  return a.compare(b) == 0;
};

bool biggerOrEqual(string a, string b) {
  return (bigger(a, b) || equal(a, b));
};

bool lower(string a, string b) {
  return (lowerOrEqual(a, b) && !equal(a, b));
};

bool lower(CharVector a, CharVector b) {
  return lower(charVectorToString(&a), charVectorToString(&b));
};

string getNotationPow(int p) {
  string s = ONE;

  while (p--)
    s += ZERO;

  return s;
};

string addition(CharVector a, CharVector b, string result, int carry) {
  if (!a.size() && !b.size() && !carry)
    return result;

  // Берутся младшие разряды
  char leftChar = a.size() > 0? a.back(): '0';
  char rightChar = b.size() > 0? b.back(): '0';
  int left = charToInt(leftChar);
  int right = charToInt(rightChar);
  
  if (a.size())
    a.pop_back();

  if (b.size())
    b.pop_back();

  // Cложение с добавлением перебора с прошлой итерации
  int l = left + right + carry;

  // Вызов для следующих разрядов
  return addition(a, b, to_string(l % NOTATION) + result, l / NOTATION);
};

string subtraction(CharVector a, CharVector b) {
  if (lower(a, b))
    swap(a, b);

  int aLen = a.size();
  int p = 0;
  CharVector c;
  for (int i = 0; i < aLen; i++) {
    char aChar = a.size() > 0? a.back(): '0';
    char bChar = b.size() > 0? b.back(): '0';
    int aInt = charToInt(aChar);
    int bInt = charToInt(bChar);

    if (a.size())
      a.pop_back();

    if (b.size())
      b.pop_back();

    int diff = aInt - bInt - p;
    bool diffPositive = diff >= 0;
    int nextResultDigit = diffPositive? diff: diff + NOTATION;
    c.push_back(intToChar(nextResultDigit));

    p = diffPositive? 0: 1;
  }

  deleteZerosAtEnd(&c);
  reverse(c.begin(), c.end());

  return charVectorToString(&c);
};

string additionInner(CharVector a, CharVector b, string result, int carry, bool bNegative) {
  if (bNegative)
    return subtraction(a, b);
    
  return addition(a, b, result, carry);
};

string multiplicationInner(CharVector a, CharVector b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  IntVector stack;
  stack.resize(a.size() + b.size() + 1);

  // Цифры перемножаются и записываются в stack
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < b.size(); j++) {
      char aChar = a[i];
      char bChar = b[j];
      int aInt = charToInt(aChar);
      int bInt = charToInt(bChar);

      stack[i + j] += aInt * bInt;
    }

  // Обработка stack
  // в ячейке стека должна остаться одна цифра,
  // а десятки и прочие порядки переносятся на позицию выше в stack
  for (int i = 0; i < stack.size(); i++) {
    // Получение цифры
    int num = stack[i] % NOTATION;
    // Переносится вверх
    int move = stack[i] / NOTATION;
    // Установка цифры
    stack[i] = num;

    // Высшие порядки переносятся вверх
    if (stack[i + 1])
      stack[i + 1] += move;
    else if (move != 0)
      stack[i + 1] = move;
  }

  CharVector stackChar = intVectorToCharVector(&stack);
  deleteZerosAtEnd(&stackChar);
  reverse(stackChar.begin(), stackChar.end());

  return charVectorToString(&stackChar);
};

BigInt randomBigInt(unsigned len) {
  string accumulator = "";

  int firstDigit = getRandomInt(1, 9);
  accumulator += to_string(firstDigit);

  for (unsigned i = 0; i < len - 1; i++) {
    int digit = getRandomInt(0, 9);
    accumulator += to_string(digit);
  }

  return BigInt(accumulator);
};

BigIntVector intVectorToBigIntVector(IntVector a) {
  BigIntVector b;

  for (auto x : a)
    b.push_back(BigInt(x));

  return b;
};

bool isOdd(BigInt num) {
  string s = num.getAccumator();
  
  char lastDigit = s.back();
  int lastDigitInt = charToInt(lastDigit);

  return (lastDigitInt % 2);
};

bool isEven(BigInt num) {
  return !isOdd(num);
};

int byteToInt(byte b) {
  return to_integer<int>(b);
};

ByteVector stringToByteVector(string text) {
  ByteVector bytes;

  for (size_t i = 0; i < text.length(); i++)
    bytes.push_back(byte(text[i]));

  return bytes;
};

BigInt byteVectorToBigInt(ByteVector bytes) {
  BigInt q(1);
  BigInt result(0);

  for (auto byte : bytes)
    for (int i = 0; i < 8; i++) {
      BigInt p((byteToInt(byte) >> i) & 1);

      result += p * q;
      q *= B_TWO;
    }

  return result;
};

ByteVector bigIntToByteVector(BigInt a) {
  ByteVector bytes;

  int i = 7;
  byte b{0};
  byte maskZero{0};
  byte maskOne{1};
  while (a != B_ZERO) {
    b |= (isEven(a)? maskZero: maskOne) << 7 - i--;
    a /= B_TWO;

    if (i == -1) {
      bytes.push_back(b);
      i = 7;
      b &= maskZero;
    }
  }
  bytes.push_back(b);

  return bytes;
};

string byteVectorToString(ByteVector bytes) {
  string s = "";

  for (auto byte : bytes)
    s += (char)(byte);

  return s;
};

string bigIntToString(BigInt a) {
  return byteVectorToString(bigIntToByteVector(a));
};