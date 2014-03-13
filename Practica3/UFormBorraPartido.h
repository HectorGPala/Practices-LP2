//---------------------------------------------------------------------------

#ifndef UFormBorraPartidoH
#define UFormBorraPartidoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UTorneo.h"
//---------------------------------------------------------------------------
class TFormBorrarPartido : public TForm
{
__published:	// IDE-managed Components
        TComboBox *ComboBoxLocal;
        TComboBox *ComboBoxVisitante;
        TButton *ButtonBorrar;
        TButton *ButtonCancelar;
        TLabel *Label1;
        TLabel *Label2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCancelarClick(TObject *Sender);
        void __fastcall ButtonBorrarClick(TObject *Sender);
private:       
        TTorneo &t;
public:		// User declarations
        __fastcall TFormBorrarPartido(TComponent* Owner, TTorneo &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormBorrarPartido *FormBorrarPartido;
//---------------------------------------------------------------------------
#endif
