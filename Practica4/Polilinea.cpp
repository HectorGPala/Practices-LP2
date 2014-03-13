
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Polilinea.h"

Polilinea::Polilinea(){
        grosor = 1;
        Lista_p = new Lista<Punto*>();
}
Polilinea::Polilinea(int g){
        grosor = g;
        Lista_p = new Lista<Punto*>();
}
Polilinea::~Polilinea(){
        grosor = 0;
        delete Lista_p;
}
void Polilinea::ponPunto(Punto* p){
        Lista_p->pon_elem(p);
}
void Polilinea::quitaPunto(int i){
        Lista_p->quita_elem(i);
}
Punto* Polilinea::dameIesimo(int i){
        Punto *p;
        Lista_p->iesimo(i,p);
        return p;
}
void Polilinea::setGrosor(int n){
        grosor = n;
}
void Polilinea::dibuja(TCanvas* canvas){
        int n = Lista_p->longitud();
        canvas->Pen->Width = grosor;
        for(int i = 0; i < n;i++){
                Punto *p;
                Lista_p->iesimo(i,p);
                TColor col = p->get_Color();
                canvas->Pen->Color = col;
                int x = p->get_X();
                int y = p->get_Y();
                p = NULL;
                if(i == 0)
                        canvas->MoveTo(x,y);
                else
                        canvas->LineTo(x,y);
        }
}

void Polilinea::dibujaConVertices(TCanvas* canvas){
        int n = Lista_p->longitud();
        canvas->Pen->Width = grosor;
        for(int i = 0; i < n;i++){
                Punto *p;
                Lista_p->iesimo(i,p);
                canvas->Pen->Color = p->get_Color();
                canvas->Brush->Color = p->get_Color();
                int x = p->get_X();
                int y = p->get_Y();
                if(i == 0){
                        canvas->MoveTo(x,y);
                        canvas->Rectangle(x-5,y-5,x+5,y+5);
                }
                else{
                        canvas->LineTo(x,y);
                        canvas->Rectangle(x-5,y-5,x+5,y+5);
                }
        }

}
//AMIGAS
void Lista_BorraElemento(Polilinea *p){
        delete p;
        p = NULL;
}

bool Lista_guardarDato(ofstream &f,Polilinea *p){
        //int n = p->num_puntos();
        int g = p->grosor;
        //f.write((char*)&n,sizeof(int));
        f.write((char*)&g,sizeof(int));
        p->Lista_p->guardar(f);
        return true;
}

Polilinea* Lista_cargarDato(ifstream &f,Polilinea *p){
        int g;
        f.read((char*)&g,sizeof(int));
        Polilinea *x = new Polilinea(g);
        x->Lista_p->abrir(f);
        return x;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)

