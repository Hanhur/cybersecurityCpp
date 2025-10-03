
// Идентификация стеков

#include <iostream>
using namespace std;

const int SIZE = 26;

class stack
{
    char stck[SIZE]; // Элементы стека
    int tos;         // Вершина стека
    int stackID;     // ID стека
    public:
        stack(int id);      // Конструктор класса
        ~stack();           // Деструктор
        void init();        // Инициализация стека
        void push(char ch); // Добавить символ в стек
        char pop();         // Вытолкнуть символ из стека
};

stack::stack(int id)
{
    stackID = id; // Устанавливаем ID стека
    cout << "Инициализация стека" << stackID << endl;
    tos = 0;
}

stack::~stack()
{
    cout << "Деструктор стека#" << stackID << "выполняется ... \n";
}

void stack::init()
{
    tos = 0;
}

void stack::push(char ch)
{
    if (tos == SIZE)
    {
        cout << "Стек полон!" << endl;
        return;
    }

    stck[tos] = ch;
    tos++;
}

char stack::pop()
{
    if (tos == 0)
    {
        cout << "Стек пуст" << endl;
        return 0;
    }

    tos--;
    return stck[tos];
}

int main()
{
    // Создаем объекты и устанавливаем их ID
    stack s1(1), s2(2);
    int i;

    // Добавляем элементы в стеки
    s1.push('a');
    s2.push('b');
    s1.push('c');
    s2.push('d');
    s1.push('e');
    s2.push('f');

    // Выводим содержимое стеков
    for (i = 0; i < 3; i++)
        cout << s1.pop() << " ";
    cout << endl;
    for (i = 0; i < 3; i++)
        cout << s2.pop() << " ";
    cout << endl;
}