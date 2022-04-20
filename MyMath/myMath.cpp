#include "./myMath.hpp"

bool isBetween(int value, int a, int b) {
  return (a <= value && value <= b);
};

int getRandomInt(int min, int max) {
  ++max;
  int Δ = max - min;

  if (Δ > RAND_MAX)
    throw (std::invalid_argument("Δ > RAND_MAX"));

  return rand() % Δ + min;
};

// Возвращает количество информации по Шеннону для события с вероятностью p
double informationAmountShannon(double p) {
  return -log2(p);
};

double calculateEntropy(DoubleVector probabilities) {
  // Количество информации i-го символа
  DoubleVector imformationAmount;

  for (auto p : probabilities)
    imformationAmount.push_back(informationAmountShannon(p));

  double entropy = 0;
  for (int i = 0; i < imformationAmount.size(); i++)
    entropy += (-imformationAmount[i] * probabilities[i]);

  return (-entropy);
};