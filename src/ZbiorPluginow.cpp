#include "ZbiorPluginow.hh"
/*!
   * \brief Metoda dodaje plugin.
   */
  bool ZbiorPluginow::DodajPlugin(const string nazwa){
    Plugin *Plug;
    Plug = new Plugin(); 
    Plug->Init(nazwa.c_str());
    
    if(nazwa == "command4rotate.so"){
      mymap["Rotate"] = Plug; 
    }
    
    else if (nazwa == "command4turn.so")
      mymap["Turn"] = Plug; 
    
    else if (nazwa == "command4move.so")
      mymap["Move"] = Plug;   
    
    else if (nazwa == "command4grasper.so")
      mymap["Grasper"] = Plug;   

    return true; 
  }
  
   /*!
   * \brief Metoda usuwajaca plugin.
   */
bool ZbiorPluginow::UsunPlugin(const string nazwa){
   map<string, Plugin*>::iterator curr; 
  curr = mymap.find( nazwa );

    if (curr == mymap.end()){
      cerr<<endl;
      cout<<"Wtyczka o nazwie "<<nazwa<<" nie istnieje w systemie"<<endl;
      cout<<endl;
      return false;	
    }
    delete curr->second;
    mymap.erase(curr);
    return true;  


}


/*!
 * \brief Dekonstuktor.
 */
ZbiorPluginow::~ZbiorPluginow(){
  
  for(pair<const string,Plugin*> &Pair: this->mymap){ 
    delete Pair.second; 
  } 
  mymap.clear();
}  


