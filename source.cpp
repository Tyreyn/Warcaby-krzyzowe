//POP_2017_12_18_projekt_1_Lewalski_Michal_EiT_4_171753 Microsoft Visual Studio
#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<string>
#define LICZBA_PIONKOW 16
#define LICZBA_POL 81
using namespace std;
typedef struct pole {                   //definiuje wyglad mapy
	bool aktywny;

	bool temp_plansza[LICZBA_POL] =
	{   0,0,1,0,1,0,1,0,0,
		0,0,0,1,1,1,0,0,0,
		1,0,1,1,1,1,1,0,1,
		0,1,1,1,1,1,1,1,0,
		1,1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,0,
		1,0,1,1,1,1,1,0,1,
		0,0,0,1,1,1,0,0,0,
		0,0,1,0,1,0,1,0,0, };

	bool temp_pionkow[LICZBA_POL] =
	{   0,0,1,0,1,0,1,0,0,
		0,0,0,1,1,1,0,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,0,1,1,1,0,0,0,
		0,0,1,0,1,0,1,0,0, };
	bool temp_pionkowX[LICZBA_POL] =
	{   0,0,1,0,1,0,1,0,0,
		0,0,0,1,1,1,0,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0, };
	bool temp_pionkowO[LICZBA_POL] =
	{ 0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,0,1,1,1,0,0,0,
		0,0,1,0,1,0,1,0,0, };


};


typedef struct ruch {               //definiuje gdzie poszczegolny pionek moze sie poruszac
	bool ruch_poziomy[LICZBA_POL] =
	{ 0,0,1,0,1,0,1,0,0,
		0,0,0,1,1,1,0,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,1,1,1,1,1,0,0,
		1,1,1,1,1,1,1,1,1,
		0,0,1,1,1,1,1,0,0,
		0,0,1,1,1,1,1,0,0,
		0,0,0,1,1,1,0,0,0,
		0,0,1,0,1,0,1,0,0,
	};

	bool ruch_pionowy[LICZBA_POL] =
	{ 0,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,0,
		1,0,1,1,1,1,1,0,1,
		0,1,1,1,1,1,1,1,0,
		1,1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,0,
		1,0,1,1,1,1,1,0,1,
		0,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,0,
	};

	bool ruch_ukosny_lewo[LICZBA_POL] = {
		0,0,0,0,0,0,1,0,0,
		0,0,0,0,0,1,0,0,0,
		0,0,0,0,1,0,1,0,1,
		0,0,0,1,0,1,0,1,0,
		0,0,1,0,1,0,1,0,1,
		0,1,0,1,0,1,0,0,0,
		1,0,1,0,1,0,0,0,0,
		0,0,0,1,0,0,0,0,0,
		0,0,1,0,0,0,0,0,0,
	};
	bool ruch_ukosny_prawo[LICZBA_POL] = {
		0,0,1,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,
		1,0,1,0,1,0,0,0,0,
		0,1,0,1,0,1,0,0,0,
		0,0,1,0,1,0,1,0,0,
		0,0,0,1,0,1,0,1,0,
		0,0,0,0,1,0,1,0,0,
		0,0,0,0,0,1,0,0,0,
		0,0,0,0,0,0,1,0,0,
	};
	bool temp_plansza[LICZBA_POL] =
	{ 0,0,1,0,1,0,1,0,0,
		0,0,0,1,1,1,0,0,0,
		1,0,1,1,1,1,1,0,1,
		0,1,1,1,1,1,1,1,0,
		1,1,1,1,1,1,1,1,1,
		0,1,1,1,1,1,1,1,0,
		1,0,1,1,1,1,1,0,1,
		0,0,0,1,1,1,0,0,0,
		0,0,1,0,1,0,1,0,0, };
};
void wypisz(pole &plansza, int wybor) {
	int a = 0;
	for (int i = 0; i <= 9; i++) {
		cout << i << setw(3);
	}
	for (int i = 0; i < LICZBA_POL; i++) {
		if (i == 0)cout << "\nI";
		if (i == 9)cout << "H";
		if (i == 18)cout << "G";
		if (i == 27)cout << "F";
		if (i == 36)cout << "E";
		if (i == 45)cout << "D";
		if (i == 54)cout << "C";
		if (i == 63)cout << "B";
		if (i == 72)cout << "A";
		if (plansza.temp_plansza[i] == 1) {
			if (plansza.temp_pionkowO[i] == 1) {
				if (i == wybor)cout << setw(3) << "*O";
				else cout << setw(3) << "O";
				a++;
			}
			else if (plansza.temp_pionkowX[i] == 1) {
				if (i == wybor)cout << setw(3) << "*X";
				else cout << setw(3) << "X";
				a++;
			}
			else if (plansza.temp_pionkowO[i] == 0 && plansza.temp_pionkowX[i] == 0) {
				cout << setw(3) << ".";
				a++;
			}
		}
		else {
			cout << setw(3) << " ";
			a++;
		}
		if (a % 9 == 0)cout << endl;
	}
}
void wczytywanie(pole &plansza) {

	system("cls");
	fstream plik;
	char wiersz[10000];
	plik.open("historia.txt", ios::in);
	while (plik.getline(wiersz, 10000))
	{
		cout << wiersz << endl;
	}
	system("pause");
	system("cls");
	wypisz(plansza, -1);
}
int wybierz(int gracz,pole &plansza) {                  //wczytywanie liczby ze sprawdzeniem bledu or konwersja jego na system liczbowy
	fstream plik;
	int a = 0, b = 0;
	char i[255];
	do {
		memset(i, '\0', 255);
		cout << "wybierz pionek " << endl;
		cin >> i;

	} while (i[2] != '\0');


	if (i[0] == 'a' || i[0] == 'A' || i[1] == 'a' || i[1] == 'A') a = 9;
	if (i[0] == 'b' || i[0] == 'B' || i[1] == 'b' || i[1] == 'B') a = 8;
	if (i[0] == 'c' || i[0] == 'C' || i[1] == 'c' || i[1] == 'C') a = 7;
	if (i[0] == 'd' || i[0] == 'D' || i[1] == 'd' || i[1] == 'D') a = 6;
	if (i[0] == 'e' || i[0] == 'E' || i[1] == 'e' || i[1] == 'E') a = 5;
	if (i[0] == 'f' || i[0] == 'F' || i[1] == 'f' || i[1] == 'F') a = 4;
	if (i[0] == 'g' || i[0] == 'G' || i[1] == 'g' || i[1] == 'G') a = 3;
	if (i[0] == 'h' || i[0] == 'H' || i[1] == 'h' || i[1] == 'H') a = 2;
	if (i[0] == 'i' || i[0] == 'I' || i[1] == 'i' || i[1] == 'I') a = 1;
	if (i[1] == '1' || i[0] == '1') b = 1;
	if (i[1] == '2' || i[0] == '2') b = 2;
	if (i[1] == '3' || i[0] == '3') b = 3;
	if (i[1] == '4' || i[0] == '4') b = 4;
	if (i[1] == '5' || i[0] == '5') b = 5;
	if (i[1] == '6' || i[0] == '6') b = 6;
	if (i[1] == '7' || i[0] == '7') b = 7;
	if (i[1] == '8' || i[0] == '8') b = 8;
	if (i[1] == '9' || i[0] == '9') b = 9;
	if (b == 0) a = 0;
	if (a == 0) b = 0;
	if (i[0] == 'P' || i[0] == 'p') wczytywanie(plansza);
	if ((((9 * (a - 1)) + b) - 1) > 0) {
		plik.open("historia.txt", ios::app);
		if (plik.good() == true)
		{
			plik << "\nGracz" << gracz << "   wybrany pionek   " << i << "   ";
			plik.close();
		}
		else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
		return(((9 * (a - 1)) + b) - 1);
	}
	else return wybierz(gracz,plansza);
}

