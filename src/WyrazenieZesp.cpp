#include "WyrazenieZesp.hh"
#include <iostream>

using namespace std;

/*!
 * Funkcja wyswietlajaca wyrazenie zespolone
 * Argumenty:
 *    WyrZ- Wyrazenie ktore zostanie wyswietlone
 */

void wyswietl(WyrazenieZesp WyrZ){
  using namespace std;
  
  cout << '(' << WyrZ.Arg1.re << showpos<< WyrZ.Arg1.im <<'i'<< noshowpos << ')';
switch(WyrZ.Op){
 case Op_Dodaj:
   cout<<"+";
   break;
 case Op_Odejmij:
   cout<<"-";
   break;
 case Op_Mnoz:
   cout<<"*";
   break;
 case Op_Dziel:
   cout<<"/";
   break;
 default:
   cout<< "Error"<<endl;
   break;
 }
   cout<< '(' << WyrZ.Arg2.re << showpos<< WyrZ.Arg2.im <<'i'<< noshowpos << ')';
   cout<< endl;
}

/*!
 * Funkcja obliczajaca wartosc wyrazenia zespolonego
 * Argumenty:
 *    WyrZ - Wyrazenie ktore zostanie obliczone
 * Zwraca:
 *    Liczbe zespolona bedaca wynikiem rownania zespolonego
 */

LZespolona oblicz(WyrazenieZesp WyrZ){
  LZespolona Wynik;

  switch (WyrZ.Op)
  {
  case Op_Dodaj:
    Wynik=WyrZ.Arg1+WyrZ.Arg2;
    return Wynik;
    break;
  case Op_Odejmij:
    Wynik=WyrZ.Arg1-WyrZ.Arg2;
    return Wynik;
    break;
  case Op_Mnoz:
    Wynik=WyrZ.Arg1*WyrZ.Arg2;
    return Wynik;
    break;
  case Op_Dziel:
    Wynik=WyrZ.Arg1/WyrZ.Arg2;
    return Wynik;
    break;
  default:
    cout<<"Error."<<endl;
    Wynik=utworz(0,0);
    return Wynik;
    break;
  }
}

