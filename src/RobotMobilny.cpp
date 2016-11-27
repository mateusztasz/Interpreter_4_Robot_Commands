
#pragma implementation
#include "RobotMobilny.hh"
#include <cassert>
#include <cmath>

using namespace std;

#define NAZWA_PLIKU_SCIEZKA_ROBOTA  "./pliki_danych/sciezka_robota.dat"
#define NAZWA_PLIKU_POZYCJA_ROBOTA  "./pliki_danych/pozycja_robota.dat"



#define ROZMIAR_ROBOTA              4

#include <iomanip>
#include <fstream>
#include <limits>
#include <cmath>
#include <unistd.h>


#include "funkcje_wykonujace.hh"
#include "Scene.hh"
/*!
 *\brief Konstruktor
 */
RobotMobilny::RobotMobilny( MojeLaczeDoGNUplota *pPlotter): _pPlotter(pPlotter)
 {
   assert( pPlotter != nullptr );
   _GrasppedObject = nullptr;
 }


/*!
 * \brief Zapisz wspolrzedne do pliku
 * \retval true - jeśli operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool RobotMobilny::WriteCoord(double &x_mm, double &y_mm)
{
  // double  x_mm, y_mm,
double angle;

// Get(x_mm,y_mm);
  GetAlpha(angle);

  _Strm4Path.open(NAZWA_PLIKU_SCIEZKA_ROBOTA,ios::app);
  if (!_Strm4Path.is_open()) {
    cerr << "! Blad otwarcia pliku: " << NAZWA_PLIKU_SCIEZKA_ROBOTA << endl;
    return false;
  }
  
  if (!(_Strm4Path << x_mm << " " << y_mm << endl)) {
    cout << "! Blad zapisu do pliku: " << NAZWA_PLIKU_SCIEZKA_ROBOTA << endl;
    return false;
  }
  _Strm4Path.close();
  
  ofstream  Strm4Position(NAZWA_PLIKU_POZYCJA_ROBOTA);
  if (!Strm4Position.is_open()) {
    cerr << "! Blad otwarcia do zapisu pliku: " << NAZWA_PLIKU_POZYCJA_ROBOTA << endl;
    return false;
  }
  if (!(Strm4Position << x_mm << " " << y_mm << endl)) {
    cerr << "! Blad zapisu do pliku: " << NAZWA_PLIKU_POZYCJA_ROBOTA << endl;
    return false;
  }
  

  
  ofstream  Strm4Wy("./pliki_danych/obrys_robota.dat");
  ifstream  Strm4We("./pliki_danych/robot_ksztalt.dat");
  if (!Strm4We.is_open()) {
    cerr << "! Blad otwarcia do zapisu pliku: " << "robot_ksztalt.dat" << endl;
    return false;
  }
  if (!Strm4Wy.is_open()) {
    cerr << "! Blad otwarcia do zapisu pliku: " << "obrys_robota.dat" << endl;
    return false;
  }
  
  int x_wzorzec,y_wzorzec;
  do {
    if (Strm4We >> x_wzorzec >> y_wzorzec) {
      Strm4Wy <<( x_wzorzec*cos(angle) - y_wzorzec*sin(angle) + x_mm );
      Strm4Wy<<" ";
      Strm4Wy<<( x_wzorzec*sin(angle) + y_wzorzec*cos(angle) + y_mm );
      Strm4Wy<< endl; 
      continue;
    }
    Strm4We.clear();
    Strm4We.ignore(numeric_limits<int>::max(),'\n');  // Przeskakuje linie
  } while (!Strm4We.eof());
  
  
  return true;
}



/*!
 * \brief Inicjalizuje struktury robota
 * \retval true - jeśli operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool RobotMobilny::Init()
{
  assert( _pPlotter != nullptr );
  double x=0,y=0;
  // Aby usunąć zawartość pliku
  _Strm4Path.open(NAZWA_PLIKU_SCIEZKA_ROBOTA);
  if (!_Strm4Path.is_open()) return false;
  _Strm4Path.close();
  if (!WriteCoord(x,y)) return false;
  _Strm4Path.close();
  
  _pPlotter->DodajNazwePliku(NAZWA_PLIKU_SCIEZKA_ROBOTA);

  _pPlotter->DodajNazwePliku("./pliki_danych/obrys_robota.dat",PzG::RR_Ciagly,2);

  //_pPlotter->DodajNazwePliku("./pliki_danych/Obiekty_poz.dat",PzG::RR_Punktowy);

  _pPlotter->Rysuj();
  return true;
}


/*!
 \brief Rysuj skoro zmieniono polozenie robota
 */
bool RobotMobilny::AfterUpdate()
{
  double OdlegloscOdObiektu = 0;
  double Epsilon = 1;
  double x = 0,y = 0;

  Get(x,y);
  
  if( this->GetOperation() == TO_neutralna){
    if (_GrasppedObject != nullptr){
      _GrasppedObject->pos_x = x;
      _GrasppedObject->pos_y = y;
    }
  }
  
  else if( this->GetOperation() == TO_chwycenie){
    for( Obiekt* it:this->_pScene->Lst){  
      OdlegloscOdObiektu = sqrt( pow((it->pos_x - x),2)  + pow((it->pos_y -y),2) );
      if(OdlegloscOdObiektu < Epsilon ) {
	_GrasppedObject = it;
      }
    }
    //Jesli nie chwycono nicze
    if(_GrasppedObject == nullptr){
      cout<<"Nie mozna chwycic zadnego obiektu."<<endl;
      return false;
    }
  }
  
  else if( this->GetOperation() == TO_puszczenie){
    _GrasppedObject = nullptr;
  }
  
  assert( _pPlotter != nullptr );
  if (!WriteCoord(x,y)) return false;

  _pPlotter->Rysuj();
  return true;
}


RobotMobilny::~RobotMobilny(){
  cout<<"Usunieto Robota."<<endl;
}
