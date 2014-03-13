//---------------------------------------------------------------------------

#ifndef PuntoH
#define PuntoH
#include "Lista.h"
//---------------------------------------------------------------------------
class Punto{
        friend void Lista_BorrarElemento(Punto *p);
        friend bool Lista_guardarDato(ofstream &f,Punto *d);
        friend Punto* Lista_cargarDato(ifstream &f,Punto *a);
        private:
                int x,y;
                TColor col;
        public:
                Punto();
                Punto(int x,int y,TColor c);
                ~Punto();
                inline int get_X(){return x;};
                inline int get_Y(){return y;};
                inline TColor get_Color(){return col;};
                void setXY(int x, int y);
};
void Lista_BorraElemento(Punto *p);
bool Lista_guardarDato(ofstream &f,Punto *d);
Punto* Lista_cargarDato(ifstream &f,Punto *a);



#endif
