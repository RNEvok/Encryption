#include "AsymmetricEncryption/asymmetricEncryption.h"

int main() {
	try {
		srand((unsigned)time(NULL));

		AsymmetricEncryption RSA;

		//Message msg("Hello, world!");
		Message msg("Hello, world! Today is 17th april of 2022.");
		// cout << "Message: " << endl;
		cout << msg.text << endl;

		Message secureMessage = RSA.encode(msg);

		cout << "secureMessage is secure: " << secureMessage.isSecure << endl;
		secureMessage.logMessage();

		Message decodedMessage = RSA.decode(secureMessage);

		cout << "decodedMessage is secure: " << decodedMessage.isSecure << endl;
		decodedMessage.logMessage();
		
		// Message msg("Hello, world! Today is 16th april of 2022.");
		// // Message msg("C++");
		// msg.logMessage();
		// ByteVector b = msg.convertToBytes();

		// for (auto &byte : b)
		// 	cout << to_integer<int>(byte) << " ";

		// cout << "\nЧисловое представление: " << endl;
		// BigInt nMsg = msg.convertToBigInt();
		// nMsg.logNumber();

		// ByteVector c = bigIntToByteVector(nMsg);
		// for (auto &byte : c)
		// 	cout << to_integer<int>(byte) << " ";

		// cout << "\nСнова строка: " << endl;
		// string msg2 = byteVectorToString(c);
		// cout << msg2 << endl;

	} catch (std::invalid_argument e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (std::exception e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (...) {
		cout << "Неизвестная ошибка!" << endl;
	}

	return 0;
}