void zapis_bicie(int wybierz) {
	fstream plik;
	plik.open("historia.txt", ios::app);
	if (plik.good() == true)
	{
		plik << "  zbity zostal   ";
		int a;
		char wynik[1];
		if (wybierz > 0 && wybierz < 8) {
			wynik[0] = 'I';
			a = 1;
		}
		if (wybierz > 9 && wybierz < 17) {
			wynik[0] = 'H';
			a = 2;
		}
		if (wybierz > 18 && wybierz < 26) {
			wynik[0] = 'G';
			a = 3;
		}
		if (wybierz > 27 && wybierz < 35) {
			wynik[0] = 'F';
			a = 4;
		}
		if (wybierz > 36 && wybierz < 44) {
			wynik[0] = 'E';
			a = 5;
		}
		if (wybierz > 45 && wybierz < 53) {
			wynik[0] = 'D';
			a = 6;
		}
		if (wybierz > 54 && wybierz < 62) {
			wynik[0] = 'C';
			a = 7;
		}
		if (wybierz > 63 && wybierz < 71) {
			wynik[0] = 'B';
			a = 8;
		}
		if (wybierz > 72 && wybierz < 80) {
			wynik[0] = 'A';
			a = 9;
		}
		int b = wybierz + 1 - (9 * (a - 1));
		plik << wynik[0] << b << "     ";

	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}

int zamiana(pole &plansza, int wybor, int ruch, int gracz) {


	if (gracz == 1) {

		plansza.temp_pionkowX[wybor + ruch] = 1;
		plansza.temp_pionkow[wybor] = 0;
		plansza.temp_pionkow[wybor + ruch] = 1;
		plansza.temp_pionkowX[wybor] = 0;
	}
	else {

		plansza.temp_pionkowO[wybor + ruch] = 1;
		plansza.temp_pionkowO[wybor] = 0;
		plansza.temp_pionkow[wybor + ruch] = 1;
		plansza.temp_pionkow[wybor] = 0;
	}
	system("cls");
	return 0;
}
int bicieX(pole &plansza, int wybor, int ruch) {
	plansza.temp_pionkowX[wybor] = 0;
	plansza.temp_pionkowX[wybor + (2 * ruch)] = 1;
	plansza.temp_pionkowO[wybor + ruch] = 0;
	plansza.temp_pionkow[wybor] = 0;
	plansza.temp_pionkow[wybor + (2 * ruch)] = 1;
	plansza.temp_pionkow[wybor + ruch] = 0;
	zapis_bicie(wybor + ruch);
	return 0;
}

int bicieO(pole &plansza, int wybor, int ruch) {
	plansza.temp_pionkowO[wybor] = 0;
	plansza.temp_pionkowO[wybor + (2 * ruch)] = 1;
	plansza.temp_pionkowX[wybor + ruch] = 0;
	plansza.temp_pionkow[wybor] = 0;
	plansza.temp_pionkow[wybor + (2 * ruch)] = 1;
	plansza.temp_pionkow[wybor + ruch] = 0;
	zapis_bicie(wybor + ruch);
	return 0;
}




bool czy_zamiana(pole &plansza, int wybor, int ruch, int gracz) {
	if (gracz == 1 && plansza.temp_pionkow[wybor] == 1 && plansza.temp_pionkow[wybor + ruch] == 0 && plansza.temp_pionkowO[wybor + ruch] == 0 && plansza.temp_plansza[wybor + ruch] == 1) return true;
	else if (gracz == 2 && plansza.temp_pionkow[wybor] == 1 && plansza.temp_pionkow[wybor + ruch] == 0 && plansza.temp_pionkowO[wybor + ruch] == 0 && plansza.temp_plansza[wybor + ruch] == 1) return true;
	else return false;
}
bool czy_zbicieX(pole &plansza, int wybierz, int ruch, int gracz, bool czy_sprawdzenie) {
	if (gracz == 1 && plansza.temp_plansza[wybierz + (2 * ruch)] == 1 && plansza.temp_plansza[wybierz + ruch] == 1 && plansza.temp_plansza[wybierz] == 1) {
		if (plansza.temp_pionkowO[wybierz + (2 * ruch)] == 0 && plansza.temp_pionkowX[wybierz + (2 * ruch)] == 0 && plansza.temp_pionkowO[wybierz + ruch] == 1 && plansza.temp_pionkowX[wybierz + ruch] == 0) {
			return true;
		}
		else {
			if (czy_sprawdzenie == false)
				cout << "nie mozna wykonac takiego bicia" << endl;
			return false;
		}
	}
}
bool czy_zbicieO(pole &plansza, int wybierz, int ruch, int gracz, bool czy_sprawdzenie) {
	if (gracz == 2 && plansza.temp_plansza[wybierz + (2 * ruch)] == 1 && plansza.temp_plansza[wybierz + ruch] == 1 && plansza.temp_plansza[wybierz] == 1) {
		if (plansza.temp_pionkowO[wybierz + (2 * ruch)] == 0 && plansza.temp_pionkowX[wybierz + (2 * ruch)] == 0 && plansza.temp_pionkowX[wybierz + ruch] == 1 && plansza.temp_pionkowO[wybierz + ruch] == 0) {
			return true;
		}
		else {
			if (czy_sprawdzenie == false)
				cout << "nie mozna wykonac takiego bicia" << endl;
			return false;
		}
	}
}
int CbicieX(pole &plansza, int wybierz, int gracz) {            //sprawdza czy jest zbicie jesli jest oddaje ruch jaki trzeba wykonac do zbicia
	if (plansza.temp_pionkowO[wybierz + 8] == 1 && plansza.temp_pionkow[wybierz + 2 * 8] == 0 && plansza.temp_plansza[wybierz + 2 * 8] == 1)return 8;
	if (plansza.temp_pionkowO[wybierz - 8] == 1 && plansza.temp_pionkow[wybierz - 2 * 8] == 0 && plansza.temp_plansza[wybierz - 2 * 8] == 1)return -8;
	if (plansza.temp_pionkowO[wybierz + 1] == 1 && plansza.temp_pionkow[wybierz + 2 * 1] == 0 && plansza.temp_plansza[wybierz + 2 * 1] == 1)return 1;
	if (plansza.temp_pionkowO[wybierz - 1] == 1 && plansza.temp_pionkow[wybierz - 2 * 1] == 0 && plansza.temp_plansza[wybierz - 2 * 1] == 1)return -1;
	if (plansza.temp_pionkowO[wybierz + 9] == 1 && plansza.temp_pionkow[wybierz + 2 * 9] == 0 && plansza.temp_plansza[wybierz + 2 * 9] == 1) return 9;
	if (plansza.temp_pionkowO[wybierz - 9] == 1 && plansza.temp_pionkow[wybierz - 2 * 9] == 0 && plansza.temp_plansza[wybierz - 2 * 9] == 1) return -9;

	if (plansza.temp_pionkowO[wybierz + 10] == 1 && plansza.temp_pionkow[wybierz + (2 * 10)] == 0 && plansza.temp_plansza[wybierz + (2 * 10)] == 1)return 10;
	if (plansza.temp_pionkowO[wybierz - 10] == 1 && plansza.temp_pionkow[wybierz - (2 * 10)] == 0 && plansza.temp_plansza[wybierz - (2 * 10)] == 1)return -10;
	return 0;
}
int CbicieO(pole &plansza, int wybierz, int gracz) {
	ruch RUCH;

	if (plansza.temp_pionkowX[wybierz + 8] == 1 && plansza.temp_pionkow[wybierz + 2 * 8] == 0 && plansza.temp_plansza[wybierz + 2 * 8] == 1)return 8;
	if (plansza.temp_pionkowX[wybierz - 8] == 1 && plansza.temp_pionkow[wybierz - 2 * 8] == 0 && plansza.temp_plansza[wybierz - 2 * 8] == 1)return -8;

	if (plansza.temp_pionkowX[wybierz + 1] == 1 && plansza.temp_pionkow[wybierz + 2 * 1] == 0 && plansza.temp_plansza[wybierz + 2 * 1] == 1)return 1;
	if (plansza.temp_pionkowX[wybierz - 1] == 1 && plansza.temp_pionkow[wybierz - 2 * 1] == 0 && plansza.temp_plansza[wybierz - 2 * 1] == 1)return -1;
	if (plansza.temp_pionkowX[wybierz + 9] == 1 && plansza.temp_pionkow[wybierz + 2 * 9] == 0 && plansza.temp_plansza[wybierz + 2 * 9] == 1)return 9;
	if (plansza.temp_pionkowX[wybierz - 9] == 1 && plansza.temp_pionkow[wybierz - 2 * 9] == 0 && plansza.temp_plansza[wybierz - 2 * 9] == 1)return -9;
	if (plansza.temp_pionkowX[wybierz + 10] == 1 && plansza.temp_pionkow[wybierz + 2 * 10] == 0 && plansza.temp_plansza[wybierz + 2 * 10] == 1)return 10;
	if (plansza.temp_pionkowX[wybierz - 10] == 1 && plansza.temp_pionkow[wybierz - 2 * 10] == 0 && plansza.temp_plansza[wybierz - 2 * 10] == 1)return -10;
	return 0;
}
bool zamiana_o_dwa(pole &plansza, int wybor, int ruch, int gracz) {
	if (plansza.temp_pionkow[wybor] == 1 && plansza.temp_plansza[wybor + ruch] == 0 && plansza.temp_pionkow[wybor + (2 * ruch)] == 0 && plansza.temp_plansza[wybor + (2 * ruch)] == 1) return true;
	else {
		if (czy_zamiana(plansza, wybor, ruch, gracz) == true)
			cout << "nie mozna wykonac takiego ruchu" << endl;
		return false;
	}
}
bool warunki_koncaX(int i,pole &plansza) {              // sprawdza czy kazdy pionek ma ruch
	if (czy_zamiana(plansza, i, -8, 1) == false && zamiana_o_dwa(plansza, i, -8, 1) == false && czy_zbicieX(plansza, i, -8, 1, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, 8, 1) == false && zamiana_o_dwa(plansza, i,8, 1) == false && czy_zbicieX(plansza, i, 8, 1, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, -1, 1) == false && zamiana_o_dwa(plansza, i, -1, 1) == false && czy_zbicieX(plansza, i, -1, 1, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, 1, 1) == false && zamiana_o_dwa(plansza, i, 1, 1) == false && czy_zbicieX(plansza, i, 1, 1, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, -10, 1) == false && zamiana_o_dwa(plansza, i, -10, 1) == false && czy_zbicieX(plansza, i, -10, 1, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, 10, 1) == false && zamiana_o_dwa(plansza, i,10,1) == false && czy_zbicieX(plansza, i, 10, 1, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, -9, 1) == false && zamiana_o_dwa(plansza, i, -9, 1) == false && czy_zbicieX(plansza, i, -9, 1, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, 9, 1) == false && zamiana_o_dwa(plansza, i, 9, 1) == false && czy_zbicieX(plansza, i, 9, 1, 1) == false) {
		return false;
	}
	return true;
}
bool warunki_koncaO(int i,pole &plansza) {
	if (czy_zamiana(plansza, i, -8, 2) == false && zamiana_o_dwa(plansza, i, -8, 2) == false && czy_zbicieO(plansza, i, -8, 2, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, 8, 2) == false && zamiana_o_dwa(plansza, i, 8, 2) == false && czy_zbicieO(plansza, i, 8, 2, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, -1, 2) == false && zamiana_o_dwa(plansza, i, -1, 2) == false && czy_zbicieO(plansza, i, -1, 2, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, 1, 2) == false && zamiana_o_dwa(plansza, i, 1, 2) == false && czy_zbicieO(plansza, i, 1, 2, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, -10, 2) == false && zamiana_o_dwa(plansza, i, -10, 2) == false && czy_zbicieO(plansza, i, -10, 2, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, 10, 2) == false && zamiana_o_dwa(plansza, i, 10, 2) == false && czy_zbicieO(plansza, i, 10, 2, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, -9, 2) == false && zamiana_o_dwa(plansza, i, -9, 2) == false && czy_zbicieO(plansza, i, -9, 2, 1) == false) {
		return false;
	}
	if (czy_zamiana(plansza, i, 9, 2) == false && zamiana_o_dwa(plansza, i, 9, 2) == false && czy_zbicieO(plansza, i, 9, 2, 1) == false) {
		return false;
	}
	return true;
}
bool koniec(pole &plansza) {
	int sumaX = 0, sumaO = 0, X = 0,O = 0;
	for (int i = 0; i < LICZBA_POL; i++) {
		if (plansza.temp_pionkowX[i] == 1)sumaX++;
		if (plansza.temp_pionkowO[i] == 1)sumaO++;
		if(plansza.temp_pionkowX[i] == 1 && warunki_koncaX(i, plansza)==false) X++;
		if(plansza.temp_pionkowO[i] == 1 && warunki_koncaO(i, plansza) == false) O++;

	}
	if (X > sumaX) {
		cout << "gracz 1 nie ma ruchu i przygrywa" << endl;
		return false;
	}
	else if (O > sumaO) {
		cout << "gracz 2 nie ma ruchu i przygrywa" << endl;
		return false;

	}
	else if (sumaX == 0) {
		cout << "gracz 1 przegral" << endl;
		return false;
	}
	else if (sumaO == 0) {
		cout << "gracz 2 przegral" << endl;
		return false;
	}
	return true;
}

int wymus_zbic(pole &plansza, int wybierz, int gracz) {
	ruch RUCH;
	int a = 0;
	if (gracz == 1) {
		for (int i = 0; i < LICZBA_POL; i++) {
			if (plansza.temp_plansza[i] == 1 && plansza.temp_pionkowX[i] == 1) {
				if (czy_zbicieX(plansza, i, 8, gracz, 1) == true && plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz + 8] == 0 && RUCH.ruch_ukosny_lewo[i] == 1)a = i;
				if (czy_zbicieX(plansza, i, -8, gracz, 1) == true && plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz - 8] == 0 && RUCH.ruch_ukosny_lewo[i] == 1) a = i;
				if (czy_zbicieX(plansza, i, 1, gracz, 1) == true && plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz + 1] == 0 && RUCH.ruch_poziomy[i] == 1) a = i;
				if (czy_zbicieX(plansza, i, -1, gracz, 1) == true && plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz - 9] == 0 && RUCH.ruch_poziomy[i] == 1) a = i;
				if (czy_zbicieX(plansza, i, 9, gracz, 1) == true && plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz + 9] == 0 && RUCH.ruch_pionowy[i] == 1) a = i;
				if (czy_zbicieX(plansza, i, -9, gracz, 1) == true && plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz - 9] == 0 && RUCH.ruch_pionowy[i] == 1) a = i;
				if (czy_zbicieX(plansza, i, 10, gracz, 1) == true && plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz + 10] == 0 && RUCH.ruch_ukosny_prawo[i] == 1) a = i;
				if (czy_zbicieX(plansza, i, -10, gracz, 1) == true && plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz - 10] == 0 && RUCH.ruch_ukosny_prawo[i] == 1) a = i;
			}
		}
		return a;
	}
	else {
		for (int i = 0; i < LICZBA_POL; i++) {
			if (plansza.temp_plansza[i] == 1 && plansza.temp_pionkowO[i] == 1) {
				if (czy_zbicieO(plansza, i, 8, gracz, 1) == true && plansza.temp_pionkowO[i] == 1 && plansza.temp_pionkowO[i + 8] == 0 && RUCH.ruch_ukosny_lewo[i] == 1)a = i;
				if (czy_zbicieO(plansza, i, -8, gracz, 1) == true && plansza.temp_pionkowO[i] == 1 && plansza.temp_pionkowO[i - 8] == 0 && RUCH.ruch_ukosny_lewo[i] == 1) a = i;
				if (czy_zbicieO(plansza, i, 1, gracz, 1) == true && plansza.temp_pionkowO[i] == 1 && plansza.temp_pionkowO[i + 1] == 0 && RUCH.ruch_poziomy[i] == 1) a = i;
				if (czy_zbicieO(plansza, i, -1, gracz, 1) == true && plansza.temp_pionkowO[i] == 1 && plansza.temp_pionkowO[i - 1] == 0 && RUCH.ruch_poziomy[i] == 1) a = i;
				if (czy_zbicieO(plansza, i, 9, gracz, 1) == true && plansza.temp_pionkowO[i] == 1 && plansza.temp_pionkowO[i + 9] == 0 && RUCH.ruch_pionowy[i] == 1) a = i;
				if (czy_zbicieO(plansza, i, -9, gracz, 1) == true && plansza.temp_pionkowO[i] == 1 && plansza.temp_pionkowO[i - 9] == 0 && RUCH.ruch_pionowy[i] == 1) a = i;
				if (czy_zbicieO(plansza, i, 10, gracz, 1) == true && plansza.temp_pionkowO[i] == 1 && plansza.temp_pionkowO[i + 10] == 0 && RUCH.ruch_ukosny_prawo[i] == 1) a = i;
				if (czy_zbicieO(plansza, i, -10, gracz, 1) == true && plansza.temp_pionkowO[i] == 1 && plansza.temp_pionkowO[i - 10] == 0 && RUCH.ruch_ukosny_prawo[i] == 1) a = i;
			}
		}
		return a;
	}

}

