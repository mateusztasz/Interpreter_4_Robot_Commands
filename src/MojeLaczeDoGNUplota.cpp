
#include "MojeLaczeDoGNUplota.hh"

#include <sstream>
#include <fstream>


/*!
 *\brief  Metoda odpowiada za rysowanie obiektow na scenie
 */
bool MojeLaczeDoGNUplota::DopiszWlasnePolecenieDoRysowania( std::string &Polecenie, char const **Sep ){
  /***********************************
   ***ROZWIAZANIE SZYBSZE********
   
  ofstream Wy("./pliki_danych/Obiekty_poz.dat");
  if(Wy.is_open()){
    for( Obiekt* it:Lst_DlaLacza ){
      Wy<<it->pos_x<<" "<<it->pos_y<<endl;
    }
  }
  *************************************** */
  
  for( Obiekt* it:Lst_DlaLacza ){
    
    Polecenie += *Sep;
    Polecenie += " \"";
    Polecenie += "< echo '";
    Polecenie += to_string(it->pos_x);
    Polecenie += " ";
    Polecenie += to_string(it->pos_y);
    Polecenie += "' \" notitle pointtype 5";
    Polecenie += " pointsize ";
    Polecenie += to_string(it->size); 
    
    *Sep = ","; 
  }



  return true;
}
