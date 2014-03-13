//---------------------------------------------------------------------------

#ifndef ListaH
#define ListaH
#include <fstream>
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------

template<class T>
class Lista{
        template<class T>
        struct TNodo{
        T dato;
        TNodo<T>*sig;
        };
        private:
                TNodo<T>* primero;
                TNodo<T>* ultimo;
                int num_elem;
        public:
                Lista();
                ~Lista();
                inline int longitud(){return num_elem;};
                bool iesimo(int i, T & d);//elem i-esimo de la lista
                void pon_elem(const T &e);//añade elem a la lista
                bool quita_elem(int i);//si existe quita ese elem
                bool guardar(ofstream &f);//guarda en bin
                bool abrir(ifstream &f);  //abre binario
};
template<class T>
void Lista_BorraElemento(T c);
template<class T>
bool Lista_guardarDato(ofstream &f,T &a);
template<class T>
T Lista_cargarDato(ifstream &f,T &a);

/*IMPLEMENTACION
DE PLANTILLA
-------------------------------------------------------------------------*/

template<class T>
Lista<T>::Lista(){
        primero = NULL;
        ultimo = NULL;
        num_elem = 0;
}

template<class T>
Lista<T>::~Lista(){
        ultimo = NULL;
        for(int i = 0;i < num_elem;i++){
                TNodo<T>* a = primero;
                primero = primero->sig;
                a->sig = NULL;
                Lista_BorraElemento(a->dato);
                a->dato = NULL;
                delete a;
                a = NULL;
        }
        primero = ultimo = NULL;
        num_elem = 0;
}

template<class T>
bool Lista<T>::iesimo(int i,T &d){
        int n = longitud();
        if(i < n){
                TNodo<T>* a = primero;
                for(int j =0; j < i;j++)
                        a = a->sig;
                d = a->dato;
                return true;
        }
        else return false;
}

template<class T>
void Lista<T>::pon_elem(const T &e){
        if(num_elem == 0){
                TNodo<T>* aux = new TNodo<T>;
                aux->dato = e;
                aux->sig = NULL;
                primero = aux;
                ultimo = aux;
                num_elem++;

        }
        else{
                TNodo<T>* aux = new TNodo<T>;
                aux->dato = e;
                aux->sig = NULL;
                ultimo->sig = aux;
                ultimo = aux;
                num_elem++;
        }
}

template<class T>
bool Lista<T>::quita_elem(int i){
        if(i < num_elem){
                if(i ==0){
                        TNodo<T> *a = primero;
                        primero = primero->sig;
                        a->sig = NULL;
                        Lista_BorraElemento(a->dato);
                        a->dato = NULL;
                        delete a;
                        a = NULL;
                        num_elem--;
                        return true;
                }
                else if(i == num_elem-1){
                        TNodo<T> *a = primero;
                        for(int j = 0; j < num_elem-2;j++){
                                a = a->sig;
                        }
                        ultimo = a;
                        a = a->sig;
                        ultimo->sig = NULL;
                        Lista_BorraElemento(a->dato);
                        a->dato = NULL;
                        delete a;
                        a = NULL;
                        num_elem--;
                        return true;
                }
                else{
                        TNodo<T> *a;
                        a = primero;
                        for(int j = 0; j < i-1;j++)
                                a = a->sig;
                        TNodo<T>*aux = a->sig;
                        a->sig = aux->sig;
                        aux->sig = NULL;
                        Lista_BorraElemento(aux->dato);
                        delete aux;
                        aux = NULL;
                        num_elem--;
                        return true;
                }
        }
        else
                return false;
}

template<class T>
bool Lista<T>::guardar(ofstream &f){
        TNodo<T> *a = primero;
        int n = longitud();
        f.write((char*)&n,sizeof(int));
        for(int i = 0; i < num_elem;i++){
                Lista_guardarDato(f,a->dato);
                a = a->sig;
        }
        return true;

}

template<class T>
bool Lista<T>::abrir(ifstream &f){
        T a;
        int n = 0;
        f.read((char*)&n,sizeof(int));
        for(int i = 0; i < n;i++){
                a = Lista_cargarDato(f,a);
                pon_elem(a);
        }
        return true;
}



#endif
