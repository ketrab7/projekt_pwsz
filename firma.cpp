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
    while(pesel.length()!=11){
        cout<<"Pesel jest zbyt krotki"<<endl;
        cout<<"podaj pesel: ";
        cin>>pesel;
    }
    cout<<"podaj stanowisko: ";
    cin>>stanowisko;
    cout<<"podaj login: ";
    cin>>login;
    cout<<"podaj haslo: ";
    cin>>haslo;


    cin.clear();
}

void Firma::data_urodzenia(){

    string t = pesel;
    string rok(t,0,2);
    string miesiac(t,2,2);
    string dzien(t,4,2);
    cout<<"Twoja data urodzenia to: "<<dzien<<"."<<miesiac<<"."<<rok<<endl;
}