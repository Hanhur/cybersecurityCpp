#include <iostream>
#include <signal.h>
#include "TCPClient.h"
TCPClient tcp; // наш основной класс

// обработчик выхода из программы

void sig_exit(int s)
{
    tcp.exit(); // вызов метода exit()
    exit(0);
}

int main(int argc, char *argv[])
{
    // Установка обработчика выхода из программы
    signal(SIGINT, sig_exit);

    tcp.setup("127.0.0.l", 11999);

    while (1)
    {
        // Инициализация генератора случайных чисел
        srand(time(NULL));

        // Отправляем строку на сервер
        tcp.Send(to string(rand() % 25000));

        // Получаем ответ сервера
        string rec = tcp.receive();

        if (rec != "")
        {
            // Выводим ответ сервера
            cout << "Server Response:" << rec << endl;
        }
        sleep(l); // Засыпаем на 1 секунду
    }
    return 0;
}

// Заголовочный файл TCPClient.h
#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netdb.h>
#include <vector>

using namespace std;

class TCPClient
{
    private:
        int sock;
        std::string address;
        int port;
        struct sockaddr in server;

    public : TCPClient();
        bool setup(string address, int port);
        bool Send(string data);
        string receive(int size = 4096);
        string read();
        void exit();
};
#endif

if(sock == -1)
{
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1)
    {
        cout << "Could not create socket" << endl;
    }
}

TCPClient::TCPClient()
{
    sock = -1;
    port = 0;
    address = "";
}

struct sockaddr in server;

server.sin_addr.s_addr = inet_addr(address.c str());
server.sin_family = AF_INET;
server.sin_port = htons(port);

if(connect(sock, (struct sockaddr *} &server , sizeof(server)) < 0)
{
    perror("connect failed. Error");
    return false;
}
return true;

if(send(sock , data.c_str() , strlen( data.c_str() ) , 0) < 0)
{
    cout << "Send failed : " << data << endl;
    return false;
}

/*
Метод read() позволяет получить ответ от сервера. Для чтения данных мы
будем использовать метод recv. Читать данные будем в массив buffer. Чтение будет происходить посимвольно, а как прочитаем последний байт (когда
встретим символ '\n'), мы вернем полученную строку reply:
*/
char buffer[l] = {}; // буфер
string reply; // результат

while (buffer [0] != '\n')
{
    if( recv(sock , buffer , sizeof(buffer), 0) < 0)
    {
        cout << "receive failed!" << endl;
        return nullptr;
    }
    // добавляем каждый прочитанный символ к reply
    reply += buffer[0];
}

return reply; // возвращаем результат
/*
Кроме метода read() у нас есть еще метод receive(), который делает все то
же самое, но немного иначе. Здесь у нас будет не посимвольное чтение, а
чтение строки определенного размера size:
*/
string TCPClient::receive(int size)
{
    char buffer[size];
    memset(&buffer[0], 0, sizeof(buffer));

    string reply;

    if( recv(sock , buffer , size, 0) < 0)
    {
        cout << "receive failed!" << endl;
        return nullptr;
    }
    buffer[size - 1] = '\0';
    reply = buffer;
    return reply;
}