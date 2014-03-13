//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormBorraPartido.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormBorrarPartido *FormBorrarPartido;
//---------------------------------------------------------------------------
__fastcall TFormBorrarPartido::TFormBorrarPartido(TComponent* Owner, TTorneo &x)
        : TForm(Owner),t(x)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormBorrarPartido::FormCreate(TObject *Sender)
{
int n = torneo_numero_equipos(t);
        AnsiString nombre_equipo;
        for(int i = 0; i < n; i++){
                torneo_nombre_equipo(t,i,nombre_equipo);
                ComboBoxLocal->Items->Values[i] = nombre_equipo;
                ComboBoxVisitante->Items->Values[i] = nombre_equipo;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormBorrarPartido::ButtonCancelarClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormBorrarPartido::ButtonBorrarClick(TObject *Sender)
{
        if(torneo_borrar_partido(t,ComboBoxLocal->ItemIndex,ComboBoxVisitante->ItemIndex) == -2)
                ShowMessage("El partido no ha sido jugado");
        else
        if(torneo_borrar_partido(t,ComboBoxLocal->ItemIndex,ComboBoxVisitante->ItemIndex) == -1)
                ShowMessage("No es posible");
        else{
                ShowMessage("Partido Borrado");
                Close();
        }

}
//---------------------------------------------------------------------------

