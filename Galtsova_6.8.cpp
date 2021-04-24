#include <iostream>
#include <string>

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
    FirstType* nextCell;
    int cellsAmount;

    Cell();
    ~Cell();
    void  pushBack();
    void  printInfo();
    void  clear();
};

int main()
{
    Cell* list = new Cell();
    list->pushBack();
    list->pushBack();
    list->printInfo();

    return 0;
}

Cell::Cell() {
    head = nullptr;
    nextCell = nullptr;
    cellsAmount = 0;
}

Cell::~Cell() {
    clear();
}

void Cell::pushBack()
{
    if (head == nullptr) {
        head = new FirstType();
        cin >> head->data;

        head->ptrLeft = new SecondType;
        cin >> head->ptrLeft->data;

        head->ptrRight = new SecondType;
        cin >> head->ptrRight->data;

        head->ptrLeft->ptrNext = new SecondType;
        cin >> head->ptrLeft->ptrNext->data;

        head->ptrRight->ptrNext = new SecondType;
        cin >> head->ptrRight->ptrNext->data;

        head->ptrLeft->ptrNext->ptrNextNode = head->ptrRight->ptrNext->ptrNextNode = nullptr;

        ++cellsAmount;

    }
    else {
        FirstType* current = head;

        while (current != nullptr) {
            current = current->ptrLeft->ptrNext->ptrNextNode;
        }
        current = new FirstType();
        cin >> current->data;

        current->ptrLeft = new SecondType;
        cin >> current->ptrLeft->data;

        current->ptrRight = new SecondType;
        cin >> current->ptrRight->data;

        current->ptrLeft->ptrNext = new SecondType;
        cin >> current->ptrLeft->ptrNext->data;

        current->ptrRight->ptrNext = new SecondType;
        cin >> current->ptrRight->ptrNext->data;

        current->ptrLeft->ptrNext->ptrNextNode = current->ptrRight->ptrNext->ptrNextNode = nullptr;
        ++cellsAmount;
    }
}

void Cell::printInfo()
{
    FirstType* current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        cout << current->ptrLeft->data << endl;
        cout << current->ptrRight->data << endl;
        cout << current->ptrLeft->ptrNext->data << endl;
        cout << current->ptrRight->ptrNext->data << endl;
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