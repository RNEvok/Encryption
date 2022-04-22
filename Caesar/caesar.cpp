#include "./caesar.hpp"

CaesarEncryption::CaesarEncryption(int shift, CharVector alphabet) {
  this->shift = shift;
  this->alphabet = alphabet;
  this->n = alphabet.size();

  AlphabetTable alphabetTable;
  for (int i = 0; i < alphabet.size(); i++)
    alphabetTable.insert(AlphabetTable::value_type(alphabet[i], i));

  this->alphabetTable = alphabetTable;
};

Message CaesarEncryption::encode(Message m) {
  return this->encode(m, shift);
};

Message CaesarEncryption::encode(Message m, int shift) {
  string plainMsg = m.text;
  CharVector plainMsgChars = stringToCharVector(plainMsg);
  string cipherMsg = "";

  for (auto sym : plainMsgChars) {
    cout << "HERE3" << sym << endl;
    char symUpper = toupper(sym);
    bool isUpper = sym == symUpper;
    auto el = this->alphabetTable.find(symUpper);

    if (el != this->alphabetTable.end()) {
      char shiftedSym = this->alphabet[(el->second + shift) % this->n];
      cipherMsg += isUpper? shiftedSym: tolower(shiftedSym);
    } else
      cipherMsg += sym;
  }

  return Message(cipherMsg, true);
};

Message CaesarEncryption::decode(Message m) {
  return this->decode(m, shift);
};

Message CaesarEncryption::decode(Message m, int shift) {
  Message shiftedBackMsg = this->encode(m, -shift + this->n);

  return Message(shiftedBackMsg.text, false);
};