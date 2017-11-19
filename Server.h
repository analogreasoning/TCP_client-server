/*
*	Serwer TCP dla agenta decyzyjnego
*	wersja dla MS Windows, przepisana z wersji Linuxowej
*	plik naglowkowy
*	odtworzone 11 lipiec 2017
*	autor: Luk
*/

#pragma once
#pragma comment(lib, "Ws2_32.lib")

/*
*****************************************************
*	alternatywnie uwzglednic w linkerze Ws2_32.lib	*
*****************************************************
*/

#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>

#ifndef SCK_VERSION2
#define SCK_VERSION2	0x0202
#endif // !SCK_VERSION2
