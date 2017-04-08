template<class T>
class memoria_t{
	private:
		T* datos_;
		unsigned int tam_;
	public:
		memoria_t(){}
		unsigned int obtTam(void);
		T& operator [](unsigned int);
		~memoria_t();
};