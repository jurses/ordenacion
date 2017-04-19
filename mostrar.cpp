#include "mostrar.hpp"
mostrar_t::mostrar_t():
	control_(false)
{}

void mostrar_t::set(){
	control_ = true;
}

mostrar_t& mostrar_t::operator<<(const char* algo){
	if(control_)
		printf("%s", algo);
	
	return *this;
}

mostrar_t& mostrar_t::operator<<(const unsigned long& algo){
	if(control_)
		printf("%lu", algo);
	
	return *this;
}

mostrar_t& mostrar_t::operator<<(const int& algo){
	if(control_)
		printf("%d",algo);

	return *this;
}

mostrar_t& mostrar_t::operator<<(const std::string& algo){
	if(control_)
		printf("%s", algo.c_str());
	
	return *this;
}

mostrar_t& mostrar_t::operator<<(const float& algo){
	if(control_)
		printf("%f", algo);
}