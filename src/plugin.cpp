#include <iostream>
#include <dlfcn.h>
#include <cassert>


#include "plugin.hh"

using namespace std;

 /*!
   * \brief Metoda inicjalizujaca wtyczke na podstawie biblioteki.
   */
bool Plugin::Init(const char* LibName){
    
    void *pFun; 
    Command *(*pCreateCmd)(void);
      
    void *pLibHnd = dlopen( LibName ,RTLD_LAZY);

    if (!pLibHnd) {
      cerr << "!!! Brak biblioteki:" << LibName << endl;
      return false;
    }
  
    pFun = dlsym(pLibHnd,"CreateCmd");
    if (!pFun) {
      cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
      return false;
    }
    
    pCreateCmd = *reinterpret_cast<Command* (**)(void)>(&pFun);
    _pCmd =  pCreateCmd();
    cout<<"Udalo sie storzyc Plugin na dpostawie biblioteki "<<LibName<<endl;
    
    _pHandler = pLibHnd;
    return true;
  }

/*!
   * \brief Destruktor. 
   */
Plugin::~Plugin(){ 
  string nazwa_usiniecia;
  nazwa_usiniecia =static_cast<string>( _pCmd->GetCmdName() );
  
  delete this->_pCmd; 
  
  dlclose(this->_pHandler);
  
  cout<<"Usunieto wtyczke "<<nazwa_usiniecia<<"."<<endl;
  
}

