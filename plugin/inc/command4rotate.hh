#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "command.hh"

/*!
 * \file
 * \brief Definicja klasy Command4Rotate
 *
 * Plik zawiera definicję klasy Command4Rotate ...
 */

/*!
 * \brief Modeluje polecenie dla robota mobilnego, które wymusza jego obrot wokol wlasnej osi
 *
 *  Klasa modeluje ...
 */
class Command4Rotate: public Command {
   /*!
   * \brief Pole przechowujace zadana predkosc katowa
   */
  double  ang_speed;
  /*!
   * \brief Pole przechowujace zadany kat obrotu
   */
  double  ang;
 public:
  /*!
   * \brief Konstruktor polecenia Rotate
   */
  Command4Rotate();  
  /*!
   * \brief Wypisuje zadana komende Rotate
   *
   * Wyswietla nazwe Rotate i wartosci parametrow ruchu
   */
  virtual void PrintCmd() const;
  /*!
   * \brief Wypisuje skladnie polecenia Rotate
   *
   * Wyswietla nazwe i skladnie polecenia Rotate
   */
  virtual void PrintSyntax() const;
  /*!
   * \brief Zwraca nazwe komendy - Rotate
   *
   * Zwraca wskaznik do napisu Rotate
   */
  virtual const char* GetCmdName() const;
  /*!
   * \brief Wykonuje polecenie Rotate
   *
   *\retval true - jezeli operacja zakonczyla sie powodzeniem
   *\retval false - w przypadku przeciwnym
   */
  virtual bool ExecCmd( RobotPose  *pRobPose  ) const;
  /*!
   * \brief Czyta parametry ruchu
   *
   * Wczytuje z ciagu tekstowego liste parametrow dla polecenia Rotate
   */
  virtual bool ReadParams(std::istream& Strm_CmdsList);
   /*!
   * \brief Metoda powodująca utworzenie obiektu klasy Command4Rotate. 
   */
  static Command* CreateCmd();
 };

#endif
