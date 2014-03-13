//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Punto.h"

//---------------------------------------------------------------------------
Punto::Punto(){
        x = 0;
        y = 0;
        col = clWhite;
}
Punto::Punto(int x,int y,TColor c){
        this->x = x;
        this->y = y;
        col = c;
}

Punto::~Punto(){
        x = 0;
        y = 0;
        col = clWhite;
}
void Punto::setXY(int x, int y){
        this->x = x;
        this->y = y;
}
//AMIGAS
void Lista_BorraElemento(Punto *p){
        delete p;
        p = NULL;
}

bool Lista_guardarDato(ofstream &f,Punto *d){
        int x = d->x;
        int y = d->y;
        TColor c = d->col;
        f.write((char*)&x,sizeof(int));
        f.write((char*)&y,sizeof(int));
        f.write((char*)&c,sizeof(TColor));
        return true;
}

Punto* Lista_cargarDato(ifstream &f,Punto *p){
        int x;
        int y;
        TColor c;
        f.read((char*)&x,sizeof(int));
        f.read((char*)&y,sizeof(int));
        f.read((char*)&c,sizeof(TColor));
        Punto *xy = new Punto(x,y,c);
        return xy;
}

#pragma package(smart_init)
