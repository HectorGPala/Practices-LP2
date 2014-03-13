//---------------------------------------------------------------------------

#ifndef URectanguloH
#define URectanguloH
#include "UGrafico.h"
#include <iostream>
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
class tRectangulo : public tGrafico{
        public:
                tRectangulo():tGrafico(){};
                tRectangulo(int Xini,int Yini,int Xfin,int Yfin,TColor c,bool r,int g);
                virtual ~tRectangulo(){};
                virtual void dibujar(TCanvas *canvas);
                virtual void dibujarCPS(TCanvas *canvas);
                virtual void salvar(ofstream& archivo);
                virtual void cargar(ifstream& archivo) throw (EConvertError);
                virtual tGrafico* copiar();
};


#endif
