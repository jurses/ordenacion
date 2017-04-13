#include <iostream>
#include <string>
#include "matricula.hpp"
#include "memoria.hpp"
#include "ordenacion.hpp"

typedef memoria_t<matricula_t> memMat;

int main(void){
	srand(time(NULL));
	memMat a1(5);
	memMat a2(3);
	ordenacion_t<memMat> b1(a1);
	a1.write(std::cout);

	b1.seleccion();
	std::cout << std::endl;
	a1.write(std::cout);
}