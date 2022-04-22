#include "./../Encryption/encryption.hpp"

const DoubleVector ENGLISH_PROBABILITIES {0.0817, 0.0149, 0.0278, 0.0425, 0.127, 0.0223, 0.0202, 0.0609, 0.0697, 0.0015, 0.0077, 0.0403, 0.0241, 0.0675, 0.0751, 0.0193, 0.001, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0005};

typedef map<char, double> SymbolProbabilitiesTable;
typedef map<string, string> Codes;
struct Symbol {
  string symbol;
  double probability;
};
typedef vector<Symbol> ProbabilitiesTable;

class ShannonFanoEncryption: public Encryption {
  private:
    // Алфавит сообщения
    CharVector alplabet;
    // Размер блока
    int blockSize;
    // Таблица вероятностей появления символов
    SymbolProbabilitiesTable symbolPr;
    // Таблица вероятностей появления символов (ключей)
    ProbabilitiesTable probabilitiesTable;
    // Коды символов
    Codes codes;
    Codes codesInverse;
    // Энтропия алфавита
    double entropy;
    // Средняя длина символа (ключа)
    double avgLen;
    IntVector uppercasePositions;
    IntVector punctuationPositions;
    CharVector punctuation;

    // Создать таблицу кодовых слов
    void createCodes(int start, int end);

    // Возвращает оптимальный индекс разделения
    int getSplitIndex(int start, int end);

    // Отсортировать таблицу вероятностей
    void sortByProbability(ProbabilitiesTable* t);
  public:
    // Конструктор по умолчанию
    // a - набор символов; p - вероятности их появления
    // blockSize - размер блока
    ShannonFanoEncryption(CharVector a = ENGLISH, DoubleVector p = ENGLISH_PROBABILITIES, int blockSize = 2);

    // Возвращает строку без пунктуации
    string savePunctuation(string plainMsg);

    // Возвращает строку с пунктуацией
    string withPunctuation(string plainMsg);

    Message encode(Message m);

    Message decode(Message m);
};