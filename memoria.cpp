#include "memoria.hpp"

template<class T>
memoria_t<T>::~memoria_t(){
	delete [] T_;
}

template<class t>
int memoria_t<T>::obtTam(void){
	return tam_;
}

template<class T>
T& memoria_t<T>::operator[](unsigned int i){
	return T[i];
}

template<>