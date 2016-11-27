#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "command.hh"

/*!
 * \file
 * \brief Definicja klasy Command4Grasper
 *
 * Plik zawiera definicję klasy Command4Grasper ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza prace manipulatora
 *
 *  Klasa modeluje ...
 */
class Command4Grasper: public Command {
/*!
   * \brief Pole przechwyjace stan chwytaka.
   */
  bool  grab;

 public:
  /*!
   * \brief Konstruktor polecenia Grasper
   */
  Command4Grasper();  
  /*!
   * \brief Wypisuje zadana komende Grasper
   *
   * Wyswietla nazwe Grasper i stan chwytaka
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wypisuje skladnie polecenia Grasper
   *
   * Wyswietla nazwe i skladnie polecenia Grasper
   */
  virtual void PrintSyntax() const;
    /*!
   * \brief Zwraca nazwe komendy - Grasper
   *
   * Zwraca wskaznik do napisu Grasper
   */
  virtual const char* GetCmdName() const;
  /*!
   * \brief Wykonuje polecenie Grasper
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
   * \brief Metoda powodująca utworzenie obiektu klasy Command4Grasper. 
   */
  static Command* CreateCmd();
 };

#endif
