#include <iostream>
#include "command4grasper.hh"

#include <unistd.h>
#include <cmath>
using namespace std;

extern "C" {
  Command* CreateCmd(void);
}




/*!
* \brief Funkcja powodująca wywołanie metody powodującej utworzenie wtyczki Grasper.
 */
Command* CreateCmd(void){
  return Command4Grasper::CreateCmd();
}


/*!
 *\brief Konstruktor polecenia Grasper
 */
Command4Grasper::Command4Grasper(){
  grab = false;
}


/*!
 *\brief Wypisuje zadana komende Grasper
 */
void Command4Grasper::PrintCmd() const{
  cout<<"   "<< GetCmdName() << " " << grab  << endl;
}


/*!
 *\brief Zwraca nazwe komendy - Grasper
 */
const char* Command4Grasper::GetCmdName() const{
  return "Grasper";
}


/*!
 *\brief Wykonuje polecenie Grasper
 */
 bool Command4Grasper::ExecCmd( RobotPose     *pRobPose ) const{
   bool CzySukces = false;

   if(grab)
    CzySukces = pRobPose->SetOperation(TO_chwycenie);
   else 
    CzySukces = pRobPose->SetOperation(TO_puszczenie);


   usleep(0.5*1000000);

   return CzySukces;
 }

/*!
 *
 */
bool Command4Grasper::ReadParams(std::istream& Strm_CmdsList){
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  Strm_CmdsList >> grab;
  if(Strm_CmdsList.fail()){
    cout << endl;
    cout << "Wczytanie parametrow dla polecenia "<< GetCmdName();
    cout <<" nie powiodła się."<< endl;
    cout << endl;
  }

  if(grab != 1  && grab !=0){
    cout << endl;
    cout << "Prametr stanu chwytaka w poleceniu "<< GetCmdName();
    cout <<" ma nieprawidlowa wartosc.";
    cout<<" Rozpozanno "<<grab<< endl;
    cout << endl;
    return false;
  }  
  
  
  return true;
  
}


/*!
 *\brief Metoda powodująca utworzenie obiektu klasy Command4Grasper. 
 */
Command* Command4Grasper::CreateCmd(){
  return new Command4Grasper();
}


/*!
 *\brief Wypisuje skladnie polecenia Grasper
 */
void Command4Grasper::PrintSyntax() const{
  cout <<endl<< "   Grasper  manipulator state[ 0 / 1]" << endl;
}
