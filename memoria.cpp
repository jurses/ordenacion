#include "memoria.hpp"

/*
template<class T>
memoria_t<T>::~memoria_t(){
	delete [] datos_;
}
*/

template<class T>
memoria_t<T>::memoria_t(int tam)
tam_(tam)
{
	datos_ = new T[tam_];0
}

template<class T>
unsigned int memoria_t<T>::obtTam(void){
	return tam_;
}

template<class T>
T& memoria_t<T>::operator[](unsigned int i){
	return datos_[i];
}