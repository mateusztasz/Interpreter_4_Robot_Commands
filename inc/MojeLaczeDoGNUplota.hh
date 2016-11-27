#ifndef MOJELACZEDOGNUPLOTA_HH
#define MOJELACZEDOGNUPLOTA_HH
#include <iostream>
#include <string>

using namespace std;

#include "lacze_do_gnuplota.hh"
#include "Obiekt.hh"

/*!
 * \file
 * \brief Definicja klasy MojeLaczeDoGNUplota
 *
 * Plik zawiera definicję klasy MojeLaczeDoGNUplota ...
 */


/*!
 * \brief Modeluje Lacze do gnu plota
 *
 *  Klasa dziedziczy z klasy LaczaDoGNUPlota
 */
class MojeLaczeDoGNUplota : public  PzG::LaczeDoGNUPlota {
  
private:
  /*!
   *\brief Metoda odpowiada za rysowanie obiektow na scenie
   *
   *Metoda jest wykorzystana do rysowania punktow na scenie za pomoca Polecenia.
   *W tym celu wykorzystuje opcje w gnuplocie >echo
   */
  virtual bool DopiszWlasnePolecenieDoRysowania( std::string &Polecenie, char const **Sep );
  
public:
  
  list<Obiekt*> Lst_DlaLacza;
};

#endif
