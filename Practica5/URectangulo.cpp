//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "URectangulo.h"

//---------------------------------------------------------------------------
tRectangulo::tRectangulo(int Xini,int Yini,int Xfin,int Yfin,TColor c,bool r,int g):
                tGrafico(Xini,Yini,Xfin,Yfin,c,r,g){};

void tRectangulo::dibujar(TCanvas *canvas){
        canvas->Brush->Color = color;
        if(relleno == false)
                canvas->Brush->Style = bsClear;
        else
                canvas->Brush->Style = bsSolid;
        canvas->Pen->Width = grosor;
        canvas->Pen->Color = color;
        canvas->Rectangle(Xini,Yini,Xfin,Yfin);
}

void tRectangulo::dibujarCPS(TCanvas *canvas){
        dibujar(canvas);
        canvas->Brush->Color = color;
        canvas->Brush->Style = bsSolid;
        canvas->Rectangle(Xini-5,Yini-5,Xini+5,Yini+5);
}

void tRectangulo::salvar(ofstream& archivo){
        archivo << "\\Rectangulo" << " \\Xini " << Xini
        << " \\Yini " << Yini << " \\Xfin " << Xfin << " \\Yfin " << Yfin
        << " \\Grosor " << grosor << " \\Color "
        << color << " \\Relleno " << relleno << "\n";
}
void tRectangulo::cargar(ifstream& archivo)throw (EConvertError){
        string id;
        int aux;
        archivo >> id;
        archivo >> id;//Xini
        try{Xini = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Xini RECTANGULO");}
        archivo >> id;archivo >> id;//Yini
        try{Yini = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Yini RECTANGULO");}
        archivo >> id;archivo >> id;//Xfin
        try{Xfin = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Xfin RECTANGULO");}
        archivo >> id;archivo >> id;//Yfin
        try{Yfin = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Yfin RECTANGULO");}
        archivo >> id;archivo >> id;//Grosor
        try{grosor = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Grosor RECTANGULO");}
        archivo >> id;archivo >> id;//Color
        try{(int)color = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Color RECTANGULO");}
        archivo >> id;archivo >> id;//Relleno
        try{relleno = StrToInt(id.c_str());}
        catch(const EConvertError &E){throw EConvertError("Error de lectura Relleno RECTANGULO");}
}

tGrafico* tRectangulo::copiar(){
        tRectangulo *a = new tRectangulo(Xini,Yini,Xfin,Yfin,color,relleno,grosor);
        return a;
}

#pragma package(smart_init)
