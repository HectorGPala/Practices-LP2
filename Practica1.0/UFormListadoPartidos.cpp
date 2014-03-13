//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormListadoPartidos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormListadoPartidos *FormListadoPartidos;
//---------------------------------------------------------------------------
__fastcall TFormListadoPartidos::TFormListadoPartidos(TComponent* Owner, TTorneo &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------


void __fastcall TFormListadoPartidos::FormCreate(TObject *Sender)
{
        GridListadoPartidos->ColCount = 5;
        GridListadoPartidos->RowCount = 1;
        GridListadoPartidos->Cells[0][0] = "Nº";
        GridListadoPartidos->Cells[1][0] = "Local";
        GridListadoPartidos->Cells[2][0] = "Goles";
        GridListadoPartidos->Cells[3][0] = "Visitante";
        GridListadoPartidos->Cells[4][0] = "Goles";
        int n = torneo_numero_equipos(t);
        AnsiString nombre_equipo;
        for(int i = 0; i < n; i++){
                torneo_nombre_equipo(t,i,nombre_equipo);
                ComboBoxEquipo->Items->Values[i] = nombre_equipo;
        }
}

//---------------------------------------------------------------------------


void __fastcall TFormListadoPartidos::ComboBoxEquipoChange(TObject *Sender)
{
        GridListadoPartidos->RowCount = 1;
        int id = ComboBoxEquipo->ItemIndex;
        int n = torneo_numero_equipos(t);
        int gl,gv;
        int j = 1;
        for(int i = 0; i < n; i++){
                if(torneo_info_partido(t,id,i,gl,gv) == 0){
                        GridListadoPartidos->RowCount++;
                        AnsiString nombre_equipo;
                        torneo_nombre_equipo(t,id,nombre_equipo);
                        GridListadoPartidos->Cells[0][j] = j;
                        GridListadoPartidos->Cells[1][j] = nombre_equipo;
                        torneo_nombre_equipo(t,i,nombre_equipo);
                        GridListadoPartidos->Cells[2][j] = gl;
                        GridListadoPartidos->Cells[3][j] = nombre_equipo;
                        GridListadoPartidos->Cells[4][j] = gv;
                        j++;
                }
                if(torneo_info_partido(t,i,id,gl,gv) == 0){
                        GridListadoPartidos->RowCount++;
                        AnsiString nombre_equipo;
                        torneo_nombre_equipo(t,i,nombre_equipo);
                        GridListadoPartidos->Cells[0][j] = j;
                        GridListadoPartidos->Cells[1][j] = nombre_equipo;
                        torneo_nombre_equipo(t,id,nombre_equipo);
                        GridListadoPartidos->Cells[2][j] = gl;
                        GridListadoPartidos->Cells[3][j] = nombre_equipo;
                        GridListadoPartidos->Cells[4][j] = gv;
                        j++;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormListadoPartidos::ButtonCancelarClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

