#include "MyMath/myMath.hpp"
#include "AsymmetricEncryption/asymmetricEncryption.hpp"
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

		cout << "Total threads: " << omp_get_max_threads() << endl;
		// BigInt a = getLowLevelPrime(100);
		// cout << "Кандидат: " << endl;
		// a.logNumber();
		// bool ok = isMillerRabinTestOk(BigInt("85053461164796801949539541639542805770666392330682673302530819774105141531698707146930307290253537320447270457"));
		// cout << "Тест Миллера-Рабина: " << ok << endl;

		BigInt a("3606424576967919093705865277959324266530101739539046932559017030911149917983520574105683370314241690674112708913629934224080803490478759479623478054752686510877737477754308385512276007574641798168956250936617733106919345629889355671482887187706515839329371");
		ByteVector b = bigIntToByteVector(a);
		cout << "HERE " << b.size() << endl;

		// cout << "Total threads: " << omp_get_max_threads() << endl;
		// BigInt a("491249400599388959949383888232395293523");
		// BigInt b("400599388959949383888232395293523400599388959949383888232395293523");
		// BigInt c = a * b; // 196794209707056609970526590664283617136967469120413512013890305609171871757762063803541487299641325751529
		// c.logNumber();

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