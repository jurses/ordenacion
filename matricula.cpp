#include "matricula.hpp"

matricula_t::matricula_t(std::string matr_cadena):
	matr_cadena_(matr_cadena)
{}

matricula_t::operator unsigned long(){
	unsigned long suma = 0;

	for(int i = 4; i < 7; i++)
		suma += (matr_cadena_[i]-MCAR) * pow(10, i);

	return(atoi(matr_cadena_.substr(0,4).c_str()) + suma);
}

void matricula_t::darMatricula(std::string matr_cadena){
	matr_cadena_ = matr_cadena;
}