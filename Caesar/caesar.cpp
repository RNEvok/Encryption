#include "./caesar.hpp"

CaesarEncryption::CaesarEncryption(Parameters params) {
  this->shift = params.shift;
  this->alphabet = params.alphabet;
  this->n = params.alphabet.size();

  AlphabetTable alphabetTable;
  for (int i = 0; i < this->alphabet.size(); i++)
    alphabetTable.insert(AlphabetTable::value_type(this->alphabet[i], i));

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