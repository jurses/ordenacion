#ifndef _MATRICULA_H_
#define _MATRICULA_H_

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

class matricula_t{
	private:
		int nIntentos_;
		std::string matr_cadena_;

	public:
		matricula_t();
		matricula_t(std::string);
		~matricula_t(){}
		void darMatricula(std::string);
		std::string obtCadena(void){ return matr_cadena_; }
		operator unsigned long();
		operator std::string();
};

#endif	// _MATRICULA_H_