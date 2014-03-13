//---------------------------------------------------------------------------

#ifndef UFormAuxH
#define UFormAuxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormAux : public TForm
{
__published:	// IDE-managed Components
        TButton *ButtonAceptar;
        TButton *ButtonCancelar;
        TEdit *Edit;
        void __fastcall ButtonAceptarClick(TObject *Sender);
        void __fastcall ButtonCancelarClick(TObject *Sender);
private:
        String &t;	// User declarations
public:		// User declarations
        __fastcall TFormAux(TComponent* Owner,String &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAux *FormAux;
//---------------------------------------------------------------------------
#endif
