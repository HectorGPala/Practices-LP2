//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormAux.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TFormAux *FormAux;
//---------------------------------------------------------------------------
__fastcall TFormAux::TFormAux(TComponent* Owner,String &x)
        : TForm(Owner),t(x)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormAux::ButtonAceptarClick(TObject *Sender)
{
        t = Edit->Text;
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TFormAux::ButtonCancelarClick(TObject *Sender)
{
        ModalResult = mrCancel;
}
//---------------------------------------------------------------------------



