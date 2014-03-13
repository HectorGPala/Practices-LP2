//---------------------------------------------------------------------------

#ifndef UFormIndiceH
#define UFormIndiceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UNodoIndice.h"
#include "UBST.h"
//---------------------------------------------------------------------------
class TFormIndice : public TForm
{
__published:	// IDE-managed Components
        TMemo *MemoIndice;
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
private:
        tBST<tNodoIndice*>* &indice;	// User declarations
public:		// User declarations
        __fastcall TFormIndice(TComponent* Owner,tBST<tNodoIndice*>* &t);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormIndice *FormIndice;
//---------------------------------------------------------------------------
#endif
