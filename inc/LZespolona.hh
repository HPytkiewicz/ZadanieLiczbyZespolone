#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona operator - (LZespolona Skl1, LZespolona Skl2);

LZespolona operator * (LZespolona Skl1, LZespolona Skl2);

double modul(LZespolona Skl1);

LZespolona sprzezenie(LZespolona Skl1);

LZespolona operator / (LZespolona Skl1, double R1);

LZespolona operator / (LZespolona Skl1, LZespolona Skl2);

LZespolona utworz(double l1, double l2);

void wyswietl(LZespolona Skl1);


#endif
