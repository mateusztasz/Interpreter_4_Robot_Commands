#include <iostream>
#include "command4turn.hh"

#include <unistd.h>
#include <cmath>
using namespace std;

extern "C" {
  Command* CreateCmd(void);
}




/*!
* \brief Funkcja powodująca wywołanie metody powodującej utworzenie wtyczki Turn.
*Jest ona kompilowana za pomoca kompilatora jezyka C
 */
Command* CreateCmd(void){
  return Command4Turn::CreateCmd();
}


/*!
 *\brief Konstruktor polecenia Turn
 */
Command4Turn::Command4Turn(){
  speed = 0;
  dist = 0;
  radius = 0;
}


/*!
 *\brief Wypisuje zadana komende Turn
 */
void Command4Turn::PrintCmd() const{
  cout<<"   "<< GetCmdName() << " " << speed  << " ";
  cout<< dist << " " << radius << endl;
}


/*!
 *\brief Zwraca nazwe komendy - Turn
 */
const char* Command4Turn::GetCmdName() const{
  return "Turn";
}


/*!
 *\brief Wykonuje polecenie Turn
 */
 bool Command4Turn::ExecCmd( RobotPose     *pRobPose ) const{
   
   pRobPose->SetOperation(TO_neutralna);
   double x_actual,y_actual,alpha_actual;	
     
   //Pobierz aktualna pozycje
   pRobPose->Get(x_actual, y_actual, alpha_actual);
   
   //Wspolrzedne srodka okregu
   double x_o = x_actual - radius*sin(M_PI - alpha_actual);
   double y_o = y_actual - radius*cos(M_PI - alpha_actual);
   
   double sgn=0;
   if(speed != 0) sgn = speed/ abs(speed);
   
   //Wartosc kroku 
   double s_diff =  dist/100;
   //if((s_diff < 0.2) && (s_diff != 0) ) s_diff = 0.2;
   
   //Polozenie poczatkowe
   double s_o  = alpha_actual;
   
   //Wartosc przebytej sciezki
   double s=0;
   
   double e = sgn*(dist -s); ;
   
   while( ! (sgn*e < 0.01)  ){	//Dopoki jestem daleko od celu
     
     s=s+s_diff; //Nowa wartosc przebytej sciezki
     
     
     
     //Oblicz nowe polozenie s,y
     x_actual = radius*sin(s_o+sgn*s/radius)+x_o;
     y_actual = -radius*cos(s_o+sgn*s/radius)+y_o;
       
     //Ustal orientacje i przesun sie 
     pRobPose->Set(x_actual  , y_actual,s_o + sgn*s/radius); 
     
     //Wylicz blad polozenia					    
     e = sgn*(dist -s);
       
     //Czekaj tyle ile trwa wykonanie kroku
     usleep(s_diff/ abs(speed)* 1000000);
       
   }
   
 
 
   cout<<endl<<"Ruch zostal zrealizowany poprawnie z bledem polozenia "<<e<<" mm."<<endl;


 return true;
 }

/*!
 *
 */
bool Command4Turn::ReadParams(std::istream& Strm_CmdsList){
  /*
   *  Tu trzeba napisać odpowiedni kod.
   */
  Strm_CmdsList >> speed;
  Strm_CmdsList >> dist;
  Strm_CmdsList >> radius;
  if(Strm_CmdsList.fail()){
    cout << endl;
    cout << "Wczytanie parametrow dla polecenia "<< GetCmdName();
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
 
  if(radius == 0 ) {
    cout<<endl;
    cout<<"Parametr krzywizny okgregu w poleceniu "<<GetCmdName();
    cout<<" ma bledna  wartosc. Wykryto "<<radius<<endl;
    cout<<endl;
    return false;
  }
 if( dist != 0 && speed ==0){
   cout<<endl;
   cout<<"W skladni dla polecenia "<<GetCmdName();
   cout<<" wystepuje blad. Zadana predkosc wynosi zero,";
   cout<<" a dlugosc drogi jest niezerowa.";
   cout<<" Ruch nie moze zostac zrealizowany."<<endl;
   cout<<endl;
     return false;
  
 }

  return true;
  
}


/*!
 *\brief Metoda powodująca utworzenie obiektu klasy Command4Turn. 
 */
Command* Command4Turn::CreateCmd(){
  return new Command4Turn();
}


/*!
 *\brief Wypisuje skladnie polecenia Turn
 */
void Command4Turn::PrintSyntax() const{
  cout <<endl<< "   Turn  speed[mm/s] dist[mm] radius[mm]" << endl;
}
