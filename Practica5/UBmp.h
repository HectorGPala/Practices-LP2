//---------------------------------------------------------------------------

#ifndef UBmpH
#define UBmpH
#include "UGrafico.h"
//---------------------------------------------------------------------------
class tBMP : public tGrafico{
        private:
                string nombre;
                Graphics::TBitmap* bmp;
        public:
                tBMP():tGrafico(){bmp = new Graphics::TBitmap();};
                tBMP(int Xin,int Yin,const string &fich)throw (Exception);
                ~tBMP();
                virtual void dibujar(TCanvas *canvas);
                virtual void dibujarCPS(TCanvas *canvas);
                virtual void salvar(ofstream& archivo);
                virtual void cargar(ifstream& archivo)throw (Exception);
                virtual tGrafico* copiar();
};




#endif
