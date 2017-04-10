#include "memoria.hpp"

template<>
std::ostream& memoria_t<matricula_t>::write(std::ostream& os){
	for(int i=0; i<tam_; i++)
		os << static_cast<std::string>(datos_[i]) << std::setw(10) << datos_[i] << std::endl;
}

template<>
void memoria_t<matricula_t>::intercambiar(int i, int j){
	matricula_t aux;
	aux = datos_[i];
	datos_[i] = datos_[j];
	datos_[j] = aux;
}
