#include "Osoba.h"

string Osoba::nazwa() {
	return imie + " " + nazwisko;
}

string Osoba::pokoje() {
	return pokoj1 + " " + pokoj2 + " " + pokoj3 + " " + pokoj4;
}

void Osoba::setImie(string imie) {
	this->imie = string(imie);
}

void Osoba::setNazwisko(string nazwisko) {
	this->nazwisko = string(nazwisko);
}

void Osoba::setPokoj1(string pokoj1) {
	this->pokoj1 = string(pokoj1);
}

void Osoba::setPokoj2(string pokoj2) {
	this->pokoj2 = string(pokoj2);
}

void Osoba::setPokoj3(string pokoj3) {
	this->pokoj3 = string(pokoj3);
}

void Osoba::setPokoj4(string pokoj4) {
	this->pokoj4 = string(pokoj4);
}


