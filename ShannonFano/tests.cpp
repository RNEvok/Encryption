#include "./shannonFano.hpp"

int main() {
	try {
		srand((unsigned)time(NULL));

		CharVector a {'A', 'B', 'C', 'D', 'E', 'F'};
		DoubleVector p {0.2, 0.19, 0.16, 0.02, 0.39, 0.04};

		ShannonFanoEncryption shannon(ENGLISH, ENGLISH_PROBABILITIES, 2);
		// ShannonFanoEncryption shannon(a, p, 2);

		Message msg("Hello, world!");
		//Message msg("DEBCEAEEBBFFACEBEDAB");
		cout << msg.text << endl;

		Message secureMessage = shannon.encode(msg);

		cout << "secureMessage is secure: " << secureMessage.isSecure << endl;
		secureMessage.logMessage();
		cout << "1111000110100010001011011111111011000010111101111010"<< endl;

		Message decodedMessage = shannon.decode(secureMessage);

		cout << "decodedMessage is secure: " << decodedMessage.isSecure << endl;
		decodedMessage.logMessage();

		// cout << ENGLISH.size() << " " << ENGLISH_PROBABILITIES.size() << endl;

		// double test = 0;

		// for (auto x:ENGLISH_PROBABILITIES)
		// 	test+=x;

		// 	cout << test << endl;

		// IntVector testPlacementsReiterations {1, 2, 3, 4};
		// IntMatrix r = placementsReiterations<int>(testPlacementsReiterations, testPlacementsReiterations.size(), 2);

		// for (auto p : r) {
		// 	for (auto x : p)
		// 		cout << x << " ";

		// 	cout << endl;
		// }

		

	} catch (std::invalid_argument e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (std::exception e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (...) {
		cout << "Неизвестная ошибка!" << endl;
	}

	return 0;
}