//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UBmp.h"

//---------------------------------------------------------------------------

tBMP::tBMP(int Xin,int Yin,const string &fich)throw (Exception):tGrafico(){
        Xini = Xin;
        Yini = Yin;
        nombre = fich;
        bmp = new Graphics::TBitmap();
        try{bmp->LoadFromFile(nombre.c_str());}
        catch(const Exception &E){
        string texto = "Error de lectura: "+nombre+" BMP";
        throw Exception(texto.c_str());}
}

tBMP::~tBMP(){
        delete bmp;
        nombre = "";
}

void tBMP::dibujar(TCanvas *canvas){
        canvas->Draw(Xini,Yini,bmp);
}

void tBMP::dibujarCPS(TCanvas *canvas){
        dibujar(canvas);
        canvas->Brush->Color = color;
        canvas->Brush->Style = bsSolid;
        canvas->Rectangle(Xini-5,Yini-5,Xini+5,Yini+5);
}
void tBMP::salvar(ofstream& archivo){
        archivo << "\\BMP" << " \\Xini " << Xini
        << " \\Yini " << Yini << " \\Archivo " << nombre << "\n";
}

void tBMP::cargar(ifstream& archivo)throw (Exception){
        string id;
        int aux;
        archivo >> id;
        archivo >> id;//Xini
        try{Xini = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Xini BMP");}
        archivo >> id;archivo >> id;//Yini
        try{Yini = StrToInt(id.c_str());}
        catch(const EConvertError &E){
        string a;
        getline(archivo,a);
        throw EConvertError("Error de lectura Yini BMP");}
        archivo >> id;archivo >> nombre;//fich_bmp
        //bmp = new Graphics::TBitmap(); // El bmp ya se crea con la tBMP()
        try{bmp->LoadFromFile(nombre.c_str());}
        catch(const Exception &E){
        string a;
        getline(archivo,a);
        string texto = "Error de lectura: "+nombre+" BMP";
        throw Exception(texto.c_str());}
}

tGrafico* tBMP::copiar(){
        tGrafico *aux = new tBMP(Xini,Yini,nombre);
        return aux;
}


#pragma package(smart_init)
