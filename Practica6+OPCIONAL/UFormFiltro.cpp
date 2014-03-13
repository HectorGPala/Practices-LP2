//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormFiltro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TFormFiltro *FormFiltro;
//---------------------------------------------------------------------------
__fastcall TFormFiltro::TFormFiltro(TComponent* Owner,tBST<String>* &t,tBST<tNodoIndice*>* &x)
        : TForm(Owner),filtro(t),indice(x)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormFiltro::FormCreate(TObject *Sender)
{
        filtro->mostrar(MemoFiltro->Lines);
        TForm *y = new TFormIndice(this,indice);
        Show();
        y->ShowModal();
        Close();
}
//---------------------------------------------------------------------------
