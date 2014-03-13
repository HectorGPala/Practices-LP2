//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Torneo.res");
USEFORM("UFormClasificacion.cpp", FormClasificacion);
USEFORM("UFormAnyadirEquipo.cpp", FormAnyadirEquipo);
USEFORM("UFormBorraEquipo.cpp", FormBorrarEquipo);
USEFORM("UFormAnyadirPartido.cpp", FormAnyadirPartido);
USEFORM("UFormBorraPartido.cpp", FormBorrarPartido);
USEFORM("UFormListadoPartidos.cpp", FormListadoPartidos);
USEUNIT("UTorneo.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TFormClasificacion), &FormClasificacion);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
