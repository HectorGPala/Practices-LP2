//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Practica6.res");
USEFORM("FP.cpp", Form1);
USEUNIT("UListaOrd.cpp");
USEUNIT("UBST.cpp");
USEUNIT("UPalabra.cpp");
USEUNIT("UNodoIndice.cpp");
USEFORM("UFormAux.cpp", FormAux);
USEFORM("UFormIndice.cpp", FormIndice);
USEFORM("UFormFiltro.cpp", FormFiltro);
USEFORM("UFormGeneral.cpp", FormGeneral);
USEUNIT("USeccion.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
