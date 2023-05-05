#pragma once
#include"Pracownik_umyslowy.h"

class Sekretarka: public Pracownik_umyslowy
{
public:
	Sekretarka();
	Sekretarka(string imie, string nazwisko, string pokoj1, string pokoj2, string pokoj3, string pokoj4);
	string typPracownika();
};

