//Modulo producto
#include <list>
#include "Producto.h"
#include "TablaHash.h"
#include "Arbol.h"

using namespace std;

#ifndef __DICCCIONARIO_PRODUCTOS
#define __DICCCIONARIO_PRODUCTOS

class DiccionarioProductos {
	private:
		list<Producto> lista;
		TablaHash *tablaHash;
		Arbol *arbol;

		int contador;
	public:
		DiccionarioProductos();
		~DiccionarioProductos();

		void insertar(Producto nuevo);

		void eliminar (long long id);
		void producto (long long id);
		void palabras (string palabra);

		void precios (double min,double max);
		int numElem ();

		void test();
};
#endif
