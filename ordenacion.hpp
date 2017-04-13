#include <iostream>

template<class T>
class ordenacion_t{
    private:
        T* memoria_;
        void mezcla(int, int, int, int);
        void msort(int, int, int);
    public:
        ordenacion_t(T&);
        ~ordenacion_t(){}
        void seleccion(void);
        void sacudida(void);
        void msort(void);                   // el gatillo
};

template<class T>
ordenacion_t<T>::ordenacion_t(T& memoria):
    memoria_(&memoria)
{}

template<class T>
void ordenacion_t<T>::seleccion(void){
    int min;
    for(int i = 0; i < memoria_->obtTam(); i++){
        min = i;
        for(int j = i+1; j < memoria_->obtTam(); j++)
            if((*memoria_)[j] < (*memoria_)[min])
                min = j;
            
            memoria_->intercambiar(i, min);
    }
}

template<class T>
void ordenacion_t<T>::sacudida(void){
    int ini = 1;
    int fin = memoria_->obtTam() - 1;
    int cam = memoria_->obtTam();

    while(ini < fin){
        for(int j = fin; j>=ini; j--)
            if((*memoria_)[j] < (*memoria_)[j-1]){
                memoria_->intercambiar(j, j-1);
                cam = j;
            }

        ini = cam + 1;
        for(int j = ini; j<= fin; j++){
            if((*memoria_)[j]<(*memoria_)[j-1]){
                memoria_->intercambiar(j, j-1);
                cam = j;
            }
        }
        fin = cam - 1;
    }
}

template<class T>
void ordenacion_t<T>::msort(void){
    msort(0, 0, memoria_->obtTam());
}

template<class T>
void ordenacion_t<T>::msort(int sec, int ini, int fin){
    int cen;
    if (ini < fin){
        cen = (ini + fin)/2;
        msort(sec, ini, cen);
        msort(sec, cen+1, fin);
        mezcla(sec, ini, cen, fin);
    }
}

template<class T>
void ordenacion_t<T>::mezcla(int sec, int ini, int cen, int fin){
    int i = ini;
    int j = cen + 1;
    int k = ini;
    T* aux;
    while((i<=cen)&&(j<=fin)){
        if((*memoria_[i]) < (*memoria_[j])){

        }
    }
}