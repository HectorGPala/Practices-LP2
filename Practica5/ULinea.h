//---------------------------------------------------------------------------

#ifndef ULineaH
#define ULineaH
#include "UGrafico.h"
//---------------------------------------------------------------------------
class tLinea : public tGrafico{
        public:
                tLinea():tGrafico(){};
                tLinea(int Xini,int Yini,int Xfin,int Yfin,TColor c,bool r,int g);
                virtual ~tLinea(){};
                virtual void dibujar(TCanvas *canvas);
                virtual void dibujarCPS(TCanvas *canvas);
                virtual void salvar(ofstream& archivo);
                virtual void cargar(ifstream& archivo);
                virtual tGrafico* copiar();
};


#endif
