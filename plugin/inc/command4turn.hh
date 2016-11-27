#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "command.hh"

/*!
 * \file
 * \brief Definicja klasy Command4Turn
 *
 * Plik zawiera definicję klasy Command4Turn ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch po okregu
 *
 *  Klasa modeluje ...
 */
class Command4Turn: public Command {
/*!
   * \brief Pole przechwyjace zadana predkosc liniowa.
   */
  double  speed;
  /*!
   * \brief Pole przechowujace zadany dystans. 
   */
  double  dist;
  /*!
   * \brief Poleprzechowujace promien okregu po kotrym odbywa sie ruch.
   */
  double  radius;

 public:
  /*!
   * \brief Konstruktor polecenia Turn
   */
  Command4Turn();  
  /*!
   * \brief Wypisuje zadana komende Turn
   *
   * Wyswietla nazwe Turn i wartosci parametrow ruchu
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wypisuje skladnie polecenia Turn
   *
   * Wyswietla nazwe i skladnie polecenia Turn
   */
  virtual void PrintSyntax() const;
    /*!
   * \brief Zwraca nazwe komendy - Turn
   *
   * Zwraca wskaznik do napisu Turn
   */
  virtual const char* GetCmdName() const;
  /*!
   * \brief Wykonuje polecenie Turn
   *
   *\retval true - jezeli operacja zakonczyla sie powodzeniem
   *\retval false - w przypadku przeciwnym
   */
  virtual bool ExecCmd( RobotPose  *pRobPose  ) const;
  /*!
   * \brief Czyta parametry ruchu
   *
   * Wczytuje z ciagu tekstowego liste parametrow dla polecenia Turn
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief Metoda powodująca utworzenie obiektu klasy Command4Turn. 
   */
  static Command* CreateCmd();
 };

#endif
