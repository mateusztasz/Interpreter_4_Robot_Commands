#include <xercesc/util/PlatformUtils.hpp>
#include "xmlparser4scene.hh"
#include <cassert>
#include <cstdlib>
#include <iostream>

#include <string>

#ifndef XMLSize_t
# define XMLSize_t unsigned int
#endif

#include <stdlib.h> 




using namespace std;
using namespace xercesc;

/*!
 * Konstruktor klasy. Tutaj należy zainicjalizować wszystkie
 * dodatkowe pola.
 * (Ten opis należy odpowiednio uzupełnić)
 */
XMLParser4Scene::XMLParser4Scene(Scene &Scn)
{
  _pScn = &Scn;
}


/*!
 * Metoda wywoływana jest bezpośrednio przed rozpoczęciem
 * przetwarzana dokumentu XML.
 */
void XMLParser4Scene::startDocument()
{
  cout << "*** Rozpoczecie przetwarzania dokumentu XML." << endl;
}


/*!
 * Metoda wywoływana jest bezpośrednio po zakończeniu
 * przetwarzana dokumentu XML.
 */
void XMLParser4Scene::endDocument()
{
  cout << "=== Koniec przetwarzania dokumentu XML." << endl;
}



/*!
 * Wykonuje operacje związane z wystąpieniem danego elementu XML.
 * W przypadku elementu \p "Action" będzie to utworzenie obiektu
 * reprezentującego odpowiednią działanie robota.
 * W przypadku elementu \p "Parameter" będzie to zapisanie parametrów
 * związanych z danym działaniem.
 * \param[in] ElemName -
 * \param[in] Attrs - (\b we,) atrybuty napotkanego elementu XML.
 */
void XMLParser4Scene::WhenStartElement( const std::string       &ElemName,
		                      const xercesc::Attributes   &Attrs
                                    )
{
  /*
   *  Tu moge rozpoznac element i przetworzyc jego atrybuty
   */


  if(ElemName == "Robot"){
    ProcessRobotAttrs(Attrs); return;
  }
 if(ElemName == "Object"){
   ProcessObjectAttrs(Attrs); return ;
  }
}




/*!
 * Metoda jest wywoływana po napotkaniu nowego elementu XML, np.
 * gdy zostanie napotkany element:
   \verbatim
     <Action Name="Rotate">
   \endverbatim
 *  to poprzez parametr \e xscElemName jest dostęp do nazwy elementu
 *  tzn. \p Action, 
 *  \param[in] pLocalName -  umożliwia dostęp do nazwy elementu XML.
 *                 W podanym przykładzie nazwą elementu XML jest "Action".
 *  \param[in] Attrs -  lista atrybutów danego symbolu XML.
 *                 W przykładzie pokazanym powyżej listę atrybutów
 *                 będą stanowiły napisy:
 */
/*
 * Te metode nalezy odpowiednio zdekomponowac!!!
 */
void XMLParser4Scene::startElement(  const   XMLCh* const    pURI,
                                       const   XMLCh* const    pLocalName,
                                       const   XMLCh* const    pQNname,
				       const   xercesc::Attributes&     Attrs
                                    )
{
  char* sElemName = xercesc::XMLString::transcode(pLocalName);
  cout << "+++ Poczatek elementu: "<< sElemName << endl;

  WhenStartElement(sElemName, Attrs);

  xercesc::XMLString::release(&sElemName);
}




/*!
 * Metoda zostaje wywołana w momencie zakończenia danego elementu
 * XML, np. jeżeli w pliku jest wpis:
   \verbatim
     <Action Name="Rotate">
     </Action>
   \endverbatim
 * to metoda ta zostanie wywołana po napotkaniu znacznika
 * \p </Action>. Jeżeli element XML ma formę skróconą, tzn.
   \verbatim
     <Parametr Name="Rotate"/>
   \endverbatim
 * to wówczas wywołana metoda wywołana zostanie w momencie
 * napotkania sekwencji "/>"
 *  \param[in] pLocalName -  umożliwia dostęp do nazwy elementu XML.
 *                 W podanym przykładzie nazwą elementu XML jest "Action".
 */
void XMLParser4Scene::endElement(  const   XMLCh* const    pURI,
                                     const   XMLCh* const    pLocalName,
                                     const   XMLCh* const    pQName
                                  )
{
   char* sElemName = xercesc::XMLString::transcode(pLocalName);
   cout << "--- Koniec elementu: "<< sElemName << endl;

   WhenEndElement(sElemName);

   xercesc::XMLString::release(&sElemName);
}



