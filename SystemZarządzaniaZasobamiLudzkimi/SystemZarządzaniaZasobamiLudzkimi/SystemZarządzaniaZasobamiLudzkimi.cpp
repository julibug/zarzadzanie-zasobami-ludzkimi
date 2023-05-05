#include <iostream>
#include "Osoba.h"
#include "Pracownik_fizyczny.h"
#include "Pracownik_umyslowy.h"
#include "Prezes.h"
#include "Sekretarka.h"
#include "OperacjeNaBazieDanych.h"
#include <list>

int main() {
    
    list<Osoba*> listaPracownikow;
    OperacjeNaBazieDanych Operacje(listaPracownikow);
    list<Osoba*> pomocniczy;
    listaPracownikow = Operacje.wczytajPracownikow("ListaPracownikow.txt");
    int odp;
    do {
        cout << "Menu:" << endl;
        cout << "1 - Dodaj pracownika" << endl;
        cout << "2 - Usun pracownika" << endl;
        cout << "3 - Lista pracownikow" << endl;
        cout << "0 - Wyjdz" << endl << endl;
        cin >> odp;
        cout << endl;
        switch (odp) {
        case 1:
            pomocniczy = Operacje.dodajPracownika();
            listaPracownikow.clear();
            for (list<Osoba*>::iterator it = pomocniczy.begin(); it != pomocniczy.end(); ++it) {
                listaPracownikow.push_back(*it);
            }
            pomocniczy.clear();
            Operacje.zapiszListePracownikow("ListaPracownikow.txt");
            cout << endl;
            system("PAUSE");
            system("CLS");
            break;
        case 2:
            Operacje.wyswietlPracownikow();
            pomocniczy = Operacje.usunPracownika();
            listaPracownikow.clear();
            for (list<Osoba*>::iterator it = pomocniczy.begin(); it != pomocniczy.end(); ++it) {
                listaPracownikow.push_back(*it);
            }
            pomocniczy.clear();
            Operacje.zapiszListePracownikow("ListaPracownikow.txt");
            system("PAUSE");
            system("CLS");
            break;
        case 3:
            Operacje.wyswietlPracownikow();
            system("PAUSE");
            system("CLS");
            break;
        case 0:
            break;
        default:
            cout << "Niepoprawna odpowiedz" << endl << endl;
            break;
        }
    } while (odp != 0);
    Operacje.wyczyscPamiec();
}

