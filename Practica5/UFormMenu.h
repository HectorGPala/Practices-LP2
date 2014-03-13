//---------------------------------------------------------------------------

#ifndef UFormMenuH
#define UFormMenuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
#include "UFormAux.h"
#include "UGrafico.h"
#include "URectangulo.h"
#include "UElipse.h"
#include "UTexto.h"
#include "ULinea.h"
#include "UBMP.h"
#include <Dialogs.hpp>
#include "UVector.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormMenu : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ButtonFuente;
        TToolButton *ButtonLinea;
        TToolButton *ButtonRectangulo;
        TToolButton *ButtonElipse;
        TToolButton *ButtonTam;
        TToolButton *ButtonRelleno;
        TToolButton *ButtonColor;
        TToolButton *ButtonGrosor;
        TToolButton *ButtonFondo;
        TToolButton *ButtonSelect;
        TToolButton *ButtonClear;
        TToolButton *ButtonMover;
        TToolButton *ButtonCopiar;
        TToolButton *ButtonPixel;
        TToolButton *ButtonBMP;
        TImageList *ImageList1;
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *Nuevo1;
        TMenuItem *N1;
        TMenuItem *Abrir1;
        TMenuItem *Guardar1;
        TMenuItem *GuardarComo1;
        TMenuItem *N2;
        TMenuItem *Salir1;
        TOpenDialog *OpenDialog;
        TSaveDialog *SaveDialog;
        TColorDialog *ColorDialog;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonTamClick(TObject *Sender);
        void __fastcall ButtonGrosorClick(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall ButtonSelectClick(TObject *Sender);
        void __fastcall GuardarComo1Click(TObject *Sender);
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall ButtonFuenteClick(TObject *Sender);
        void __fastcall ButtonLineaClick(TObject *Sender);
        void __fastcall ButtonRectanguloClick(TObject *Sender);
        void __fastcall ButtonElipseClick(TObject *Sender);
        void __fastcall ButtonRellenoClick(TObject *Sender);
        void __fastcall ButtonColorClick(TObject *Sender);
        void __fastcall ButtonFondoClick(TObject *Sender);
        void __fastcall ButtonBMPClick(TObject *Sender);
        void __fastcall ButtonClearClick(TObject *Sender);
        void __fastcall ButtonMoverClick(TObject *Sender);
        void __fastcall Nuevo1Click(TObject *Sender);
        void __fastcall ButtonCopiarClick(TObject *Sender);
        void __fastcall Guardar1Click(TObject *Sender);
private:
        tVector<tGrafico> dibujo;//vector con todos los graficos salvo actual
        tGrafico *g;//grafico actual
        int grosor,tam;
        bool dibujar,copiar,mover,borrar;//acciones para los dibujos
        bool texto,linea,rectangulo,elipse,bmp;//tipos de dibujo disponibles
        bool relleno,sel;//rellenarse y poner punto singular
        string f_bmp,fichero;//f_bmp indica la ubicacion del fichero bmp que se dibuja y fichero el fichero para guardar
        TColor col;//Color actual para dibujar
public:
        	// User declarations
        __fastcall TFormMenu(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMenu *FormMenu;
//---------------------------------------------------------------------------
#endif
