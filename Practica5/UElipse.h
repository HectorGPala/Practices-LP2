//---------------------------------------------------------------------------

#ifndef UElipseH
#define UElipseH
#include "UGrafico.h"
#include <iostream>
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
class tElipse : public tGrafico{
        public:
                tElipse():tGrafico(){};
                tElipse(int Xini,int Yini,int Xfin,int Yfin,TColor c,bool r,int g);
                virtual ~tElipse(){};
                virtual void dibujar(TCanvas *canvas);
                virtual void dibujarCPS(TCanvas *canvas);
                virtual void salvar(ofstream& archivo);
                virtual void cargar(ifstream& archivo)throw (EConvertError);
                virtual tGrafico* copiar();
};


#endif