/*!
 * Wykonuje końcowe operacje związane z danym elementem XML. 
 * W przypadku \p "Action" jest to dodanie utworzonego wcześniej
 * obiektu do listy poleceń robota.
 * Metoda wywoływana jest w momencie napotkania znacznika końca
 * danego elementu XML.
 * \param[in] ElemName -  nazwa elementu XML
 */
void XMLParser4Scene::WhenEndElement(const std::string& ElemName)
{

}



/*!
 * Metoda wywoływana jest, gdy napotkany zostanie błąd fatalny,
 * np.
  \verbatim
    <Action Name="Rotate">
    </Parametr>
  \endverbatim
 */
void XMLParser4Scene::fatalError(const xercesc::SAXParseException&  Exception)
{
   char* sMessage = xercesc::XMLString::transcode(Exception.getMessage());
   char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

   cerr << "Blad fatalny! " << endl
        << "    Plik:  " << sSystemId << endl
        << "   Linia: " << Exception.getLineNumber() << endl
        << " Kolumna: " << Exception.getColumnNumber() << endl
        << " Informacja: " << sMessage 
        << endl;

   xercesc::XMLString::release(&sMessage);
   xercesc::XMLString::release(&sSystemId);
   
}

/*!
 * Metoda jest wywoływana, gdy napotkany zostanie błąd, który nie
 * jest traktowany jako fatalny. W ten sposób traktowane są błędy
 * występujące w opisie gramatyki dokumentu.
 * \param[in] Except - zawiera informacje dotyczące błędu. Informacje
 *                     te to opis błędu oraz numer linii, w której
 *                     wystąpił błąd.
 */
void XMLParser4Scene::error(const xercesc::SAXParseException&  Exception)
{
   char* sMessage = xercesc::XMLString::transcode(Exception.getMessage());
   char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

   cerr << "Blad! " << endl
        << "    Plik:  " << sSystemId << endl
        << "   Linia: " << Exception.getLineNumber() << endl
        << " Kolumna: " << Exception.getColumnNumber() << endl
        << " Informacja: " << sMessage 
        << endl;

   xercesc::XMLString::release(&sMessage);
   xercesc::XMLString::release(&sSystemId);
  
}



/*!
 *
 */
void XMLParser4Scene::warning(const xercesc::SAXParseException&  Exception)  
{
  cerr << "Ostrzezenie ..." << endl;

}



void XMLParser4Scene::ProcessObjectAttrs(const xercesc::Attributes   &Attrs ){

  if(Attrs.getLength() != 4){
    cerr<<"Zla ilosc atrybutow dla \"Object\""<<endl; throw 1;
  }
  
  XMLParser4Scene::_pScn->DodajObiektDoSceny();
  
  unsigned int  i = 0;
  
  char* sObjectName = xercesc::XMLString::transcode(Attrs.getValue(i));
  XMLParser4Scene::_pScn->pHandler->name = static_cast<string>(sObjectName);
  
  char* sPos_X = xercesc::XMLString::transcode(Attrs.getValue(1));
  XMLParser4Scene::_pScn->pHandler->pos_x = atof(sPos_X); 
  
  char* sPos_Y = xercesc::XMLString::transcode(Attrs.getValue(2));
  XMLParser4Scene::_pScn->pHandler->pos_y = atof(sPos_Y);
  
  char* sSize = xercesc::XMLString::transcode(Attrs.getValue(3));
  XMLParser4Scene::_pScn->pHandler->size = atoi(sSize);
  
  
  xercesc::XMLString::release(&sObjectName);
  xercesc::XMLString::release(&sPos_X);
  xercesc::XMLString::release(&sPos_Y);
  xercesc::XMLString::release(&sSize);
}




void XMLParser4Scene::ProcessRobotAttrs(const xercesc::Attributes   &Attrs ){
  
  if(Attrs.getLength() != 3){
    cerr<<"Zla ilosc atrybutow dla \"Robot\""<<endl; throw 1;
  }


  unsigned int  i = 0;
  
  char* sPos_X = xercesc::XMLString::transcode(Attrs.getValue(i));
  char* sPos_Y = xercesc::XMLString::transcode(Attrs.getValue(1));
  char* sPos_Angle = xercesc::XMLString::transcode(Attrs.getValue(2));
  
 
  double x_p = atof(sPos_X);
  double y_p = atof(sPos_Y);
  double alpha_p = atof(sPos_Angle);
  
  XMLParser4Scene::_pScn->DodajRobotaDoSceny( x_p, y_p, alpha_p);
  
  
  xercesc::XMLString::release(&sPos_X);
  xercesc::XMLString::release(&sPos_Y);
  xercesc::XMLString::release(&sPos_Angle);
}


