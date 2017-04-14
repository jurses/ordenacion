#include "matricula.hpp"
#define MCAR 65

matricula_t::matricula_t(std::string matr_cadena):
	matr_cadena_(matr_cadena)
{}

matricula_t::matricula_t(){
	matr_cadena_.resize(7);
	for(int i=0; i<4; i++)
		matr_cadena_[i] = rand()%10 + '0';

	for(int i=4; i<7; i++)
		matr_cadena_[i] = rand()%26 + MCAR;
}

matricula_t::operator unsigned long(){
	unsigned long suma = 0;

	for(int i = 4; i < 7; i++)
		suma += (matr_cadena_[i]-MCAR) * pow(10, i);

	return(atoi(matr_cadena_.substr(0,4).c_str()) + suma);
}

matricula_t::operator std::string(){
	return matr_cadena_;
}

void matricula_t::darMatricula(std::string matr_cadena){
	matr_cadena_ = matr_cadena;
}