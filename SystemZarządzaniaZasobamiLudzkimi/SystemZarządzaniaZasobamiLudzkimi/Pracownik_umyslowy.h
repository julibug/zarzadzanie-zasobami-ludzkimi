#pragma once
#include "Osoba.h"

class Pracownik_umyslowy: public Osoba
{
public:
	Pracownik_umyslowy();
	Pracownik_umyslowy(string imie, string nazwisko, string pokoj1, string pokoj2, string pokoj3, string pokoj4);
	string typPracownika();
};

