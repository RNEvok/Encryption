#include "AsymmetricEncryption/asymmetricEncryption.hpp"
#include "Caesar/caesar.hpp"
#include "ShannonFano/shannonFano.hpp"

int main() {
	try {
		srand((unsigned)time(NULL));

		cout << "\nВыберите метод шифрования:\n0-RSA (асимметричное шифрование)\n1-Шифр Цезаря (шифрование со сдвигом)\n2-Код Шеннона-Фано (префиксное кодирование)" << endl;
		int type;
		cin >> type;

		Encryptor encryptor;

		switch (type) {
			case 0:
				encryptor.setStrategy(new AsymmetricEncryption());
				break;
			case 1:
				encryptor.setStrategy(new CaesarEncryption());
				break;
			case 2:
				encryptor.setStrategy(new ShannonFanoEncryption());
				break;
			default:
				cout << "\n Необходимо выбрать один из предложенных методов." << endl;
				break;
		}

		Message msg("Hello, world!");
		// Message msg("Hello, world! Today is 17th april of 2022.");
		cout << msg.text << endl;

		Message secureMessage = encryptor.encode(msg);

		cout << "\nЗашифрованное сообщение: " << endl;
		secureMessage.logMessage();

		Message decodedMessage = encryptor.decode(secureMessage);

		cout << "\nРасшифрованное сообщение: " << endl;
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