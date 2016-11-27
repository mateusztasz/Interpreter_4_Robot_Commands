#ifndef ZBIOR_PLUGINOW_HH
#define ZBIOR_PLUGINOW_HH

#include <iostream>
#include <map>
#include <utility>
#include "plugin.hh"



using namespace std;
/*!
 * \file
 * \brief Definicja klasy ZbiorPluginow
 *
 * Plik zawiera definicję klasy ZbiorPluginow ...
 */



/*!
 * \brief Modeluje wtyczke ZbiorPluginow.
 *
 *  Klasa modeluje zespol stworzony z kilku pluginow.
 */
class ZbiorPluginow{
public:
  /*!
   * \brief Pole okreslajace odwzorowanie pomiedzy nazwa plginu a faktycznym obiektem.
   */
  std::map<string, Plugin*> mymap;
  
  /*!
   * \brief Metoda dodaje plugin.
   * \param nazwa - okresla nazwe biblioteki z ktorej powstanie plugin 
   * \retval true - W sytuacji powodzenia
   * \retval false - Gdy porazka
   */
  bool DodajPlugin(const string nazwa);
 
 /*!
   * \brief Metoda usuwajaca plugin.
   * \param nazwa - okresla nazwe pluginu do usuniecia 
   * \retval true - W sytuacji powodzenia
   * \retval false - Gdy porazka
   */
  bool UsunPlugin(const string nazwa);
   
/*!
   * \brief Dekonstuktor.
   */
  ~ZbiorPluginow();
};

#endif
