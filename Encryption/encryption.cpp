#include "./encryption.hpp"

Message::Message(string text, bool isSecure) {
  this->text = text;
  this->isSecure = isSecure;
};

void Message::logMessage() {
  cout << this->text << endl;
};

ByteVector Message::convertToBytes() {
  return stringToByteVector(text);
};

BigInt Message::convertToBigInt() {
  return byteVectorToBigInt(this->convertToBytes());
};

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