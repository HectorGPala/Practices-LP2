//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormAnyadirPartido.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAnyadirPartido *FormAnyadirPartido;
//---------------------------------------------------------------------------
__fastcall TFormAnyadirPartido::TFormAnyadirPartido(TComponent* Owner, TTorneo &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormAnyadirPartido::ButtonCancelarClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------


void __fastcall TFormAnyadirPartido::FormCreate(TObject *Sender)
{
        int n = torneo_numero_equipos(t);
        AnsiString nombre_equipo;
        for(int i = 0; i < n; i++){
                torneo_nombre_equipo(t,i,nombre_equipo);
                ComboBoxEquipoCasa->Items->Values[i] = nombre_equipo;
                ComboBoxEquipoVisitante->Items->Values[i] = nombre_equipo;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormAnyadirPartido::ButtonAnyadirClick(TObject *Sender)
{
        if((EditGolesCasa->Text != "") && (EditGolesVisitante->Text != "")){
                int id_local = ComboBoxEquipoCasa->ItemIndex;
                int id_visitante = ComboBoxEquipoVisitante->ItemIndex;
                int gl = StrToInt(EditGolesCasa->Text);
                int gf = StrToInt(EditGolesVisitante->Text);
                if(torneo_anyadir_partido(t,id_local,id_visitante,gl,gf) == -2){
                        ShowMessage("Partido ya jugado!");
                        if(MessageDlg("Quiere modificar este partido?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes){
                                torneo_borrar_partido(t,id_local,id_visitante);
                                torneo_anyadir_partido(t,id_local,id_visitante,gl,gf);
                                ShowMessage("Cambios Efectuados");
                                Close();
                        }
                        Close();
                }
                else
                if(torneo_anyadir_partido(t,id_local,id_visitante,gl,gf) == -1)
                        ShowMessage("Error, posiblemente sean el mismo equipo");
                else
                if(torneo_anyadir_partido(t,id_local,id_visitante,gl,gf) == -3)
                        ShowMessage("Introduce valores de goles positivos");
                else{
                        ShowMessage("Partido añadido");
                        Close();
                }
        }
        else
                ShowMessage("Rellena los campos que faltan");
}
//---------------------------------------------------------------------------

