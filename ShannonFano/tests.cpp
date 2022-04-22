#include "./shannonFano.hpp"

int main() {
	try {
		srand((unsigned)time(NULL));

		CharVector a {'A', 'B', 'C', 'D', 'E', 'F'};
		DoubleVector p {0.2, 0.19, 0.16, 0.02, 0.39, 0.04};

		Encryptor shannon(new ShannonFanoEncryption());
		// ShannonFanoEncryption shannon(a, p, 2);

		Message msg("Hello, world!");
		//Message msg("DEBCEAEEBBFFACEBEDAB");
		cout << msg.text << endl;

		Message secureMessage = shannon.encode(msg);

		cout << "secureMessage is secure: " << secureMessage.isSecure << endl;
		secureMessage.logMessage();

		Message decodedMessage = shannon.decode(secureMessage);

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