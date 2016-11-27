#ifndef  ROBOTPOSE_HH
#define  ROBOTPOSE_HH

#include <iostream>

/*!
 * \file
 * \brief Definicja klasy RobotPose
 *
 * Plik zawiera definicję klasy RobotPose
 */


/*!
 *\brief Definiuje mozliwe operacje na chwytaku
 *
 */
enum TypOperacji{
  TO_neutralna,
  TO_chwycenie,
  TO_puszczenie
};



/*!
 * \brief Modeluje zestaw informacji określający pozę robota
 *
 *  Klasa modeluje zestaw informacji określających pozę robota.
 *  Ponadto udostępnia metody, które pozwalają aktualizowanie
 *  współrzędnych pozy robota, jak też pobieranie tych informacji.
 *  Zmiana współrzędnych powoduje wywołanie spacjalnej metody
 *   \link RobotPose::AfterUpdate AfterUpdate()\endlink.
 *  Należy ją zdefiiować w klasie pochodnej.
 */
class RobotPose {
public:
  /*!
   * \brief Zeruje pozę robota i ustawia neutralna operacje na chytaku
   *
   *  Inicjalizuje wartościami 0 zarówno pozycję robota,
   *  jak też jego kąt orientacji.
   */   
  RobotPose(): x_mm(0), y_mm(0), alpha_deg(0),_TypOperacji(TO_neutralna){}
  
  /*!
   * \brief Ustawia wartości współrzędnych pozy robota
   *
   *  Ustawia wartości współrzędnych kartezjańskich pozycji
   *  oraz kąt orientacji robota.
   *  Po wykonaniu tej operacji wywołana zostaje metoda
   *  \link RobotPose::AfterUpdate AfterUpdate()\endlink.
   *  \param[in] x_mm - usawiana wartość współrzędnej \e x-owej
   *                    wyrażonej w milimetrach,
   *  \param[in] y_mm - usawiana wartość współrzędnej \e y-owej
   *                    wyrażonej w milimetrach,
   *  \param[in] alpha_deg - ustawiana wartość kąta orientacji 
    *                   robota wyrażona w stopniach.
    */
  bool Set( double x_mm, double y_mm, double alpha_deg )
  {
    RobotPose::x_mm = x_mm;
    RobotPose::y_mm = y_mm;
    RobotPose::alpha_deg = alpha_deg;
    return AfterUpdate();
  }
  /*!
   * \brief Ustawia wartości współrzędnych pozycji robota
   *
   *  Ustawia wartości współrzędnych kartezjańskich pozycji
   *  robota.
   *  Po wykonaniu tej operacji wywołana zostaje metoda
   *  \link RobotPose::AfterUpdate AfterUpdate()\endlink.
   *  \param[in] x_mm - usawiana wartość współrzędnej \e x-owej
   *                    wyrażonej w milimetrach,
   *  \param[in] y_mm - usawiana wartość współrzędnej \e y-owej
   *                    wyrażonej w milimetrach,
   */
  bool Set( double x_mm, double y_mm )
  {
    RobotPose::x_mm = x_mm;
    RobotPose::y_mm = y_mm;
    return AfterUpdate();
  }
  /*!
   * \brief Ustawia wartości kąta orientacji robota
   *
   *  Ustawia wartości kąta orientacji robota.
   *  Po wykonaniu tej operacji wywołana zostaje metoda
   *  \link RobotPose::AfterUpdate AfterUpdate()\endlink.
   *  \param[in] alpha_deg - ustawiana wartość kąta orientacji 
   *                   robota wyrażona w stopniach.
   */
  bool SetAlpha( double alpha_deg )
  {
    RobotPose::alpha_deg = alpha_deg;
    return AfterUpdate();
  }
  
  void GetAlpha( double &alpha_deg )
  {
    alpha_deg = RobotPose::alpha_deg;
  }
  /*!
   * \brief Udostępnia wartości współrzędnych pozy robota
   *
   *  Udostępnia wartości współrzędnych kartezjańskich pozycji
   *  oraz kąt orientacji robota.
   *  \param[out] x_mm - współrzędna \e x-owa wyrażona w milimetrach,
   *  \param[out] y_mm - współrzędna \e y-owa wyrażona w milimetrach,
   *  \param[out] alpha_deg - kąt orientacji robota wyrażony w stopniach.
   */
  void Get( double &x_mm, double &y_mm, double &alpha_deg )
  {
    x_mm = RobotPose::x_mm;
    y_mm = RobotPose::y_mm;
    alpha_deg = RobotPose::alpha_deg;
  }
  /*!
   * \brief Udostępnia wartości współrzędnych pozycji robota
   *
   *  Udostępnia wartości współrzędnych kartezjańskich pozycji
   *  robota.
   *  \param[out] x_mm - współrzędna \e x-owa wyrażona w milimetrach,
   *  \param[out] y_mm - współrzędna \e y-owa wyrażona w milimetrach,
   */
  void Get( double &x_mm, double &y_mm )
  {
    x_mm = RobotPose::x_mm;
    y_mm = RobotPose::y_mm;
  
}
   /*!
   * \brief Ustawia zadany typ operacji
   *  
   *  \param[in] TO - Typ operacji ktory chcemy ustawic,
   *  \param[out] AfterUpdate - Wymusza odrysowanie sceny
   */
  bool SetOperation(TypOperacji TO){
    RobotPose::_TypOperacji = TO;
    return AfterUpdate();
  }
  
 /*!
   * \brief Udostępnia wartosc aktualnej operacji
   *
   */
  TypOperacji GetOperation(){
    return RobotPose::_TypOperacji;
  }
  
  protected:
  /*!
   *  Metoda wywoływana jest po aktualizacji położenia i orientacji
   *  lub samego położenia.
   *  \retval true - gdy operacja powiodła się,
   *  \retval false - w przypadku przeciwnym.
   */
  virtual bool AfterUpdate() = 0;
  
private:
    /*!
     * \brief  współrzędna \e x-owa w globalnym układzie współrzędnych
     *
     * Współrzędna \e x-owa w globalnym układzie współrzędnych.
     * Wartość współrzędnej wyrażona jest w milimetrach.
     */
  double    x_mm;
  /*!
   * \brief  współrzędna \e y-owa w globalnym układzie współrzędnych
   *
   * Współrzędna \e y-owa w globalnym układzie współrzędnych.
   * Wartość współrzędnej wyrażona jest w milimetrach.
   */
  double    y_mm;
  /*!
   * \brief Kąt orientacji robota w globalnym układzie współrzednych
   *
   *  Kąt orientacji robota w globalnym układzie współrzednych.
   *  Wartość kąta wyrażona jest w stopniach.
   */
  double    alpha_deg;
  
  /*!
   *\brief Pole przechowuje aktalny typ operacji na chwytaku
   */
  TypOperacji _TypOperacji;
  
};





#endif
