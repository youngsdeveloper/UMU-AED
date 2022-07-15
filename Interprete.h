//Modulo Interprete

#include "DiccionarioProductos.h"


#ifndef __INTERPRETE
#define __INTERPRETE


class Interprete {
	private:
        DiccionarioProductos* diccionarioProductos;
		void procesar_insertar();
		void procesar_eliminar();
		void procesar_palabras();
		void procesar_precios();
		void procesar_producto();

	public:
		Interprete();
		~Interprete();
		void handle(std::string);
		void test();
		

};
#endif
