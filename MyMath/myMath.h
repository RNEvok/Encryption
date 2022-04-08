#include <random>

// Возвращает true, если a <= value <= b
bool isBetween(int value, int a, int b);

// Возвращает случайное целое от min до max
int getRandomInt(int min, int max);

// Возвращает value, если min <= value <= b, min, если value < min и max, если value > max
// int clamp(int value, int min, int max) {
//   return Math.min(Math.max(value, min), max);
// }