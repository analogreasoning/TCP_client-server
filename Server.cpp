/*
*	Serwer TCP dla agenta decyzyjnego
*	wersja dla MS Windows, przepisana na podstawie oryginalnej wersji Linuxowej
*	kod zrodlowy
*	odtworzone 11 lipiec 2017
*	autor: Luk
*/

#include "Server.h"

using namespace std;

int __cdecl main(int argc, char **argv)
{
	int SUCCESS;
	WSAData WinSockData;
	WORD REQVER;
	REQVER = MAKEWORD(2, 2);
	SOCKADDR_IN ADDRESS;
	int AddressSize = sizeof(ADDRESS);
	SOCKET LISTEN;
	SOCKET CONNECTION;
	SUCCESS = WSAStartup(REQVER, &WinSockData);
	CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
	ADDRESS.sin_family = AF_INET;

	//wrocic tutaj
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_port = htons(323);
	//wrocic tutaj

	LISTEN = socket(AF_INET, SOCK_STREAM, NULL);

	//wywolujemy pare bind-listen
	bind(LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
	listen(LISTEN, SOMAXCONN);							//max dopuszczalny limit polaczen

	if (SUCCESS)
	{
		for (;;)
		{
			cout << "\n tekst wyswietlajacy sie podczas oczekiwania na polaczenie \n";

			if (CONNECTION = accept(LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize))
			{
				//wrocic tutaj
				cout << "\n ustanowiono polaczenie \n";
				SUCCESS = send(CONNECTION, "tutaj jest bufor z wysylana wiadomoscia ...", 46, NULL);
				//wrocic tutaj
			}
		}
		return 0;
	}
	else
	{
		cout << "\n Nie mozna zainicjowac stosu TCP/IP \n";
		return SUCCESS;
	}
}
