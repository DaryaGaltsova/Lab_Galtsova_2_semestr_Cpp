#include <iostream>
#include <clocale>
#include <limits>
#include <cmath>

using namespace std;

int sizeArr(); // ввод размера массива

int checkInput(); // проверка на корректность ввода эл. массива arrayXi

double* arrayXi(int SIZE); // ввод массива Xi

double* arrayPi(int SIZE); // ввод массива Pi

void calculationDispersion(int SIZE); // вычисление висперсии по формулам

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "** Данная програма вычисляет дисперсию случайной велечины Xi с вероятность появления Pi соответственно. **" << endl << endl;

    int SIZE = sizeArr();

    calculationDispersion(SIZE);

    system("pause");
    return 0;
}

int sizeArr()
{
    while (true)
    {
        cout << "** Введите количество элементов массива Xi и Pi: ";
        int SIZE;
        cin >> SIZE;

        if (cin.fail() || SIZE <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return SIZE;
        }
    }
}

int checkInputArr()
{
    while (true)
    {
        int number;
        cin >> number;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return number;
        }
    }

}

double* arrayXi(int SIZE)
{
    double* arrayXi;
    arrayXi = (double*)malloc(SIZE * sizeof(double));

    for (int i = 0; i < SIZE; i++)
    {
        cout << "** Введите " << i << "-й коэффициент массива Xi: ";
        arrayXi[i] = checkInputArr();
    }
    return arrayXi;
}

double* arrayPi(int SIZE)
{
    double* arrayPi;
    arrayPi = (double*)malloc(SIZE * sizeof(double));

    double sum = 0.0;

    for (int i = 0; i < SIZE; i++)
    {
        while (true)
        {
            cout << "** Введите вероятность " << i + 1 << "-го элемента Xi(Сумма элементов должна быть равна 1!): ";
            cin >> arrayPi[i];

            if (cin.fail() ||  1 < arrayPi[i] < 0 || (sum + arrayPi[i]) > 1)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "** ERROR! Некорректный ввод. Попробуйте снова: " << endl;
            }
            else
            {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        } 
        sum += arrayPi[i];
    }
    return arrayPi;
}

void calculationDispersion(int SIZE)
{
    double* Xi;
    double* Pi;
    double MDoubleXi = 0.0, doubleMXi = 0.0, dispersion = 0.0;

    Xi = (double*)malloc(SIZE * sizeof(double));
    Xi = arrayXi(SIZE);

    Pi = (double*)malloc(SIZE * sizeof(double));
    Pi = arrayPi(SIZE);

    for (int i = 0; i < SIZE; i++) doubleMXi += Xi[i] * Pi[i];
    doubleMXi *= doubleMXi;

    for (int i = 0; i < SIZE; i++) MDoubleXi += ((Xi[i] * Xi[i]) * Pi[i]);
    
    dispersion = MDoubleXi - doubleMXi;
    
    cout << "\n** Дисперсия случайной величины Xi = " << dispersion << endl;
}