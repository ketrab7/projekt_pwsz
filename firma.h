#ifndef FIRMA_H
#define FIRMA_H
#include<String>

using namespace std;

class Firma
{
    public:
        Firma();
        ~Firma()=default;

        string imie;
        string nazwisko;
        string pesel;
        string stanowisko;
        string login;
        string haslo;
        int tel_stacjonarny;
        int tel_sluzbowy;
        string email;


        void dodaj_pracownika();
        void data_urodzenia();
        void wygeneruj_mail();
        void wygeneruj_nr_sluzbowy();
        

    private:
        bool sprawdz_pesel();
        bool sprawdz_imie();
        bool sprawdz_nazwisko();
        bool sprawdz_haslo();

    protected:

};
#endif