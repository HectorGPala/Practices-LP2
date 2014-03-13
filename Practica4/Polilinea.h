//---------------------------------------------------------------------------

#ifndef PolilineaH
#define PolilineaH
#include "Punto.h"
#include "Lista.h"

class Polilinea{
        friend void Lista_BorraElemento(Polilinea *p);
        friend bool Lista_guardarDato(ofstream &f,Polilinea *p);
        friend Polilinea* Lista_cargarDato(ifstream &f,Polilinea *a);
        private:
                Lista<Punto*>* Lista_p;
                int grosor;
        public:
                Polilinea();
                Polilinea(int grosor);
                ~Polilinea();
                void ponPunto(Punto* p);
                void quitaPunto(int i);
                void setGrosor(int n);
                inline int num_puntos(){return Lista_p->longitud();};
                Punto* dameIesimo(int i);
                inline int get_Grosor(){return grosor;};
                void dibuja(TCanvas* canvas);
                void dibujaConVertices(TCanvas* canvas);
};
void Lista_BorraElemento(Polilinea *p);
bool Lista_guardarDato(ofstream &f,Polilinea *p);
Polilinea * Lista_cargarDato(ifstream &f,Polilinea *a);



//---------------------------------------------------------------------------
#endif
