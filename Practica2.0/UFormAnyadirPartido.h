//---------------------------------------------------------------------------

#ifndef UFormAnyadirPartidoH
#define UFormAnyadirPartidoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UTorneo.h"
//---------------------------------------------------------------------------
class TFormAnyadirPartido : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TComboBox *ComboBoxEquipoCasa;
        TComboBox *ComboBoxEquipoVisitante;
        TEdit *EditGolesCasa;
        TEdit *EditGolesVisitante;
        TLabel *Goles;
        TLabel *Label3;
        TButton *ButtonAnyadir;
        TButton *ButtonCancelar;
        void __fastcall ButtonCancelarClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonAnyadirClick(TObject *Sender);
private:
        TTorneo &t;
public:		// User declarations
        __fastcall TFormAnyadirPartido(TComponent* Owner, TTorneo &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAnyadirPartido *FormAnyadirPartido;
//---------------------------------------------------------------------------
#endif