void zapis(int a, int gracz) {
	fstream plik;
	plik.open("historia.txt", ios::app);
	if (plik.good() == true)
	{
		if (a == 5) plik << "wykonany ruch   " << a;
		else plik << "wykonany ruch   " << a << endl;
		plik.close();
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}
int spis_ruchu(int wybierz, pole &plansza, int gracz) {
	ruch RUCH;

	int z = 0;
	cout << "MENU RUCHU" << endl;
	int a;
	int b = wymus_zbic(plansza, wybierz, gracz);
	int CBX = CbicieX(plansza, wybierz, gracz);
	int CBO = CbicieO(plansza, wybierz, gracz);

		if (b != 0) {
			if (gracz == 1) {
				cout << "[5] Zbicie" << endl;
				do {
					cin >> a;
					if (a != 5)cout << "musisz zbic " << endl;
				} while (a != 5);
				zapis(a, gracz);
				return CBX;
			}
			else {
				cout << "[5] Zbicie" << endl;
				do {
					cin >> a;
					if (a != 5)cout << "musisz zbic " << endl;
				} while (a != 5);
				zapis(a, gracz);
				return CBO;
			}
		}                                   // sprawdzenie poszczegolnych przypadkow w celu wypisania w konsoli mozliwych ruchow
	if (RUCH.ruch_pionowy[wybierz] == RUCH.temp_plansza[wybierz]) {
		if (plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz - 9] == 0 || plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz - 9] == 0)
			if (plansza.temp_pionkow[wybierz - 9] != 1 && plansza.temp_plansza[wybierz - 9] == 1 && plansza.temp_plansza[wybierz - 2 * 9] == 1)
				cout << "[8]Gora" << endl;
		if (plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz + 9] == 0 || plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz + 9] == 0)
			if (plansza.temp_pionkow[wybierz + 9] != 1 && plansza.temp_plansza[wybierz + 9] == 1 && plansza.temp_plansza[wybierz + 2 * 9] == 1)
				cout << "[2]Dol" << endl;
	}
	if (RUCH.ruch_poziomy[wybierz] == RUCH.temp_plansza[wybierz]) {
		if (plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz - 1] == 0 || plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz - 1] == 0)
			if (plansza.temp_pionkow[wybierz - 1] != 1 && plansza.temp_plansza[wybierz - 1] == 1 && plansza.temp_plansza[wybierz - 2 * 1] == 1)
				cout << "[4]Lewo" << endl;
		if (plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz + 1] == 0 || plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz + 1] == 0)
			if (plansza.temp_pionkow[wybierz + 1] != 1 && plansza.temp_plansza[wybierz + 1] == 1 && plansza.temp_plansza[wybierz + 2 * 1] == 1)
				cout << "[6]Prawo" << endl;
	}
	if (RUCH.ruch_ukosny_lewo[wybierz] == RUCH.temp_plansza[wybierz]) {
		if (plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz + 8] == 0 || plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz + 8] == 0)
			if (plansza.temp_pionkow[wybierz + 8] != 1 && plansza.temp_plansza[wybierz - 8] == 1 && plansza.temp_plansza[wybierz + 2 * 8] == 1)
				cout << "[1]Lewy Skos Dol" << endl;
		if (plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz - 8] == 0 || plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz - 8] == 0)
			if (plansza.temp_pionkow[wybierz - 8] != 1 && plansza.temp_plansza[wybierz + 8] == 1 && plansza.temp_plansza[wybierz - 2 * 8] == 1)
				cout << "[9]Prawo Skos Gora" << endl;
	}
	if (RUCH.ruch_ukosny_prawo[wybierz] == RUCH.temp_plansza[wybierz]) {
		if (plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz + 10] == 0 || plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz + 10] == 0)
			if (plansza.temp_pionkow[wybierz + 10] != 1 && plansza.temp_plansza[wybierz + 10] == 1 && plansza.temp_plansza[wybierz + 2 * 10] == 1)
				cout << "[3]Prawo Skos Dol" << endl;
		if (plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz - 10] == 0 || plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz - 10] == 0)
			if (plansza.temp_pionkow[wybierz - 10] != 1 && plansza.temp_plansza[wybierz - 10] == 1 && plansza.temp_plansza[wybierz - 2 * 10] == 1)
				cout << "[7]Lewo Skos Gora" << endl;
	}
	if (plansza.temp_plansza[wybierz] == 1 && plansza.temp_plansza[wybierz - 1] == 0 && plansza.temp_plansza[wybierz - 2] == 1 && RUCH.ruch_poziomy[wybierz - 2] == 1 && RUCH.ruch_poziomy[wybierz]==1)
		if (plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz - 2] == 0 || plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz - 2] == 0)
			cout << "[4]Lewo" << endl;
	if (plansza.temp_plansza[wybierz] == 1 && plansza.temp_plansza[wybierz + 1] == 0 && plansza.temp_plansza[wybierz + 2] == 1 && RUCH.ruch_poziomy[wybierz + 2] == 1 && RUCH.ruch_poziomy[wybierz] == 1)
		if (plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz + 2] == 0 || plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz + 2] == 0)
			cout << "[6]Prawo" << endl;
	if (plansza.temp_plansza[wybierz] == 1 && plansza.temp_plansza[wybierz - 9] == 0 && plansza.temp_plansza[wybierz - 18] == 1 && RUCH.ruch_pionowy[wybierz - 18] == 1 && RUCH.ruch_pionowy[wybierz] == 1)
		if (plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz - 18] == 0 || plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz -18] == 0)
			cout << "[8]Gora" << endl;
	if (plansza.temp_plansza[wybierz] == 1 && plansza.temp_plansza[wybierz + 9] == 0 && plansza.temp_plansza[wybierz + 18] == 1 && RUCH.ruch_pionowy[wybierz + 18] == 1 && RUCH.ruch_pionowy[wybierz] == 1)
		if (plansza.temp_pionkowO[wybierz] == 1 && plansza.temp_pionkowO[wybierz +18] == 0 || plansza.temp_pionkowX[wybierz] == 1 && plansza.temp_pionkowX[wybierz +18] == 0)
			cout << "[2]Dol" << endl;

	cout << "[0]wybierz inny pionek" << endl;
	bool CzySukces = cin.good();
	do {
		do {
			cin >> a;
			cin.clear();
			cin.ignore(1000, '\n');
		} while (CzySukces != true);



		if (a == 8)z = -9;
		if (a == 2)z = 9;
		if (a == 1)z = 8;
		if (a == 3)z = 10;
		if (a == 4)z = -1;
		if (a == 6)z = 1;
		if (a == 7)z = -10;
		if (a == 9)z = -8;
		if (z == 9) {
			if (RUCH.ruch_pionowy[wybierz] == 1 && RUCH.ruch_pionowy[wybierz + z] == 1) {
				zapis(a, gracz);
				return z;
			}
			if (RUCH.ruch_pionowy[wybierz] == 1 && RUCH.ruch_pionowy[wybierz + z] == 0 && RUCH.ruch_pionowy[wybierz + 2 * z] == 1 && RUCH.temp_plansza[wybierz + z] == 0) {
				zapis(a, gracz);
				return z;
			}
		}
		if (z == -9) {
			if (RUCH.ruch_pionowy[wybierz] == 1 && RUCH.ruch_pionowy[wybierz + z] == 1) {
				zapis(a, gracz);
				return z;
			}
			if (RUCH.ruch_pionowy[wybierz] == 1 && RUCH.ruch_pionowy[wybierz + z] == 0 && RUCH.ruch_pionowy[wybierz + 2 * z] == 1 && RUCH.temp_plansza[wybierz + z] == 0) {
				zapis(a, gracz);
				return z;
			}

		}
		if (z == 1) {
			if (RUCH.ruch_poziomy[wybierz] == 1 && RUCH.ruch_poziomy[wybierz + z] == 1) {
				zapis(a, gracz);
				return z;
			}
			if (RUCH.ruch_poziomy[wybierz] == 1 && RUCH.ruch_poziomy[wybierz + z] == 0 && RUCH.ruch_poziomy[wybierz + 2 * z] == 1 && RUCH.temp_plansza[wybierz + z] == 0) {
				zapis(a, gracz);
				return z;
			}

		}
		if (z == -1) {
			if (RUCH.ruch_poziomy[wybierz] == 1 && RUCH.ruch_poziomy[wybierz + z] == 1) {
				zapis(a, gracz);
				return z;
			}
			if (RUCH.ruch_poziomy[wybierz] == 1 && RUCH.ruch_poziomy[wybierz + z] == 0 && RUCH.ruch_poziomy[wybierz + 2 * z] == 1 && RUCH.temp_plansza[wybierz + z] == 0) {
				zapis(a, gracz);
				return z;
			}

		}
		if (z == -8) {
			if (RUCH.ruch_ukosny_lewo[wybierz] == 1 && RUCH.ruch_ukosny_lewo[wybierz + z] == 1) {
				zapis(a, gracz);
				return z;
			}
		}
		if (z == 8) {
			if (RUCH.ruch_ukosny_lewo[wybierz] == 1 && RUCH.ruch_ukosny_lewo[wybierz + z] == 1) {
				zapis(a, gracz);
				return z;
			}
		}
		if (z == 10) {
			if (RUCH.ruch_ukosny_prawo[wybierz] == 1 && RUCH.ruch_ukosny_prawo[wybierz + z] == 1) {
				zapis(a, gracz);
				return z;
			}
		}
		if (z == -10) {
			if (RUCH.ruch_ukosny_prawo[wybierz] == 1 && RUCH.ruch_ukosny_prawo[wybierz + z] == 1) {
				zapis(a, gracz);
				return z;
			}
		}

		if (a == 0) return 0;
		cout << "ruch ktory chcesz wykonac jest niepoprawny" << endl;
		cout << "powtorz go:" << endl;
	} while (a != 0);
}

