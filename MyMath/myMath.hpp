#include <random>
#include <time.h>
#include <exception>
#include <vector>

using namespace std;

#define all(x) begin(x), end(x)
#define logRed(s) "\033[1;31m" << s << "\033[0m"
#define logGreen(s) "\033[1;32m" << s << "\033[0m"

// Вектор символов
typedef vector<char> CharVector;
// Вектор строк
typedef vector<string> StringVector;
// Вектор целых
typedef vector<int> IntVector;
// Вектор дробных
typedef vector<double> DoubleVector;
// Вектор байтов
typedef vector<byte> ByteVector;
// Матрица символов
typedef vector<CharVector> CharMatrix;
// Матрица целых
typedef vector<IntVector> IntMatrix;
// Матрица строк
typedef vector<StringVector> StringMatrix;

// Возвращает true, если a <= value <= b
bool isBetween(int value, int a, int b);

// Возвращает случайное целое от min до max
int getRandomInt(int min, int max);

// Возвращает энтропию дискретного источника с алфавитом произвольного размера
// probabilities - вектор чисел, где probabilities[i] - вероятность появления 
// i-го символа в сообщении
double calculateEntropy(DoubleVector probabilities);

template<class Type>
static vector<vector<Type>> placementsReiterationsInner(vector<Type> M, int i, size_t n, int k) {
  static vector<Type> D(k);
  static vector<vector<Type>> P;

  for (int x = 0; x < n; x++) {
    D[i] = M[x];
    if (i == k - 1)
      P.push_back(D);
    else
      placementsReiterationsInner(M, i + 1, n, k);
  };

  return P;
};

// Получение размещений с повторениями для объектов любого типа
template<class Type>
vector<vector<Type>> placementsReiterations(vector<Type> M, size_t n, int k) {
  return placementsReiterationsInner(M, 0, n, k);
};