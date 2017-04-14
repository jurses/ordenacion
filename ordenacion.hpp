#include <iostream>
#include <vector>

template<class T>
class ordenacion_t{
    private:
        T* memoria_;
        void mezcla(T*, int, int, int);
        void msort(T*, int, int);
        void qsort(T*, int, int);
    public:
        ordenacion_t(T&);
        ~ordenacion_t(){}
        void seleccion(void);
        void sacudida(void);
        void msort(void);                   // el gatillo
        void qsort(void);
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
    msort(memoria_, 0, memoria_->obtTam());
}

template<class T>
void ordenacion_t<T>::msort(T* sec, int ini, int fin){
    int cen;
    if (ini < fin){
        cen = (ini + fin)/2;
        msort(sec, ini, cen);
        msort(sec, cen+1, fin);
        mezcla(sec, ini, cen, fin);
    }
}

template<class T>
void ordenacion_t<T>::mezcla(T* sec, int ini, int cen, int fin){
    int i = ini;
    int j = cen + 1;
    int k = ini;
    T aux(fin);

    while((i<=cen) && (j<=fin)){
        if((*sec)[i] < (*sec)[j]){
            aux[k] = (*sec)[i];
            i++;
        }else{
            aux[k] = (*sec)[j];
            j++;
        }

        if(i > cen)
        while(j<=fin){
            aux[k] = (*sec)[j];
            j++;
            k++;
        }
        k++;
    }

    if(i > cen)
        while(j <= fin){
            aux[k] = (*sec)[j];
            j++;
            k++;
        }
    else
        while(i <= cen){
            aux[k] = (*sec)[i];
            i++;
            k++;
        }
        for(int k = ini; k <= fin; k++)
            (*sec)[k] = aux[k];
}

template<class T>
void ordenacion_t<T>::qsort(void){
    qsort(memoria_, 0, memoria_->obtTam()-1);
}

template<class T>
void ordenacion_t<T>::qsort(T* sec, int ini, int fin){
    T p(1);
    int i = ini;
    int f = fin;
    p[0] = (*sec)[(i+f)/2];
    
    while(i<f){
        while(((*sec)[i] < p[0]) && (f <= fin))
            i++;
        while(((*sec)[f] > p[0]) && (f > ini))
            f--;
        if(i <= f){
            memoria_->intercambiar(i, f);
            i++;
            f--;
        }
    }
    if(ini < f)
        qsort(sec, ini, f);
    if(i < fin)
        qsort(sec, i, fin);
}

