#ifndef  COMMAND_HH
#define  COMMAND_HH

#include <iostream>
#include "robotpose.hh"
#include <iomanip>
/*!
 * \file
 * \brief Definicja klasy Command
 *
 * Plik zawiera definicję klasy Command ...
 */

/*!
 * \brief Modeluje abstrakcyjne polecenie dla robota mobilnego
 *
 *  Klasa modeluje ...
 */
 class Command {
  public:
   /*!
    * \brief Destruktor wirtualny ze wzgledu na klasy pochodne
    *
    *  
    */
   virtual ~Command() {}
   /*!
    * \brief Abstrakcyjne pojecie wypisania komendy
    */
   virtual void PrintCmd() const = 0;
   /*!
    * \brief Abstrakcyjne pojecie wypisania skladni
    */
   virtual void PrintSyntax() const = 0;
   /*!
    * \brief Abstrakcyjne pojecie zwrocenia wskaznika na nazwe
    */
   virtual const char* GetCmdName() const = 0;
   /*!
    * \brief Abstrakcyjne polecie wykonania zadania
    */
   virtual bool ExecCmd(  RobotPose  *pRobPose  ) const = 0;
   /*!
    * \brief Abstrakcyjne pojecie czytania parametrow
    */
   virtual bool ReadParams(std::istream& Strm_CmdsList) = 0;
 };

#endif
