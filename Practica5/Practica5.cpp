//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Practica5.res");
USEFORM("UFormMenu.cpp", FormMenu);
USEFORM("UFormAux.cpp", FormAux);
USEUNIT("UGrafico.cpp");
USEUNIT("URectangulo.cpp");
USEUNIT("UElipse.cpp");
USEUNIT("UTexto.cpp");
USEUNIT("ULinea.cpp");
USEUNIT("UBmp.cpp");
USEUNIT("UVector.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormMenu), &FormMenu);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