void gra(int gracz, pole &plansza) {
	fstream plik;
	int wybor, odp_ruch, CB, a, N,BUFCB;
	system("cls");
	cout << "Tura gracza" << gracz << endl;
	do {
		a = 0;
		if (gracz == 1) {
			do {
				do {

					wypisz(plansza, -1);

					wybor = wybierz(gracz,plansza);
					while (wymus_zbic(plansza, wybor, gracz) != wybor) {
						if (wymus_zbic(plansza, wybor, gracz) == 0) break;
						system("cls");
						wypisz(plansza, -1);
						cout << "musisz zbic pionek!" << endl;
						cout << "wybierz go:";
						wybor = wybierz(gracz,plansza);
					}
					if (plansza.temp_pionkowX[wybor] == 1 && plansza.temp_pionkow[wybor] == 1) {
						system("cls");
						break;
					}
					else if (plansza.temp_pionkowO[wybor] == 1 && plansza.temp_pionkow[wybor] == 1) {
						system("cls");

						cout << "to nie twoj pionek wybierz jeszcze raz:" << endl;
					}
					else if (plansza.temp_pionkow[wybor] == 0) {
						system("cls");

						cout << "tutaj jest puste pole... wybierz pionek" << endl;
					}

				} while (wybor != 0);
				wypisz(plansza, wybor);
				odp_ruch = spis_ruchu(wybor, plansza, gracz);
				system("cls");

			} while (odp_ruch == 0);
		}
		else {
			do {
				do {

					wypisz(plansza, -1);
					wybor = wybierz(gracz,plansza);
					while (wymus_zbic(plansza, wybor, gracz) != wybor) {
						if (wymus_zbic(plansza, wybor, gracz) == 0) break;
						system("cls");
						wypisz(plansza, -1);
						cout << "musisz zbic pionek!" << endl;
						cout << "wybierz go:";
						wybor = wybierz(gracz,plansza);
					}
					if (plansza.temp_pionkowO[wybor] == 1 && plansza.temp_pionkow[wybor] == 1) {
						system("cls");
						break;
					}
					else if (plansza.temp_pionkowX[wybor] == 1 && plansza.temp_pionkow[wybor] == 1) {
						system("cls");

						cout << "to nie twoj pionek wybierz jeszcze raz:" << endl;
					}
					else if (plansza.temp_pionkow[wybor] == 0) {
						system("cls");

						cout << "tutaj jest puste pole... wybierz pionek" << endl;
					}

				} while (wybor != 0);
				wypisz(plansza, wybor);
				odp_ruch = spis_ruchu(wybor, plansza, gracz);
				system("cls");

			} while (odp_ruch == 0);
		}

		if (czy_zamiana(plansza, wybor, odp_ruch, gracz) == true) {
			zamiana(plansza, wybor, odp_ruch, gracz);
			a++;
		}
		else {
			if (zamiana_o_dwa(plansza, wybor, odp_ruch, gracz) == true) {
				zamiana(plansza, wybor, 2 * odp_ruch, gracz);
				a++;
			}

			while (czy_zbicieX(plansza, wybor , odp_ruch, gracz, 0) == true) {
				bicieX(plansza, wybor, odp_ruch);
				CB = CbicieX(plansza, wybor + 2 * odp_ruch, gracz);
				BUFCB = odp_ruch;
				N = wybor + 2*odp_ruch;
				a++;
				if (CB != 0) {
					while (CB != 0) {
						bicieX(plansza, N , CB);
						N += (2*CB);


						CB = CbicieX(plansza, N , gracz);


					}
				}
				else {
					system("cls");
					wypisz(plansza, wybor);
					break;
				}
				system("cls");
				wypisz(plansza, wybor);
			}
			while (czy_zbicieO(plansza, wybor, odp_ruch, gracz, 0) == true) {
				bicieO(plansza, wybor, odp_ruch);
				CB = CbicieO(plansza, wybor + 2 * odp_ruch, gracz);
				BUFCB = odp_ruch;
				N = wybor + 2 * odp_ruch;
				a++;
				if (CB != 0) {
					while (CB != 0) {
						bicieO(plansza, N, CB);
						N += (2 * CB);


						CB = CbicieO(plansza, N, gracz);


					}
				}
				else {
					break;
					system("cls");
					wypisz(plansza, wybor);
				}
				system("cls");
				wypisz(plansza, wybor);
			}

		}
	} while (a != 1);
	system("cls");
	wypisz(plansza, wybor);

}
int main() {
	pole plansza;
	fstream plik;
	plik.open("historia.txt", ios::out | ios::trunc);
	plik.close();
	int gracz = 1;
	cout << "-----WARCABY KRZYZOWE-----" << endl;
	cout << "[1]Rozpocznij gre" << endl;
	cout << "[0]Koniec rozgrywki" << endl;
	cout << "PO WCZYTANIU LITERY ''P''  OTWORZY SIE HISTORIA RUCHOW" << endl;
	int a;
	cin >> a;
	switch (a) {
	case 1:
		while (koniec(plansza) != 0) {
			gra(gracz, plansza);
			if (gracz == 1) gracz++;
			else gracz--;
		}
		system("pause");
		break;
	default:
		cout << "KONIEC" << endl;
		break;
	}
	return 0;
}
