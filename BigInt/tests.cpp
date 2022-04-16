#include "bigInt.h"
#include <list>

int testsFailed = 0;

void test(bool ok) {
  if (ok)
    cout << "\033[1;32m Test passed \033[0m\n" << endl;
  else {
    testsFailed++;
    cout << "\033[1;31m Test failed \033[0m\n";
  }
};

int main() {
	try {
		{
			cout << "\nСложение: " << endl;

			{
				BigInt a("12");
				BigInt b("3");
				BigInt c = a + b;
				cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
				c.logNumber();
				cout << endl;

        BigInt expectedRes(15);
        test(c == expectedRes);
			} 

			{
				BigInt a("12", true);
				BigInt b("3");
				BigInt c = a + b;
				cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
				c.logNumber();
				cout << endl;

        BigInt expectedRes(9, true);
        test(c == expectedRes);
			} 

			{
				BigInt a("12");
				BigInt b("3", true);
				BigInt c = a + b;
				cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
				c.logNumber();
				cout << endl;

        BigInt expectedRes(9);
        test(c == expectedRes);
			} 

			{
				BigInt a("12", true);
				BigInt b("3", true);
				BigInt c = a + b;
				cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
				c.logNumber();
				cout << endl;

        BigInt expectedRes(15, true);
        test(c == expectedRes);
			} 

			{
				BigInt a("123456789012345678901234567890");
				BigInt b("1111111111111111111");
				BigInt c = a + b;
				cout << a.getAccumatorWithSign() << " + " << b.getAccumatorWithSign();
				c.logNumber();
				cout << endl;

        BigInt expectedRes("123456789013456790012345679001");
        test(c == expectedRes);
			} 
		}

		{
			cout << "\nВычитание: " << endl;

			{
				BigInt a("123");
				BigInt b("100");
				BigInt c = a - b;
				cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes(23);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
				BigInt d = b - a;
				d.logNumber();

        BigInt expectedRes1(23, true);
        test(d == expectedRes1);
				cout << endl;
			} 
			{
				BigInt a("123", true);
				BigInt b("100");
				BigInt c = a - b;
				cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes(223, true);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
				BigInt d = b - a;
				d.logNumber();

        BigInt expectedRes1(223);
        test(d == expectedRes1);
				cout << endl;
			} 
			{
				BigInt a("123");
				BigInt b("100", true);
				BigInt c = a - b;
				cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes(223);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
				BigInt d = b - a;
				d.logNumber();

        BigInt expectedRes1(223, true);
        test(d == expectedRes1);
				cout << endl;
			} 
			{
				BigInt a("123", true);
				BigInt b("100", true);
				BigInt c = a - b;
				cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes(23, true);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
				BigInt d = b - a;
				d.logNumber();

        BigInt expectedRes1(23);
        test(d == expectedRes1);
				cout << endl;
			} 
			{
				BigInt a("1");
				BigInt b("1000");
				BigInt c = a - b;
				cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes(999, true);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
				BigInt d = b - a;
				d.logNumber();

        BigInt expectedRes1(999);
        test(d == expectedRes1);
				cout << endl;
			} 
			{
				BigInt a("12");
				BigInt b("12");
				BigInt c = a - b;
				cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes(0);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
				BigInt d = b - a;
				d.logNumber();

        BigInt expectedRes1(0);
        test(d == expectedRes1);
				cout << endl;
			} 
			{
				BigInt a("123456789012345678901234567890");
				BigInt b("987654321987654321");
				BigInt c = a - b;
				cout << a.getAccumatorWithSign() << " - " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("123456789011358024579246913569");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " - " << a.getAccumatorWithSign();
				BigInt d = b - a;
				d.logNumber();
        BigInt expectedRes1("123456789011358024579246913569", true);
        test(d == expectedRes1);
				cout << endl;
			} 
		}

		{
			cout << "\nУмножение: " << endl;

			{
				BigInt a("123");
				BigInt b("100");
				BigInt c = a * b;
				cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("12300");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
				BigInt d = b * a;
				d.logNumber();
        test(d == expectedRes);
				cout << endl;
			} 
			{
				BigInt a("123", true);
				BigInt b("100");
				BigInt c = a * b;
				cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("12300", true);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
				BigInt d = b * a;
				d.logNumber();
        test(d == expectedRes);
				cout << endl;
			} 
			{
				BigInt a("123");
				BigInt b("100", true);
				BigInt c = a * b;
				cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("12300", true);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
				BigInt d = b * a;
				d.logNumber();
        test(d == expectedRes);
				cout << endl;
			} 
			{
				BigInt a("123", true);
				BigInt b("100", true);
				BigInt c = a * b;
				cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("12300");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
				BigInt d = b * a;
				d.logNumber();
        test(d == expectedRes);
				cout << endl;
			} 
			{
				BigInt a("1");
				BigInt b("1000");
				BigInt c = a * b;
				cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("1000");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
				BigInt d = b * a;
				d.logNumber();
        test(d == expectedRes);
				cout << endl;
			} 
			{
				BigInt a("46");
				BigInt b("22");
				BigInt c = a * b;
				cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("1012");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
				BigInt d = b * a;
				d.logNumber();
        test(d == expectedRes);
				cout << endl;
			} 
			{
				BigInt a("0");
				BigInt b("22");
				BigInt c = a * b;
				cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("0");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " * " << a.getAccumatorWithSign();
				BigInt d = b * a;
				d.logNumber();
        test(d == expectedRes);
				cout << endl;
			} 

			{
				BigInt a("8888888888888877777777777777");
				BigInt b("1111111111111122222222222222");
				BigInt c = a * b;
				cout << a.getAccumatorWithSign() << " * " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("9876543209876629629629629626666666666666660493827160494");
        test(c == expectedRes);

				cout << endl;
			} 
		}

		{
			cout << "\nДеление: " << endl;

			{
				BigInt a("0");
				BigInt b("10");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("0");
        test(c == expectedRes);
				cout << endl;
			}
			{
				BigInt a("120");
				BigInt b("30");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("4");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
				BigInt d = b / a;
				d.logNumber();

        BigInt expectedRes1("0");
        test(d == expectedRes1);

				cout << endl;
			}

			{
				BigInt a("120");
				BigInt b("3");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("40");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
				BigInt d = b / a;
				d.logNumber();

        BigInt expectedRes1("0");
        test(d == expectedRes1);

				cout << endl;
			}

			{
				BigInt a("120", true);
				BigInt b("3");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("40", true);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
				BigInt d = b / a;
				d.logNumber();

        BigInt expectedRes1("0", true);
        test(d == expectedRes1);

				cout << endl;
			}

			{
				BigInt a("120");
				BigInt b("3", true);
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("40", true);
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
				BigInt d = b / a;

        BigInt expectedRes1("0", true);
        test(d == expectedRes1);

				d.logNumber();
				cout << endl;
			}

			{
				BigInt a("120", true);
				BigInt b("3", true);
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("40");
        test(c == expectedRes);
			}

			{
				BigInt a("1500");
				BigInt b("500");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("3");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
				BigInt d = b / a;
				d.logNumber();

        BigInt expectedRes1("0");
        test(d == expectedRes1);
				cout << endl;
			}

			{
				BigInt a("1500");
				BigInt b("5");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("300");
        test(c == expectedRes);
			}

			{
				BigInt a("1000000");
				BigInt b("2");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("500000");
        test(c == expectedRes);

				cout << b.getAccumatorWithSign() << " / " << a.getAccumatorWithSign();
				BigInt d = b / a;
				d.logNumber();

        BigInt expectedRes1("0");
        test(d == expectedRes1);
				cout << endl;
			}

			{
				BigInt a("9");
				BigInt b("2");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("4");
        test(c == expectedRes);
			}
			{
				BigInt a("10000000");
				BigInt b("3");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();
				cout << endl;

        BigInt expectedRes("3333333");
        test(c == expectedRes);
			}
			{
				BigInt a("10000000");
				BigInt b("3333333");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("3");
        test(c == expectedRes);
				cout << endl;
			}
			{
				BigInt a("12481632641282565120");
				BigInt b("125");
				BigInt c = a / b;
				cout << a.getAccumatorWithSign() << " / " << b.getAccumatorWithSign();
				c.logNumber();
				cout << endl;

        BigInt expectedRes("99853061130260520");
        test(c == expectedRes);
			}
		}

		{
			cout << "\nОстаток от деления: " << endl;
			{
				BigInt a("0");
				BigInt b("10");
				BigInt c = a % b;
				cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("0");
        test(c == expectedRes);
				cout << endl;
			}
			{
				BigInt a("10");
				BigInt b("1");
				BigInt c = a % b;
				cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("0");
        test(c == expectedRes);
				cout << endl;
			}
			{
				BigInt a("17");
				BigInt b("3");
				BigInt c = a % b;
				cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("2");
        test(c == expectedRes);
				cout << endl;
			}
			{
				BigInt a("562");
				BigInt b("33");
				BigInt c = a % b;
				cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("1");
        test(c == expectedRes);
				cout << endl;
			}
			{
				BigInt a("562", true);
				BigInt b("33");
				BigInt c = a % b;
				cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("1", true);
        test(c == expectedRes);
				cout << endl;
			}
			{
				BigInt a("562");
				BigInt b("33", true);
				BigInt c = a % b;
				cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("1");
        test(c == expectedRes);
				cout << endl;
			}
			{
				BigInt a("562", true);
				BigInt b("33", true);
				BigInt c = a % b;
				cout << a.getAccumatorWithSign() << " % " << b.getAccumatorWithSign();
				c.logNumber();

        BigInt expectedRes("1", true);
        test(c == expectedRes);
				cout << endl;
			}
		}

		{
			cout << "\nИнкремент: " << endl;
			{
				BigInt a("0");
				a.logNumber();
				a++;
				a.logNumber();

        BigInt expectedRes("1");
        test(a == expectedRes);
				cout << endl;
			}
			{
				BigInt a("10");
				a.logNumber();
				a++;
				a.logNumber();

        BigInt expectedRes("11");
        test(a == expectedRes);
				cout << endl;
			}
			{
				BigInt a("1", true);
				a.logNumber();
				a++;
				a.logNumber();

        BigInt expectedRes("0");
        test(a == expectedRes);
				cout << endl;
			}
		}

		{
			cout << "\nДикремент: " << endl;
			{
				BigInt a("0");
				a.logNumber();
				a--;
				a.logNumber();

        BigInt expectedRes("1", true);
        test(a == expectedRes);
				cout << endl;
			}
			{
				BigInt a("10");
				a.logNumber();
				a--;
				a.logNumber();

        BigInt expectedRes("9");
        test(a == expectedRes);
				cout << endl;
			}
			{
				BigInt a("1", true);
				a.logNumber();
				a--;
				a.logNumber();

        BigInt expectedRes("2", true);
        test(a == expectedRes);
				cout << endl;
			}
			{
				BigInt a("10", true);
				a.logNumber();
				a--;
				a.logNumber();

        BigInt expectedRes("11", true);
        test(a == expectedRes);
				cout << endl;
			}
		}

		{
			cout << "\nПрисваивающее сложение: " << endl;
			{
				BigInt a("100");
				BigInt b("23");
				cout << b.getAccumatorWithSign() << " += " << a.getAccumatorWithSign();
				b += a;
				b.logNumber();

        BigInt expectedRes("123");
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100");
				BigInt b("23", true);
				cout << b.getAccumatorWithSign() << " += " << a.getAccumatorWithSign();
				b += a;
				b.logNumber();

        BigInt expectedRes("77");
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100", true);
				BigInt b("23");
				cout << b.getAccumatorWithSign() << " += " << a.getAccumatorWithSign();
				b += a;
				b.logNumber();

        BigInt expectedRes("77", true);
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100", true);
				BigInt b("23", true);
				cout << b.getAccumatorWithSign() << " += " << a.getAccumatorWithSign();
				b += a;
				b.logNumber();

        BigInt expectedRes("123", true);
        test(b == expectedRes);
				cout << endl;
			}
		}

		{
			cout << "\nПрисваивающее вычитание: " << endl;
			{
				BigInt a("100");
				BigInt b("23");
				cout << b.getAccumatorWithSign() << " -= " << a.getAccumatorWithSign();
				b -= a;
				b.logNumber();

        BigInt expectedRes("77", true);
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100");
				BigInt b("23", true);
				cout << b.getAccumatorWithSign() << " -= " << a.getAccumatorWithSign();
				b -= a;
				b.logNumber();

        BigInt expectedRes("123", true);
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100", true);
				BigInt b("23");
				cout << b.getAccumatorWithSign() << " -= " << a.getAccumatorWithSign();
				b -= a;
				b.logNumber();

        BigInt expectedRes("123");
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100", true);
				BigInt b("23", true);
				cout << b.getAccumatorWithSign() << " -= " << a.getAccumatorWithSign();
				b -= a;
				b.logNumber();

        BigInt expectedRes("77");
        test(b == expectedRes);
				cout << endl;
			}
		}

		{
			cout << "\nПрисваивающее умножение: " << endl;
			{
				BigInt a("100");
				BigInt b("23");
				cout << b.getAccumatorWithSign() << " *= " << a.getAccumatorWithSign();
				b *= a;
				b.logNumber();

        BigInt expectedRes("2300");
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100");
				BigInt b("23", true);
				cout << b.getAccumatorWithSign() << " *= " << a.getAccumatorWithSign();
				b *= a;
				b.logNumber();

        BigInt expectedRes("2300", true);
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100", true);
				BigInt b("23");
				cout << b.getAccumatorWithSign() << " *= " << a.getAccumatorWithSign();
				b *= a;
				b.logNumber();

        BigInt expectedRes("2300", true);
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100", true);
				BigInt b("23", true);
				cout << b.getAccumatorWithSign() << " *= " << a.getAccumatorWithSign();
				b *= a;
				b.logNumber();

        BigInt expectedRes("2300");
        test(b == expectedRes);
				cout << endl;
			}
		}

		{
			cout << "\nПрисваивающее деление: " << endl;
			{
				BigInt a("2");
				BigInt b("5");
				cout << b.getAccumatorWithSign() << " /= " << a.getAccumatorWithSign();
				b /= a;
				b.logNumber();

        BigInt expectedRes("2");
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("2");
				BigInt b("5", true);
				cout << b.getAccumatorWithSign() << " /= " << a.getAccumatorWithSign();
				b /= a;
				b.logNumber();

        BigInt expectedRes("2", true);
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("3", true);
				BigInt b("10");
				cout << b.getAccumatorWithSign() << " /= " << a.getAccumatorWithSign();
				b /= a;
				b.logNumber();

        BigInt expectedRes("3", true);
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("23", true);
				BigInt b("100", true);
				cout << b.getAccumatorWithSign() << " /= " << a.getAccumatorWithSign();
				b /= a;
				b.logNumber();

        BigInt expectedRes("4");
        test(b == expectedRes);
				cout << endl;
			}
		}

		{
			cout << "\nПрисваивающее остаток от деления: " << endl;
			{
				BigInt a("5");
				BigInt b("2");
				cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
				b %= a;
				b.logNumber();

        BigInt expectedRes("2");
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("5");
				BigInt b("2", true);
				cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
				b %= a;
				b.logNumber();

        BigInt expectedRes("2", true);
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("10", true);
				BigInt b("3");
				cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
				b %= a;
				b.logNumber();

        BigInt expectedRes("3");
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("100", true);
				BigInt b("23", true);
				cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
				b %= a;
				b.logNumber();

        BigInt expectedRes("23", true);
        test(b == expectedRes);
				cout << endl;
			}

			{
				BigInt a("3");
				BigInt b("10");
				cout << b.getAccumatorWithSign() << " %= " << a.getAccumatorWithSign();
				b %= a;
				b.logNumber();

        BigInt expectedRes("1");
        test(b == expectedRes);
				cout << endl;
			}
		}

		{
			cout << "\nМеньше: " << endl;
			{
				BigInt a("5");
				BigInt b("2");
				cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
        test(!(a < b));
				cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
        test(b < a);
			}
			
			{
				BigInt a("5", true);
				BigInt b("2");
				cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
        test(a < b);
				cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
        test(!(b < a));
			}

			{
				BigInt a("5");
				BigInt b("2", true);
				cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
        test(!(a < b));
				cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
        test(b < a);
			}

			{
				BigInt a("5", true);
				BigInt b("2", true);
				cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
        test(a < b);
				cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
        test(!(b < a));
			}

			{
				BigInt a("0");
				BigInt b("0", true);
				cout << a.getAccumatorWithSign() << " < " << b.getAccumatorWithSign() << " : " << (a < b) << endl;
        test(!(a < b));
				cout << b.getAccumatorWithSign() << " < " << a.getAccumatorWithSign() << " : " << (b < a) << endl;
        test(!(a < b));
			}

		}

		list<BigInt> numbersList;
		numbersList.push_back(BigInt("1"));
		numbersList.push_back(BigInt("133"));
		numbersList.push_back(BigInt("0"));
		numbersList.push_back(BigInt("17", true));
		numbersList.push_back(BigInt("244"));
		numbersList.push_back(BigInt("137", true));
		numbersList.push_back(BigInt("99999998888888888888888"));
		numbersList.push_back(BigInt("1111111"));
		numbersList.push_back(BigInt("1", true));
		numbersList.push_back(BigInt("55"));

		cout << "\nДан список чисел: " << endl;
		for (auto num : numbersList)
			num.logNumber();

		cout << "\nПо возрастанию: " << endl;
		numbersList.sort([](BigInt& a, BigInt& b) {return a < b;});
		for (auto num : numbersList)
			num.logNumber();

		cout << "\nПо убыванию: " << endl;
		numbersList.sort([](BigInt& a, BigInt& b) {return a > b;});
		for (auto num : numbersList)
			num.logNumber();

    cout << "Провалено тестов: ";
    if (testsFailed > 0)
      cout << "\033[1;31m " << testsFailed << " \033[0m\n" << endl;
    else 
      cout << "\033[1;32m 0 \033[0m\n" << endl;

	} catch (std::invalid_argument e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (std::exception e) {
		cout << "Ошибка! " << e.what() << endl;
	} catch (...) {
		cout << "Неизвестная ошибка!" << endl;
	}

	return 0;
}