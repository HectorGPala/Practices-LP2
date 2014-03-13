//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMenu *FormMenu;
//---------------------------------------------------------------------------
__fastcall TFormMenu::TFormMenu(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::FormCreate(TObject *Sender)
{
        FormMenu->Color = clWhite;
        Canvas->Pen->Color = clBlack;
        Canvas->Pen->Width = grosor = 1;
        Canvas->Font->Size = tam = 10;
        Canvas->Font->Color = col = clBlack;
        dibujar = copiar = mover = borrar = false;
        texto = linea = rectangulo = elipse = bmp = false;
        relleno = sel = false;
        DoubleBuffered = true;
        fichero = f_bmp = "";
        g = NULL;
        //EL DIBUJO SE INICIA SOLO PORQUE ES UNA VAR ESTATICA
}
//---------------------------------------------------------------------------
void __fastcall TFormMenu::ButtonTamClick(TObject *Sender)
{
        int t = 0;
        TForm *x = new TFormAux(this,t);
        x->Caption = "Tamaño Fuente";
        x->ShowModal();
        if(x->ModalResult == mrOk){
                tam = t;
                Canvas->Font->Size = t;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonGrosorClick(TObject *Sender)
{
        int t = 1;
        TForm *x = new TFormAux(this,t);
        x->Caption = "Grosor";
        x->ShowModal();
        if(x->ModalResult == mrOk){
                grosor = t;
                Canvas->Pen->Width = t;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::Salir1Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormPaint(TObject *Sender)
{
        if(sel){
                int n = dibujo.dameNum_Elem();
                for(int i = 0; i < n;i++)
                        dibujo[i]->dibujarCPS(Canvas);
                if(g != NULL)
                        g->dibujarCPS(Canvas);
        }
        else{
                int n = dibujo.dameNum_Elem();
                for(int i = 0; i < n;i++)
                        dibujo[i]->dibujar(Canvas);
                if(g != NULL)
                        g->dibujar(Canvas);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(dibujar){
                if(texto)
                        g = new tTexto(X,Y,X,Y,col,relleno,tam);
                else if(rectangulo)
                        g = new tRectangulo(X,Y,X,Y,col,relleno,grosor);
                else if(elipse)
                        g = new tElipse(X,Y,X,Y,col,relleno,grosor);
                else if(linea)
                        g = new tLinea(X,Y,X,Y,col,relleno,grosor);
                else if(bmp)
                        g = new tBMP(X,Y,f_bmp);
        }
        else if(borrar){
                int i = 0;
                bool fin = false;
                int x,y;
                while((i < dibujo.dameNum_Elem())&&(!fin)){
                        dibujo[i]->damePuntoSingular(x,y);
                        if(((X-5<=x)&&(x<=X+5))&&((Y-5<=y)&&(y<=Y+5))){
                                fin = true;
                                dibujo.quitaIesimo(i);
                        }
                        i++;
                }
        }
        else if(mover){
                int i = 0;
                bool fin = false;
                int x,y;
                while((i < dibujo.dameNum_Elem())&&(!fin)){
                        dibujo.dameIesimo(i)->damePuntoSingular(x,y);
                        if(((X-5<=x)&&(x<=X+5))&&((Y-5<=y)&&(y<=Y+5))){
                                fin = true;
                                sel = false;
                                g = dibujo.dameIesimo(i);
                        }
                        i++;
                }
        }
        else if(copiar){
                int i = 0;
                bool fin = false;
                int x,y;
                while((i < dibujo.dameNum_Elem())&&(!fin)){
                        dibujo[i]->damePuntoSingular(x,y);
                        if(((X-5<=x)&&(x<=X+5))&&((Y-5<=y)&&(y<=Y+5))){
                                fin = true;
                                sel = false;
                                g = dibujo[i]->copiar();
                        }
                        i++;
                }
        }
        Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TFormMenu::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        if((dibujar)&&(g != NULL)&&(!texto)){
                int x,y;
                g->damePuntoSingular(x,y);
                g->ponCoordenadas(x,y,X,Y);
        }
        if((copiar || mover)&&(g != NULL))
                g->ponPuntoSingular(X,Y);
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::FormMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if(g!= NULL){
                if(mover)
                        g = NULL;
                else if(!texto){
                        dibujo.ponElem(g);
                        g = NULL;
                }
        }
        Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TFormMenu::FormKeyPress(TObject *Sender, char &Key)
{
        if(g!= NULL)
        if(typeid(*g) == typeid(tTexto)){
                if (Key=='\r'){
                        dibujo.ponElem(g);
                        g = NULL;
                }
                else
                        if (Key=='\b')((tTexto*)g)->borraChar();
                else
                        ((tTexto*)g)->ponChar(Key);
        }
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonSelectClick(TObject *Sender)
{
        sel = !sel;
        linea = false;
        texto = false;
        rectangulo = false;
        elipse = false;
        bmp = false;
        Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TFormMenu::GuardarComo1Click(TObject *Sender)
{
        if(SaveDialog->Execute()){
                ofstream f;
                fichero = SaveDialog->FileName.c_str();
                f.open(fichero.c_str());
                int n = dibujo.dameNum_Elem();
                for(int i = 0;i<n;i++)
                        dibujo[i]->salvar(f);
                f.close();
        }
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::Abrir1Click(TObject *Sender)
{
        if(OpenDialog->Execute()){
                ifstream f;
                fichero = OpenDialog->FileName.c_str();
                f.open(fichero.c_str());
                dibujo.inicializa();
                int i = 0;
                while(!(f.eof())){
                        string tipo;
                        f >> tipo;
                        if(tipo != ""){
                                if(tipo == "\\Rectangulo")
                                        g = new tRectangulo();
                                else if(tipo == "\\Elipse")
                                        g = new tElipse();
                                else if(tipo == "\\Linea")
                                        g = new tLinea();
                                else if(tipo == "\\Texto")
                                        g = new tTexto();
                                else if(tipo == "\\BMP")
                                        g = new tBMP();
                                else{
                                throw Exception("Error de lectura!");
                                }
                                i++;//NUMERO DE LINEA QUE SE VA LEER
                                try{g->cargar(f);}
                                catch(const Exception &E){
                                        AnsiString mensaje = "Error de lectura en linea: "+IntToStr(i)+"\n"+E.Message;
                                        ShowMessage(mensaje);
                                        delete g;
                                        g = NULL;
                                }
                                if(g!=NULL){
                                        dibujo.ponElem(g);
                                        g = NULL;
                                }
                        }
                }
                f.close();
        }
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonFuenteClick(TObject *Sender)
{
        dibujar = true;
        texto = true;
        linea = false;
        rectangulo = false;
        elipse = false;
        bmp = false;
        copiar = mover = borrar = false;
        sel = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonLineaClick(TObject *Sender)
{
        dibujar = true;
        linea = true;
        texto = false;
        rectangulo = false;
        elipse = false;
        bmp = false;
        copiar = mover = borrar = false;
        sel = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonRectanguloClick(TObject *Sender)
{
        dibujar = true;
        linea = false;
        texto = false;
        rectangulo = true;
        elipse = false;
        bmp = false;
        copiar = mover = borrar = false;
        sel = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonElipseClick(TObject *Sender)
{
        dibujar = true;
        linea = false;
        texto = false;
        rectangulo = false;
        elipse = true;
        bmp = false;
        copiar = mover = borrar = false;
        sel = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonRellenoClick(TObject *Sender)
{
        relleno = !relleno;
        ButtonRelleno->Marked = !ButtonRelleno->Marked;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonColorClick(TObject *Sender)
{
        if(ColorDialog->Execute())
                col = ColorDialog->Color;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonFondoClick(TObject *Sender)
{
        if(ColorDialog->Execute())
                FormMenu->Color = ColorDialog->Color;
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonBMPClick(TObject *Sender)
{
        dibujar = true;
        linea = false;
        texto = false;
        rectangulo = false;
        elipse = false;
        bmp = true;
        copiar = mover = borrar = false;
        sel = false;
        if(OpenDialog->Execute()){
                ifstream f;
                f_bmp = OpenDialog->FileName.c_str();
        }
}
//---------------------------------------------------------------------------


void __fastcall TFormMenu::ButtonClearClick(TObject *Sender)
{
        if(!sel)
                ShowMessage("Marque seleccionar para señalar Punto Singular");
        else{
                borrar = true;
                dibujar = mover = copiar = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonMoverClick(TObject *Sender)
{
        if(!sel)
                ShowMessage("Marque seleccionar para señalar Punto Singular");
        else{
                mover = true;
                dibujar = borrar = copiar = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::Nuevo1Click(TObject *Sender)
{
        dibujo.inicializa();
        f_bmp = fichero = "";
        Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::ButtonCopiarClick(TObject *Sender)
{
if(!sel)
                ShowMessage("Marque seleccionar para señalar Punto Singular");
        else{
                copiar = true;
                dibujar = mover = borrar = false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormMenu::Guardar1Click(TObject *Sender)
{
        ofstream f;
        if(fichero == "")
                throw Exception("No se ha seleccionado un fichero, Use Guardar Como");
        try{
        f.open(fichero.c_str());
        }
        catch(const Exception &E){ShowMessage(E.Message);}
        int n = dibujo.dameNum_Elem();
        for(int i = 0;i<n;i++)
                dibujo[i]->salvar(f);
        f.close();
        Repaint();
}
//---------------------------------------------------------------------------
