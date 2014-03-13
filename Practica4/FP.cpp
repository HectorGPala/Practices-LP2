//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FP.h"
#include <fstream>
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormPrincipal *FormPrincipal;
//---------------------------------------------------------------------------
__fastcall TFormPrincipal::TFormPrincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormPrincipal::ColorFondo1Click(TObject *Sender)
{
if(ColorDialog->Execute())
        colorFondo = ColorDialog->Color;
        FormPrincipal->Color = colorFondo;
        Guardar1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::FormCreate(TObject *Sender)
{
        dibujo = new Dibujo();
        archivo="";
        colorFondo = clWhite;
        colorActual = clBlack;
        FormPrincipal->Color = colorFondo;
        poliLineaActual = new Polilinea();//color negro y grosor 1
        poliLineaModificada = NULL;
        punto_a_mover = 0;
        dibujar,elim_punto,elim_poli,mover_punto = false;
        DoubleBuffered = true;
        ForceCurrentDirectory=true;
        Guardar1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::FormPaint(TObject *Sender)
{
        if(elim_poli || elim_punto || mover_punto){
                dibujo->dibujaConVertices(Canvas);
                poliLineaActual->dibujaConVertices(Canvas);
        }
        else{
                dibujo->dibuja(Canvas);
                poliLineaActual->dibuja(Canvas);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::FormDestroy(TObject *Sender)
{
        delete dibujo;
        dibujo=NULL;
        delete poliLineaActual;
        poliLineaActual=NULL;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::FormMouseDown(TObject *Sender,
      TMouseButton b, TShiftState Shift, int X, int Y)
{
        if (dibujar){
                if (b==mbLeft){
                        Guardar1->Enabled = true;
                        Punto *p = new Punto(X,Y,colorActual);
                        poliLineaActual->ponPunto(p);
                }
                else if (b==mbRight){
                        int grosor = poliLineaActual->get_Grosor();
                        dibujo->ponPolilinea(poliLineaActual);
                        poliLineaActual = new Polilinea(grosor);
                        dibujar = false;
                        Polilinea1->Enabled = true;
                }
        }
        if(elim_punto){
                if (b==mbLeft){
                        Guardar1->Enabled = true;
                        for(int i = 0; i < dibujo->num_dibujos();i++){
                                Polilinea *aux = dibujo->dameIesimo(i);
                                for(int j = 0; j < aux->num_puntos();j++){
                                        Punto *p = aux->dameIesimo(j);
                                        int x = p->get_X();
                                        int y = p->get_Y();
                                        if(((X-5<=x)&&(x<=X+5))&&((Y-5<=y)&&(y<=Y+5)))
                                                aux->quitaPunto(j);
                                }
                        }
                }
                else if (b==mbRight){
                        elim_punto = false;
                        Polilinea1->Enabled = true;
                }
        }
        if(elim_poli){
                if (b==mbLeft){
                        Guardar1->Enabled = true;
                        for(int i = 0; i < dibujo->num_dibujos();i++){
                                Polilinea *aux = dibujo->dameIesimo(i);
                                int j = 0;
                                bool encontrado = false;
                                while(!encontrado && j < aux->num_puntos()){
                                        Punto *p = aux->dameIesimo(j);
                                        int x = p->get_X();
                                        int y = p->get_Y();
                                        if(((X-5<=x)&&(x<=X+5))&&((Y-5<=y)&&(y<=Y+5))){
                                                dibujo->quitaPolilinea(i);
                                                encontrado = true;
                                        }
                                        else
                                                j++;
                                }
                        }
                }
                else if (b==mbRight){
                        elim_poli = false;
                        Polilinea1->Enabled = true;
                }
        }
        if(mover_punto){
                punto_a_mover = 0;
                if (b==mbLeft){
                        Guardar1->Enabled = true;
                        Punto *p;
                        for(int i = 0; i < dibujo->num_dibujos();i++){
                                Polilinea *aux = dibujo->dameIesimo(i);
                                int j = 0;
                                bool encontrado = false;
                                while(!encontrado && j < aux->num_puntos()){
                                        p = aux->dameIesimo(j);
                                        int x = p->get_X();
                                        int y = p->get_Y();
                                        if(((X-5<=x)&&(x<=X+5))&&((Y-5<=y)&&(y<=Y+5))){
                                                encontrado = true;
                                                poliLineaModificada = aux;
                                                punto_a_mover = j;
                                        }
                                        else
                                                j++;
                                }
                        }
                }
                else if (b==mbRight){
                        mover_punto = false;
                        poliLineaModificada = NULL;
                        Polilinea1->Enabled = true;
                }
        }
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        if (mover_punto){
                if(poliLineaModificada != NULL){
                        Punto *p = poliLineaModificada->dameIesimo(punto_a_mover);
                        p->setXY(X,Y);
                        Repaint();
                }
                }
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Dibujar1Click(TObject *Sender)
{
elim_punto = false;
elim_poli = false;
mover_punto = false;
dibujar = true;
Repaint();
Polilinea1->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::GrosorLinea1Click(TObject *Sender)
{
        if(ColorDialog->Execute()){
                colorActual = ColorDialog->Color;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::EliminarPunto1Click(TObject *Sender)
{
elim_punto = true;
elim_poli = false;
mover_punto = false;
dibujar = false;
Repaint();
Polilinea1->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::N11Click(TObject *Sender)
{
poliLineaActual->setGrosor(1);
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::N21Click(TObject *Sender)
{
poliLineaActual->setGrosor(2);
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::N31Click(TObject *Sender)
{
poliLineaActual->setGrosor(3);
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::EliminarPolilinea1Click(TObject *Sender)
{
elim_punto = false;
elim_poli = true;
mover_punto = false;
dibujar = false;
Repaint();
Polilinea1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::MoverPunto1Click(TObject *Sender)
{
elim_punto = false;
elim_poli = false;
mover_punto = true;
dibujar = false;
Repaint();
Polilinea1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::GuardarComo1Click(TObject *Sender)
{
        if(SaveDialog1->Execute()){
                ofstream f;
                archivo = SaveDialog1->FileName;
                f.open(archivo.c_str(),ios::binary);
                f.write((char*)&colorFondo,sizeof(TColor));
                dibujo->guardar(f);
                f.close();
                Guardar1->Enabled = false;
        }
        Repaint();


}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Abrir1Click(TObject *Sender)
{
        if(OpenDialog1->Execute()){
                ifstream f;
                archivo = OpenDialog1->FileName;
                f.open(archivo.c_str(),ios::binary);
                f.read((char*)&colorFondo,sizeof(TColor));
                FormPrincipal->Color = colorFondo;
                delete dibujo;
                delete poliLineaActual;
                dibujo = new Dibujo();
                poliLineaActual = new Polilinea();
                dibujo->cargar(f);
                f.close();
        }
        Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::Salir1Click(TObject *Sender)
{
        if(MessageDlg("Seguro?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
                Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormPrincipal::Nuevo1Click(TObject *Sender)
{
        delete dibujo;
        delete poliLineaActual;
        dibujo = new Dibujo();
        archivo="";
        colorFondo = clWhite;
        colorActual = clBlack;
        FormPrincipal->Color = colorFondo;
        poliLineaActual = new Polilinea();
        poliLineaModificada = NULL;
        punto_a_mover = 0;
        Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TFormPrincipal::Guardar1Click(TObject *Sender)
{
        if(archivo != ""){
                ofstream f;
                f.open(archivo.c_str(),ios::binary);
                f.write((char*)&colorFondo,sizeof(TColor));
                dibujo->guardar(f);
                f.close();
                Guardar1->Enabled = false;
                Repaint();
        }
        else
                if(SaveDialog1->Execute()){
                        ofstream f;
                        archivo = SaveDialog1->FileName;
                        f.open(archivo.c_str(),ios::binary);
                        f.write((char*)&colorFondo,sizeof(TColor));
                        dibujo->guardar(f);
                        f.close();
                        Repaint();
                }

}
//---------------------------------------------------------------------------

