#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

const double PI{ 3.14159 };

int checkInp_int();
double checkInp_double();

template <class T>
double EXP(T z);

long long int factorial(int x);

class Complex {
public:
    void inputSelection();
    void printComplexNum();
    Complex expComplexNum();

private:
    void transitForm();
    double x, y;
    double modZ, phi;
    bool algForm = false;
    bool trigForm = false;
};

void Complex::inputSelection()
{
    char userChoice{};

    do {
        cout << "\n>> Выбирите форму представления комплексного числа z:"
            << "\n>> а - алгебраическая   t - тригонометрическая"
            << "\n>> Ваш выбор: ";
        cin >> setw(1) >> userChoice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (userChoice != 'a' && userChoice != 't')
            cout << "\n>> Вы ввели недопустимое значение. Повторите попытку снова.";

    } while (userChoice != 'a' && userChoice != 't');

    if (userChoice == 'a') {
        cout << "\n>> Алгебраическая форма: х + у * i" << endl
            << ">> Введите х: ";
        x = checkInp_double();

        cout << ">> Введите y: ";
        y = checkInp_double();
        cout << endl;

        algForm = true;
        transitForm();
    }

    if (userChoice == 't') {
        cout << "\n>> Триганометрическая форма комплексного числа: |z| * (cos(phi) + i * sin(phi)" << endl
            << ">> Введите |z|: ";
        modZ = checkInp_double();

        cout << ">> Введите угол phi: ";
        phi = checkInp_double();

        trigForm = true;
        transitForm();
    }
}

void Complex::printComplexNum()
{
    cout << ">> Алгебраической формы: " << x << " + " << y << " * i" << endl;
    cout << ">> Триганометрической формы: " << modZ << " * (cos(" << phi << ") + i * sin(" << phi << ")" << endl;
}

Complex Complex::expComplexNum()
{
    Complex res;
    res.x = EXP(x);
    res.y = EXP(y);
    res.algForm = true;
    res.transitForm();
    return res;
}

void Complex::transitForm()
{
    if (algForm) {
        modZ = sqrt(pow(x, 2) + pow(y, 2));
        double cos = acos(x / modZ);
        double sin = asin(y / modZ);
        double stockPhi = abs(sin);

        if (sin < 0 && cos < 0)
            phi = -PI + stockPhi;
        else if (cos < 0 && sin > 0)
            phi = PI - stockPhi;
        else if (sin < 0 && cos>0)
            phi = -stockPhi;
        else if (cos > 0 && sin > 0)
            phi = stockPhi;
        else
            phi = stockPhi;
    }

    else if (trigForm) {
        x = cos(phi) * modZ;
        y = sin(phi) * modZ;
    }
}


int main()
{
    setlocale(LC_ALL, "RU");

    cout << ">> Данная программа вычисляет значение от действительного и комплексного аргумента по уже заданной формуле. <<";

    Complex num;
    num.inputSelection();

    cout << ">> Ваше число в комплексном виде: " << endl;
    num.printComplexNum();

    Complex expNumber;
    expNumber = num.expComplexNum();

    cout << "\n>> Экспонента от комплексного числа: " << endl;
    expNumber.printComplexNum();
    return 0;
}

template <class T>
double EXP(T z)
{
    z = -z;
    double var, result = 0;
    for (int i = 0; i < 20; i++) {
        long long int fact = factorial(i);
        var = pow(-1, i) * pow(z, i) / fact;
        result += var;
    }
    return result;
}

long long int factorial(int x)
{
    if (x < 0)
        return 0;
    if (x == 0 || x == 1)
        return 1;
    if (x > 1)
        return x * factorial(x - 1);
}

double checkInp_double()
{
    while (true) {
        double num;
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n>> Введено недопустимое значение.\n>> Повторите попытку: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}

int checkInp_int()
{
    while (true) {
        int num;
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n>> Введено недопустимое значение.\n>> Повторите попытку: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return num;
        }
    }
}