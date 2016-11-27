#include "funkcje_wykonujace.hh"
#include <errno.h>


/*!
 * \brief Funkcja uruchamia preprocessor#
 */
bool ExecPreProcessor(const string NazwaPliku, istringstream &IStrm4Cmds){
  string Cmd4Preproc = "cpp -P ";
  char Line[LINE_SIZE];
  ostringstream OTmpStrm;
  Cmd4Preproc += NazwaPliku;

  FILE* pProc = popen(Cmd4Preproc.c_str(),"r");

  if(!pProc) return false;

  while (fgets(Line,LINE_SIZE,pProc)){
    OTmpStrm << Line;
  }
  IStrm4Cmds.str(OTmpStrm.str());
  return pclose(pProc) == 0;
}



/*!
 * \brief Funkcja realizuje zadanie ruchu
 */
bool Wykonaj(istream & StrmWe,ZbiorPluginow &Zb, Scene &Scn){


  map<string, Plugin*>::iterator current; 
  
  string word;
  while( StrmWe >> word ){
    if(StrmWe.fail()){
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

    if(! current->second->_pCmd->ReadParams(StrmWe) ){
      return false;
    }  
    current->second->_pCmd->PrintSyntax();
    current->second->_pCmd->PrintCmd();
     if(! current->second->_pCmd->ExecCmd((Scn.Robot)) ){ 
      return false; 
    }
  
  } 

  return true;
}

/*!
 * \brief Funkcja przygotowuje struktury do przeczytania pliku z komendami przez preprocessor
 */
bool WykonajPlik(const string Nazwa_Pliku, ZbiorPluginow &Zb, Scene &Scn){
  if(Nazwa_Pliku == "") {cout<<"Nie wprowadzono nazwy pliku z komendami."<<endl; return false;}
  istringstream Strm_Polecen;
  if(!ExecPreProcessor(Nazwa_Pliku,Strm_Polecen))
    return false;
  return Wykonaj(Strm_Polecen,Zb,Scn);
}

