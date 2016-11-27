#ifndef FUNKCJE_DLA_MENU_HH
#define FUNKCJE_DLA_MENU_HH

#include <iostream>
#include <string>
#include <map>
#include "plugin.hh"
#include "ZbiorPluginow.hh"
#include "funkcje_wykonujace.hh"
/*!
 * \file
 * \brief Definicje funkcji w menu
 *
 * Plik zawiera definicje funkcji modelujacych funkjconalnosc menu ...
 */


/*!
 * \brief Modeluje wyglad menu 
 */
void WyswietlMenu();

/*!
 * \brief Funkcja wyswietla sekwencje instrukcji na standardowym wyjsciu.
 */
bool PokazSekwencjeInstrukcji(ZbiorPluginow &Zb, const string Nazwa_Pliku );

/*!
 * \brief Funkcja wyswietla dostepne wtyczki na standardowym wyjsciu
 */
void PokazDostepneWtyczki(ZbiorPluginow &Zb);

/*!
 * \brief Funkcja dodaje nowa wtyczke do Zbioru Pluginow. 
 *
 * Jest obudowana wersja dla metody UsunPlugin . Zawira sprawdzenie bledow oraz wypisanie niezbednych informajci dla uzytkownika.
 */
void DodajNowaWtyczke(ZbiorPluginow &Zb);

/*!
 * \brief Funkcja usuwa wtyczke ze zbioru plugonow.
 *
 * Jest obudowana wersja dla metody UsunPlugin . Zawiera sprawdzenie bledow i informacje na temat mozliwosci usniecia. 
 */
bool UsunWtyczke(ZbiorPluginow &Zb);
#endif


