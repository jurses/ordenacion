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
	public:
		memoria_t(int);
		unsigned int obtTam(void);

		std::ostream& write(std::ostream& os){
			for(int i=0; i<tam_; i++)
				os << datos_[i] << std::endl;
		}
		void intercambiar(int, int);
		T& operator [](unsigned int);
		memoria_t<T> operator=(const memoria_t<T>&);
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
memoria_t<T> memoria_t<T>::operator =(const memoria_t<T>& mem){
	std::cout << "Hola" << std::endl;
	datos_ = mem.datos_;
	tam_ = mem.tam_;
	return *this;
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

#endif // _MEMORIA_H_