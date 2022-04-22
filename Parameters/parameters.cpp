#include "./parameters.hpp"

Parameters::Parameters() {
  this->shift = 3;
  this->alphabet = ENGLISH;
  this->probabilities = ENGLISH_PROBABILITIES;
  this->blockSize = 2;
  this->primeLength = 64;
};

void Parameters::setShift(int shift) {
  this->shift = shift;
};

void Parameters::setBlockSize(int blockSize) {
  this->blockSize = blockSize;
};

void Parameters::setPrimeLength(int primeLength) {
  this->primeLength = primeLength;
};