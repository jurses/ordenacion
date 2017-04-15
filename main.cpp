#include <iostream>
#include <string>
#include <vector>
#include "matricula.hpp"
#include "memoria.hpp"
#include "ordenacion.hpp"

typedef memoria_t<matricula_t> memMat;
typedef memoria_t<int> memInt;
typedef std::vector<matricula_t> vecMat;

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
	
	memMat A(40);
	ordenacion_t<memMat> ord(A);
	ord.ssort(0.34);
	A.write(std::cout);
}