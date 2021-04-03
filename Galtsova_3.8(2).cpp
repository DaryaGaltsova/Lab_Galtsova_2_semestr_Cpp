#include <iostream>
#include <clocale>
#include <limits>
#include <ctime> 

using namespace std;

int sizeArr(); // ввод размера массива

int checkInput(); // проверка на корректность ввода эл. массива arrayXi

double* arrayXi(int SIZE); // ввод массива Xi

double* arrayPi(int SIZE); // рандомное заполнение массива с вероятностями Pi

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

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++)
    {
        arrayPi[i] = rand() % 100 / 100. + .01;
        sum += arrayPi[i];
    }

    for (int i = 0; i < SIZE; i++) arrayPi[i] /= sum;

    sum = 0;
    cout << "** Вероятность кождого элемента массива Xi соответственно: " << endl;
    for (int i = 0; i < SIZE; i++) cout << arrayPi[i] << ' ', sum += arrayPi[i];
    cout << "\n** Сумма данных вероятностей = " << sum << endl;

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