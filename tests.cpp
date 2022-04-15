#include "MyMath/myMath.h"
// #include "BigInt/bigInt.h"
// #include "Encryption/encryption.h"
#include "AsymmetricEncryption/asymmetricEncryption.h"
#include <list>

int main() {
	try {
		srand((unsigned)time(NULL));

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

		KeysGenerator g;

		// BigInt a = getPrime(10);
		// cout << "Кандидат: " << endl;
		// a.logNumber();

		// BigInt a = getLowLevelPrime(100);
		// cout << "Кандидат: " << endl;
		// a.logNumber();
		// bool ok = isMillerRabinTestOk(BigInt("6867760115452856200139921162967719673559"));
		// cout << "Тест Миллера-Рабина: " << ok << endl;

		// bool ok = isMillerRabinTestOk(a);
		// cout << "Тест Миллера-Рабина: " << ok << endl;

		// Message a("gaga");

		// a.logMessage();

		// KeyPair a()

		// {
		// 	cout << "\nСложение: " << endl;

		// 	{
		// 		BigInt a("12");
		// 		BigInt b("3");
		// 		BigInt c = a + b;
		// 		cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	} 

		// 	{
		// 		BigInt a("12", true);
		// 		BigInt b("3");
		// 		BigInt c = a + b;
		// 		cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	} 

		// 	{
		// 		BigInt a("12");
		// 		BigInt b("3", true);
		// 		BigInt c = a + b;
		// 		cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	} 

		// 	{
		// 		BigInt a("12", true);
		// 		BigInt b("3", true);
		// 		BigInt c = a + b;
		// 		cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	} 

		// 	{
		// 		BigInt a("123456789012345678901234567890");
		// 		BigInt b("1111111111111111111");
		// 		BigInt c = a + b;
		// 		cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	} 
		// }

		// {
		// 	cout << "\nВычитание: " << endl;

		// 	{
		// 		BigInt a("123");
		// 		BigInt b("100");
		// 		BigInt c = a - b;
		// 		cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
		// 		BigInt d = b - a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("123", true);
		// 		BigInt b("100");
		// 		BigInt c = a - b;
		// 		cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
		// 		BigInt d = b - a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("123");
		// 		BigInt b("100", true);
		// 		BigInt c = a - b;
		// 		cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
		// 		BigInt d = b - a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("123", true);
		// 		BigInt b("100", true);
		// 		BigInt c = a - b;
		// 		cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
		// 		BigInt d = b - a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("1");
		// 		BigInt b("1000");
		// 		BigInt c = a - b;
		// 		cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
		// 		BigInt d = b - a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("12");
		// 		BigInt b("12");
		// 		BigInt c = a - b;
		// 		cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
		// 		BigInt d = b - a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("123456789012345678901234567890");
		// 		BigInt b("987654321987654321");
		// 		BigInt c = a - b;
		// 		cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
		// 		BigInt d = b - a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// }

		// {
		// 	cout << "\nУмножение: " << endl;

		// 	{
		// 		BigInt a("123");
		// 		BigInt b("100");
		// 		BigInt c = a * b;
		// 		cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
		// 		BigInt d = b * a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("123", true);
		// 		BigInt b("100");
		// 		BigInt c = a * b;
		// 		cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
		// 		BigInt d = b * a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("123");
		// 		BigInt b("100", true);
		// 		BigInt c = a * b;
		// 		cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
		// 		BigInt d = b * a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("123", true);
		// 		BigInt b("100", true);
		// 		BigInt c = a * b;
		// 		cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
		// 		BigInt d = b * a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("1");
		// 		BigInt b("1000");
		// 		BigInt c = a * b;
		// 		cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
		// 		BigInt d = b * a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("46");
		// 		BigInt b("22");
		// 		BigInt c = a * b;
		// 		cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
		// 		BigInt d = b * a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 
		// 	{
		// 		BigInt a("0");
		// 		BigInt b("22");
		// 		BigInt c = a * b;
		// 		cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
		// 		BigInt d = b * a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	} 

		// 	{
		// 		BigInt a("8888888888888877777777777777");
		// 		BigInt b("1111111111111122222222222222");
		// 		BigInt c = a * b;
		// 		cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	} 
		// }

		// {
		// 	cout << "\nДеление: " << endl;

		// 	// {
		// 	// 	BigInt a("10");
		// 	// 	BigInt b("0");
		// 	// 	BigInt c = a / b;
		// 	// 	cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 	// 	c.logNumber();
		// 	// 	cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 	// 	BigInt d = b / a;
		// 	// 	d.logNumber();
		// 	// 	cout << endl;
		// 	// }
		// 	{
		// 		BigInt a("0");
		// 		BigInt b("10");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("120");
		// 		BigInt b("30");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 		BigInt d = b / a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("120");
		// 		BigInt b("3");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 		BigInt d = b / a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("120", true);
		// 		BigInt b("3");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 		BigInt d = b / a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("120");
		// 		BigInt b("3", true);
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 		BigInt d = b / a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("120", true);
		// 		BigInt b("3", true);
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 		BigInt d = b / a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("1500");
		// 		BigInt b("500");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 		BigInt d = b / a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("1500");
		// 		BigInt b("5");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 		BigInt d = b / a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("1000000");
		// 		BigInt b("2");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 		BigInt d = b / a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("9");
		// 		BigInt b("2");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
		// 		BigInt d = b / a;
		// 		d.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("10000000");
		// 		BigInt b("3");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("10000000");
		// 		BigInt b("3333333");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("12481632641282565120");
		// 		BigInt b("125");
		// 		BigInt c = a / b;
		// 		cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// }

		// {
		// 	cout << "\nОстаток от деления: " << endl;
		// 	{
		// 		BigInt a("0");
		// 		BigInt b("10");
		// 		BigInt c = a % b;
		// 		cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("10");
		// 		BigInt b("1");
		// 		BigInt c = a % b;
		// 		cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("17");
		// 		BigInt b("3");
		// 		BigInt c = a % b;
		// 		cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("562");
		// 		BigInt b("33");
		// 		BigInt c = a % b;
		// 		cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("562", true);
		// 		BigInt b("33");
		// 		BigInt c = a % b;
		// 		cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("562");
		// 		BigInt b("33", true);
		// 		BigInt c = a % b;
		// 		cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("562", true);
		// 		BigInt b("33", true);
		// 		BigInt c = a % b;
		// 		cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
		// 		c.logNumber();
		// 		cout << endl;
		// 	}
		// }

		// {
		// 	cout << "\nИнкремент: " << endl;
		// 	{
		// 		BigInt a("0");
		// 		a.logNumber();
		// 		a++;
		// 		a.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("10");
		// 		a.logNumber();
		// 		a++;
		// 		a.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("1", true);
		// 		a.logNumber();
		// 		a++;
		// 		a.logNumber();
		// 		cout << endl;
		// 	}
		// }

		// {
		// 	cout << "\nДикремент: " << endl;
		// 	{
		// 		BigInt a("0");
		// 		a.logNumber();
		// 		a--;
		// 		a.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("10");
		// 		a.logNumber();
		// 		a--;
		// 		a.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("1", true);
		// 		a.logNumber();
		// 		a--;
		// 		a.logNumber();
		// 		cout << endl;
		// 	}
		// 	{
		// 		BigInt a("10", true);
		// 		a.logNumber();
		// 		a--;
		// 		a.logNumber();
		// 		cout << endl;
		// 	}
		// }

		// {
		// 	cout << "\nПрисваивающее сложение: " << endl;
		// 	{
		// 		BigInt a("100");
		// 		BigInt b("23");
		// 		cout << b.getAccumatorWithSign() << " += " << a.getAccumatorWithSign();
		// 		b += a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100");
		// 		BigInt b("23", true);
		// 		cout << b.getAccumatorWithSign() << " += " << a.getAccumatorWithSign();
		// 		b += a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100", true);
		// 		BigInt b("23");
		// 		cout << b.getAccumatorWithSign() << " += " << a.getAccumatorWithSign();
		// 		b += a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100", true);
		// 		BigInt b("23", true);
		// 		cout << b.getAccumatorWithSign() << " += " << a.getAccumatorWithSign();
		// 		b += a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}
		// }

		// {
		// 	cout << "\nПрисваивающее вычитание: " << endl;
		// 	{
		// 		BigInt a("100");
		// 		BigInt b("23");
		// 		cout << b.getAccumatorWithSign() << " -= " << a.getAccumatorWithSign();
		// 		b -= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100");
		// 		BigInt b("23", true);
		// 		cout << b.getAccumatorWithSign() << " -= " << a.getAccumatorWithSign();
		// 		b -= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100", true);
		// 		BigInt b("23");
		// 		cout << b.getAccumatorWithSign() << " -= " << a.getAccumatorWithSign();
		// 		b -= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100", true);
		// 		BigInt b("23", true);
		// 		cout << b.getAccumatorWithSign() << " -= " << a.getAccumatorWithSign();
		// 		b -= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}
		// }

		// {
		// 	cout << "\nПрисваивающее умножение: " << endl;
		// 	{
		// 		BigInt a("100");
		// 		BigInt b("23");
		// 		cout << b.getAccumatorWithSign() << " *= " << a.getAccumatorWithSign();
		// 		b *= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100");
		// 		BigInt b("23", true);
		// 		cout << b.getAccumatorWithSign() << " *= " << a.getAccumatorWithSign();
		// 		b *= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100", true);
		// 		BigInt b("23");
		// 		cout << b.getAccumatorWithSign() << " *= " << a.getAccumatorWithSign();
		// 		b *= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100", true);
		// 		BigInt b("23", true);
		// 		cout << b.getAccumatorWithSign() << " *= " << a.getAccumatorWithSign();
		// 		b *= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}
		// }

		// {
		// 	cout << "\nПрисваивающее деление: " << endl;
		// 	{
		// 		BigInt a("2");
		// 		BigInt b("5");
		// 		cout << b.getAccumatorWithSign() << " /= " << a.getAccumatorWithSign();
		// 		b /= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("2");
		// 		BigInt b("5", true);
		// 		cout << b.getAccumatorWithSign() << " /= " << a.getAccumatorWithSign();
		// 		b /= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("3", true);
		// 		BigInt b("10");
		// 		cout << b.getAccumatorWithSign() << " /= " << a.getAccumatorWithSign();
		// 		b /= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("23", true);
		// 		BigInt b("100", true);
		// 		cout << b.getAccumatorWithSign() << " /= " << a.getAccumatorWithSign();
		// 		b /= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}
		// }

		// {
		// 	cout << "\nПрисваивающее остаток от деления: " << endl;
		// 	{
		// 		BigInt a("5");
		// 		BigInt b("2");
		// 		cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
		// 		b %= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("5");
		// 		BigInt b("2", true);
		// 		cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
		// 		b %= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("10", true);
		// 		BigInt b("3");
		// 		cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
		// 		b %= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("100", true);
		// 		BigInt b("23", true);
		// 		cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
		// 		b %= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}

		// 	{
		// 		BigInt a("3");
		// 		BigInt b("10");
		// 		cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
		// 		b %= a;
		// 		b.logNumber();
		// 		cout << endl;
		// 	}
		// }

		// {
		// 	cout << "\nМеньше: " << endl;
		// 	{
		// 		BigInt a("5");
		// 		BigInt b("2");
		// 		cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
		// 		cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
		// 	}
			
		// 	{
		// 		BigInt a("5", true);
		// 		BigInt b("2");
		// 		cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
		// 		cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
		// 	}

		// 	{
		// 		BigInt a("5");
		// 		BigInt b("2", true);
		// 		cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
		// 		cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
		// 	}

		// 	{
		// 		BigInt a("5", true);
		// 		BigInt b("2", true);
		// 		cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
		// 		cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
		// 	}

		// 	{
		// 		BigInt a("0");
		// 		BigInt b("0", true);
		// 		cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
		// 		cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
		// 	}

		// }

		// list<BigInt> numbersList;
		// numbersList.push_back(BigInt("1"));
		// numbersList.push_back(BigInt("133"));
		// numbersList.push_back(BigInt("0"));
		// numbersList.push_back(BigInt("17", true));
		// numbersList.push_back(BigInt("244"));
		// numbersList.push_back(BigInt("137", true));
		// numbersList.push_back(BigInt("99999998888888888888888"));
		// numbersList.push_back(BigInt("1111111"));
		// numbersList.push_back(BigInt("1", true));
		// numbersList.push_back(BigInt("55"));

		// cout << "\nДан список чисел: " << endl;
		// for (auto num : numbersList)
		// 	num.logNumber();

		// cout << "\nПо возрастанию: " << endl;
		// numbersList.sort([](BigInt& a, BigInt& b) {return a < b;});
		// for (auto num : numbersList)
		// 	num.logNumber();

		// cout << "\nПо убыванию: " << endl;
		// numbersList.sort([](BigInt& a, BigInt& b) {return a > b;});
		// for (auto num : numbersList)
		// 	num.logNumber();

	} catch (const string e) {
		cout << "Ошибка! " << endl;
	}

	return 0;
}