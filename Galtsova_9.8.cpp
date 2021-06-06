#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct FirstType;
struct SecondType;

struct FirstType {
    SecondType* ptrLeft;
    SecondType* ptrRight;
    string data;
};

struct SecondType {
    SecondType* ptrNext;
    FirstType* ptrNextNode;
    string data;
};

struct Cell {
    FirstType* head;
    FirstType* current;
    int cellsAmount;

    Cell();
    ~Cell();
    void  pushBack();
    void  printInfo();
    void  clear();
};

void CrEntPrint(int quantity);

int checkInput();

int main()
{
    setlocale(LC_ALL, "RU");

    cout << ">> Данная программа создаёт ячейки динамической структуры из 5-и элементов. <<"
        << "\n>> Введите кол-во ячеек(максимум 30): ";
    int quantity = checkInput();

    CrEntPrint(quantity);

    return 0;
}

void CrEntPrint(int quantity)
{
    Cell* list = new Cell();

    for (int i = 0; i < quantity; i++) {
        cout << "\n>> Введите 5 элементов " << i + 1 << "-й ячейки: ";
        list->pushBack();
    }

    list->printInfo();
}

Cell::Cell() {
    head = nullptr;
    cellsAmount = 0;
}

Cell::~Cell() {
    clear();
}

void Cell::pushBack() {
    if (head == nullptr) {
        head = new FirstType();
        cout << "\n>> Первый элемент: ";
        cin >> head->data;

        head->ptrLeft = new SecondType;
        cout << ">> Второй элемент: ";
        cin >> head->ptrLeft->data;

        head->ptrRight = new SecondType;
        cout << ">> Третий элемент: ";
        cin >> head->ptrRight->data;

        head->ptrLeft->ptrNext = new SecondType;
        cout << ">> Четвертый элемент: ";
        cin >> head->ptrLeft->ptrNext->data;

        head->ptrRight->ptrNext = new SecondType;
        cout << ">> Пятый элемент: ";
        cin >> head->ptrRight->ptrNext->data;

        head->ptrLeft->ptrNext->ptrNextNode = new FirstType;
        head->ptrRight->ptrNext->ptrNextNode = head->ptrLeft->ptrNext->ptrNextNode = nullptr;
        ++cellsAmount;
    }

    else {
        if (cellsAmount == 1)
            current = head;

        if (current->ptrLeft->ptrNext->ptrNextNode == nullptr)
            current->ptrLeft->ptrNext->ptrNextNode = new FirstType();


        current = current->ptrLeft->ptrNext->ptrNextNode;

        cout << "\n>> Первый элемент: ";
        cin >> current->data;

        current->ptrLeft = new SecondType;
        cout << ">> Второй элемент: ";
        cin >> current->ptrLeft->data;

        current->ptrRight = new SecondType;
        cout << ">> Третий элемент: ";
        cin >> current->ptrRight->data;

        current->ptrLeft->ptrNext = new SecondType;
        cout << ">> Четвертый элемент: ";
        cin >> current->ptrLeft->ptrNext->data;

        current->ptrRight->ptrNext = new SecondType;
        cout << ">> Пятый элемент: ";
        cin >> current->ptrRight->ptrNext->data;

        current->ptrLeft->ptrNext->ptrNextNode = new FirstType;
        current->ptrRight->ptrNext->ptrNextNode = current->ptrLeft->ptrNext->ptrNextNode = nullptr;
        ++cellsAmount;
    }
}

void Cell::printInfo()
{
    FirstType* current = head;
    while (current != nullptr) {
        cout << "           " << current->data << endl;
        cout << "       " << current->ptrLeft->data << "        " << current->ptrRight->data << endl;
        cout << "       " << current->ptrLeft->ptrNext->data << "        " << current->ptrRight->ptrNext->data << endl;
        cout << endl;
        current = current->ptrLeft->ptrNext->ptrNextNode;
    }
}

void Cell::clear()
{
    while (cellsAmount > 0) {
        FirstType* current = head;
        delete current->ptrLeft->ptrNext;
        delete current->ptrLeft;
        delete current->ptrRight->ptrNext;
        delete current->ptrRight;
        delete current;
        --cellsAmount;
        head = head->ptrLeft->ptrNext->ptrNextNode;
    }
}

int checkInput()
{
    while (true) {
        int num;
        cin >> num;

        if (cin.fail() || num <= 0 || num > 30) {
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