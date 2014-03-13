//---------------------------------------------------------------------------

#ifndef UVectorH
#define UVectorH
const int SIZE_INIT = 3;
//---------------------------------------------------------------------------
template<class T>
class tVector{
        private:
                int size;
                int num_elem;
                T** vector;
        public:
                tVector();
                ~tVector();
                void ponElem(T* a);
                T* dameIesimo(int i) throw(EAccessViolation);
                void quitaIesimo(int i) throw(EAccessViolation);
                void inicializa();
                int dameSize(){return size;};
                int dameNum_Elem(){return num_elem;};
                T* operator[](int i)throw (Exception);
};

/*IMPLEMENTACION DE LA PLANTILLA*/

template<class T>
tVector<T>::tVector(){
        size = SIZE_INIT;
        num_elem = 0;
        vector = new T*[size];
        for(int i = 0;i < size;i++){
                vector[i] = NULL;
        }
}

template<class T>
tVector<T>::~tVector(){
        for(int i = 0;i<num_elem;i++)
                delete vector[i];
        delete []vector;
        vector = NULL;
        size = 0;
        num_elem = 0;
}

template<class T>
void tVector<T>::ponElem(T* a){
        if(size == num_elem){
                T** vector_aux = new T*[size*2];
                size = size*2;
                for(int i = 0;i < num_elem;i++)
                        vector_aux[i] = vector[i];
                for(int i = num_elem; i < size;i++)
                        vector_aux[i] = NULL;
                delete[] vector;
                vector = vector_aux;
        }
        vector[num_elem] = a;
        num_elem++;
}

template<class T>
T* tVector<T>::dameIesimo(int i) throw(EAccessViolation){
        if((i < 0) || (i>num_elem))
                throw EAccessViolation("Fuera de rango");
        else
                return vector[i];
}

template<class T>
void tVector<T>::quitaIesimo(int i) throw (EAccessViolation){
        if((i < 0) || (i>num_elem))
                throw EAccessViolation("Fuera de rango");
        else{
        delete vector[i];
        for(int j = i; j<num_elem-1;j++)
                vector[j] = vector[j+1];
        num_elem--;
        }
}

template<class T>
void tVector<T>::inicializa(){
        for(int i = 0;i<num_elem;i++){
                delete vector[i];
                vector[i] = NULL;
        }
        num_elem = 0;
}

template<class T>
T* tVector<T>::operator[](int i)throw (Exception){
        if((i < 0) || (i > size))//CREO QUE SERIA MEJOR CON NUM_ELEM
                throw Exception("Fuera de rango");
        else
                return vector[i];
}






#endif
