
#include "Scene.hh"



bool Scene::DodajRobotaDoSceny( double &x_p,  double &y_p,  double &alpha_p) {
    
  Robot = new RobotMobilny(&Lacze);
  Robot->_pScene = this;    
  
  Robot->Set_X_Y_Alpha(x_p,y_p,alpha_p);
  return true;
}


Scene::~Scene(){
  delete Robot;
  for( Obiekt* it:Lst ){
    delete it;
  }
}

bool Scene::DodajObiektDoSceny(){
  
  Obiekt *Ob;
  Ob = new Obiekt();
  Lst.push_back(Ob);
  pHandler = Ob;
  Lacze.Lst_DlaLacza = Lst;
  
  return true;
}



bool Scene::Init(){
  double x_p,y_p, alpha_p;
  Robot->Get_X(x_p);
  Robot->Get_Y(y_p);
  Robot->GetAlpha(alpha_p);
  Robot->Set( x_p, y_p, alpha_p);
  Robot->Init();
  
  Lacze.UstawZakresY(-100,120);
  Lacze.UstawZakresX(-10,220);
  Lacze.Rysuj();

  return true;
}
