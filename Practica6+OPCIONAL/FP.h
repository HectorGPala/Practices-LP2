//---------------------------------------------------------------------------

#ifndef FPH
#define FPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include "UNodoIndice.h"//Nodo indice que se insertan en el ARBOL INDICE
#include "UBST.h"//ARBOL
#include "USeccion.h"//Clase seccion PARTE OPCIONAL
#include "UFormAux.h"//Form para introducir o borrar palabras al filtro
#include "UFormFiltro.h"// Form que muestra el filtro
#include "UFormGeneral.h"//Form que muestra INDICE GENERAL PARTE OPCIONAL
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *IndicedePalabras1;
        TMenuItem *Generar1;
        TMenuItem *Mostrar1;
        TMenuItem *Archivo1;
        TMenuItem *Guardar1;
        TMenuItem *Cargar1;
        TMenuItem *Filtro1;
        TMemo *Memo;
        TLabel *Label1;
        TMenuItem *Nuevo1;
        TMenuItem *Guardar;
        TMenuItem *GuardarComo;
        TMenuItem *Cargar2;
        TMenuItem *IndiceGeneral1;
        TMenuItem *N1;
        TMenuItem *Aadir1;
        TMenuItem *Eliminar1;
        TMenuItem *N2;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TMenuItem *Generar2;
        TMenuItem *Mostrar2;
        TMenuItem *Nuevo2;
        TMenuItem *N3;
        TMenuItem *GuardarComo1;
        void __fastcall Aadir1Click(TObject *Sender);
        void __fastcall Eliminar1Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall GuardarComoClick(TObject *Sender);
        void __fastcall Cargar2Click(TObject *Sender);
        void __fastcall Nuevo1Click(TObject *Sender);
        void __fastcall Mostrar1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Cargar1Click(TObject *Sender);
        void __fastcall Generar1Click(TObject *Sender);
        void __fastcall Mostrar2Click(TObject *Sender);
        void __fastcall Generar2Click(TObject *Sender);
        void __fastcall Nuevo2Click(TObject *Sender);
        void __fastcall GuardarComo1Click(TObject *Sender);
        void __fastcall Guardar1Click(TObject *Sender);
        void __fastcall GuardarClick(TObject *Sender);
        void __fastcall MemoKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:
        bool comparaString(String c,String d);//Compara strings aunque tengan minusculas o mayusculas
        void procesaLinea(AnsiString linea,int &num_pagina);
        void procesaLineaGeneral(AnsiString linea,int &num_pagina,int &sec,int &subsec,int &subsub);
        void saltarBlancos(AnsiString linea,int &i);
        void leerPalabra(AnsiString linea,int &i,AnsiString &palabra);
        void leerRestoLinea(AnsiString linea,int &i,AnsiString &cad);
        void dameSec(const int &sec,const int &subsec,const int &subsub,AnsiString &n_sec);//Componer seccion Ejemplo: 1.2.3
        tBST<tNodoIndice*>* indice;//arbol de NodoIndice que guarda el indice de palabras
        tBST<String>* filtro; //arbol de Strings que guarda todas las palabras del filtro
        tListaOrd<tSeccion>* seccion;//lista de secciones
        AnsiString fichero,fichero_filtro;
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
