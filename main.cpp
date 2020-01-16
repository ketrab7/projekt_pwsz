#include "firma.h"
#include <iostream>
#include <cstring>

using namespace std;



int main () {

   Firma pracownik1;

   pracownik1.dodaj_pracownika();
   pracownik1.data_urodzenia();
   pracownik1.wygeneruj_mail();

   return 0;
} 