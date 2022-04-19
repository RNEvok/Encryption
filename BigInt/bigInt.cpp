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

CharVector shiftRight(CharVector number, long long shiftPower) {
  number.reserve(shiftPower);
  for (long long i = 0; i < shiftPower; i++)
    number.insert(number.begin(), intToChar(0));

  return number;
}

CharVector shiftLeft(CharVector number, long long shiftPower) {
  number.resize(number.size() + shiftPower);

  for (long long i = 0; i < shiftPower; i++)
    number.push_back(intToChar(0));

  return number;
}

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

  IntVector stack(a.size() + b.size());

  //Цифры перемножаются и записываются в stack
  // // #pragma omp parallel for
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++)
      stack[i + j] += charToInt(a[i]) * charToInt(b[j]);
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
    else if (move)
      stack[i + 1] = move;
  }

  CharVector stackChar = intVectorToCharVector(&stack);
  deleteZerosAtEnd(&stackChar);
  reverse(stackChar.begin(), stackChar.end());

  return charVectorToString(&stackChar);
};

// CharVector multiplicationInnerSmallNumbers(CharVector a, CharVector b) {
//   reverse(a.begin(), a.end());
//   reverse(b.begin(), b.end());

//   IntVector stack(a.size() + b.size() + 1);

//   // Цифры перемножаются и записываются в stack
//   for (int i = 0; i < a.size(); i++)
//     for (int j = 0; j < b.size(); j++)
//       stack[i + j] += charToInt(a[i]) * charToInt(b[j]);

//   // Обработка stack
//   // в ячейке стека должна остаться одна цифра,
//   // а десятки и прочие порядки переносятся на позицию выше в stack
//   for (int i = 0; i < stack.size(); i++) {
//     // Получение цифры
//     int num = stack[i] % NOTATION;
//     // Переносится вверх
//     int move = stack[i] / NOTATION;
//     // Установка цифры
//     stack[i] = num;

//     // Высшие порядки переносятся вверх
//     if (stack[i + 1])
//       stack[i + 1] += move;
//     else if (move)
//       stack[i + 1] = move;
//   }

//   CharVector stackChar = intVectorToCharVector(&stack);
//   deleteZerosAtEnd(&stackChar);
//   reverse(stackChar.begin(), stackChar.end());

//   return stackChar;
// };

// CharVector multiplicationInner(CharVector a, CharVector b, bool iterationThirst = true) {
//   if (min(a.size(), b.size()) <= MAX_NUM_LENGTH_FOR_DEFAULT_MULTIPLICATION)
//     return multiplicationInnerSmallNumbers(a, b);
  
//   if (a.size() % 2 != 0)
//     a.insert(a.begin(), 0);
  
//   if (b.size() % 2 != 0)
//     b.insert(b.begin(), 0);

//   if (a.size() > b.size())
//     b = shiftRight(b, a.size() - b.size());
//   else
//     a = shiftRight(a, b.size() - a.size());
  
//   long long numsSize = a.size();
//   long long partSize = numsSize / 2;
//   CharVector aPartLeft;
//   CharVector aPartRight;
//   CharVector bPartLeft;
//   CharVector bPartRight;
//   aPartLeft.resize(partSize);
//   aPartRight.resize(partSize);
//   bPartLeft.resize(partSize);
//   bPartRight.resize(partSize);
//   copy(a.begin(), a.begin() + partSize, aPartLeft.begin());
//   copy(b.begin(), b.begin() + partSize, bPartLeft.begin());
//   copy(a.begin() + partSize, a.begin() + numsSize, aPartRight.begin());
//   copy(b.begin() + partSize, b.begin() + numsSize, bPartRight.begin());
//   CharVector pFirst;
//   CharVector pSecond;
//   CharVector pThird;

//   if (iterationThirst && thread::hardware_concurrency() >= 3) {
//     auto thread_first = async(multiplicationInner, aPartLeft, bPartLeft, false);
//     auto thread_second = async(multiplicationInner, aPartRight, bPartRight, false);
//     pThird = multiplicationInner(_zeroes_leading_remove(aPartLeft) + _zeroes_leading_remove(aPartRight), _zeroes_leading_remove(bPartLeft) + _zeroes_leading_remove(bPartRight), false);
//     pFirst = thread_first.get();
//     pSecond = thread_second.get();
//   } else if (iterationThirst && thread::hardware_concurrency() == 2) {
//     auto thread_first = async(multiplicationInner, aPartLeft, bPartLeft, false);
//     pSecond = multiplicationInner(aPartRight, bPartRight, false);
//     pThird = multiplicationInner(_zeroes_leading_remove(aPartLeft) + _zeroes_leading_remove(aPartRight), _zeroes_leading_remove(bPartLeft) + _zeroes_leading_remove(bPartRight), false);
//     pFirst = thread_first.get();
//   } else {
//     pFirst = multiplicationInner(aPartLeft, bPartLeft, false);
//     pSecond = multiplicationInner(aPartRight, bPartRight, false);
//     pThird = multiplicationInner(_zeroes_leading_remove(aPartLeft) + _zeroes_leading_remove(aPartRight), _zeroes_leading_remove(bPartLeft) + _zeroes_leading_remove(bPartRight), false);
//   }

//   return shiftLeft(pFirst, numsSize) + shiftLeft(pThird - (pFirst + pSecond), partSize) + pSecond;
// };

int findQuotient(BigInt b, BigInt aPart) { 
  string aPartStr = aPart.getAccumator();

  int quotient = 0;
  int left = 0; 
  int right = NOTATION;

  while (left <= right) {
    int middle = (left + right) / 2;
    BigInt tmp = b * BigInt(middle);

    if (lowerOrEqual(tmp.getAccumator(), aPartStr)) {
      quotient = middle;
      left = middle + 1;
    } else
      right = middle - 1;
  }

  return quotient;
}

BigInt pow(BigInt a, BigInt b) {
  if (a == B_ZERO && b == B_ZERO)
    throw (std::invalid_argument("Exponentiation is not possible. Cannot raise zero to zero degree."));

  if (b < B_ZERO) 
    throw (std::invalid_argument("Exponentiation is not possible. Specified number is less than zero."));
  
  BigInt result(1);
  while (b != B_ZERO) {
    if (isEven(b)) {
      b /= B_TWO;
      a *= a;
    } else {
      b--;
      result *= a;
    }
  }

  return result;
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
  char lastDigit = num.getAccumator().back();
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

  for (auto byte : bytes) {
    for (int i = 0; i < 8; i++) {
      BigInt p((byteToInt(byte) >> i) & 1);

      result += p * q;
      q *= B_TWO;
    }
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