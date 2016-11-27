#include <iostream>
#include "command4move.hh"
#include <unistd.h>
#include <cmath>


using namespace std;


extern "C" {
  Command* CreateCmd(void);
}




/*!
* \brief Funkcja powodująca wywołanie metody powodującej utworzenie wtyczki Move.
* Jest ona kompilowana za pomoca kompilatora jezyka C
 */
Command* CreateCmd(void){
  return Command4Move::CreateCmd();
}


/*!
 *
 */
Command4Move::Command4Move(){
  speed = 0;
  dist = 0;
}


/*!
 * \brief Wypisuje zadana komende Move
 */
void Command4Move::PrintCmd() const{
  cout<<"   " << GetCmdName() << " " << speed  << " " << dist << endl;
}


/*!
 * \brief Zwraca nazwe komendy Move
 */
const char* Command4Move::GetCmdName() const{
  return "Move";
}


/*!
 * \brief Wykonuje polecenie Move
 */
bool Command4Move::ExecCmd( RobotPose     *pRobPose ) const {
  pRobPose->SetOperation( TO_neutralna );
  
  double sgn =0;
  if(speed != 0 ) sgn = speed / abs(speed);
  double x_actual,y_actual,alpha_actual, x_diff, y_diff;	
  
  //Pobierz aktualna pozycje
  pRobPose->Get(x_actual, y_actual, alpha_actual);
  
  //Wylicza roznice polozen we wspolrzednych kartezjanskich
  x_diff = sgn*dist * cos(alpha_actual);
  y_diff = sgn*dist * sin(alpha_actual);
  
  //Wylicza wspolrzedne konca ruchu
  double  x_cel = x_actual + x_diff;    
  double  y_cel = y_actual + y_diff;
  
  int Sgnx=0;
  int Sgny=0;
  double delta_x =0 ;
  double delta_y =0 ;
  if(x_diff != 0 ) delta_x  = x_diff/100;
  if(x_diff != 0 ) Sgnx = x_diff/abs(x_diff);
  if(y_diff != 0 ) delta_y  =  y_diff/100;
  if(y_diff != 0 ) Sgny = y_diff/abs(y_diff);
  // if(abs(delta_x) < 0.1 && delta_x != 0 ) delta_x = Sgnx*0.1;
  //  if(abs(delta_y) < 0.1 && delta_y != 0 ) delta_y = Sgny*0.1;
  
  
  //Wyliczas maly dlugosc ruchu we wsp kartezjanskich
  double delta_s = sqrt(delta_x*delta_x + delta_y*delta_y);
    
  //Wylicza blad polozenia
  double e_x = Sgnx*(x_cel - x_actual);
  double e_y = Sgny*(y_cel - y_actual);
  double e = sqrt(e_x*e_x + e_y*e_y);
  double x,y;
  while( ! (e_x < 0.01 && e_y < 0.01) ){	//Dopoki jestem daleko od celu
    
    x =   x_actual + delta_x;
    y =  y_actual + delta_y;
    
    pRobPose->Set(x,y); //Przesun sie o krok
    
    pRobPose->Get(x_actual, y_actual, alpha_actual);			
    
    //Wylicz nowy blad polozenia
    e_x = Sgnx*(x_cel - x_actual);		  		
    e_y = Sgny*(y_cel - y_actual);
    e = sqrt(e_x*e_x + e_y*e_y);
    
    usleep(delta_s / abs(speed) * 1000000);	
  }
  
  
  cout<<endl<<"Ruch zostal zrealizowany poprawnie z bledem polozenia ";
  cout<<e<<" mm."<<endl;
  
  
  return true;
}


/*!
 *
 */
bool Command4Move::ReadParams(std::istream& Strm_CmdsList){
  
  Strm_CmdsList >> speed;
  Strm_CmdsList >> dist;
  if(Strm_CmdsList.fail()){
    cout << endl;
    cout<< "Wczytanie parametrow dla polecenia "<< GetCmdName();
    cout <<" nie powiodła się."<< endl;
    cout << endl;
    return false;
  }
  if(dist < 0 ) {
    cout<<endl;
    cout<<"Parametr dlugosc drogi w poleceniu "<<GetCmdName();
    cout<<" ma ujemna wartosc. Wykryto "<<dist<<endl;
    cout<<endl;
    return false;
  }
  
  if( dist != 0  && speed == 0){
    cout<<endl;
    cout<<"W skladni dla polecenia "<<GetCmdName();
    cout<<" wystepuje blad. Zadana predkosc wynosi zero, a odleglosc jest";
    cout<<" niezerowa. Ruch nie moze zostac zrealizowany."<<endl;
    cout<<endl;
    return false;
  }
  
  return true;
}


/*!
 * \brief Metoda powodująca utworzenie obiektu klasy Command4Move.
 */
Command* Command4Move::CreateCmd(){
  return new Command4Move();
}


/*!
 * \brief Wypisuje skladnie polecenia Move
 */
void Command4Move::PrintSyntax() const{
  cout <<endl<< "   Move speed[mm/s] dist[mm/s]" << endl;
}
