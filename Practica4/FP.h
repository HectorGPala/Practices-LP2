//---------------------------------------------------------------------------

#ifndef FPH
#define FPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include "Polilinea.h"
#include "UtDibujo.h"

//---------------------------------------------------------------------------
class TFormPrincipal : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Polilinea1;
        TMenuItem *Dibujar1;
        TMenuItem *EliminarPunto1;
        TMenuItem *EliminarPolilinea1;
        TMenuItem *MoverPunto1;
        TMenuItem *ColorFondo1;
        TMenuItem *GrosorLinea1;
        TMenuItem *GrosordeLinea1;
        TMenuItem *Archivo1;
        TMenuItem *Abrir1;
        TMenuItem *Guardar1;
        TMenuItem *GuardarComo1;
        TMenuItem *Salir1;
        TColorDialog *ColorDialog;
        TMenuItem *N11;
        TMenuItem *N21;
        TMenuItem *N31;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *Nuevo1;
        void __fastcall ColorFondo1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Dibujar1Click(TObject *Sender);
        void __fastcall GrosorLinea1Click(TObject *Sender);
        void __fastcall EliminarPunto1Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
        void __fastcall N31Click(TObject *Sender);
        void __fastcall EliminarPolilinea1Click(TObject *Sender);
        void __fastcall MoverPunto1Click(TObject *Sender);
        void __fastcall GuardarComo1Click(TObject *Sender);
        void __fastcall Abrir1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall Nuevo1Click(TObject *Sender);
        void __fastcall Guardar1Click(TObject *Sender);
private:
        Dibujo *dibujo;
        Polilinea *poliLineaActual,*poliLineaModificada;
        AnsiString archivo;
        TColor colorFondo,colorActual;
        bool dibujar,elim_punto,elim_poli,mover_punto;
        int punto_a_mover;/*es el indice que ocupa el punto en polilineaModificada
                          si se recalcula todo el rato el movimiento pierde fluidez*/
public:
        __fastcall TFormPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPrincipal *FormPrincipal;
//---------------------------------------------------------------------------
#endif
