//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UTexto.h"

//---------------------------------------------------------------------------
tTexto::tTexto(int Xini,int Yini,int Xfin,int Yfin,TColor c,bool r,int g):
tGrafico(Xini,Yini,Xfin,Yfin,c,r,g){
        tam = g;
        cadena = "";
}

void tTexto::ponChar(char c){
        cadena = cadena+c;
}

void tTexto::borraChar(){
        cadena.Delete(cadena.Length(),1);
}

void tTexto::dibujar(TCanvas *canvas){
        canvas->Font->Size = tam;
        canvas->Font->Color = color;
        canvas->Brush->Style = bsClear;
        canvas->MoveTo(Xini,Yini);
        canvas->TextOut(Xini,Yini,cadena);
}

void tTexto::dibujarCPS(TCanvas *canvas){
        dibujar(canvas);
        canvas->Brush->Color = color;
        canvas->Brush->Style = bsSolid;
        canvas->Rectangle(Xini-5,Yini-5,Xini+5,Yini+5);
}

void tTexto::salvar(ofstream& archivo){
        archivo << "\\Texto" << " \\Xini " << Xini
        << " \\Yini " << Yini << " \\Cadena " << cadena.c_str() << " \\TamFuente " << tam
        << " \\Color " << color << "\n";
}
void tTexto::cargar(ifstream& archivo){
        string id;
        int aux;
        archivo >> id;
        archivo >> id;//Xini
        try{Xini = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Xini TEXTO");}
        archivo >> id;archivo >> id;//Yini
        try{Yini = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Yini TEXTO");}
        archivo >> id;archivo >> id;//cadena
        while((id != "\\TamFuente")){
                cadena = cadena+" "+id.c_str();
                archivo >> id;
        }
        archivo >> id;//Tam
        try{tam = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Tamaño TEXTO");}
        archivo >> id;archivo >> id;//Color
        try{(int)color = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        throw EConvertError("Error de lectura Color TEXTO");}
}

tGrafico* tTexto::copiar(){
        tGrafico *a = new tTexto(Xini,Yini,Xfin,Yfin,color,relleno,grosor);
        ((tTexto*) a)->cadena = cadena;
        ((tTexto*) a)->tam = tam;
        return a;
}



#pragma package(smart_init)
