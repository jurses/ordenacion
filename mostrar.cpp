#include "mostrar.hpp"
mostrar_t::mostrar_t(bool x):
	traza_(x)
{}

void mostrar_t::set(bool x){
	traza_ = x;
}

mostrar_t& mostrar_t::operator<<(const char* algo){
	if(traza_)
		printf("%s", algo);
	
	return *this;
}

mostrar_t& mostrar_t::operator<<(const unsigned long& algo){
	if(traza_)
		printf("%lu", algo);
	
	return *this;
}

mostrar_t& mostrar_t::operator<<(const std::string& algo){
	if(traza_)
		printf("%s", algo.c_str());
	
	return *this;
}

mostrar_t& mostrar_t::operator<<(const float& algo){
	if(traza_)
		printf("%f", algo);
}