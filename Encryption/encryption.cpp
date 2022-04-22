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