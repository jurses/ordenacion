#include "matricula.hpp"
#define MCAR 65

matricula_t::matricula_t(std::string matr_cadena):
	matr_cadena_(matr_cadena)
{
	nIntentos_ = 0;
	nCompar_ = 0;
}

matricula_t::matricula_t(){
	nIntentos_ = 0;
	nCompar_ = 0;
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

void matricula_t::operator=(const matricula_t& otra_matricula){
	nIntentos_ = otra_matricula.nIntentos_;
	matr_cadena_ = otra_matricula.matr_cadena_;
}

void matricula_t::operator=(const std::string& cadena){
	matr_cadena_ = cadena;
}

bool matricula_t::operator<(matricula_t& otra_matricula){
	nCompar_++;
	otra_matricula.nCompar_++;
	return (*this) < static_cast<unsigned long>(otra_matricula);
}

bool matricula_t::operator>(matricula_t& otra_matricula){
	nCompar_++;
	otra_matricula.nCompar_++;
	return (*this) > static_cast<unsigned long>(otra_matricula);
}

int matricula_t::mostrarCompar(void){
	return nCompar_;
}