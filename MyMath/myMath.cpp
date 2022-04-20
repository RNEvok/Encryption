#include "./myMath.hpp"
#include <time.h>
#include <exception>

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