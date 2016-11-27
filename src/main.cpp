/*
$HeadURL:
$Author:
$Date:
$Revision:
 */
#include <iostream>
#include <string>

#include "funkcje_dla_menu.hh"
#include "ZbiorPluginow.hh"
#include "funkcje_wykonujace.hh"
#include "Scene.hh"
#include "xmlparser4scene.hh"

#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;


int main(){
  
  Scene Scn;
  
  if (!ReadFile("opis_sceny.xml",Scn)) return 1;
  
  Scn.Init();
  
  ZbiorPluginow Zb;
  
  Zb.DodajPlugin("command4turn.so");
  Zb.DodajPlugin("command4rotate.so");
  Zb.DodajPlugin("command4move.so");
  Zb.DodajPlugin("command4grasper.so");

  string Nazwa_Pliku = "";
  
  string Opcja="?";

  char *sLiniaPolecenia;
  const char* sZacheta = "Twoj wybor (? -menu)>";

  rl_bind_key('\t',rl_complete);


    while(Opcja!= "k"){

    if(Opcja == "w"){
      cout<<endl<<"Wprowadz nazwe pliku."<<endl;
      cin>> Nazwa_Pliku;
    }
    else if(Opcja == "p"){
      PokazSekwencjeInstrukcji(Zb,Nazwa_Pliku);
    }    
    else  if(Opcja == "i"){
      PokazDostepneWtyczki(Zb);
    }  
    else if(Opcja == "s"){
      if(Nazwa_Pliku != "") {
	WykonajPlik(Nazwa_Pliku,Zb,Scn); 	
      }
      else cout<<"Nie wprowadzono nazyw pliku z komendami."<<endl;
    }
    else if(Opcja == "a"){ 
      DodajNowaWtyczke(Zb);
    }  
    else if(Opcja == "d"){
      UsunWtyczke(Zb);
    }   
    else if(Opcja == "?"){
      WyswietlMenu();
    }
    else cout<<"Nie poprawna opcja "<<Opcja<<"."<<endl;
    
    
    sLiniaPolecenia = readline(sZacheta);
    if(!sLiniaPolecenia) return 0;
    add_history(sLiniaPolecenia);
    Opcja = static_cast<string>(sLiniaPolecenia);
    free(sLiniaPolecenia);
    
    }
    
    return 0;
  
}      
