//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPalabra.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


tPalabra::tPalabra(){
        cadena = "";
        paginas = new tListaOrd<int>();
}

tPalabra::tPalabra(const tPalabra &p){
        cadena = p.cadena;
        paginas = new tListaOrd<int>(*p.paginas);
}

tPalabra::tPalabra(String pal,int np){
        cadena = pal;
        paginas = new tListaOrd<int>();
        paginas->insertar(np);
}

tPalabra::~tPalabra(){
        cadena = "";
        delete paginas;
}

void tPalabra::insertarPagina(int n){
        paginas->insertar(n);
}

//FUNCIONES DE LISTA
bool tListaOrdMenor(const int &d1,const  int &d2){
        return d1 < d2;
}

bool tListaIguales(const int &d1,const int &d2){
        return d1 == d2;
}

void ListToStringNodo(AnsiString &cadena,const int &elem){
        AnsiString aux = IntToStr(elem);
        cadena = cadena+aux;
}

void mostrarNodoLista(TStrings* p,const int &elem){
        AnsiString aux = IntToStr(elem);
        p->Add(aux);
}

//FUNCIONES DE ARBOL
void liberaDatoBST(tPalabra* &dato){
        delete dato;
}

void copiaDatoBST(tPalabra* &d1,tPalabra* d2){
        d1 = new tPalabra(*d2);
}

bool datoMenorBST(tPalabra* dato,tPalabra* d){
       return dato->cadena < d->cadena;
}

bool datoIgualBST(tPalabra* dato,tPalabra* d){
        String c = dato->cadena;
        String e = d->cadena;
        int n = c.Length();
        for(int i = 1; i <= n;i++)
                c[i] = UpCase(c[i]);
        n = e.Length();
        for(int i = 1; i <= n;i++)
                e[i] = UpCase(e[i]);
        return e == c;
}

void actualizaNodoBST(tPalabra* &dato,tPalabra* d){
        int n = d->paginas->dameLong();
        for(int i = 0;i < n;i++){
                int np;
                d->paginas->dameElem(i,np);
                dato->insertarPagina(np);
        }

}

void nodoToStringBST(AnsiString &cad,tPalabra* dato){
        AnsiString pal = dato->cadena;
        AnsiString lista = dato->paginas->ListToString();
        cad = pal + " : " + lista;
}

void mostrarNodoBST(TStrings* p,tPalabra* dato){
        AnsiString cad;
        nodoToStringBST(cad,dato);
        p->Add(cad);
}




