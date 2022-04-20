#include "./../Encryption/encryption.hpp"

const CharVector ENGLISH {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

typedef map<char, int> AlphabetTable;

class CaesarEncryption: public Encryption {
  private:
    // Сдвиг шифра
    int shift;
    // Алфавит сообщения
    CharVector alphabet;
    // Таблица алфавита
    AlphabetTable alphabetTable;
    // Мощность алфавита
    int n;
  public:
    // Конструктор по умолчанию
    CaesarEncryption(int shift = 0, CharVector alphabet = ENGLISH);

    Message encode(Message m);

    Message encode(Message m, int shift);

    Message decode(Message m);

    Message decode(Message m, int shift);
};