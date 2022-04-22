#include "./caesar.hpp"

int main() {
	try {
		srand((unsigned)time(NULL));

		Encryptor caesar(new CaesarEncryption());

		Message msg("Hello, world!");
		cout << msg.text << endl;

		Message secureMessage = caesar.encode(msg);

		cout << "secureMessage is secure: " << secureMessage.isSecure << endl;
		secureMessage.logMessage();

		Message decodedMessage = caesar.decode(secureMessage);

		cout << "decodedMessage is secure: " << decodedMessage.isSecure << endl;
		decodedMessage.logMessage();

	} catch (std::invalid_argument e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (std::exception e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (...) {
		cout << "Неизвестная ошибка!" << endl;
	}

	return 0;
}