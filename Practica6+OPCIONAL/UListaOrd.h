//---------------------------------------------------------------------------

#ifndef UListaOrdH
#define UListaOrdH
//---------------------------------------------------------------------------
template<class T>
class tListaOrd{
        template<class T>
        struct tNodo{
                T dato;
                tNodo<T>* sig;
        };
        struct PuntoInteres{
                int indice;
                tNodo<T>* pCur;
        };
        private:
                tNodo<T>* pCab;
                int longitud;
                PuntoInteres* p_int;
                //METODOS PRIVADOS
                void iniciaPI();
                bool buscaPos(const T &d);
        public:
                tListaOrd();
                ~tListaOrd();
                tListaOrd(const tListaOrd<T> &l);
                void insertar(const T &d);
                void eliminar(int i) throw (EAccessViolation);
                void dameElem(int i, T &p) throw (EAccessViolation);
                int dameLong(){return longitud;}
                AnsiString ListToString();//FUNCION ListToStringNodo!!!
                void mostrar(TStrings* p);//FUNCION mostrarNodoLista!!!

};
//FUNCIONES------------------------------
template<class T>
void liberaDato(T &dato);
template<class T>
bool tListaOrdMenor(const T &d1,const T &d2);
template<class T>
bool tListaIguales(const T &d1,const T &d2);
template<class T>
void actualizaNodo(const T &d);
template<class T>
void ListToStringNodo(AnsiString &cadena,const T &elem);
template<class T>
void mostrarNodoLista(TStrings* p,const T &elem);

//IMPLEMENTACION-------------------------
template<class T>
tListaOrd<T>::tListaOrd(){
        longitud = 0;
        tNodo<T>* aux = new tNodo<T>();
        aux->sig = aux;
        pCab = aux;
        p_int = new PuntoInteres();
        p_int->indice = 0;
        p_int->pCur = pCab;
}

template<class T>
tListaOrd<T>::~tListaOrd(){
        while(longitud != 0){
                iniciaPI();
                tNodo<T>* aux;
                aux = p_int->pCur->sig;
                p_int->pCur->sig = aux->sig;
                liberaDato(aux->dato);
                delete aux;
                longitud--;
        }
        delete p_int;
        delete pCab;
}

template<class T>
tListaOrd<T>::tListaOrd(const tListaOrd<T> &l){
        longitud = 0;
        tNodo<T>* aux = new tNodo<T>();
        aux->dato = NULL;
        aux->sig = aux;
        pCab = aux;
        p_int = new PuntoInteres();
        p_int->indice = 0;
        p_int->pCur = pCab;
        int n = l.longitud;
        for(int i = 0; i < n;i++){
                T elemento;
                l.dameElem(i,elemento);
                insertar(elemento);
        }
}

template<class T>
void tListaOrd<T>::iniciaPI(){
    p_int->pCur = pCab;
    p_int->indice = 0;
}

template<class T>
void tListaOrd<T>::insertar(const T &d){
    if(buscaPos(d))
        actualizaNodo(d);
    else{
        tNodo<T>* aux = new tNodo<T>();
        aux->dato = d;
        aux->sig = p_int->pCur->sig;
        p_int->pCur->sig = aux;
        longitud++;
    }
}

template<class T>
bool tListaOrd<T>::buscaPos(const T &d){
    if(longitud == 0)
        return false;
    if(tListaOrdMenor(d,p_int->pCur->sig->dato))
        iniciaPI();
    while(tListaOrdMenor(p_int->pCur->sig->dato,d) && (p_int->indice <= longitud-1)){
        p_int->indice++;
        p_int->pCur = p_int->pCur->sig;
    }
    return tListaIguales(p_int->pCur->sig->dato,d);
}

template<class T>
void tListaOrd<T>::eliminar(int i) throw (EAccessViolation){
        if((i < 0) || (i >= longitud))
                throw EAccessViolation("Acceso posicion no valida");
        else{
                if(p_int->indice > i)
                        iniciaPI();
                while(p_int->indice != i){
                        p_int->pCur = p_int->pCur->sig;
                        p_int->indice++;
                }
                tNodo<T>* aux;
                aux = p_int->pCur->sig;
                p_int->pCur->sig = aux->sig;
                aux->sig = NULL;
                delete aux;
                longitud--;
        }
}

template<class T>
void tListaOrd<T>::dameElem(int i, T &p) throw (EAccessViolation){
        if((i < 0) || (i >= longitud))
                throw EAccessViolation("Acceso posicion no valida");
        else{
                if(p_int->indice > i)
                        iniciaPI();
                while(p_int->indice != i){
                        p_int->pCur = p_int->pCur->sig;
                        p_int->indice++;
                }
                tNodo<T>* aux;
                aux = p_int->pCur->sig;
                p = aux->dato;
        }

}

template<class T>
AnsiString tListaOrd<T>::ListToString(){
        int l = dameLong();
        AnsiString cadena = "";
        T elem;
        for(int i = 0; i < l;i++){
                dameElem(i,elem);
                ListToStringNodo(cadena,elem);
                if(i != l-1)
                        cadena = cadena + ',';
        }
        return cadena;
}

template<class T>
void tListaOrd<T>::mostrar(TStrings* p){
        int l = dameLong();
        String cadena = "";
        T elem;
        for(int i = 0; i < l;i++){
                dameElem(i,elem);
                mostrarNodoLista(p,elem);
        }
}
#endif
