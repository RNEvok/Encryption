#include "MyMath/myMath.h"
#include "AsymmetricEncryption/asymmetricEncryption.h"
#include <list>

int main() {
	try {
		srand((unsigned)time(NULL));

		// Message msg("Hello, world!");
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



		// BigInt a(1121);
		// BigInt b(10);
		// BezoutResult res = bezout(a, b);
		// res.x.logNumber();
		// res.y.logNumber();
		// res.gcd.logNumber();

		// BigInt testBezout = a * res.x + b * res.y;
		// testBezout.logNumber();

		// BigInt a("9699541732464975014054357308555373257319");
		// BigInt b("3826065689335905119379430621628781648521");
		// a.logNumber();
		// b.logNumber();

    // clock_t tic = clock();
		// BigInt t1 = gcd(a, b);
		// t1.logNumber();
    // clock_t toc = clock();
		// double time = toc - tic;
		// cout << "Время gcd: " << time << endl;

		// tic = clock();
		// BigInt t2 = steinGCD(a, b);
		// t2.logNumber();
    // toc = clock();
		// time = toc - tic;
		// cout << "Время steinGCD: " << time << endl;

		// KeysGenerator g;

		// BigInt a = getPrime(10);
		// cout << "Кандидат: " << endl;
		// a.logNumber();

		// cout << "Thread: " << omp_get_thread_num();
		// BigInt a = getLowLevelPrime(20);
		// cout << "Кандидат: " << endl;
		// a.logNumber();
		// bool ok = isMillerRabinTestOk(BigInt("6867760115452856200139921162967719673559"));
		// cout << "Тест Миллера-Рабина: " << ok << endl;

		cout << "Total threads: " << omp_get_max_threads() << endl;
		BigInt a("491249400599388959949383888232395293523");
		BigInt b("400599388959949383888232395293523400599388959949383888232395293523");
		BigInt c = a * b;
		c.logNumber();

		// bool ok = isMillerRabinTestOk(a);
		// cout << "Тест Миллера-Рабина: " << ok << endl;

		// Message a("gaga");

		// a.logMessage();

		// KeyPair a()

	} catch (std::invalid_argument e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (std::exception e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (...) {
		cout << "Неизвестная ошибка!" << endl;
	}

	return 0;
}