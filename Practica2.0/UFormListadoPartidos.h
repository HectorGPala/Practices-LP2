//---------------------------------------------------------------------------

#ifndef UFormListadoPartidosH
#define UFormListadoPartidosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include "UTorneo.h"
//---------------------------------------------------------------------------
class TFormListadoPartidos : public TForm
{
__published:	// IDE-managed Components
        TComboBox *ComboBoxEquipo;
        TStringGrid *GridListadoPartidos;
        TButton *ButtonCancelar;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ComboBoxEquipoChange(TObject *Sender);
        void __fastcall ButtonCancelarClick(TObject *Sender);
private:
        TTorneo &t;
public:		// User declarations
        __fastcall TFormListadoPartidos(TComponent* Owner, TTorneo &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormListadoPartidos *FormListadoPartidos;
//---------------------------------------------------------------------------
#endif
