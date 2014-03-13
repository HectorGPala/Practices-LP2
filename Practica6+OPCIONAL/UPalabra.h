//---------------------------------------------------------------------------

#ifndef UPalabraH
#define UPalabraH
#include "UListaOrd.h"
#include "UBST.h"
//---------------------------------------------------------------------------

class tPalabra{
        friend void liberaDatoBST(tPalabra* &dato);
        friend void copiaDatoBST(tPalabra* &d1,tPalabra* d2);
        friend bool datoMenorBST(tPalabra* dato,tPalabra* d);
        friend bool datoIgualBST(tPalabra* dato,tPalabra* d);
        friend void actualizaNodoBST(tPalabra* &dato,tPalabra* d);
        friend void mostrarNodoBST(TStrings* p,tPalabra* dato);
        friend void nodoToStringBST(AnsiString &cad,tPalabra* dato);
        private:
                String cadena;
                tListaOrd<int>* paginas;
        public:
                tPalabra();
                tPalabra(const tPalabra &p);
                tPalabra(String pal,int np);
                ~tPalabra();
                void insertarPagina(int n);
                String damePalabra(){return cadena;}
                tListaOrd<int>* damePaginas(){return paginas;}
};
//FUNCIONES DE LISTA PARA <int>
void liberaDato(int &n){}
bool tListaOrdMenor(const int &d1,const  int &d2);
bool tListaIguales(const int &d1,const int &d2);
void actualizaNodo(const int &d){}//NO NECESITA MODIFICAR NADA
void ListToStringNodo(AnsiString &cadena,const int &elem);
void mostrarNodoLista(TStrings* p,const int &elem);

//FUNCIONES DE ARBOL PARA <tPalabra>
void liberaDatoBST(tPalabra* &dato);
void copiaDatoBST(tPalabra* &d1,tPalabra* d2);
bool datoMenorBST(tPalabra* dato,tPalabra* d);
bool datoIgualBST(tPalabra* dato,tPalabra* d);
void actualizaNodoBST(tPalabra* &dato,tPalabra* d);
void mostrarNodoBST(TStrings* p,tPalabra* dato);
void nodoToStringBST(AnsiString &cad,tPalabra* dato);








#endif
