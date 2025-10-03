/*
    Представим, что у нас есть какой-то класс coord:
    coord а, Ь, с;

    Что произойдет, когда мы попытаемся сложить два объекта этого класса:
    с = а + Ь;

    Наши функции operator+ и operator- возвращают объект типа coord. Внутри
    каждый из операторов производит вычисление координат: к текущим координатам х иу добавляются координаты х и у второго объекта (оЫ) и все это
    помещается в объект temp, который и возвращается оператором.
    
    Затем возвращенные объекты присваиваются соответствующим переменным типа coord, в нашем случае это переменные с и d.
*/

// Пример перезагрузки операторов + и -

#include <iostream>
using namespace std;

class coord {
    int x, y;
    public:
        coord()
        {
            x = 0;
            y = 0;
        }
        coord(int i, int j)
        {
            x = i;
            y = j;
        }
        void get_xy()
        {
            cout << "X: " << x << " Y: " << y << endl;
        }
        coord operator+(coord ob2);
        coord operator-(coord ob2);
};

coord coord::operator+(coord ob2) {
    coord temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}

coord coord::operator-(coord ob2) {
    coord temp;
    temp.x = x - ob2.x;
    temp.y = y - ob2.y;
    return temp;
}

int main()
{
    coord a(100, 200), b(50, 70), c, d;

    c = a + b;
    d = a - b;
    c.get_xy();
    d.get_xy();

    return 0;
}

// 65 str