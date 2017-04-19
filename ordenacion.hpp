#include <iostream>
#include <cmath>
#include <vector>
#include "mostrar.hpp"

template<class T>
class ordenacion_t{
	private:
		T* memoria_;
		void mezcla(int, int, int);
		void msort(int, int);
		void qsort(int, int);
		void deltasort(int);
		mostrar_t mos_;
	public:
		ordenacion_t(){}
		ordenacion_t(T&);
		ordenacion_t(T*);
		~ordenacion_t(){}
		void cambioMem(T*);
		void seleccion(void);
		void sacudida(void);
		void msort(void);                   // el gatillo
		void qsort(void);
		void ssort(float);
		void traza(void);
};

template<class T>
ordenacion_t<T>::ordenacion_t(T& memoria):
	memoria_(&memoria)
{
}

template<class T>
ordenacion_t<T>::ordenacion_t(T* memoria):
	memoria_(memoria)
{
}

template<class T>
void ordenacion_t<T>::cambioMem(T* memoria){
	memoria_ = memoria;
}

template<class T>
void ordenacion_t<T>::seleccion(void){
	int min;
	for(int i = 0; i < memoria_->obtTam(); i++){
		min = i;
		for(int j = i+1; j < memoria_->obtTam(); j++)
			if(((*memoria_)[j] < (*memoria_)[min]) && (j != min)){
				min = j;
				mos_ << "Min = [" << min << "]: " << (unsigned long)(*memoria_)[min] << "\n";	
			}
		if(i!=min){
			mos_ << "Se produce intercambio: elemento[" << i << "] por elemento["
			<< min << "]\n";
			mos_ << (unsigned long)(*memoria_)[i] << " <-> " << (unsigned long)(*memoria_)[min] << "\n";
				memoria_->intercambiar(i, min);
		}
	}
	memoria_->orden(true);
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
				mos_ << "Intercambiamos el: elemento[" << j << "] por [" << j-1 << "]\n"
				<< (unsigned long)(*memoria_)[j] << " <-> " << (unsigned long)(*memoria_)[j-1] << "\n\n";
				cam = j;
			}

		ini = cam + 1;
		for(int j = ini; j<= fin; j++){
			if((*memoria_)[j]<(*memoria_)[j-1]){
				memoria_->intercambiar(j, j-1);
				mos_ << "Intercambiamos el: elemento[" << j << "] por [" << j-1 << "]\n"
				<< (unsigned long)(*memoria_)[j] << " <-> " << (unsigned long)(*memoria_)[j-1] << "\n\n";
				cam = j;
			}
		}
		fin = cam - 1;
	}
	memoria_->orden(true);
}

template<class T>
void ordenacion_t<T>::msort(void){
	msort(0, memoria_->obtTam()-1);
	memoria_->orden(true);
}

template<class T>
void ordenacion_t<T>::msort(int ini, int fin){
	if (ini < fin){
		int cen = ini + (fin - ini)/2;
		mos_ << ini << ", " << cen << ", " << fin << "\n";
		mos_ << " < " << ini << ", " << cen << "\n";
		msort(ini, cen);
		mos_ << " > " << cen+1 << ", " << fin << "\n";
		msort(cen+1, fin);
		mos_ << "\nMezcla entre: " << ini  << " y " << fin << "\n";
		mezcla(ini, cen, fin);
	}
}

template<class T>
void ordenacion_t<T>::mezcla(int ini, int cen, int fin){
	int n1 = cen - ini + 1;
	int n2 =  fin - cen;
	int i = 0, j = 0;
	int k = ini;

	T L(n1); 
	T R(n2);

	for (; i < n1; i++)
	   	L[i] = (*memoria_)[ini + i];

	for (; j < n2; j++)
	    R[j] = (*memoria_)[cen + 1 + j];

	i = 0;
	j = 0;

	while (i < n1 && j < n2){
		if (L[i] < R[j]){
			mos_ << "Se mete a: " << (unsigned long)L[i] << 
			" en posRel[" << k-ini << "], posReal[" << k << "]\n";
			(*memoria_)[k] = L[i];
			i++;
		}else{
			mos_ << "Se mete a: " << (unsigned long)R[j] << 
			" en posRel[" << k-ini << "], posReal[" << k << "]\n";
			(*memoria_)[k] = R[j];
			j++;
		}
		k++;
	}
 
 
	while (i < n1){
		mos_ << "Se mete a: " << (unsigned long)L[i] << 
		" en posRel[" << k-ini << "], posReal[" << k << "]\n";
		(*memoria_)[k] = L[i];
		i++;
		k++;
	}

	while (j < n2){
		mos_ << "Se mete a: " << (unsigned long)R[j] << 
		" en posRel[" << k-ini << "], posReal[" << k << "]\n";
		(*memoria_)[k] = R[j];
		j++;
		k++;
	}
}

template<class T>
void ordenacion_t<T>::qsort(void){
	qsort(0, memoria_->obtTam()-1);
	memoria_->orden(true);
}

template<class T>
void ordenacion_t<T>::qsort(int ini, int fin){
	T p(1);
	int i = ini;
	int f = fin;
	p[0] = (*memoria_)[(i+f)/2];
	
	while(i<f){
		while(((*memoria_)[i] < p[0]) && (f <= fin)){
			i++;
			mos_ << "Pivote izq en: " << i << "\n";
		}
		while(((*memoria_)[f] > p[0]) && (f > ini)){
			f--;
			mos_ << "Pivote der en: " << f << "\n";
		}
		if(i <= f){
			if(i<f){
				memoria_->intercambiar(i, f);
				mos_ << "Intercambio entre: [" << i << "] y [" << f << "]\n";
				mos_ << (unsigned long)(*memoria_)[i] << " <-> " << (unsigned long)(*memoria_)[f] << "\n\n";
			}
			i++;
			f--;
		}
	}
	if(ini < f)
		qsort(ini, f);
	if(i < fin)
		qsort(i, fin);
}

template<class T>
void ordenacion_t<T>::ssort(float a){
	int del = memoria_->obtTam();
	while(del > 1){
		del = ceil(del * a);
		mos_ << "Se divide en: " << del << "\n";
		deltasort(del);
	}
	memoria_->orden(true);
}

template<class T>
void ordenacion_t<T>::deltasort(int d){
	T aux(1);
	for(int i = d; i<memoria_->obtTam(); i++){
		aux[0] = (*memoria_)[i];
		int j = i;
		while((j>=d) && (aux[0] < (*memoria_)[j-d])){
			mos_ << "Hay intercambio entre: [" << j << "] y [" << j-d << "]\n"
			<< (unsigned long)(*memoria_)[j] << " <-> " << (unsigned long)(*memoria_)[j-d] << "\n";
			(*memoria_)[j] = (*memoria_)[j-d];
			j = j - d;
		}
		(*memoria_)[j] = aux[0];
	}
}

template<class T>
void ordenacion_t<T>::traza(void){
	mos_.set();
}