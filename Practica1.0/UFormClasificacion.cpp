//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormClasificacion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormClasificacion *FormClasificacion;
//---------------------------------------------------------------------------
__fastcall TFormClasificacion::TFormClasificacion(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormClasificacion::ButtonSalirClick(TObject *Sender)
{
        if(MessageDlg("Seguro?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
        Close();        
}
//---------------------------------------------------------------------------
void __fastcall TFormClasificacion::FormCreate(TObject *Sender)
{
torneo_inicializar(t);
//torneo_abrir(t,"C:/Documents and Settings/Hector Gutierrez/Escritorio/a.txt");
MostrarClasificacion();
}
//---------------------------------------------------------------------------
void TFormClasificacion::MostrarClasificacion(){
        GridClasificacion->RowCount = torneo_numero_equipos(t)+1;
        GridClasificacion->ColCount =  11;
        GridClasificacion->Cells[0][0] = "POSICION";
        GridClasificacion->Cells[1][0] = "NOMBRE";
        GridClasificacion->Cells[2][0] = "PUNTOS";
        GridClasificacion->Cells[3][0] = "JUGADOS";
        GridClasificacion->Cells[4][0] = "J_CASA";
        GridClasificacion->Cells[5][0] = "J_FUERA";
        GridClasificacion->Cells[6][0] = "GANADOS";
        GridClasificacion->Cells[7][0] = "EMPATADOS";
        GridClasificacion->Cells[8][0] = "PERDIDOS";
        GridClasificacion->Cells[9][0] = "G_FAVOR";
        GridClasificacion->Cells[10][0] = "G_CONTRA";
        int n = torneo_numero_equipos(t);
        for(int i = 0; i < n;i++){
                int id_equipo,pc,pf,pg,pe,pp,gf,gc,pts;
                AnsiString nombre_equipo;
                torneo_linea_clasificacion(t,i,id_equipo,pc,pf,pg,pe,pp,gf,gc,pts);
                torneo_nombre_equipo(t,id_equipo,nombre_equipo);
                GridClasificacion->Cells[0][i+1] = i+1;
                GridClasificacion->Cells[1][i+1] = nombre_equipo;
                GridClasificacion->Cells[2][i+1] = pts;
                GridClasificacion->Cells[3][i+1] = pc+pf;
                GridClasificacion->Cells[4][i+1] = pc;
                GridClasificacion->Cells[5][i+1] = pf;
                GridClasificacion->Cells[6][i+1] = pg;
                GridClasificacion->Cells[7][i+1] = pe;
                GridClasificacion->Cells[8][i+1] = pp;
                GridClasificacion->Cells[9][i+1] = gf;
                GridClasificacion->Cells[10][i+1] = gc;
        } 
}

void __fastcall TFormClasificacion::ButtonAnyadirEquipoClick(
      TObject *Sender)
{
        TForm *x = new TFormAnyadirEquipo(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::ButtonAnyadirPartidoClick(
      TObject *Sender)
{
        TForm *x = new TFormAnyadirPartido(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();
}
//---------------------------------------------------------------------------



void __fastcall TFormClasificacion::ButtonBorraEquipoClick(
        TObject *Sender)
{
        TForm *x = new TFormBorrarEquipo(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::ButtonBorraPartidoClick(
      TObject *Sender)
{
        TForm *x = new TFormBorrarPartido(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();
        
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::ButtonListadoPartidosClick(
      TObject *Sender)
{
        TForm *x = new TFormListadoPartidos(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();

}
//---------------------------------------------------------------------------


void __fastcall TFormClasificacion::AbrirTorneo1Click(TObject *Sender)
{
        if(OpenDialog1->Execute()){
                AnsiString nombre = OpenDialog1->FileName;
                torneo_abrir(t,nombre);
        }
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::GuardarTorneo1Click(TObject *Sender)
{
        if(SaveDialog1->Execute()){
                AnsiString nombre = SaveDialog1->FileName;
                torneo_guardar(t,nombre);
        }
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

