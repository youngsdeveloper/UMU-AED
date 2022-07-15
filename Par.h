//Modulo TablaHash

#include "Producto.h"
#include <list>



#ifndef __PAR
#define __PAR


class Par {
	private:
        
        std::string palabra;
        std::list<Producto*> l;
		int contador;
        
	public:
		Par(std::string palabra);
		std::string getPalabra();
		void insertarProducto(Producto* producto);
		void eliminarProducto(long long id);

		std::list<Producto*> getProductoList();

		int getNumProductos();
		

};
#endif

