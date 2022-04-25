#include "./../Parameters/parameters.hpp"

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
    CaesarEncryption(Parameters params = Parameters());

    Message encode(Message m);

    Message encode(Message m, int shift);

    Message decode(Message m);

    Message decode(Message m, int shift);
};