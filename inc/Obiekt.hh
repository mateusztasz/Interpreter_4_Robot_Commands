#ifndef OBIEKT_HH
#define OBIEKT_HH

#include <string>
#include <iostream>


/*!
 * \file
 * \brief Definicja klasy Obiekt
 *
 * Plik zawiera definicję klasy Obiekt
 */


/*!
 *\brief Definiuje obiekt -- przeszkode na scenie
 *
 */
class Obiekt {
public:
/*!
 *\brief Pozycja x obietu
 *
 */
  double pos_x;
  /*!
 *\brief Pozycja y obietu
 *
 */
  double pos_y;
  /*!
 *\brief Rozmiar obietu
 *
 */
  int size;
  /*!
 *\brief Nazwa obietu
 *
 */
  std::string name;
/*!
 *\brief Destruktor obiektu
 *
 */
  ~Obiekt();
};


#endif

