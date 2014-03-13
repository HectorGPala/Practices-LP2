//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UGrafico.h"

//---------------------------------------------------------------------------

tGrafico::tGrafico(){
                Xini = 0;
                Yini = 0;
                Xfin = 1;
                Yfin = 1;
                color = clBlack;
                relleno = false;
                grosor = 1;
}

tGrafico::tGrafico(int Xini,int Yini,int Xfin,int Yfin,TColor c,bool r,int g){
                this->Xini = Xini;
                this->Yini = Yini;
                this->Xfin = Xfin;
                this->Yfin = Yfin;
                color = c;
                relleno = r;
                grosor = g;
}

tGrafico::~tGrafico(){
                Xini = 0;
                Yini = 0;
                Xfin = 1;
                Yfin = 1;
                color = (TColor) 0;
                relleno = false;
                grosor = 0;
}

void tGrafico::ponCoordenadas(int Xin,int Yin,int Xfin,int Yfin){
        Xini = Xin;
        Yini = Yin;
        this->Xfin = Xfin;
        this->Yfin = Yfin;
}

void tGrafico::damePuntoSingular(int &x, int &y){
        x = Xini;
        y = Yini;
}

void tGrafico::ponPuntoSingular(int x,int y){
        int distanciaX = Xfin - Xini;
        int distanciaY = Yfin - Yini;
        Xini = x;
        Yini = y;
        Xfin = Xini + distanciaX;
        Yfin = Yini + distanciaY;
}

void tGrafico::dibujarCPS(TCanvas *canvas){
        dibujar(canvas);
        canvas->Brush->Color = color;
        canvas->Brush->Style = bsSolid;
        canvas->Rectangle(Xini-5,Yini-5,Xini+5,Yini+5);
}


//---------------------------------------------------------------------------
#pragma package(smart_init)


