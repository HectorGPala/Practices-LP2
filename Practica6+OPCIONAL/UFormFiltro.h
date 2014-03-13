//---------------------------------------------------------------------------

#ifndef UFormFiltroH
#define UFormFiltroH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UNodoIndice.h"
#include "UBST.h"
#include "UFormIndice.h"
//---------------------------------------------------------------------------
class TFormFiltro : public TForm
{
__published:	// IDE-managed Components
        TMemo *MemoFiltro;
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
private:
        tBST<String>* &filtro;
        tBST<tNodoIndice*>* &indice;	// User declarations
public:		// User declarations
        __fastcall TFormFiltro(TComponent* Owner,tBST<String>* &t,tBST<tNodoIndice*>* &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormFiltro *FormFiltro;
//---------------------------------------------------------------------------
#endif
