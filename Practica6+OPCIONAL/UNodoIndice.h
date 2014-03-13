//---------------------------------------------------------------------------

#ifndef UNodoIndiceH
#define UNodoIndiceH
#include "UPalabra.h"
#include "UBST.h"
#include <fstream>
#include "iostream.h"
//---------------------------------------------------------------------------
class tNodoIndice{
        friend void liberaDatoBST(tNodoIndice* &dato);
        friend void copiaDatoBST(tNodoIndice* &d1,tNodoIndice* d2);
        friend bool datoMenorBST(tNodoIndice* dato,tNodoIndice* d);
        friend bool datoIgualBST(tNodoIndice* dato,tNodoIndice* d);
        friend void actualizaNodoBST(tNodoIndice* &dato,tNodoIndice* d);
        friend void mostrarNodoBST(TStrings* p,tNodoIndice* dato);
        friend void nodoToStringBST(AnsiString &cad,tNodoIndice* dato);
        private:
                char letra;
                tBST<tPalabra*>* palabras;
        public:
                tNodoIndice();
                tNodoIndice(const tNodoIndice &p);
                tNodoIndice(char let, String pal, int np);
                ~tNodoIndice();
                void insertarPalabra(tPalabra* pal);
                char dameLetra(){return letra;}
                tBST<tPalabra*>* damePalabras(){return palabras;}
};

//FUNCIONES DE ARBOL PARA <tNodoIndice>
void liberaDatoBST(tNodoIndice* &dato);
void copiaDatoBST(tNodoIndice* &d1,tNodoIndice* d2);
bool datoMenorBST(tNodoIndice* dato,tNodoIndice* d);
bool datoIgualBST(tNodoIndice* dato,tNodoIndice* d);
void actualizaNodoBST(tNodoIndice* &dato,tNodoIndice* d);
void mostrarNodoBST(TStrings* p,tNodoIndice* dato);
void nodoToStringBST(AnsiString &cad,tNodoIndice* dato);

//FUNCIONES DE ARBOL PARA <String>
void liberaDatoBST(String &dato){dato = NULL;};
void copiaDatoBST(String &d1,const String &d2){d1 = d2;};
bool datoMenorBST(const String &dato,const String &d){return dato < d;};
bool datoIgualBST(String dato,String d);
void actualizaNodoBST(String &dato,const String &d){};
void mostrarNodoBST(TStrings* p,const String &dato){p->Add(dato);};
void nodoToStringBST(AnsiString &cad,const String &dato){cad = dato;};
void guardarNodoBST(ofstream &f,const String &dato){f << dato.c_str() << endl;};
void convertirLinea(String &datoIns,const string &d){datoIns = d.c_str();};











#endif
