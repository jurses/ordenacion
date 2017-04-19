#ifndef _MOSTRAR_H_
#define _MOSTRAR_H_

#include <cstdio>
#include <ostream>
#include <string>

class mostrar_t{
	private:
		bool traza_;
	public:
		mostrar_t(bool);
		void set(bool);
		mostrar_t& operator<<(const char*);
		mostrar_t& operator<<(const unsigned long&);
		mostrar_t& operator<<(const std::string&);
		mostrar_t& operator<<(const float&);
};
#endif //_MOSTRAR_H:;