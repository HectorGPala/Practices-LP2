//---------------------------------------------------------------------------

#ifndef UtDibujoH
#define UtDibujoH
#include "Punto.h"
#include "Lista.h"
#include "Polilinea.h"
//---------------------------------------------------------------------------

class Dibujo{
        private:
                Lista<Polilinea*>* Lista_poli;
        public:
                Dibujo();
                ~Dibujo();
                void ponPolilinea(Polilinea* p);
                void quitaPolilinea(int i);
                Polilinea* dameIesimo(int i);
                inline int num_dibujos(){return Lista_poli->longitud();};
                void dibuja(TCanvas* canvas);
                void dibujaConVertices(TCanvas* canvas);
                void guardar(ofstream &f);
                void cargar(ifstream &f);
};


#endif
