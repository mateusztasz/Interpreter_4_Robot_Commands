#ifndef ROBOTMOBILNY_HH
#define ROBOTMOBILNY_HH

#pragma interface

/*!
 * \file
 * \brief Definicja klasy RobotMobilny
 *
 * Plik zawiera definicję klasy RobotMobilny
 */

class Scene;

#include "robotpose.hh"
#include "lacze_do_gnuplota.hh"

#include "MojeLaczeDoGNUplota.hh"
#include "Obiekt.hh"
#include <fstream>



/*!
 * \brief Modeluje zestaw informacji określający miejsce robota w przestrzeni roboczej
 *
 */
class RobotMobilny: public RobotPose {
  
private:
  Obiekt *_GrasppedObject;
  
public:
  Scene *_pScene;
  
  /*!
   * \brief Konstruktor
   */
  RobotMobilny(MojeLaczeDoGNUplota *pPlotter);
  
  /*!
   * \brief Inicjalizuje struktury robota
   */
  bool Init();
  
  /*!
   * \brief Resetuje pozycję robot i kasuje jego ścieżkę
   */
  bool Reset();
  /*!
   * \brief Współrzędne robota zapisane zostają do pliku
   */
  bool WriteCoord(double &x_mm, double &y_mm);
  
    /*!
   * \brief Ustawia wspolrzedne poczatkowe robota
   */
  void Set_X_Y_Alpha(double x, double y, double alpha){
    RobotMobilny::x_p = x;
    RobotMobilny::y_p = y;
    RobotMobilny::alpha_p = alpha;
  }
    /*!
   * \brief Pobiera wspolrzedne X poczatkowa robota
   */
  void Get_X(double &x){
    x = RobotMobilny::x_p;
  }
      /*!
   * \brief Pobiera wspolrzedne Y poczatkowa robota
   */
  void Get_Y(double &y){
    y = RobotMobilny::y_p;
  }
      /*!
   * \brief Pobiera wspolrzedne orientacji poczatkowa robota
   */
  void Get_Alpha(double &alpha){
    alpha = RobotMobilny::alpha_p;
  }
  
  /*!
   *  Metoda wywoływana jest po aktualizacji położenia i orientacji
   *  lub samego położenia.
   *  \retval true - gdy operacja powiodła się,
   *  \retval false - w przypadku przeciwnym.
   */
  virtual bool AfterUpdate();
  
  virtual ~RobotMobilny();
  
private:
  /*!
   * \brief Pole przechowujace rysik z dostepem do rysowania
   */
  MojeLaczeDoGNUplota  *_pPlotter;
  /*!
   * \brief W strumieniu zapisywana są kolejne współrzędne robota
   */
  std::ofstream   _Strm4Path;
  
    /*!
   * \brief Pole przechowujace pozycje x poczatkowe
   */
  double x_p;
      /*!
   * \brief Pole przechowujace pozycje y poczatkowe
   */
  double y_p;
      /*!
   * \brief Pole przechowujace pozycje kat poczatkowy
   */
  double alpha_p;
};


#endif
