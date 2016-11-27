#ifndef SCENE_HH
#define SCENE_HH
#include <string>
#include <list>
#include <iostream>
using namespace std;



#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sstream>
#include <cstdlib>


#include "RobotMobilny.hh"


#include "MojeLaczeDoGNUplota.hh"
#include "Obiekt.hh"


/*!
 * \file
 * \brief Definicja klasy Scene
 *
 * Plik zawiera definicję klasy Scene
 */


/*!
 * \brief Modeluje scene po ktorej porusza sie robot
 */
class Scene {
  
private:
  /*!
   *\brief Obiekt lacza do gnuplota
   *
   *Jest obiektem klasy pochodnej lacze_do_gnuplota. Pozwala na 
   *reimplementowanie metody wirtualnej i dopisywanie komend do rysowania
   *wprost z Polecenia.
   */
  MojeLaczeDoGNUplota Lacze;
   
public:


  /*!
   *\brief Wskaznik na dodany obiekt do sceny
   *Bardzo uzyteczny przy dodawaniu obiektu do sceny
   *z pliku xml.
   */
  Obiekt *pHandler;

  /*!
   *\brief Lista Obiektow na scenie.
   */
  list<Obiekt*>Lst;
  
  /*!
   *\brief Pole Robota na scenie.
   */
  RobotMobilny *Robot;
  
  /*!
   *\brief Metoda dodaje robota do sceny.
   *
   *Metoda twrzy robota jako obiekt dynamiczny i 
   *inicjalizuje jego parametry poczatkowe.
   *
   */
  bool DodajRobotaDoSceny( double &x_p,  
			   double &y_p,
			   double &alpha_p);

  /*!
   *\brief Metoda dodaje obiekt do sceny.
   *
   *Metoda tworzy obiekt jako obiekt dynamiczny i 
   *umieszcza na liscie obiektow.
   *
   */
  bool DodajObiektDoSceny();

  /*!
   *\brief Metoda inicjalizuje ustawienia sceny dla gnuplota
   *
   *Metoda ustawia zakres gnuplota i ustawia robota w jego
   *punkcie poczatkowym.
   *
   */
  bool Init();

  
  /*!
   *\brief Desktuktor sceny
   *
   *Usuwa Robota i wszystkie obiekty z niej.
   */
  ~Scene(); 
};

#endif
