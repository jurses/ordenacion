#include <iostream>

template<class T>
class ordenacion_t{
    private:
        T memoria_;
    public:
        ordenacion_t(T&);
        ~ordenacion_t(){}
        void seleccion(void);
};

template<class T>
ordenacion_t<T>::ordenacion_t(T& memoria):
    memoria_(memoria)
{}

template<class T>
void ordenacion_t<T>::seleccion(void){
    int i, j, k;
    
    for(i=0; i<memoria_.obtTam(); i++){
        k = i;
        for(j=i; j<memoria_.obtTam(); j++)
            if(memoria_[k] > memoria_[j])
                k = j;

        memoria_.intercambiar(k, i);
    }
}