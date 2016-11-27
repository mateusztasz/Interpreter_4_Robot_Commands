#ifndef PLUGIN_HH
#define PLUGIN_HH


#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "command.hh"

using namespace std;
/*!
 * \file
 * \brief Definicja klasy Plugin
 *
 * Plik zawiera definicję klasy Plugin ...
 */



/*!
 * \brief Modeluje wtyczke
 *
 *  Klasa modeluje wtyczke niezbedna do wykonania ruchu
 */
class Plugin {
public:
  /*!
   * \brief Wskaznik z dostepem do biblioteki
   */
  void* _pHandler;
  
  /*!
   * \brief Wskaznik na interesujacy nas obiekt  
   */
  Command* _pCmd;
  
  /*!
   * \brief Modeluje komende tworzaca obiekt odpowiedniefo typu  
   */
  Command *(*s_Move)(void);
  
  
  /*!
   * \brief Metoda inicjalizujaca wtyczke na podstawie biblioteki.
   * \param LibName -  okresla nazwe biblioteki
   * \retval true - Gdy sukces
   * \retval false - Gdy porażka  
   */  
  bool Init(const char* LibName );
  
  /*!
   * \brief Destruktor. 
   */
  ~Plugin();
  
};


#endif
