/*
*	Klient TCP dla agenta decyzyjnego
*	wersja dla MS Windows, przepisana z wersji Linuxowej
*	kod zrodlowy
*	odtworzone 11 lipiec 2017
*	autor: Luk
*/

#include "Client.h"

using namespace std;

int __cdecl main(int argc, char **argv)
{
	int SUCCESS;
	WSAData WinSockData;
	WORD ReqVer = MAKEWORD(2,2);
	string URCHOICE;
	string STRMSG;
	char MSG[300];
	SOCKADDR_IN ADDRESS;
	SOCKET SCKT;
	SUCCESS = WSAStartup(ReqVer, &WinSockData);
	SCKT = socket(AF_INET, SOCK_STREAM, NULL);
	ADDRESS.sin_family = AF_INET;

	//do modyfikacji
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_port = htons(323);
	//do modyfikacji

	cout << "\n zaakceptowac polaczenie ? (t/n) ?\n";
	cin >> URCHOICE;
	URCHOICE[0] = tolower(URCHOICE[0]);

	if (SUCCESS)
	{
		if (URCHOICE == "n")
		{
			cout << "\n zakonczenie programu \n";
		}
		else if (URCHOICE == "t")
		{
			connect(SCKT, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
			SUCCESS = recv(SCKT, MSG, sizeof(MSG), NULL);
			STRMSG = MSG;			// i teraz wiadomosc jest juz w stringu
			cout << "\n Dane od serwera: \n" << STRMSG << endl;
		}
		else
		{
			cout << "\n niepoprawny wybor! \n";
		}
		exit(1);
	}
	else
	{
		cout << "\n Nie mozna zainicjowac stosu TCP/IP" << endl;
		return SUCCESS;
	}
}