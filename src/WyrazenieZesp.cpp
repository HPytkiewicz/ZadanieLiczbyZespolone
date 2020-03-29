#include "WyrazenieZesp.hh"
#include <iostream>

using namespace std;

/*!
 * Funkcja wyswietlajaca wyrazenie zespolone
 * Argumenty:
 *    WyrZ- Wyrazenie ktore zostanie wyswietlone
 */

std::ostream & operator <<(std::ostream & strm, WyrazenieZesp WyrZ){
  using namespace std;
  strm << WyrZ.Arg1;
  switch(WyrZ.Op){
   case Op_Dodaj:
   strm<<"+";
   break;
 case Op_Odejmij:
   strm<<"-";
   break;
 case Op_Mnoz:
   strm<<"*";
   break;
 case Op_Dziel:
   strm<<"/";
   break;
 default:
   strm.setstate(std::ios::failbit);
   break;
  }
  strm << WyrZ.Arg2;
return strm;
}

std::istream & operator >>(std::istream & strm, WyrazenieZesp & WyrZ){
  using namespace std;
  char znak;
  strm >> WyrZ.Arg1;
  strm >> znak;
  switch(znak){
  case '+':
    WyrZ.Op= Op_Dodaj;
    break;
  case '-':
    WyrZ.Op= Op_Odejmij;
    break;
  case '*':
    WyrZ.Op= Op_Mnoz;
    break;
  case '/':
    WyrZ.Op= Op_Dziel;
    break;
  default:
    strm.setstate(std::ios::failbit);
    break;
  }
  strm >> WyrZ.Arg1;
  return strm;
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

