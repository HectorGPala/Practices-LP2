//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ULinea.h"

//---------------------------------------------------------------------------
tLinea::tLinea(int Xini,int Yini,int Xfin,int Yfin,TColor c,bool r,int g):
                tGrafico(Xini,Yini,Xfin,Yfin,c,r,g){};


void tLinea::dibujar(TCanvas *canvas){
        canvas->Pen->Width = grosor;
        canvas->Pen->Color = color;
        canvas->MoveTo(Xini,Yini);
        canvas->LineTo(Xfin,Yfin);
}

void tLinea::dibujarCPS(TCanvas *canvas){
        dibujar(canvas);
        canvas->Brush->Color = color;
        canvas->Brush->Style = bsSolid;
        canvas->Rectangle(Xini-5,Yini-5,Xini+5,Yini+5);
}

void tLinea::salvar(ofstream& archivo){
        archivo << "\\Linea" << " \\Xini " << Xini
        << " \\Yini " << Yini << " \\Xfin " << Xfin << " \\Yfin " << Yfin
        << " \\Grosor " << grosor << " \\Color "
        << color << "\n";
}

void tLinea::cargar(ifstream& archivo){
        string id;
        int aux;
        archivo >> id;
        archivo >> id;//Xini
        try{Xini = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Xini LINEA");}
        archivo >> id;archivo >> id;//Yini
        try{Yini = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Yini LINEA");}
        archivo >> id;archivo >> id;//Xfin
        try{Xfin = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Xfin LINEA");}
        archivo >> id;archivo >> id;//Yfin
        try{Yfin = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Yfin LINEA");}
        archivo >> id;archivo >> id;//Grosor
        try{grosor = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Grosor LINEA");}
        archivo >> id;archivo >> id;//Color
        try{(int)color = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        throw EConvertError("Error de lectura Color LINEA");}
}

tGrafico* tLinea::copiar(){
        tGrafico *a = new tLinea(Xini,Yini,Xfin,Yfin,color,relleno,grosor);
        return a;
}


#pragma package(smart_init)
