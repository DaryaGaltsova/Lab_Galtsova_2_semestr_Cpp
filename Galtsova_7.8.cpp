#include <iostream>
using namespace std;

class DoubleFact
{
public:
    void calculatingFactorial(long int n)
    {
        long double result = n;

        for (double iterat = (n - 2); iterat > 0; iterat -= 2) result *= iterat;

        cout << "\n** Двойной факториал числа " << n << "!! = " << result << endl;
    }
};


long int checkInput();

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "** Данная программа вычисляет двойной факториал числа n **" << endl;

    long int n = checkInput();

    DoubleFact add;
    add.calculatingFactorial(n);

    return 0;
}

long int checkInput()
{
    cout << "\n** Введите любое целочисленное число n: ";
    while (true)
    {
        long int num;
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