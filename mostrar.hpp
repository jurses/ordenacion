#ifndef _MOSTRAR_H_
#define _MOSTRAR_H_

#include <cstdio>
#include <ostream>
#include <string>
#include "matricula.hpp"

class mostrar_t{
	private:
		bool control_;
	public:
		mostrar_t();
		void set(void);
		mostrar_t& operator<<(const char*);
		mostrar_t& operator<<(const unsigned long&);
		mostrar_t& operator<<(const std::string&);
		mostrar_t& operator<<(const float&);
		mostrar_t& operator<<(const int&);
};
#endif //_MOSTRAR_H:;