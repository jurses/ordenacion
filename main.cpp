#include <iostream>
#include <string>
#include "matricula.hpp"
#include "memoria.hpp"
#include "ordenacion.hpp"

typedef memoria_t<matricula_t> memMat;
typedef memoria_t<int> memInt;

void asignacion(memInt& x){
	x[0] = 44;
	x[1] = 55;
	x[2] = 12;
	x[3] = 42;
	x[4] = 94;
	x[5] = 18;
	x[6] = 06;
	x[7] = 67;
}

int main(void){
	srand(time(NULL));
	/*
	memMat a1(100);
	a1.write(std::cout);
	ordenacion_t<memMat> b1(a1);
	b1.qsort();
	std::cout << std::endl;
	a1.write(std::cout);
	*/
	
}