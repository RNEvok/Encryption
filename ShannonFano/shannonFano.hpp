#include "./../Parameters/parameters.hpp"

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
    ShannonFanoEncryption(Parameters params = Parameters());

    // Возвращает строку без пунктуации
    string savePunctuation(string plainMsg);

    // Возвращает строку с пунктуацией
    string withPunctuation(string plainMsg);

    Message encode(Message m);

    Message decode(Message m);
};