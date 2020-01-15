#include "firma.h"
#include <iostream>
#include<String>

using namespace std;

Firma::Firma(){

}

void Firma::dodaj_pracownika(){

    cout<<"Witaj w naszej firmie."<<endl;
    cout<<"Jak masz na imie: ";
    cin>>this->imie;
        if(sprawdz_imie() == false){
            while(sprawdz_imie()==false){
                cout<<endl<<"Podaj swoje imie:";
                cin>> this->imie;
            }
        }
    cout<<"Jak masz na nazwisko: ";
    cin>>nazwisko;
    cout<<"Witaj "<<imie<<" "<<nazwisko<<endl;
    cout<<"Podaj pozostale dane."<<endl;
    cout<<"podaj pesel: ";
    cin>>this->pesel;
        while(this->pesel.length()!=11){
            cout<<"Pesel jest zbyt krotki"<<endl;
            cout<<"podaj pesel: ";
            cin>>this->pesel;
        }
        if (sprawdz_pesel() == false)
        {
            while(sprawdz_pesel()==false){
                cout<<endl<<"W podanym peselu sa litery";
                cin>> this->pesel;
            }
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
bool Firma::sprawdz_pesel(){
    for(int i = 0; i < this->pesel.size(); i++){
        if(pesel[i]<48 || pesel[i]>57){
                return true;
         } else {
                return false;
         }
    }
}
bool Firma::sprawdz_imie(){
    this->imie[0] = toupper(this->imie[0]);
    for(int i=1; i<this->imie.length(); i++){
        this->imie[i] = tolower(this->imie[i]);
    }
    for (int j=0; this->imie.length(); j++){
        if(this->imie[j] >= 65 || this->imie[j] <= 90 && this->imie[j] >= 97 || this->imie[j] <= 122)  return true;
            else return false;
    }
}