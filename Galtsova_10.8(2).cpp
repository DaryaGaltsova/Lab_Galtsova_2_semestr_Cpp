#include <iostream>
#include <cmath>
#include <ctime>
#include <limits>

using namespace std;

int checkInput();

class overload
{
public:
    int n;
    double* a, x, * b, result, result_2, Qx_2 = 0, Qx = 0;
    bool some;

    void filling()
    {
        cout << "** Введите n: ";
        n = checkInput();
        a = new double[n + 1];
        b = new double[n + 1];

        for (int i = 0; i <= n; i++)
        {
            a[i] = rand() % 10;
            b[i] = rand() % 10;
        }
    }

    void randArray()
    {
        for (int i = 0; i <= n; i++)
            cout << "\n** a[" << i << "]: " << a[i];
        cout << "\n-----------" << endl;
    }

    void randArray_2()
    {
        for (int i = 0; i <= n; i++)
            cout << "** b[" << i << "]: " << b[i] << endl;
    }

    void countQ1(double x) {
        for (int i = 0; i <= n; i++)
            Qx += (a[i]) / pow(x, i);
        cout << "** Q1(x) = " << Qx << endl;
    }

    void countQ2(double x)
    {
        for (int i = 0; i <= n; i++)
            Qx_2 += (b[i]) / pow(x, i);
        cout << "** Q2(x) = " << Qx_2 << endl << endl;
    }

    overload operator+ (bool isTrue)
    {
        if (isTrue == true)
            result = Qx + Qx_2;
        cout << "** Результат сложения Q1(x) + Q2(x): " << result << endl;
        return *this;
    }

    overload operator- (bool isTrue)
    {
        if (isTrue == true)
            result = Qx - Qx_2;
        cout << "** Результат вычитания Q1(x) - Q2(x): " << result << endl;
        return *this;
    }

    overload operator* (int num)
    {
        if (num != 0) {
            result = Qx * num;
            result_2 = Qx_2 * num;
        }
        cout << "** Результат умножения Q1(x) на число: " << result << endl;
        cout << "** Результат умножения Q2(x) на число: " << result_2 << endl;
        return *this;
    }

    overload operator/ (int num)
    {
        if (num != 0) {
            result = Qx / num;
            result_2 = Qx_2 / num;
        }
        cout << "** Результат деления Q1(x) на число: " << result << endl;
        cout << "** Результат деления Q2(x) на число: " << result_2 << endl;
        return *this;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "** Данная программа реализует следующее выражение: Qn(x) = a0 + a1/x + ... + an/xn. **\n"
        << "** А так же складывает/вычитает такие выражения и умножает/делит на число.          **" << endl;

    srand(time(NULL));

    overload obj;
    obj.filling();
    obj.randArray();
    obj.randArray_2();

    cout << "\n** Введите x: ";
    double x = checkInput();
    obj.countQ1(x);
    obj.countQ2(x);

    cout << "** Введите число на которое нужно умножениить/разделить Q1(x) и Q2(x): ";
    int  value = checkInput();

    obj + true;
    obj - true;
    obj* value;
    obj / value;
}

int checkInput()
{
    while (true)
    {
        int info;
        cin >> info;

        if (cin.fail() || info < 1)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "** Введено некорректное значение. Повторите попытку: ";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return info;
        }
    }
}