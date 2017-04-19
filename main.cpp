#include <iostream>
#include <string>
#include <vector>
#include "matricula.hpp"
#include "memoria.hpp"
#include "ordenacion.hpp"

typedef memoria_t<matricula_t> memMat;
typedef memoria_t<int> memInt;

int main(void){
	srand(time(NULL));
	int n, r;
	std::cout << "Ingrese el número de elementos: ";
	std::cin >> n;
	std::cout << "Ingrese el número de pruebas: ";
	std::cin >> r;

	memMat* A;
	memMat* B;
	memMat* C;
	memMat* D;
	memMat* E;

	ordenacion_t<memMat> orden;

	for(int i=0; i<r; i++){
		A = new memMat(n);
		B = new memMat(n);
		C = new memMat(n);
		D = new memMat(n);
		E = new memMat(n);
		
		orden.cambioMem(A);
		orden.seleccion();
		orden.sacudida();
		orden.qsort();
		orden.

		delete A;
		delete B;
		delete C;
		delete D;
		delete E;
	}
}