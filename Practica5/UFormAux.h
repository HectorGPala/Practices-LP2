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
        TButton *Button1;
        TButton *Button2;
        TComboBox *ComboBox;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:
        int &t;// User declarations
public:		// User declarations
        __fastcall TFormAux(TComponent* Owner, int &x);
};
//---------------------------------------------------------------------------
//extern PACKAGE TFormAux *FormAux;
//---------------------------------------------------------------------------
#endif
