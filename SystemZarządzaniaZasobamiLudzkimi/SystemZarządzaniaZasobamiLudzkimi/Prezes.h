#pragma once
#include"Pracownik_umyslowy.h"

class Prezes: public Pracownik_umyslowy
{
public:
	Prezes();
	Prezes(string imie, string nazwisko, string pokoj1, string pokoj2, string pokoj3, string pokoj4);
	string typPracownika();
};

