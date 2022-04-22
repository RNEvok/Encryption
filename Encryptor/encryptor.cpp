#include "./encryptor.hpp"

Encryptor::Encryptor() {};

Encryptor::Encryptor(Encryption* encryption) {
  this->encryption = encryption;
};

Encryptor::~Encryptor() {
  delete encryption;
};

void Encryptor::setStrategy(Encryption* encryption) {
  this->encryption = encryption;
};

Message Encryptor::encode(Message m) {
  return encryption->encode(m);
};

Message Encryptor::decode(Message m) {
  return encryption->decode(m);
};