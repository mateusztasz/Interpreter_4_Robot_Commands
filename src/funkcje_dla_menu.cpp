#include <iostream>
#include "funkcje_dla_menu.hh"

using namespace std;

/*!
 * \brief Modeluje wyglad menu 
 */
void WyswietlMenu(){
  cout<<endl<< "w - wczytanie nazwy pliku sekwencji intrukcji dla robota"<<endl
      <<"p - pokaz sekwencje intrukcji"<<endl
      <<"i - pokaz dostepne intrukcje/wtyczki"<<endl
      <<"s - start wykonywania sekwencji intrukcji"<<endl
      <<"a - dodaj nowa wtyczke"<<endl
      <<"d - usun wtyczke"<<endl
      <<"? - wyswietl ponownie menu"<<endl
      <<endl
      <<"k - koniec dzialania programu"<<endl<<endl; 
}

/*!
 * \brief Funkcja wyswietla sekwencje instrukcji na standardowym wyjsciu.
 */
bool PokazSekwencjeInstrukcji(ZbiorPluginow &Zb,const string Nazwa_Pliku ){

  map<string, Plugin*>::iterator current; 

  if(Nazwa_Pliku == "") {
    cout<<endl<<"Wczytany plik ,,"<<Nazwa_Pliku<<"'' nie istnieje"<<endl<<"Wczytaj poprawny plik za pomoca instrukcji ,,w''"<<endl<<endl;
    return false;
  }

  istringstream Is;
  if(!ExecPreProcessor(Nazwa_Pliku,Is) ) {
    return false;
  }
  string word;
  cout<<"Sekwencje dostepnych instrukcji:"<<endl;
  

    while( Is >> word ){
    if(Is.fail()){
      cout<< "Wczytanie danych nie powiodło się."<<endl;
      return false;
    }
    
    current = Zb.mymap.find( word );
    if (current == Zb.mymap.end()){
      cerr<<endl;
      cout<<"W pliku komend jest blad."<<endl;
      cout<<"Komenda "<<word<<" nie istnieje w slowniku"<<endl;
      cout<<endl;
      return false;	
    }
    if(! current->second->_pCmd->ReadParams(Is) ){
      return false;
    }  
    current->second->_pCmd->PrintCmd();
    }
  // while(getline(Is,word))
  //  cout<<word<<endl;   
  
  return true;
}


/*!
 * \brief Funkcja wyswietla dostepne wtyczki na standardowym wyjsciu
 */
void PokazDostepneWtyczki(ZbiorPluginow &Zb){
     map<string, Plugin*>::iterator curr; 
      curr = Zb.mymap.begin();

      cout<<"Aktualnie dostepne wtyczki to:"<<endl;
      
      for(unsigned int i = 0; i < Zb.mymap.size() ; i++){
	cout<<">> "<<curr->second->_pCmd->GetCmdName()<<endl;
	curr++;
      }
      cout<<endl;
    }
    

/*!
 * \brief Funkcja dodaje nowa wtyczke do Zbioru Pluginow
 */    
 void DodajNowaWtyczke(ZbiorPluginow &Zb){
      cout<<"Możesz dodac nastepujace wtyczki:"<<endl;
      cout<<"command4move.so"<<endl;
      cout<<"command4rotate.so"<<endl;
      cout<<"command4turn.so"<<endl;
      cout<<"command4grasper.so"<<endl;
      cout<<endl;

      string NazwaDodanejWtyczki;
      cin>>NazwaDodanejWtyczki;
      Zb.DodajPlugin(NazwaDodanejWtyczki) ;
    }
    
/*!
 * \brief Funkcja usuwa wtyczke ze zbioru plugonow.
 */
bool UsunWtyczke(ZbiorPluginow &Zb){
  cout<<"Ktora wtyczke chcesz usunac sposrod istniejacych?"<<endl;
  cout<<endl;
  string NazwaPluinuDoUsuniecia;
  cin>>NazwaPluinuDoUsuniecia;
  if(! Zb.UsunPlugin(NazwaPluinuDoUsuniecia) ){
    cout<<"Nie udalo sie usunac wtyczki "<<NazwaPluinuDoUsuniecia<<"."<<endl;
    return false;
  }
  cout<<"Usuwanie wtyczki  "<<NazwaPluinuDoUsuniecia<<" zakonczone sukcesem."<<endl;
  return true;
  
}

