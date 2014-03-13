//---------------------------------------------------------------------------

#ifndef UFormAnyadirEquipoH
#define UFormAnyadirEquipoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UTorneo.h"
//---------------------------------------------------------------------------
class TFormAnyadirEquipo : public TForm
{
__published:	// IDE-managed Components
        TEdit *EditNombreEquipo;
        TLabel *Label1;
        TButton *ButtonAnyadirEquipo;
        TButton *ButtonCancelar;
        void __fastcall ButtonCancelarClick(TObject *Sender);
        void __fastcall ButtonAnyadirEquipoClick(TObject *Sender);
private:
        TTorneo &t;
public:		// User declarations
        __fastcall TFormAnyadirEquipo(TComponent* Owner, TTorneo &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAnyadirEquipo *FormAnyadirEquipo;
//---------------------------------------------------------------------------
#endif
