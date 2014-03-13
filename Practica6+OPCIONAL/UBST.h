//---------------------------------------------------------------------------

#ifndef UBSTH
#define UBSTH
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
template<class T>
class tBST{
        private:
                T dato;
                tBST<T>* HI;
                tBST<T>* HD;
        protected:
                bool esVacio();
                bool esHoja(){return (HI->esVacio() && HD->esVacio());}
                tBST<T>* extremo_izq();//devuelve el primer elemento en INORDEN
        public:
                tBST();
                tBST(const tBST<T> &a);
                ~tBST();
                T dameRaiz();
                void insertar(const T &d);
                tBST<T>* eliminar(const T &d) throw (EAccessViolation);
                bool buscaPos(const T &d,tBST<T>* &a);//FUNCION actualizaNodoBST!!!
                bool buscaPosAnterior(const T &d,tBST<T>* &a);
                void mostrar(TStrings* p);//FUNCION mostrarNodoBST!!!
                AnsiString BSTToString();//FUNCION nodoToStringBST!!!
                void guardar(ofstream &f);
                void cargar(ifstream &f);
};

//FUNCIONES------------------------------
template<class T>
void liberaDatoBST(T &dato);
template<class T>
void copiaDatoBST(T &d1,const T &d2);
template<class T>
bool datoMenorBST(const T &dato,const T &d);
template<class T>
bool datoIgualBST(const T &dato,const T &d);
template<class T>
void actualizaNodoBST(T &dato,const T &d);
template<class T>
void mostrarNodoBST(TStrings* p,const T &dato);
template<class T>
void nodoToStringBST(AnsiString &cad,const T &dato);
template<class T>
void guardarNodoBST(ofstream &f,const T &dato);
template<class T>
void convertirLinea(T &datoIns,const string &d);


//IMPLEMENTACION-------------------------
template<class T>
tBST<T>::tBST(){
        dato = NULL;
        HI = NULL;
        HD = NULL;
}

template<class T>
tBST<T>::tBST(const tBST<T> &a){
        if(a.esVacio()){
                HI = NULL;
                HD = NULL;
                dato = NULL;
        }
        else{
                HI = new tBST<T>(*a.HI);
                HD = new tBST<T>(*a.HD);
                copiaDatoBST(dato,a.dato);
        }
}

template<class T>
tBST<T>::~tBST(){
        if(!esVacio()){
                delete HI;
                delete HD;
                liberaDatoBST(dato);
        }
}

template<class T>
bool tBST<T>::esVacio(){
        return ((HI == NULL) && (HD == NULL) && (dato == NULL));
}

template<class T>
T tBST<T>::dameRaiz(){
        if(esVacio())
                return NULL;
        else
                return dato;
}

template<class T>
void tBST<T>::insertar(const T &d){
        if(esVacio()){
                copiaDatoBST(dato,d);
                HI = new tBST<T>();
                HD = new tBST<T>();
        }
        else{
                tBST<T>* abb = this;
                if(buscaPos(d,abb))
                        actualizaNodoBST(abb->dato,d);
                else{
                        if(datoMenorBST(abb->dato,d)){
                                abb->HD->insertar(d);
                        }
                        else
                                abb->HI->insertar(d);
                }
        }
}

template<class T>
bool tBST<T>::buscaPos(const T &d,tBST<T>* &a){
        if(esVacio())
                return false;
        else{
                if(datoIgualBST(dato,d)){
                        a = this;
                        return true;
                }
                else{
                        if(esHoja()){
                                a = this;
                                return false;
                        }
                        if(datoMenorBST(dato,d))
                                return HD->buscaPos(d,a);
                        else
                                return HI->buscaPos(d,a);
                }
        }
}

template<class T>
bool tBST<T>::buscaPosAnterior(const T &d,tBST<T>* &a){
        if(esVacio())
                return false;
        else{
                if(datoIgualBST(dato,d))
                        return true;
                else{
                        if(esHoja()){
                                return false;
                        }
                        if(datoMenorBST(dato,d)){
                                a = this;
                                return HD->buscaPosAnterior(d,a);
                        }
                        else{
                                a = this;
                                return HI->buscaPosAnterior(d,a);
                        }
                }

        }
}

