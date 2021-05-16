#include <iostream>
#include <cmath>
using namespace std;
int scanf_number();
class overload
{
public:
    int n;
    double* a, res, result = 0, x;
    bool some;
    void filling() {
        cout << "Введите n: ";
        n = scanf_number();
        a = new double[n + 1];
        for (int i = 0; i <= n; i++)
            a[i] = rand() % 10;
    }
    void show_array() {
        for (int i = 0; i <= n; i++)
            cout << "a[" << i << "]: " << a[i] << endl;
    }
    void count(double x) {
        for (int i = 0; i <= n; i++)
            result += (a[i]) / pow(x, i);
        cout << "Q(x) = " << result << endl;
        cout << endl;
        some = true;
    }
    overload operator+ (int value) {
        if (some == true)
            res = result + value;
        cout << "Результат сложения: " << res << endl;
        return *this;
    }
    overload operator- (int value) {
        if (some == true)
            res = result - value;
        cout << "Результат вычитания: " << res << endl;
        return *this;
    }
    overload operator* (int value) {
        if (some == true)
            res = result * value;
        cout << "Результат умножения: " << res << endl;
        return *this;
    }
    overload operator/ (int value) {
        if (some == true)
            res = result / value;
        cout << "Результат деления: " << res << endl;
        return *this;
    }
    void free() {
        delete[] a;
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    overload obj;
    obj.filling();
    obj.show_array();
    cout << endl;
    cout << "Введите x: ";
    double x = scanf_number();
    obj.count(x);
    cout << "Введите число с которым будут проведенны операции: ";
    int  value = scanf_number();
    obj + value;
    obj - value;
    obj* value;
    obj / value;
    obj.free();
}
int scanf_number() {
    while (true) {
        int info;
        cin >> info;
        if (cin.fail() || info < 1) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Некорректный ввод, введите положительное число" << endl;
        }
        else  return info;
    }
}