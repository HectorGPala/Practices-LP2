//---------------------------------------------------------------------------

#ifndef UGraficoH
#define UGraficoH
#include <iostream>
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
class tGrafico{
        protected:
                int Xini;
                int Yini;
                int Xfin;
                int Yfin;
                TColor color;
                bool relleno;
                int grosor;
        public:
                tGrafico();
                tGrafico(int Xini,int Yini,int Xfin,int Yfin,TColor c,bool r,int g);
                virtual ~tGrafico();
                void ponCoordenadas(int Xin,int Yin,int Xfin,int Yfin);
                void damePuntoSingular(int &x, int &y);
                void ponPuntoSingular(int x,int y);
                virtual void dibujar(TCanvas *canvas)=0;
                virtual void dibujarCPS(TCanvas *canvas);
                virtual void salvar(ofstream& archivo)=0;
                virtual void cargar(ifstream& archivo)=0;
                virtual tGrafico* copiar()=0;

};
#endif
