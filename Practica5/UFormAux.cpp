//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormAux.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TFormAux *FormAux;
//---------------------------------------------------------------------------
__fastcall TFormAux::TFormAux(TComponent* Owner,int &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormAux::Button2Click(TObject *Sender)
{
        ModalResult = mrCancel;
}
//---------------------------------------------------------------------------


void __fastcall TFormAux::Button1Click(TObject *Sender)
{
        t = StrToInt(ComboBox->Text);
        ModalResult = mrOk;
}
//---------------------------------------------------------------------------




void __fastcall TFormAux::FormCreate(TObject *Sender)
{
if (t == 0){
        ComboBox->Items->Add("10");
        ComboBox->Items->Add("12");
        ComboBox->Items->Add("14");
}
else{
        ComboBox->Items->Add("1");
        ComboBox->Items->Add("2");
        ComboBox->Items->Add("3");
        ComboBox->Items->Add("4");
}
}
//---------------------------------------------------------------------------

