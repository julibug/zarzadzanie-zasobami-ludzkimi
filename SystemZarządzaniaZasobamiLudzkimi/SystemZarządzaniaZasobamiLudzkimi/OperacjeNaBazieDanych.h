#pragma once
#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include "Osoba.h"
#include "Pracownik_fizyczny.h"
#include "Pracownik_umyslowy.h"
#include "Prezes.h"
#include "Sekretarka.h"

using namespace std;

class OperacjeNaBazieDanych
{
private:
	list<Osoba*> listaPracownikow;
	const char SEPARATOR = ' ';
	const int INDEX_TYP = 0;
	const int INDEX_IMIE = 1;
	const int INDEX_NAZWISKO = 2;
	const int INDEX_POKOJ_1 = 3;
	const int INDEX_POKOJ_2 = 4;
	const int INDEX_POKOJ_3 = 5;
	const int INDEX_POKOJ_4 = 6;
	template <class T>
	void zwolnijPamiec(list<T*> wskazniki);
public:
	OperacjeNaBazieDanych(list<Osoba*> listaPracownikow);
	list<Osoba*> wczytajPracownikow(const string& sciezka);
	string readFileIntoString(const string& sciezka);
	void wyswietlPracownikow();
	void zapiszListePracownikow(const string& sciezka);
	list<Osoba*> dodajPracownika();
	list<Osoba*> usunPracownika();
	void wyczyscPamiec();
};

