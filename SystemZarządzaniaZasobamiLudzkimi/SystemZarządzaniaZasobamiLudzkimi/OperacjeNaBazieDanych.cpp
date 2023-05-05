#include "OperacjeNaBazieDanych.h"
#include <vector>

OperacjeNaBazieDanych::OperacjeNaBazieDanych(list<Osoba*> listaPracownikow) {
    this->listaPracownikow = listaPracownikow;
}

list<Osoba*> OperacjeNaBazieDanych::wczytajPracownikow(const string& sciezka) {
    istringstream sstream(readFileIntoString(sciezka));
    vector<string> items;
    string record;
    while (getline(sstream, record)) {
        istringstream line(record);
        while (getline(line, record, SEPARATOR)) {
            items.push_back(record);
        }
        string typPracownika = items[INDEX_TYP];
        if (typPracownika == "1") {
            listaPracownikow.push_back(new Pracownik_fizyczny(items[INDEX_IMIE], items[INDEX_NAZWISKO],items[INDEX_POKOJ_1],items[INDEX_POKOJ_2],items[INDEX_POKOJ_3],items[INDEX_POKOJ_4]));
        } else if(typPracownika == "2"){
            listaPracownikow.push_back(new Pracownik_umyslowy(items[INDEX_IMIE], items[INDEX_NAZWISKO], items[INDEX_POKOJ_1], items[INDEX_POKOJ_2], items[INDEX_POKOJ_3], items[INDEX_POKOJ_4]));
        } else if (typPracownika == "3") {
            listaPracownikow.push_back(new Sekretarka(items[INDEX_IMIE], items[INDEX_NAZWISKO], items[INDEX_POKOJ_1], items[INDEX_POKOJ_2], items[INDEX_POKOJ_3], items[INDEX_POKOJ_4]));
        } else if(typPracownika == "4"){
            listaPracownikow.push_back(new Prezes(items[INDEX_IMIE], items[INDEX_NAZWISKO], items[INDEX_POKOJ_1], items[INDEX_POKOJ_2], items[INDEX_POKOJ_3], items[INDEX_POKOJ_4]));
        } else {
            throw invalid_argument("Niepoprawne dane");
        }
        items.clear();
    }
    return listaPracownikow;
};

string OperacjeNaBazieDanych::readFileIntoString(const string& sciezka) {
    auto ss = ostringstream{};
    ifstream input_file(sciezka);
    if (!input_file.is_open()) {
        throw runtime_error("Blad podczas wczytywania tresci pliku: " + sciezka);
    }
    ss << input_file.rdbuf();
    return ss.str();
};

void OperacjeNaBazieDanych::wyswietlPracownikow() {
    cout << "LISTA PRACOWNIKOW:" << endl << endl;
    for (list<Osoba*>::iterator it = listaPracownikow.begin(); it != listaPracownikow.end(); ++it) {
        cout << (*it)->nazwa();
        cout << (*it)->typPracownika() << endl;
    }
    cout << endl;
};

void OperacjeNaBazieDanych::zapiszListePracownikow(const string& sciezka) {
    ofstream plikwe(sciezka);
    if (plikwe.is_open()) {
        for (list<Osoba*>::iterator it = listaPracownikow.begin(); it != listaPracownikow.end(); ++it){
            if (dynamic_cast<Pracownik_fizyczny*> (*it)) {
                plikwe << "1 " << (*it)->nazwa() << " " << (*it)->pokoje() << endl;
            }
            else if (dynamic_cast<Sekretarka*> (*it)) {
                plikwe << "3 " << (*it)->nazwa() << " " << (*it)->pokoje() << endl;
            }
            else if (dynamic_cast<Prezes*> (*it)) {
                plikwe << "4 " << (*it)->nazwa() << " " << (*it)->pokoje() << endl;
            }
            else if (dynamic_cast<Pracownik_umyslowy*> (*it)) {
                plikwe << "2 " << (*it)->nazwa() << " " << (*it)->pokoje() << endl;
            }
        }
        plikwe.close();
    }
    else {
        cout << "Nie mozna wczytac listy pracownikow" << endl;
    }
};

