#include <iostream>
#include <string>
#include "matricula.hpp"
#include "memoria.hpp"
#include "ordenacion.hpp"

int main(void){
	srand(time(NULL));
	memoria_t<matricula_t> prueba(5);
	prueba.intercambiar(2,3);

	ordenacion_t<memoria_t<matricula_t>> a(prueba);
	a.seleccion();
	prueba.write(std::cout);
}