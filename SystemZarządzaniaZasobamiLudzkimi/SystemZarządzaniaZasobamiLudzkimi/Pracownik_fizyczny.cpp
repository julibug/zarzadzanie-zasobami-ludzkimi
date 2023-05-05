#include "Pracownik_fizyczny.h"

Pracownik_fizyczny::Pracownik_fizyczny() {};

Pracownik_fizyczny::Pracownik_fizyczny(string imie, string nazwisko, string pokoj1, string pokoj2, string pokoj3, string pokoj4) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->pokoj1 = pokoj1;
	this->pokoj2 = pokoj2;
	this->pokoj3 = pokoj3;
	this->pokoj4 = pokoj4;
};

string Pracownik_fizyczny::typPracownika(){
	return " (Pracownik fizyczny)";
}