template<class T>
tBST<T>* tBST<T>::eliminar(const T &d) throw (EAccessViolation){
        if(esVacio())
                throw EAccessViolation("Arbol VACIO");
        else{
                tBST<T>* abb_ant = NULL;
                bool raiz = false;
                if(buscaPosAnterior(d,abb_ant)){
                        if(abb_ant == NULL)//RAIZ!
                                raiz = true;
                        if(!raiz){
                                tBST<T>* abb_aux;
                                bool derecho = false;
                                if(datoIgualBST(abb_ant->HD->dato,d)){
                                        abb_aux = abb_ant->HD;
                                        derecho = true;
                                }
                                else
                                        abb_aux = abb_ant->HI;
                                if(abb_aux->esHoja()){
                                        liberaDatoBST(abb_aux->dato);
                                        abb_aux->dato = NULL;
                                        delete abb_aux->HD;
                                        delete abb_aux->HI;
                                        abb_aux->HD = abb_aux->HI = NULL;
                                        return this;
                                }
                                else
                                if((abb_aux->HD->esVacio()) && (!abb_aux->HI->esVacio())){
                                        if(derecho)
                                                abb_ant->HD = abb_aux->HI;
                                        else
                                                abb_ant->HI = abb_aux->HI;
                                        abb_aux->HI = NULL;
                                        delete abb_aux;
                                        return this;
                                }
                                else
                                if((!abb_aux->HD->esVacio()) && (abb_aux->HI->esVacio())){
                                        if(derecho)
                                                abb_ant->HD = abb_aux->HD;
                                        else
                                                abb_ant->HI = abb_aux->HD;
                                        abb_aux->HD = NULL;
                                        delete abb_aux;
                                        return this;
                                }
                                else
                                if((!abb_aux->HD->esVacio()) && (!abb_aux->HI->esVacio())){
                                        if(derecho)
                                                abb_ant->HD = abb_aux->HD;
                                        else
                                                abb_ant->HI = abb_aux->HD;
                                        tBST<T>* ext_izq = abb_aux->HD->extremo_izq();
                                        delete ext_izq->HI;
                                        ext_izq->HI = abb_aux->HI;
                                        abb_aux->HI = NULL;
                                        abb_aux->HD = NULL;
                                        delete abb_aux;
                                        return this;
                                }

                        }
                        else{//es RAIZ DEL ARBOL
                                if(esHoja()){
                                        liberaDatoBST(dato);
                                        delete HD;
                                        delete HI;
                                        dato = NULL;
                                        HD = HI = NULL;
                                        return this;
                                }
                                else
                                if((HD->esVacio()) && (!HI->esVacio())){
                                        abb_ant = new tBST(*HI);
                                        delete this;
                                        return abb_ant;
                                }
                                else
                                if((!HD->esVacio()) && (HI->esVacio())){
                                        abb_ant = new tBST(*HD);
                                        delete this;
                                        return abb_ant;
                                }
                                else
                                if((!HD->esVacio()) && (!HI->esVacio())){
                                        tBST<T>* nueva_raiz = new tBST(*this);
                                        tBST<T>* abb_aux;
                                        tBST<T>* ext_izq = nueva_raiz->HD->extremo_izq();
                                        delete ext_izq->HI;
                                        ext_izq->HI = nueva_raiz->HI;
                                        abb_aux = nueva_raiz;
                                        nueva_raiz = nueva_raiz->HD;
                                        abb_aux->HD = abb_aux->HI = NULL;
                                        delete abb_aux;//borro raiz
                                        delete this;//borro arbol antiguo
                                        return nueva_raiz;
                                }
                        }
                }
                else
                        throw EAccessViolation("El elemento no existe");
        }
        return NULL;
}

template<class T>
tBST<T>* tBST<T>::extremo_izq(){
        if(!esVacio()){
                if(HI->esVacio())
                        return this;
                else
                        return HI->extremo_izq();
        }
        return NULL;
}

template<class T>
void tBST<T>::mostrar(TStrings* p){
        if(!esVacio()){
                HI->mostrar(p);
                mostrarNodoBST(p,dato);
                HD->mostrar(p);
        }
}

template<class T>
AnsiString tBST<T>::BSTToString(){
        if(!esVacio()){
                AnsiString cad1 = "";
                cad1 = cad1 + HI->BSTToString();
                nodoToStringBST(cad1,dato);
                cad1 = cad1 + HD->BSTToString();
                return cad1;
        }
        return "";
}

template<class T>
void tBST<T>::guardar(ofstream &f){
        if(!esVacio()){
                HI->guardar(f);
                guardarNodoBST(f,dato);
                HD->guardar(f);
        }
}

template<class T>
void tBST<T>::cargar(ifstream &f){
        while(!(f.eof())){
                string d;
                T datoIns;
                getline(f,d);
                convertirLinea(datoIns,d);
                if(datoIns != "" )
                        insertar(datoIns);
        }
}

#endif
