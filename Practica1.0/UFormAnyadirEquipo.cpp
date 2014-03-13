//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormAnyadirEquipo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAnyadirEquipo *FormAnyadirEquipo;
//---------------------------------------------------------------------------
__fastcall TFormAnyadirEquipo::TFormAnyadirEquipo(TComponent* Owner, TTorneo &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------



void __fastcall TFormAnyadirEquipo::ButtonCancelarClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormAnyadirEquipo::ButtonAnyadirEquipoClick(
      TObject *Sender)
{
        if(EditNombreEquipo->Text == "")
                ShowMessage("Tienes que escribir un nombre!!");
        if(torneo_anyadir_equipo(t,EditNombreEquipo->Text) == -2)
                ShowMessage("Ese equipo ya existe");
        else
        if(torneo_anyadir_equipo(t,EditNombreEquipo->Text) == -1)
                ShowMessage("Lista de equipos llena");
        else{
                ShowMessage("Añadido correctamente");
                Close();
        }
}
//---------------------------------------------------------------------------




