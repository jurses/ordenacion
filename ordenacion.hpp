#include <iostream>

template<class T>
class ordenacion_t{
    private:
        T* memoria_;
    public:
        ordenacion_t(T&);
        ~ordenacion_t(){ std::cout << "san seacabó" << std::endl; }
        void seleccion(void);
        void sacudida(void);
};

template<class T>
ordenacion_t<T>::ordenacion_t(T& memoria):
    memoria_(&memoria)
{}

template<class T>
void ordenacion_t<T>::seleccion(void){
    int i, j, k;
    
    for(i=0; i<memoria_->obtTam(); i++){
        k = i;
        for(j=i; j<memoria_->obtTam(); j++)
            if(memoria_[k] > memoria_[j])
                k = j;

        memoria_->intercambiar(k, i);
    }
}

template<class T>
void ordenacion_t<T>::sacudida(void){
    bool testigo = true;
    int i = 0, si = 0;
    int j = memoria_->obtTam(), sj = memoria_->obtTam();

    while(testigo){
        testigo = false;
        for(i = si;i<j-1; i++)
            if((*memoria_)[i] < (*memoria_)[i+1]){
                testigo = true;
                memoria_->intercambiar(i, i+1);
                si++;
            }
        
        for(j = sj; j>i+1; j--)
            if((*memoria_)[j] > (*memoria_)[j-1]){
                testigo = true;
                memoria_->intercambiar(j, j-1);
                sj--;
            }
    }
}