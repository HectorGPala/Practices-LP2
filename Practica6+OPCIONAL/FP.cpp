//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

bool TForm1::comparaString(String c,String d){
        int n = c.Length();
        for(int i = 1; i <= n;i++)
                c[i] = UpCase(c[i]);
        n = d.Length();
        for(int i = 1; i <= n;i++)
                d[i] = UpCase(d[i]);
        return d == c;
}

void __fastcall TForm1::Aadir1Click(TObject *Sender)
{
        String t = "";
        while(t == ""){
                TForm *x = new TFormAux(this,t);
                x->Caption = "Añadir Palabra";
                x->ShowModal();
                if(x->ModalResult == mrOk){
                        if(t != ""){
                                filtro->insertar(t);
                                Guardar->Enabled = true;
                        }
                        else
                                ShowMessage("No se puede introducir");
                }
                else
                        t = " ";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Eliminar1Click(TObject *Sender)
{
        String t = "";
        while(t == ""){
                TForm *x = new TFormAux(this,t);
                x->Caption = "Eliminar Palabra";
                x->ShowModal();
                if(x->ModalResult == mrOk){
                        if(t != ""){
                                try{filtro = filtro->eliminar(t);}
                                catch(const Exception &E){ShowMessage(E.Message);}
                                Guardar->Enabled = true;
                        }
                        else
                                ShowMessage("Introduzca palabra!");
                }
                else
                        t = " ";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
        delete filtro;
        delete indice;
        delete seccion;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::GuardarComoClick(TObject *Sender)
{
        if(SaveDialog->Execute()){
                fichero_filtro = SaveDialog->FileName;
                ofstream f;
                f.open(fichero_filtro.c_str());
                filtro->guardar(f);
                f.close();
                Guardar->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cargar2Click(TObject *Sender)
{
        if(OpenDialog->Execute()){
                fichero_filtro = OpenDialog->FileName;
                ifstream f;
                f.open(fichero.c_str());
                delete filtro;
                filtro = new tBST<String>();
                filtro->cargar(f);
                f.close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Nuevo1Click(TObject *Sender)
{
        delete filtro;
        filtro = new tBST<String>();
        Guardar->Enabled = false;
        fichero_filtro = "";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Mostrar1Click(TObject *Sender)
{
        TForm *x = new TFormFiltro(this,filtro,indice);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        filtro = new tBST<String>();
        indice = NULL;
        seccion = NULL;
        Guardar->Enabled = false;
        Guardar1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cargar1Click(TObject *Sender)
{
        if(OpenDialog->Execute()){
                fichero = OpenDialog->FileName;
                Memo->Clear();
                Memo->Lines->LoadFromFile(fichero.c_str());
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Generar1Click(TObject *Sender)
{
        delete indice;
        indice = new tBST<tNodoIndice*>();
        int long_memo = Memo->Lines->Count;
        int num_pagina = 1;
        for(int i = 0; i < long_memo;i++){
                AnsiString linea = Memo->Lines->Strings[i];
                procesaLinea(linea,num_pagina);
        }
}
//---------------------------------------------------------------------------

void TForm1::procesaLinea(AnsiString linea,int &num_pagina){
        int i = 1;
        int long_linea = linea.Length();
        while(i <= long_linea){
                saltarBlancos(linea,i);
                AnsiString palabra = "";
                leerPalabra(linea,i,palabra);
                if(palabra == "\\newpage")
                        num_pagina++;
                else{
                        if((palabra != "\\seccion") && (palabra != "\\subseccion") &&
                        (palabra != "\\subsubseccion") && (palabra != "")){
                                char letra = palabra[1];
                                tBST<String>* aux;
                                if(!filtro->buscaPos(palabra,aux)){
                                        tNodoIndice* ni = new tNodoIndice(letra,palabra,num_pagina);
                                        indice->insertar(ni);
                                        delete ni;
                                }
                        }
                }
        }
}

void TForm1::procesaLineaGeneral(AnsiString linea,int &num_pagina,int &sec,int &subsec,int &subsub){
        int i = 1;
        int long_linea = linea.Length();
        while(i <= long_linea){
                saltarBlancos(linea,i);
                AnsiString palabra;
                AnsiString cad;
                if(i < long_linea){
                        leerPalabra(linea,i,palabra);
                        if(palabra == "\\seccion"){
                                sec++;
                                subsec = subsub = 0;
                                leerRestoLinea(linea,i,cad);
                                AnsiString n_sec;
                                dameSec(sec,subsec,subsub,n_sec);
                                tSeccion s = tSeccion(cad,n_sec,num_pagina);
                                seccion->insertar(s);
                        }
                        else
                        if(palabra == "\\subseccion"){
                                subsec++;
                                subsub = 0;
                                leerRestoLinea(linea,i,cad);
                                AnsiString n_sec;
                                dameSec(sec,subsec,subsub,n_sec);
                                tSeccion s = tSeccion(cad,n_sec,num_pagina);
                                seccion->insertar(s);
                        }
                        else
                        if(palabra == "\\subsubseccion"){
                                subsub++;
                                leerRestoLinea(linea,i,cad);
                                AnsiString n_sec;
                                dameSec(sec,subsec,subsub,n_sec);
                                tSeccion s = tSeccion(cad,n_sec,num_pagina);
                                seccion->insertar(s);
                        }
                        if(palabra == "\\newpage")
                                num_pagina++;
                }
                else
                        i++;
        }
}

void TForm1::saltarBlancos(AnsiString linea,int &i){
        int n = linea.Length();
        while((i <= n) && (linea[i] == ' '))
                i++;
}

void TForm1::leerPalabra(AnsiString linea,int &i,AnsiString &palabra){
        int n = linea.Length();
        while((i <= n) && (linea[i] != ' ') ){
                palabra = palabra + linea[i];
                i++;
        }
}

void __fastcall TForm1::Mostrar2Click(TObject *Sender)
{
        TForm *x = new TFormGeneral(this,seccion);
        x->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Generar2Click(TObject *Sender)
{
        delete seccion;
        seccion = new tListaOrd<tSeccion>();
        int long_memo = Memo->Lines->Count;
        int num_pagina = 1;
        int sec,subsec,subsub;
        sec = subsec = subsub = 0;
        for(int i = 0; i < long_memo;i++){
                AnsiString linea = Memo->Lines->Strings[i];
                procesaLineaGeneral(linea,num_pagina,sec,subsec,subsub);
        }
}

void TForm1::leerRestoLinea(AnsiString linea,int &i,AnsiString &cad){
        cad = "";
        int n = linea.Length();
        for(int j = i;j <= n;j++)
                cad = cad + linea[j];
}

void TForm1::dameSec(const int &sec,const int &subsec,const int &subsub,AnsiString &n_sec){
        n_sec ="";
        n_sec = n_sec + IntToStr(sec);
        if(subsec > 0)
                n_sec = n_sec + '.' + IntToStr(subsec);
        if(subsub > 0)
                n_sec = n_sec + '.' + IntToStr(subsub);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Nuevo2Click(TObject *Sender)
{
        Memo->Clear();
        fichero = "";
        Guardar1->Enabled = false;        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::GuardarComo1Click(TObject *Sender)
{
        if(SaveDialog->Execute()){
                fichero = SaveDialog->FileName;
                Memo->Lines->SaveToFile(fichero.c_str());
                Guardar1->Enabled = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Guardar1Click(TObject *Sender)
{
        if(fichero != ""){
                Memo->Lines->SaveToFile(fichero.c_str());
                Guardar1->Enabled = false;
        }
        else
                GuardarComo1Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GuardarClick(TObject *Sender)
{
        if(fichero_filtro != ""){
                ofstream f;
                f.open(fichero_filtro.c_str());
                filtro->guardar(f);
                f.close();
                Guardar->Enabled = false;
        }
        else
                GuardarComoClick(Sender);                
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MemoKeyPress(TObject *Sender, char &Key)
{
        Guardar1->Enabled = true;
}
//---------------------------------------------------------------------------

