//---------------------------------------------------------------------------

#ifndef UFormGeneralH
#define UFormGeneralH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UListaOrd.h"
#include "USeccion.h"
//---------------------------------------------------------------------------
class TFormGeneral : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:
        tListaOrd<tSeccion>* seccion;		// User declarations
        __fastcall TFormGeneral(TComponent* Owner,tListaOrd<tSeccion>* s);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGeneral *FormGeneral;
//---------------------------------------------------------------------------
#endif