list<Osoba*> OperacjeNaBazieDanych::dodajPracownika() {
    Osoba* osoba;
    int odp;
    int odp1;
    string name;
    string lastname;
    string room1;
    string room2;
    string room3;
    string room4;
    do {
        cout << "Dodawanie nowego pracownika" << endl << endl;
        cout << "Wprowadz imie: ";
        cin >> name;
        cout << "Wprowadz nazwisko: ";
        cin >> lastname;
        cout << endl;
        cout << "Wybierz stanowisko:" << endl;
        cout << "1 - Pracownik fizyczny" << endl;
        cout << "2 - Pracownik umyslowy" << endl;
        cout << "3 - Sekretarka" << endl;
        cout << "4 - Prezes" << endl << endl;
        cin >> odp;
        cout << endl;
        cout << "Dodawanie uprawnien dostepu do pokoi" << endl << endl;
        cout << "Podaj 1 aby przyznac dostep do pokoju albo 0 aby odmowic dostepu" << endl << endl;
        cout << "Pokoj 1: ";
        cin >> room1;
        while (room1 != "0" && room1 != "1") {
            cout << "Niepoprawna odpowiedz, prosze wprowadzic poprawna: ";
            cin >> room1;
        }
        cout << "Pokoj 2: ";
        cin >> room2;
        while (room2 != "0" && room2 != "1") {
            cout << "Niepoprawna odpowiedz, prosze wprowadzic poprawna: ";
            cin >> room2;
        }
        cout << "Pokoj 3: ";
        cin >> room3;
        while (room3 != "0" && room3 != "1") {
            cout << "Niepoprawna odpowiedz, prosze wprowadzic poprawna: ";
            cin >> room3;
        }
        cout << "Pokoj 4: ";
        cin >> room4;
        while (room4 != "0" && room4 != "1") {
            cout << "Niepoprawna odpowiedz, prosze wprowadzic poprawna: ";
            cin >> room4;
        }
        cout << endl;
        switch (odp) {
        case 1:
            osoba = new Pracownik_fizyczny();
            osoba->setImie(name);
            osoba->setNazwisko(lastname);
            osoba->setPokoj1(room1);
            osoba->setPokoj2(room2);
            osoba->setPokoj3(room3);
            osoba->setPokoj4(room4);
            listaPracownikow.push_back(osoba);
            osoba = nullptr;
            break;
        case 2:
            osoba = new Pracownik_umyslowy();
            osoba->setImie(name);
            osoba->setNazwisko(lastname);
            osoba->setPokoj1(room1);
            osoba->setPokoj2(room2);
            osoba->setPokoj3(room3);
            osoba->setPokoj4(room4);
            listaPracownikow.push_back(osoba);
            osoba = nullptr;
            break;
        case 3:
            osoba = new Sekretarka();
            osoba->setImie(name);
            osoba->setNazwisko(lastname);
            osoba->setPokoj1(room1);
            osoba->setPokoj2(room2);
            osoba->setPokoj3(room3);
            osoba->setPokoj4(room4);
            listaPracownikow.push_back(osoba);
            osoba = nullptr;
            break;
        case 4:
            osoba = new Prezes();
            osoba->setImie(name);
            osoba->setNazwisko(lastname);
            osoba->setPokoj1(room1);
            osoba->setPokoj2(room2);
            osoba->setPokoj3(room3);
            osoba->setPokoj4(room4);
            listaPracownikow.push_back(osoba);
            osoba = nullptr;
            break;
        default:
            cout << "Niepoprawnie wybrane stanowisko, nie mozna dodac pracownika" << endl << endl;
            break;
        }
        cout << "Czy dodac kolejnego pracownika? 0 - NIE, 1 - TAK" << endl << endl;
        cin >> odp1;
        if (odp1 != 0 && odp1 != 1) {
            cout << endl;
            cout << "Niepoprawna odpowiedz" << endl;
            break;
        }
    } while (odp1 != 0);
    return listaPracownikow;
}

list<Osoba*> OperacjeNaBazieDanych::usunPracownika() {
    string name;
    string lastname;
    int odp;
    do {
        cout << "Wprowadz imie usuwanego pracownika: ";
        cin >> name;
        cout << "Wprowadz nazwisko usuwanego pracownika: ";
        cin >> lastname;
        cout << endl;
        for (list<Osoba*>::iterator it = listaPracownikow.begin(); it != listaPracownikow.end(); ++it) {
            if ((*it)->nazwa() == name + " " + lastname) {
                it = listaPracownikow.erase(it);
                break;
            }
        }
        cout << "Czy chcesz usunac kolejnego pracownika? 0 - NIE, 1 - TAK" << endl << endl;
        cin >> odp;
        if (odp != 0 && odp != 1) {
            cout << endl;
            cout << "Niepoprawna odpowiedz" << endl << endl;
            break;
        }
    } while (odp != 0);
    return listaPracownikow;
};

template <class T>
void OperacjeNaBazieDanych::zwolnijPamiec(list<T*> wskazniki){
    for (list<Osoba*>::iterator it = wskazniki.begin(); it != wskazniki.end(); ++it) {
        delete *it;
    }
}

void OperacjeNaBazieDanych::wyczyscPamiec(){
    zwolnijPamiec<Osoba>(listaPracownikow);
}

