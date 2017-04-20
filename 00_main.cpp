#include <iostream>
#include <string>
#include <vector>
#include "matricula.hpp"
#include "memoria.hpp"
#include "ordenacion.hpp"

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

float media(memInt& vec){
	float med = 0;
	for(int i=0; i<vec.obtTam(); i++)
		med += vec[i];
	
	return med/vec.obtTam();
}

unsigned int menor(memInt& vec){
	int menor = vec[0];
	for(int i=0; i<vec.obtTam(); i++)
		if(menor > vec[i])
			menor = vec[i];

	return menor;
}

unsigned int mayor(memInt& vec){
	int mayor = vec[0];
	for(int i=0; i<vec.obtTam(); i++)
		if(mayor < vec[i])
			mayor = vec[i];

	return mayor;
}

void limpiar(memInt& vec){
	for(int i=0; i<vec.obtTam(); i++)
		vec[i] = 0;
}

void limpiarMatr(memMat& vec){
	for(int i=0; i<vec.obtTam();i++)
		vec[i].reset();
}

void estadistica(void){
	int n;
	int pruebas;
	float a;

	std::cout << "Tamaño de la secuencia: ";
	std::cin >> n;

	memMat secuencias(n);
	ordenacion_t<memMat> demos(secuencias);

	std::cout << "Tamaño de las pruebas: ";
	std::cin >> pruebas;

	std::cout << "Valor de a. 0<a<1: ";
	std::cin >> a;

	memInt bpr(pruebas);
	ordenacion_t<memInt> ordpruebas(bpr);

	std::cout << "\t\t\tMínimo\tMedia\tMáximo" << std::endl;
	for(int i=0; i<pruebas; i++){
		demos.seleccion();
		bpr[i] = secuencias.vecesComparado();
		limpiarMatr(secuencias); //limpiamos las comparaciones de nuestra matrícula
		secuencias.aleatorio();
	}
	std::cout << "Método: selección\t" << menor(bpr) 
	<< "\t" << media(bpr) << "\t" << mayor(bpr) << std::endl;
	limpiar(bpr);	//limpiamos nuestro banco de pruebas

	for(int i=0; i<pruebas; i++){
		demos.sacudida();
		bpr[i] = secuencias.vecesComparado();
		limpiarMatr(secuencias);
		secuencias.aleatorio();
	}
	std::cout << "Método: sacudida\t" << menor(bpr) 
	<< "\t" << media(bpr) << "\t" << mayor(bpr) << std::endl;
	limpiar(bpr);

	for(int i=0; i<pruebas; i++){
		demos.msort();
		bpr[i] = secuencias.vecesComparado();
		limpiarMatr(secuencias);
		secuencias.aleatorio();
	}
	std::cout << "Método: msort\t\t" << menor(bpr) 
	<< "\t" << media(bpr) << "\t" << mayor(bpr) << std::endl;
	limpiar(bpr);

	for(int i=0; i<pruebas; i++){
		demos.qsort();
		bpr[i] = secuencias.vecesComparado();
		limpiarMatr(secuencias);
		secuencias.aleatorio();
	}
	std::cout << "Método: qsort\t\t" << menor(bpr) 
	<< "\t" << media(bpr) << "\t" << mayor(bpr) << std::endl;
	limpiar(bpr);

	for(int i=0; i<pruebas; i++){
		demos.ssort(a);
		bpr[i] = secuencias.vecesComparado();
		limpiarMatr(secuencias);
		secuencias.aleatorio();
	}
	std::cout << "Método: ssort\t\t" << menor(bpr) 
	<< "\t" << media(bpr) << "\t" << mayor(bpr) << std::endl;
	limpiar(bpr);
}

int main(int argc, char** argv){
	srand(time(NULL));
	bool menu = true;

	if(argc > 1 && argv[1][0] == '-')
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
					std::cout << "-e modo estadístico, -d modo demostración" << std::endl;
					menu = false;
			}
	else
		std::cout << "-e modo estadístico, -d modo demostración" << std::endl;
}