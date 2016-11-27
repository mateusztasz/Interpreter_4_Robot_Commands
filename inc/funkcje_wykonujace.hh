#ifndef FUNKCJE_WYKONUJACE_HH
#define FUNKCJE_WYKONUJACE_HH

#include <iostream>
#include <string>
#include <sstream>


#include "ZbiorPluginow.hh"
#include "RobotMobilny.hh"
#include "lacze_do_gnuplota.hh"

#include "Scene.hh"
#define LINE_SIZE 500
/*!
 * \file
 * \brief Definicja funkcji wykonujacych glowne zadanie w programie
 *
 */



/*!
 * \brief Funkcja przygotowuje struktury do przeczytania pliku z komendami przez preprocessor
 
 Funkcja tworzy obiekt typu istringstream i wysyla go razem z plikiem wejsciowym do funkjci ExecPreProcessor. Sprawdza poprwnosc przetworzenia
 
 \param Nazwa_Pliku - okresla nazwe pliku wejsciowego z komendami
 \retval false - Gdy porazka
 \retval Wykonaj(Strm_Polecen,Zb) - Gdy sukces.
 
 */
bool WykonajPlik(const string Nazwa_Pliku, ZbiorPluginow &Zb,Scene &Scn);

/*!
 * \brief Funkcja uruchamia preprocessor#
 * 
 *  Uruchamia proces do czytania pliku wejsciowego i wpisuje zawartosc do strumienia wejsciowego
 *\param Nazwa_Pliku - okresla plik wejsciowy komend dla interpretera
 \param IStrm4Cmds - okresla strumien wejsciowy do ktorego zostanie zapisany plik z komendami 
 */
bool ExecPreProcessor(const string NazwaPliku, istringstream &IStrm4Cmds);


/*!
 * \brief Funkcja realizuje zadanie ruchu
 * 
 Funkcja realizuje zadanie ruchu przez robota. Odpowiada rowniez za wizualizacje ruchu w progrmaie gnuplot 
 \retval true - Gdy sukces.
 \retval false - Gdy porazka.
 */
bool Wykonaj(istream & StrmWe,ZbiorPluginow &Zb,Scene &Scn);


#endif

