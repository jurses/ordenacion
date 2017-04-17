#include <iostream>
#include <cmath>
#include <vector>

static int testigo = 0;

template<class T>
class ordenacion_t{
	private:
		T* memoria_;
		void mezcla(T*, int, int, int);
		void msort(T*, int, int);
		void qsort(T*, int, int);
		void deltasort(int);
		bool traza_;
	public:
		ordenacion_t(T&);
		~ordenacion_t(){}
		void seleccion(void);
		void sacudida(void);
		void msort(void);                   // el gatillo
		void qsort(void);
		void ssort(float);
};

template<class T>
ordenacion_t<T>::ordenacion_t(T& memoria):
	memoria_(&memoria)
{
	traza_ = false;
}

template<class T>
void ordenacion_t<T>::seleccion(void){
	int min;
	for(int i = 0; i < memoria_->obtTam(); i++){
		min = i;
		for(int j = i+1; j < memoria_->obtTam(); j++)
			if(((*memoria_)[j] < (*memoria_)[min]) && (j != min)){
				min = j;
				std::cout << "Min = [" << min << "]: " << (*memoria_)[min] << std::endl;	
			}
		if(i!=min){
			std::cout << "Se produce intercambio: " << i << " por "
			<< min << std::endl;
			std::cout << (*memoria_)[i] << " <-> " << (*memoria_)[min] << std::endl;
				memoria_->intercambiar(i, min);
		}
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
	msort(memoria_, 0, memoria_->obtTam()-1);
}

template<class T>
void ordenacion_t<T>::msort(T* sec, int ini, int fin){
	if (ini < fin){
		int cen = ini + (fin - ini)/2;
		//std::cout << ini << ", " << cen << ", " << fin <<std::endl;
		//std::cout << " < " << ini << ", " << cen << std::endl;
		msort(sec, ini, cen);
		//std::cout << " > " << cen+1 << ", " << fin << std::endl;
		msort(sec, cen+1, fin);
		//std::cout << "Mezcla entre: " << ini << ", " << cen << ", " << fin << std::endl;
		mezcla(sec, ini, cen, fin);
	}
}

template<class T>
void ordenacion_t<T>::mezcla(T* sec, int ini, int cen, int fin){
	int n1 = cen - ini + 1;
	int n2 =  fin - cen;
	int i = 0, j = 0;
	int k = ini;

	T L(n1); 
	T R(n2);

	for (; i < n1; i++)
	   	L[i] = (*sec)[ini + i];

	for (; j < n2; j++)
	    R[j] = (*sec)[cen + 1 + j];

	i = 0;
	j = 0;
	while (i < n1 && j < n2){
		if (L[i] < R[j]){
			(*sec)[k] = L[i];
			i++;
		}else{
			(*sec)[k] = R[j];
			j++;
		}
		k++;
	}
 
 
	while (i < n1){
		(*sec)[k] = L[i];
		i++;
		k++;
	}

	while (j < n2){
		(*sec)[k] = R[j];
		j++;
		k++;
	}
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

template<class T>
void ordenacion_t<T>::ssort(float a){
	int del = memoria_->obtTam();
	while(del > 1){
		del = ceil(del * a);
		deltasort(del);
	}
}

template<class T>
void ordenacion_t<T>::deltasort(int d){
	T aux(1);
	for(int i = d; i<memoria_->obtTam(); i++){
		aux[0] = (*memoria_)[i];
		int j = i;
		while((j>=d) && (aux[0] < (*memoria_)[j-d])){
			(*memoria_)[j] = (*memoria_)[j-d];
			j = j - d;
		}
		(*memoria_)[j] = aux[0];
	}
}