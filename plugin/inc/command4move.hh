#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "command.hh"

/*!
 * \file
 * \brief Definicja klasy Command4Move
 *
 * Plik zawiera definicję klasy Command4Move ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego ruch do przodu
 *
 *  
 */
class Command4Move: public Command {
 /*!
   * \brief Pole przechowujace zadana predkosc liniowa.
   */
  double speed;
  /*!
   * \brief Poleprzechowujace zadany dystans do przejechania.
   */
  double dist;

 public:

  /*!
   * \brief Konstruktor polecenia Move
   */
  Command4Move(); 
  /*!
   * \brief Wypisuje zadana komende Movexs
   *
   * Wyswietla nazwe Move i wartosci parametrow ruchu
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wypisuje skladnie polecenia  Movexs
   *
   * Wyswietla nazwe i skladnie polecenia Move
   */
  virtual void PrintSyntax() const;
  /*!
   * \brief Zwraca nazwe komendy - Move
   *
   * Zwraca wskaznik do napisu Move
   */
  virtual const char* GetCmdName() const;
  /*!
   * \brief Wykonuje polecenie Move
   *
   *\retval true - jezeli operacja zakonczyla sie powodzeniem
   *\retval false - w przypadku przeciwnym
   */
  virtual bool ExecCmd( RobotPose  *pRobPose  ) const;
  /*!
   * \brief Czyta parametry ruchu
   *
   * Wczytuje z ciagu tekstowego liste parametrow dla polecenia Move
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
  /*!
   * \brief Metoda powodująca utworzenie obiektu klasy Command4Move. 
   */
  static Command* CreateCmd();
 };

#endif
