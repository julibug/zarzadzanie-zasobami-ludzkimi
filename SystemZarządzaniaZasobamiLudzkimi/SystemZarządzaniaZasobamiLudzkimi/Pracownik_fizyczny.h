#pragma once
#include "Osoba.h"

class Pracownik_fizyczny : public Osoba {
public:
	Pracownik_fizyczny();
	Pracownik_fizyczny(string imie, string nazwisko, string pokoj1, string pokoj2, string pokoj3, string pokoj4);
	string typPracownika();
	
};

