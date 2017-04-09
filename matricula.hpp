#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>

class matricula_t{
	private:
		int nIntentos_;
		std::string matr_cadena_;

	public:
		matricula_t();
		matricula_t(std::string);
		~matricula_t(){}

		//std::string obtMatricula(void);
		void darMatricula(std::string);
		operator unsigned long();
};