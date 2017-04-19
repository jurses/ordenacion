#include <iostream>
#include <string>
#include <vector>
#include "matricula.hpp"
#include "memoria.hpp"
#include "ordenacion.hpp"
#include "mostrar.hpp"

typedef memoria_t<matricula_t> memMat;
typedef memoria_t<int> memInt;

void demostracion(void){
	int n;
	int opcion;
	float ssa;
	std::cout << "Tamaño de la secuencia: ";
	std::cin >> n;

	memMat bpruebas(n);
	ordenacion_t<memMat> demos(bpruebas);
	demos.traza();

	std::cout << "Seleccione el algoritmo" << std::endl;
	std::cout << "1: Selección" << std::endl
				<< "2: Sacudida" << std::endl
				<< "3: MergeSort" << std::endl
				<< "4: QuickSort" << std::endl
				<< "5: ShellSort" << std::endl;

	std::cin >> opcion;
	switch(opcion){
		case 1: demos.seleccion(); break;
		case 2: demos.sacudida(); break;
		case 3: demos.msort(); break;
		case 4: demos.qsort(); break;
		case 5: std::cout << "Escoja un valor entre 0 y 1: ";
				std::cin >> ssa;
				demos.ssort(ssa);
		default:	std::cerr << "Mala opción" << std::endl;
	}
}

void estadistica(void){
	int n;
	int pruebas;

	std::cout << "Tamaño de la secuencia: ";
	std::cin >> n;

	memMat bpruebas(n);
	ordenacion_t<memMat> demos(bpruebas);

	std::cout << "Seleccione el número de pruebas: ";
	std::cin >> pruebas;

	std::cout << std::setw(10) << "Número de comparaciones" << std::endl;
	std::cout << std::setw(10) << "Mínimo" << std::setw(10) << "Medio" << std::setw(10) << "Máximo" << std::endl;
	for(int i=0; i<pruebas; i++){
		demos.seleccion();
		std::cout << "Método seleccion: ";
		bpruebas.aleatorio();	// desordena el banco de pruebas
	}
}

int main(int argc, char** argv){
	srand(time(NULL));
	bool menu = true;

	if(argc> 1 && argv[1][0] == '-')
		while(menu)
			switch(argv[1][1]){
				case 'd': 
					demostracion();
					menu = false;
				break;

				case 'e':
					estadistica();
					menu = false;
				break;
				default:
					std::cerr << "Desconozco la opción: " << argv[1][1] << std::endl;
					menu = false;
			}
}