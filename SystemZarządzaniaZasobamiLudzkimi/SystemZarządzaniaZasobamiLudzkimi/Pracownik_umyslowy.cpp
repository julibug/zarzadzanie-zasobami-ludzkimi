#include "Pracownik_umyslowy.h"

Pracownik_umyslowy::Pracownik_umyslowy() {};

Pracownik_umyslowy::Pracownik_umyslowy(string imie, string nazwisko, string pokoj1, string pokoj2, string pokoj3, string pokoj4) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->pokoj1 = pokoj1;
	this->pokoj2 = pokoj2;
	this->pokoj3 = pokoj3;
	this->pokoj4 = pokoj4;
};

string Pracownik_umyslowy::typPracownika() {
	return " (Pracownik umyslowy)";
}