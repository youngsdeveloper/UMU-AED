//Modulo TablaHash

#include "Producto.h"
#include "Par.h"
#include <string>



#ifndef __TABLA_HASH
#define __TABLA_HASH

const static int M = 30000;


class TablaHash {
	

	private:
        int nElem;
        std::list<Par> *tabla; 

	public:
		TablaHash();
		~TablaHash();
		void insertar (std::string palabra, Producto *nuevo);
		
		void eliminar (std::string palabra, long long id);

		void consultar (std::string nombre);
		int numElem (void) { return nElem; }

		void test();


};
#endif
