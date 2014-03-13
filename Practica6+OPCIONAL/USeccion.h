//---------------------------------------------------------------------------

#ifndef USeccionH
#define USeccionH
//---------------------------------------------------------------------------
class tSeccion{
        friend void liberaDato(tSeccion &dato);
        friend bool tListaOrdMenor(const tSeccion &d1,const tSeccion &d2);
        friend bool tListaIguales(const tSeccion &d1,const tSeccion &d2);
        friend void actualizaNodo(const tSeccion &d);
        friend void ListToStringNodo(AnsiString &cadena,const tSeccion &elem);
        friend void mostrarNodoLista(TStrings* p,const tSeccion &elem);
        private:
                int num_pagina;
                AnsiString titulo;
                AnsiString num_seccion;
        public:
                tSeccion();
                tSeccion(AnsiString t,AnsiString numS,int num);
                ~tSeccion();
                int dameNumPagina(){return num_pagina;}
                AnsiString dameTitulo(){return titulo;}
                AnsiString dameNumSeccion(){return num_seccion;}
};
//FUNCIONES DE LISTA
void liberaDato(tSeccion &dato);
bool tListaOrdMenor(const tSeccion &d1,const tSeccion &d2);
bool tListaIguales(const tSeccion &d1,const tSeccion &d2);
void actualizaNodo(const tSeccion &d);
void ListToStringNodo(AnsiString &cadena,const tSeccion &elem);
void mostrarNodoLista(TStrings* p,const tSeccion &elem);
#endif
