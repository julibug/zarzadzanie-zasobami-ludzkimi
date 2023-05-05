#pragma once
#include <iostream>
using namespace std;

class Osoba {
protected:
	string imie;
	string nazwisko;
	string pokoj1;
	string pokoj2;
	string pokoj3;
	string pokoj4;
public:
	virtual string typPracownika() = 0;
	string nazwa();
	string pokoje();
	void setImie(string imie);
	void setNazwisko(string nazwisko);
	void setPokoj1(string pokoj1);
	void setPokoj2(string pokoj2);
	void setPokoj3(string pokoj3);
	void setPokoj4(string pokoj4);
};

