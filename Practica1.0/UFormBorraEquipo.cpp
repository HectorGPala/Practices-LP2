//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormBorraEquipo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormBorrarEquipo *FormBorrarEquipo;
//---------------------------------------------------------------------------
__fastcall TFormBorrarEquipo::TFormBorrarEquipo(TComponent* Owner, TTorneo &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------



void __fastcall TFormBorrarEquipo::FormCreate(TObject *Sender)
{
        int n = torneo_numero_equipos(t);
        AnsiString nombre_equipo;
        for(int i = 0; i < n; i++){
                torneo_nombre_equipo(t,i,nombre_equipo);
                ComboBoxEquipo->Items->Values[i] = nombre_equipo;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormBorrarEquipo::ButtonCancelarClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------


void __fastcall TFormBorrarEquipo::ButtonBorrarEquipoClick(TObject *Sender)
{
        if(ComboBoxEquipo->ItemIndex == -1)
                ShowMessage("Selecciona un equipo primero");
        else{
                torneo_borrar_equipo(t,ComboBoxEquipo->ItemIndex);
                Close();
        }
}
//---------------------------------------------------------------------------

