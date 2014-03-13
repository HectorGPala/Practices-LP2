//---------------------------------------------------------------------------

#ifndef UFormClasificacionH
#define UFormClasificacionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include "UTorneo.h"
#include "UFormAnyadirEquipo.h"
#include "UFormAnyadirPartido.h"
#include "UFormBorraEquipo.h"
#include "UFormBorraPartido.h"
#include "UFormListadoPartidos.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormClasificacion : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *GridClasificacion;
        TButton *ButtonAnyadirEquipo;
        TButton *ButtonBorraEquipo;
        TButton *ButtonAnyadirPartido;
        TButton *ButtonBorraPartido;
        TButton *ButtonListadoPartidos;
        TButton *ButtonSalir;
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *AbrirTorneo1;
        TMenuItem *GuardarTorneo1;
        TMenuItem *N1;
        TMenuItem *Salir1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TButton *ButtonLimpiar;
        void __fastcall ButtonSalirClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonAnyadirEquipoClick(TObject *Sender);
        void __fastcall ButtonAnyadirPartidoClick(TObject *Sender);
        void __fastcall ButtonBorraEquipoClick(TObject *Sender);
        void __fastcall ButtonBorraPartidoClick(TObject *Sender);
        void __fastcall ButtonListadoPartidosClick(TObject *Sender);
        void __fastcall AbrirTorneo1Click(TObject *Sender);
        void __fastcall GuardarTorneo1Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall ButtonLimpiarClick(TObject *Sender);
private:
        TTorneo t;
        void MostrarClasificacion();

public:		// User declarations
        __fastcall TFormClasificacion(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormClasificacion *FormClasificacion;
//---------------------------------------------------------------------------
#endif
