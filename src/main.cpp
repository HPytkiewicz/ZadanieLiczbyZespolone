#include <iostream>
#include "BazaTestu.hh"

using namespace std;


int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Odp;
  bool Poprawny_zapis = true;
  int i=1;
  Statystyka Statystyki={0,0};
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << "Podaj wynik operacji: ";
    cout << WyrZ_PytanieTestowe << endl;
    i=1;
    Poprawny_zapis=true;

    do{
      if(!Poprawny_zapis){
	cout<< "Niepoprawny zapis liczby zespolonej. Pozostałych prób: " << 3-i << endl;
	cin.clear();
	cin.ignore(10000,'\n');
	i++;
      }
      
    cout << "Twoja odpowiedz: ";
    cin >> Odp;
    Poprawny_zapis = cin.good();
    }while(!Poprawny_zapis && i<3);


    if(Poprawny_zapis){
      if(Odp==oblicz(WyrZ_PytanieTestowe)){
	cout<<"Odpowiedz poprawna!"<<endl;
	Statystyki.poprawna++;
      }else{
	cout<<"Blad. Prawidlowym wynikiem jest: " << oblicz(WyrZ_PytanieTestowe)<<endl;
	Statystyki.bledna++;
      }

    }else{
      cout<< "Niepoprawny zapis liczby zespolonej po raz trzeci."<<endl;
      Statystyki.bledna++;
    }

    cin.clear();
    cin.ignore(10000,'\n');
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
  cout << "Ilosc dobrych odpowiedzi: " << Statystyki.poprawna << endl;
  cout << "Ilosc blednych odpowiedzi: " << Statystyki.bledna << endl;
  Statystyki.procent = (Statystyki.poprawna/(Statystyki.poprawna+Statystyki.bledna))*100;
  cout << "Wynik procentowy poprawnych odpowiedzi: " << Statystyki.procent << '%' << endl;
  

}
