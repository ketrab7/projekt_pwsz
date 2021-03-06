#include "firma.h"
#include <iostream>
#include<String>
#include <cstdlib>
#include <time.h>

using namespace std;

Firma::Firma(){

}

void Firma::dodaj_pracownika(){

    cout<<"Witaj w naszej firmie."<<endl;
    cout<<"Jak masz na imie: ";
    cin>>this->imie;
         while(sprawdz_imie()==false){
            cout<<endl<<"Podaj swoje imie:";
            cin>> this->imie;
         }
    cout<<"Jak masz na nazwisko: ";
    cin>>this->nazwisko;
         while(sprawdz_nazwisko()==false){
            cout<<endl<<"Podaj swoje nazwisko:";
            cin>> this->nazwisko;
         }
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
    cin>>this->haslo;
    cout<<"podaj ponownie haslo: ";
    cin>>this->sprawdz_ponownie_haslo;
        while(sprawdz_haslo()==false){
            cout<<endl<<"Podane haslo nie spelnia warunkow lub nie jest takie samo. Podaj haslo: ";
            cin>> this->haslo;
            cout<<endl<<"Podaj ponownie haslo: ";
            cin>> this->sprawdz_ponownie_haslo;
         }
    cout<<"podaj kategorie prawa jazdy jakie posiadasz: ";
    cin>>this->kategoria_prawa_jazdy;

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
                return false;
         } else {
                return true;
         }
    }
}
bool Firma::sprawdz_imie(){
    this->imie[0] = toupper(this->imie[0]);
    for(int i=1; i<this->imie.length(); i++){
        this->imie[i] = tolower(this->imie[i]);
    }
    for (int j=0; this->imie.length(); j++){
        if((this->imie[j] >= 65 && this->imie[j] <= 90) || (this->imie[j] >= 97 && this->imie[j] <= 122))  return true;
            else return false;
    }
}
bool Firma::sprawdz_nazwisko(){
    this->nazwisko[0] = toupper(this->nazwisko[0]);
    for(int i=1; i<this->nazwisko.length(); i++){
        this->nazwisko[i] = tolower(this->nazwisko[i]);
    }
    for (int j=0; this->nazwisko.length(); j++){
        if((this->nazwisko[j] >= 65 && this->nazwisko[j] <= 90) || (this->nazwisko[j] >= 97 && this->nazwisko[j] <= 122))  return true;
            else return false;
    }
}
void Firma::wygeneruj_mail(){
    this->imie[0] = tolower(this->imie[0]);
    this->nazwisko[0] = tolower(this->nazwisko[0]);
    cout<<endl<<"Twoj email to: "<<this->imie<<"."<<this->nazwisko<<"@firma.pl"<<endl;
}
void Firma::wygeneruj_nr_sluzbowy(){
    srand(time(NULL));
    this->tel_sluzbowy = rand()%10000+100000;
    cout<<endl<<"Twoj numer telefonu sluzbowego to: 665"<<this->tel_sluzbowy<<endl;
}
bool Firma::sprawdz_haslo(){
        
    int ile_duzych = 0;  
    int ile_malych = 0;
    int ile_liczb = 0;    

    if(this->haslo != this->sprawdz_ponownie_haslo)
    {
        return false;
    }
    else
    {
        if (this->haslo.length() < 6 || this->haslo.length() > 20)   
            return false;
        else 
        {
            for (int i = 0; i<this->haslo.length(); i++) 
            {
                if (this->haslo[i] <= 90 && this->haslo[i] >= 65)
                    ile_duzych++;
                else if (this->haslo[i] <= 122 && this->haslo[i] >= 97)
                    ile_malych++;
                else if (this->haslo[i] <= 57 && this->haslo[i] >= 48)
                    ile_liczb++;
            }
            if (ile_duzych == 0 || ile_malych == 0 || ile_liczb == 0)
                return false;
            else
                return true;
        }
    }       
}
void Firma::przypisz_uprawnienia(){
    for(int i=0; i<this->kategoria_prawa_jazdy.size(); i++){
        this->kategoria_prawa_jazdy[i] = toupper(this->kategoria_prawa_jazdy[i]);
    }
    for(int i=0; i<this->kategoria_prawa_jazdy.size(); i++){
        
        switch(this->kategoria_prawa_jazdy[i])
        {
            case 'A':
                cout<<"Posiadasz prawo jazdy na motor"<<endl;
                break;
            case 'B':
                cout<<"Posiadasz prawo jazdy na samochod"<<endl;
                break;
            case 'C':
                cout<<"Posiadasz prawo jazdy upowazniajace do kierowania ciezarowka"<<endl;
                break;
            case 'D':
                cout<<"Posiadasz prawo jazdy upowazniajace do kierowania autobusem"<<endl;
                break;
            case 'T':
                cout<<"Posiadasz prawo jazdy upowazniajace do kierowania ciagnikiem rolniczym"<<endl;
                break;
   
            default:
                cout<<"Nie umiesz prowadzic"<<endl;
            break;
        }
    }
}