/*!
 * Czyta z pliku opis sceny i zapisuje stan sceny do parametru,
 * który ją reprezentuje.
 * \param sFileName - (\b we.) nazwa pliku z opisem poleceń.
 * \param Scn - (\b we.) reprezentuje scenę, na której ma działać robot.
 * \retval true - jeśli wczytanie zostało zrealizowane poprawnie,
 * \retval false - w przeciwnym przypadku.
 */
bool ReadFile(const char* sFileName, Scene& Scn){
  //Inicjalizacja biblioteki Xerces
   try {
            XMLPlatformUtils::Initialize();
   }
   catch (const XMLException& toCatch) {
            char* message = XMLString::transcode(toCatch.getMessage());
            cerr << "Error during initialization! :\n";
            cerr << "Exception message is: \n"
                 << message << "\n";
            XMLString::release(&message);
            return 1;
   }


   //Tworzenie obiektu parsera i ustawienie wlasnosci
   SAX2XMLReader* pParser = XMLReaderFactory::createXMLReader();

   //Gramatyka dokumentu musi wspierac mechanizm przestrzeni nazw
   pParser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);

   //Gdy true - to z dokumentem musi byc dolaczana gramatyka, ktora bedzie podstawa oceny poprawnosci skladni dokumentu
   pParser->setFeature(XMLUni::fgSAX2CoreValidation, true);

   //jesli true to poprawnosc dokumentu jest oceniana tylo wtedy gdy dostarczony jest opis gramatyki dokumentu
   pParser->setFeature(XMLUni::fgXercesDynamic, false);

   //Uaktywnia wsparcie parsera dlaXML Schema
   pParser->setFeature(XMLUni::fgXercesSchema, true);

   //Uaktywnia pelne parsowanie gramatyki dokumentu (moze to byc czasochlonne)
   pParser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

   //Gdy trnapotkane bledy beda traktowane jako fatlane i parser przerwie swoje dzialanie. W przypadku przeciwnym, parser bedzie zglaszal bledy, ale jego dzialanie bedzie kontunuowane 
   pParser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);

   //Uzyj wczytana gramatyke, jesli zotala wczesniej wczytana
   pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse, false);

   //Tworzenie handlera zdarzen
   DefaultHandler* pHandler = new XMLParser4Scene(Scn);
   pParser->setContentHandler(pHandler);
   pParser->setErrorHandler(pHandler);

   //Wczytanie gramatyki
   try {
     
     if (!pParser->loadGrammar("grammar/opis_sceny.xsd",
                              xercesc::Grammar::SchemaGrammarType,true)) {
       cerr << "!!! Plik grammar/twarz_robota.xsd, '" << endl
            << "!!! ktory zawiera opis gramatyki, nie moze zostac wczytany."
            << endl;
       return false;
     }
     pParser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse,true);
     
     //Uruchomienie parsera
     pParser->parse(sFileName);
   }

   //Przechwycenie wyjatkow
   catch (const XMLException& Exception) {
     char* sMessage = XMLString::transcode(Exception.getMessage());
            cerr << "Informacja o wyjatku: \n"
                 << "   " << sMessage << "\n";
            XMLString::release(&sMessage);
            return false;
   }
   catch (const SAXParseException& Exception) {
            char* sMessage = XMLString::transcode(Exception.getMessage());
            char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

            cerr << "Blad! " << endl
                 << "    Plik:  " << sSystemId << endl
                 << "   Linia: " << Exception.getLineNumber() << endl
                 << " Kolumna: " << Exception.getColumnNumber() << endl
                 << " Informacja: " << sMessage 
                 << endl;
	    
            XMLString::release(&sMessage);
            XMLString::release(&sSystemId);
            return false;
   }
   catch (...) {
            cout << "Zgloszony zostal nieoczekiwany wyjatek!\n" ;
            return false;
   }

   //Usuniecie pomocniczych obiektow
   delete pParser;
   delete pHandler;
   return true;
}
