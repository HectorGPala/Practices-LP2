//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormGeneral.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TFormGeneral *FormGeneral;
//---------------------------------------------------------------------------
__fastcall TFormGeneral::TFormGeneral(TComponent* Owner,tListaOrd<tSeccion>* s)
        : TForm(Owner),seccion(s)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormGeneral::FormCreate(TObject *Sender)
{
        if(seccion != NULL)
                seccion->mostrar(Memo1->Lines);        
}
//---------------------------------------------------------------------------
