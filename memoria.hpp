#ifndef _MEMORIA_H_
#define _MEMORIA_H_

#include <iostream>
#include <iomanip>
#include "matricula.hpp"

template<class T>
class memoria_t{
	private:
		T* datos_;
		unsigned int tam_;
		void borrar(void);
		bool ordenado_;
	public:
		memoria_t(int);
		unsigned int obtTam(void);

		std::ostream& write(std::ostream& os){
			for(int i=0; i<tam_; i++)
				os << datos_[i] << std::endl;
		}
		void intercambiar(int, int);
		T& operator [](unsigned int);
		memoria_t<T>* seccionar(int, int);
		void aleatorio(void){}
		int menor(bool);
		void orden(bool x){ ordenado_ = x; }
		int vecesComparado(void);
		~memoria_t();
};

template<class T>
memoria_t<T>::~memoria_t(){
	borrar();
}

template<class T>
memoria_t<T>::memoria_t(int tam):
tam_(tam)
{
	datos_ = new T[tam_];
}

template<class T>
void memoria_t<T>::borrar(void){
	if(datos_)
		delete [] datos_;
}

template<class T>
unsigned int memoria_t<T>::obtTam(void){
	return tam_;
}

template<class T>
T& memoria_t<T>::operator[](unsigned int i){
		return datos_[i];
}

template<class T>
void memoria_t<T>::intercambiar(int i, int j){
	T aux;
	aux = datos_[i];
	datos_[i] = datos_[j];
	datos_[j] = aux;
}

template<class T>
memoria_t<T>* memoria_t<T>::seccionar(int a, int b){
	memoria_t<T>* classic;
	classic = new memoria_t<T>(b-a);
	int aux = a;
	for(int i=0; i<b-a; i++){
		(*classic)[i] = datos_[aux];
		aux++;
	}
	return classic;
}

template<class T>
int memoria_t<T>::vecesComparado(void){
	int veces = 0;
	for(int i=0; i<tam_; i++)
		veces += datos_[i].mostrarCompar();
		
	return veces;
}

template<class T>
int memoria_t<T>::menor(bool x){
	if(x && ordenado_)
		return datos_[0];
	else if(!x && ordenado_)
		return datos_[tam_-1];
}

#endif // _MEMORIA_H_