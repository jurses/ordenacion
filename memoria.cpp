#include "memoria.hpp"

template<>
std::ostream& memoria_t<matricula_t>::write(std::ostream& os){
	for(int i=0; i<tam_; i++)
		os << static_cast<std::string>(datos_[i]) << std::setw(10)
		<< datos_[i] << " |Veces comparado: " << datos_[i].mostrarCompar() 
		<< std::endl;
}

template<>
memoria_t<int>::memoria_t(int nElementos):
	tam_(nElementos)
{
	datos_ = new int[tam_];
	for(int i=0; i<tam_; i++){
		datos_[i] = rand() % 32767;
	}
}

template<>
memoria_t<unsigned long>::memoria_t(int nElementos):
	tam_(nElementos)
{
	datos_ = new unsigned long[tam_];
	for(int i=0; i<tam_; i++){
		datos_[i] = rand() % 32767;
	}
}

template<>
void memoria_t<matricula_t>::intercambiar(int i, int j){
	matricula_t aux;
	aux = datos_[i];
	datos_[i] = datos_[j];
	datos_[j] = aux;
}

template<>
void memoria_t<matricula_t>::aleatorio(void){
	for(int i=0; i<tam_*2; i++){
		int x = rand()%tam_;
		int y = rand()%tam_;
		intercambiar(x, y); // no poner antes de declaracion de intercambiar
							// no cumpliría la normativa n3376 14.7.3/6 
	}

	for(int i=0; i<tam_; i++)
		datos_->reset();

	ordenado_ = false;
}