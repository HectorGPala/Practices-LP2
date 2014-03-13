//---------------------------------------------------------------------------

#ifndef UTextoH
#define UTextoH
#include "UGrafico.h"
//---------------------------------------------------------------------------
class tTexto : public tGrafico{
        private:
                int tam;
                AnsiString cadena;
        public:
                tTexto():tGrafico(){};
                tTexto(int Xini,int Yini,int Xfin,int Yfin,TColor c,bool r,int g);
                virtual ~tTexto(){tam = 0; cadena = "";};
                void ponChar(char c);
                void borraChar();
                AnsiString dameCadena(){return cadena;};
                virtual void dibujar(TCanvas *canvas);
                virtual void dibujarCPS(TCanvas *canvas);
                virtual void salvar(ofstream& archivo);
                virtual void cargar(ifstream& archivo);
                virtual tGrafico* copiar();

};







#endif
