//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "USeccion.h"

//---------------------------------------------------------------------------

tSeccion::tSeccion(){
        titulo = "";
        num_seccion = "";
        num_pagina = 0;
}

tSeccion::tSeccion(AnsiString t,AnsiString numS,int num){
        titulo = t;
        num_seccion = numS;
        num_pagina = num;
}

tSeccion::~tSeccion(){
        titulo = "";
        num_seccion = "";
        num_pagina = 0;
}

//FUNCIONES DE LISTA
void liberaDato(tSeccion &dato){
        //delete dato;  NO ES NECESARIO PORQUE ES <ESTATICA>
}

bool tListaOrdMenor(const tSeccion &d1,const tSeccion &d2){
        return d1.num_seccion < d2.num_seccion;
}

bool tListaIguales(const tSeccion &d1,const tSeccion &d2){
        return d1.num_seccion == d2.num_seccion;
}

void actualizaNodo(const tSeccion &d){}
void ListToStringNodo(AnsiString &cadena,const tSeccion &elem){
        cadena = elem.num_seccion + elem.titulo + "------>Pagina: " + IntToStr(elem.num_pagina);
}
void mostrarNodoLista(TStrings* p,const tSeccion &elem){
        AnsiString cad;
        ListToStringNodo(cad,elem);
        p->Add(cad);
}

#pragma package(smart_init)
