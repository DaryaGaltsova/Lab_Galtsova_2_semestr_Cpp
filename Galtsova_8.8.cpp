#include <iostream>
#include <cmath>
#include <limits>

#define PI 3.14

using namespace std;

class ComlexNum
{
public:
    double Re;
    double Im;

    void AlgebraicForm()
    {
        cout << "\n** Комплексное число в Алгебраической форме: "
            << "\n** z = " << Re << " + i" << Im << endl;
    }

    void ConvertAlgebraicToTrigonometricForm()
    {
        double phi = atan(Im) / (Re) * 180.0 / PI;
        double p = sqrt(Re * Re + Im * Im);

        cout << "** Комплексное число в Тригонометрической форме: "
            << "\n** z = " << p << "(cos(" << phi << "°) + i * sin(" << phi << "°))" << endl;
    }
};

int checkInput(); // Проверка на корректность пользовательского ввода

void ECP(); // Ввод. Подсчет. Вывод в консоль.

int main()
{
    setlocale(LC_ALL, "RU");

    cout << "** Данная программа преобразует два любых числа в комплексные числа двух видов: **"
        << "\n** Алгебраической и Тригонометрической формы.                                   **" << endl;

    ECP();

    return 0;
}

int checkInput()
{
    while (true)
    {
        int num;
        cin >> num;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "** Введено некорректное значение. Повторите попытку: ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}

void ECP()
{
    ComlexNum a;

    cout << "** Введите число X: ";
    a.Re = checkInput();

    cout << "** Введите число Y: ";
    a.Im = checkInput();

    a.AlgebraicForm();
    a.ConvertAlgebraicToTrigonometricForm();
}