#include "Encryptor/encryptor.hpp"
#include "Parameters/parameters.hpp"

int main() {
	try {
		srand((unsigned)time(NULL));

		cout << "\nВыберите метод шифрования:" << endl;
		cout << "0-RSA (асимметричное шифрование)" << endl;
		cout << "1-Шифр Цезаря (шифрование со сдвигом)" << endl;
		cout << "2-Код Шеннона-Фано (префиксное кодирование)" << endl;
		int type;
		cin >> type;

		Encryptor encryptor;
		Parameters params;

		switch (type) {
			case 0:
				cout << "\nУкажите необходимый размер простых чисел p и q: ";
				int primeLength;
				cin >> primeLength;
				params.setPrimeLength(primeLength);
				encryptor.setStrategy(new AsymmetricEncryption(params));
				break;
			case 1:
				cout << "\nУкажите сдвиг шифра: ";
				int shift;
				cin >> shift;
				params.setShift(shift);
				encryptor.setStrategy(new CaesarEncryption(params));
				break;
			case 2:
				cout << "\nУкажите размер блока для кодовых слов: ";
				int blockSize;
				cin >> blockSize;
				params.setBlockSize(blockSize);
				encryptor.setStrategy(new ShannonFanoEncryption(params));
				break;
			default:
				cout << "\n Необходимо выбрать один из предложенных методов." << endl;
				break;
		}

		Message msg("Hello, world! Today is 22th april of 2022.");
		// Message msg("Hello, world! Today is 17th april of 2022.");

		cout << "\nОткрытое сообщение: " << endl;
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