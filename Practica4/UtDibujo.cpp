//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UtDibujo.h"

//---------------------------------------------------------------------------

Dibujo::Dibujo(){
        Lista_poli = new Lista<Polilinea*>();
}

Dibujo::~Dibujo(){
        delete Lista_poli;
}

void Dibujo::ponPolilinea(Polilinea* p){
        Lista_poli->pon_elem(p);
}

void Dibujo::quitaPolilinea(int i){
        Lista_poli->quita_elem(i);
}

Polilinea* Dibujo::dameIesimo(int i){
        Polilinea *p;
        Lista_poli->iesimo(i,p);
        return p;
}

void Dibujo::dibuja(TCanvas* canvas){
        int n = Lista_poli->longitud();
        for(int i = 0; i < n;i++){
                Polilinea *p;
                Lista_poli->iesimo(i,p);
                p->dibuja(canvas);
        }
}

void Dibujo::dibujaConVertices(TCanvas* canvas){
        int n = Lista_poli->longitud();
        for(int i = 0; i < n;i++){
                Polilinea *p;
                Lista_poli->iesimo(i,p);
                p->dibujaConVertices(canvas);
        }
}
void Dibujo::guardar(ofstream &f){
        Lista_poli->guardar(f);
}
void Dibujo::cargar(ifstream &f){
        Lista_poli->abrir(f);
}

#pragma package(smart_init)
