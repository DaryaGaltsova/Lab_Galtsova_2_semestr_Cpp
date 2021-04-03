#include <iostream>
#include <clocale>

using namespace std;

int checkInput(); // Проверка на вводчисла n

void calculatingFactorial(); // Вычисление факториала

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "** Данная программа вычисляет двойной факториал числа n **" << endl;

	calculatingFactorial();

	system("pause");
	return 0;
}

int checkInput()
{
	cout << "\n** Введите любое целочисленное число n: ";
	while (true)
	{
		int num;
		cin >> num;

		if (cin.fail() || num <= 0)
		{
			cout << "** Ошибка! Некорректный ввод, попробуйте ещё раз: ";
			cin.clear();
			cin.ignore(66666, '\n');
		}
		else
		{
			cin.ignore(66666, '\n');
			return num;
		}
	}
}

void calculatingFactorial()
{
	int n = checkInput();

	long double result = n;

	for (double iterat = (n - 2); iterat > 0; iterat -= 2) result *= iterat;

	cout << "\n** Двойной факториал числа " << n << "!! = " << result << endl;
}