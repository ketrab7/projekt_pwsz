#include "firma.h"
#include <iostream>
#include<String>

using namespace std;

Firma::Firma(){

}

void Firma::dodaj_pracownika(){

    cout<<"Witaj w naszej firmie."<<endl;
    cout<<"Jak masz na imie: ";
    cin>>imie;
    cout<<"Jak masz na nazwisko: ";
    cin>>nazwisko;
    cout<<"Witaj "<<imie<<" "<<nazwisko<<endl;
    cout<<"Podaj pozostale dane."<<endl;
    cout<<"podaj pesel: ";
    cin>>pesel;
    cout<<"podaj stanowisko: ";
    cin>>stanowisko;
    cout<<"podaj login: ";
    cin>>login;
    cout<<"podaj haslo: ";
    cin>>haslo;


    cin.clear();
}