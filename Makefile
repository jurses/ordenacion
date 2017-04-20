matricula.o: matricula.hpp
	g++ -c matricula.cpp

mostrar.o: matricula.o mostrar.hpp
	g++ -c mostrar.cpp matricula.o

memoria.o: matricula.o memoria.hpp
	g++ -c matricula.o memoria.cpp

ordenacion.o: mostrar.o ordenacion.hpp
	g++ -c mostrar.o ordenacion.cpp

main: ordenacion.o memoria.o matricula.o
	g++ -o pr_orden ordenacion.o memoria.o matricula.o
