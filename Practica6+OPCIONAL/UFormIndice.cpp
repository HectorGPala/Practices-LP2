//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormIndice.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TFormIndice *FormIndice;
//---------------------------------------------------------------------------
__fastcall TFormIndice::TFormIndice(TComponent* Owner,tBST<tNodoIndice*>* &t)
        : TForm(Owner), indice(t)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormIndice::FormCreate(TObject *Sender)
{
        if(indice != NULL)
                indice->mostrar(MemoIndice->Lines);
}
//---------------------------------------------------------------------------
