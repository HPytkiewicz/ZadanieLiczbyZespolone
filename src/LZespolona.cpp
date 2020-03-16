#include "LZespolona.hh"
#include <cmath>
#include <iostream>

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odjecie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator - (LZespolona Skl1,LZespolona Skl2){
  LZespolona Wynik;
  
  Wynik.re=Skl1.re-Skl2.re;
  Wynik.im=Skl1.im-Skl2.im;

  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator * (LZespolona Skl1,LZespolona Skl2){
  LZespolona Wynik;
  
  Wynik.re=Skl1.re*Skl2.re-Skl2.im*Skl1.im;
  Wynik.im=Skl1.re*Skl2.im+Skl2.re*Skl1.im;

  return Wynik;
}

/*!
 * Oblicza wartosc bezwzgledna liczby zespolonej
 * Argumenty:
 *    Skl1 - liczba zespolona na ktora naklada sie modul
 * Zwraca:
 *     LIczbe rzeczywista bedaca wartoscia bezwzgledna z liczby zespolonej.
 */

double modul(LZespolona Skl1){
  double Wynik;

  Wynik=sqrt(pow(Skl1.re,2)+pow(Skl1.im,2));

  return Wynik;
}

/*!
 * Realizuje operacje sprzezenia
 * Argumenty:
 *    Skl1 - liczba zespolona
 * Zwraca:
 *    LIczbe sprzezona do liczby zespolonej
 */

LZespolona sprzezenie(LZespolona Skl1){
  LZespolona Wynik;
  Wynik.re=Skl1.re;
  Wynik.im=Skl1.im*(-1);

  return Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe rzeczywsita.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    R1 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator / (LZespolona Skl1, double R1){
  LZespolona Wynik;

  Wynik.re=Skl1.re/R1;
  Wynik.im=Skl1.im/R1;

  return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielnia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    ILoraz dwoch skladnikow przekazanych jako parametry.
 */

LZespolona operator / (LZespolona Skl1, LZespolona Skl2){
  LZespolona Wynik;

  Wynik= Skl1*sprzezenie(Skl2)/pow(modul(Skl2),2);

  return Wynik;
}

/*!
 * Funkcja przydziela strukturze wartosci
 * Argumenty:
 *    l1- wartosc czesci rzeczywistej
 *    l2- wartosc czesci urojonej
 * Zwraca:
 *    Liczbe zespolona z podanymi wartosciami
 */


LZespolona utworz(double l1, double l2){
  LZespolona Wynik;

  Wynik.re=l1;
  Wynik.im=l2;

  return Wynik;
}

/*!
 *Funkcja wypisujaca dana liczbe zespolona
 * Argumenty:
 *    Skl1 - liczba zespolona ktora ta funkcja wypisze
 */


void wyswietl(LZespolona Skl1){
  using namespace std;

  cout<< '(' << Skl1.re << showpos << Skl1.im << 'i' << ')' << endl << noshowpos;
}

void wczytaj(















