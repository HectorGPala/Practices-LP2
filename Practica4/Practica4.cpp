//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Practica4.res");
USEFORM("FP.cpp", FormPrincipal);
USEUNIT("Lista.cpp");
USEUNIT("Punto.cpp");
USEUNIT("Polilinea.cpp");
USEUNIT("UtDibujo.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormPrincipal), &FormPrincipal);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
