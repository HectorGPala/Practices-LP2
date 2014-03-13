//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UNodoIndice.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

tNodoIndice::tNodoIndice(){
        letra = ' ';
        palabras = new tBST<tPalabra*>();
}

tNodoIndice::tNodoIndice(const tNodoIndice &p){
        letra = p.dameLetra();
        palabras = new tBST<tPalabra*>(*p.damePalabras());
}

tNodoIndice::tNodoIndice(char let, String pal, int np){
        letra = UpCase(let);
        palabras = new tBST<tPalabra*>();
        tPalabra* aux = new tPalabra(pal,np);
        palabras->insertar(aux);
        delete aux;
}

tNodoIndice::~tNodoIndice(){
        letra = ' ';
        delete palabras;
}

void tNodoIndice::insertarPalabra(tPalabra* pal){
        palabras->insertar(pal);
}

//FUNCIONES
void liberaDatoBST(tNodoIndice* &dato){
        delete dato;
}

void copiaDatoBST(tNodoIndice* &d1,tNodoIndice* d2){
        d1 = new tNodoIndice(*d2);
}

bool datoMenorBST(tNodoIndice* dato,tNodoIndice* d){
       return dato->letra < d->letra;
}

bool datoIgualBST(tNodoIndice* dato,tNodoIndice* d){
        return dato->letra == d->letra;
}

void actualizaNodoBST(tNodoIndice* &dato,tNodoIndice* d){
        dato->insertarPalabra(d->palabras->dameRaiz());
}

void mostrarNodoBST(TStrings* p,tNodoIndice* dato){
        AnsiString cad;
        cad = UpCase(dato->letra);
        p->Add("-----" + cad + "-----");
        p->Add(" ");
        dato->palabras->mostrar(p);
        p->Add(" ");
}
void nodoToStringBST(AnsiString &cad,tNodoIndice* dato){
        cad = dato->letra;
        cad = cad + dato->palabras->BSTToString();
}

bool datoIgualBST(String c,String d){
        int n = c.Length();
        for(int i = 1; i <= n;i++)
                c[i] = UpCase(c[i]);
        n = d.Length();
        for(int i = 1; i <= n;i++)
                d[i] = UpCase(d[i]);
        return d == c;
}




