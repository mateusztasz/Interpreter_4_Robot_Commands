#include <iostream>
#include "command4rotate.hh"

#include <unistd.h>
#include <cmath>

using namespace std;

extern "C" {
  Command* CreateCmd(void);
}




/*!
 * \brief Funkcja powodująca wywołanie metody powodującej utworzenie wtyczki Rotate.
 * Jest ona komilowana za pomoca kompilatora jezyka C
 */
Command* CreateCmd(void){
  return Command4Rotate::CreateCmd();
}


/*!
 *\brief Konstruktor polecenia Rotate
 */
Command4Rotate::Command4Rotate(){
  ang_speed = 0;
  ang = 0;
}


/*!
 * \brief Wypisuje zadana komende Rotate
 */
void Command4Rotate::PrintCmd() const{
  cout<<"   " << GetCmdName() << " " << ang_speed << " " << ang << endl;
}


/*!
 *\brief Zwraca nazwe komendy - Rotate
 */
const char* Command4Rotate::GetCmdName() const{
  return "Rotate";
}


/*!
 *\brief Wykonuje polecenie Rotate
 */
bool Command4Rotate::ExecCmd( RobotPose     *pRobPose ) const{
  pRobPose->SetOperation(TO_neutralna);

  double ang_speed_rad = ang_speed*2*M_PI/360;
  double ang_rad = ang*2*M_PI/360;
  
  double sgn=0;
  if(ang_speed_rad != 0) sgn = ang_speed_rad/ abs(ang_speed_rad);
  
  double alpha_actual;	
  pRobPose->GetAlpha( alpha_actual); 
  
  
  double alpha_target = alpha_actual + sgn*ang_rad;
  double alpha_diff = alpha_target - alpha_actual;
  double delta_alpha =  alpha_diff /100;
  // if(abs(delta_alpha) < 0.01 && delta_alpha != 0 ) delta_alpha = sgn*0.01;
  
  double	e_alpha = sgn*(alpha_target - alpha_actual);
  
  
  while( ! ( e_alpha < 0.01) ){//Dopoki jestem daleko od celu
    
    pRobPose->SetAlpha(alpha_actual + delta_alpha); //Przesun sie o krok
    usleep(sgn*delta_alpha/ abs(ang_speed_rad) * 1000000);										//Poczekaj chwile
    
    pRobPose->GetAlpha( alpha_actual); 					//Pobierz aktualna konfiguracje
    //Wylicz nowy blad polozenia
    e_alpha = sgn*(alpha_target - alpha_actual);
    
  }
  
  cout<<endl;
  cout<<"Ruch zostal zrealizowany poprawnie z bledem polozenia ";
  cout<<e_alpha*2*M_PI/360<<" degree."<<endl;
  
 
  return true;
}


/*! 
 *\brief Czyta parametry ruchu
 */
bool Command4Rotate::ReadParams(std::istream& Strm_CmdsList){
  Strm_CmdsList >> ang_speed;
  Strm_CmdsList >> ang;
  if(Strm_CmdsList.fail()){
    cout << endl;
    cout<< "Wczytanie parametrow dla polecenia "<< GetCmdName();
    cout <<" nie powiodła się."<< endl;
    cout << endl;
    return false;
  }
  if(ang < 0 ) {
    cout<<endl;
    cout<<"Parametr dlugosc drogi w poleceniu "<<GetCmdName();
    cout<<" ma ujemna wartosc. Wykryto "<<ang<<endl;
    cout<<endl;
    return false;
  }	
  
  
  if( ang != 0 && ang_speed == 0  ){
    cout<<endl;
    cout<<"W skladni dla polecenia "<<GetCmdName();
    cout<<" wystepuje blad. Zadana predkosc katowa wynosi zero, a ";
    cout<<"kat obrotu jest niezerowy. Ruch nie moze zostac zrealizowany."<<endl;
    cout<<endl;
    return false;
  }
  return true;
}


/*!
 *\brief Metoda powodująca utworzenie obiektu klasy Command4Rotate. 
 */
Command* Command4Rotate::CreateCmd(){
  return new Command4Rotate();
}


/*!
 *\brief Wypisuje skladnie polecenia Rotate
 */
void Command4Rotate::PrintSyntax() const{
  cout <<endl<< "   Rotate  ang_speed[deg/s] ang[deg]" << endl;
}
