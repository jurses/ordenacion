#include "memoria.hpp"

template<>
std::ostream& memoria_t<matricula_t>::write(std::ostream& os){
	for(int i=0; i<tam_; i++)
		os << static_cast<std::string>(datos_[i]) << std::endl;
}