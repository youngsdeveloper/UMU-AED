//Modulo Arbol

#include <list>
#include "Nodo.h"
#include "Producto.h"




#ifndef __ARBOL
#define __ARBOL

class Arbol {
	

	private:

		std::list<Producto*> listProductosOrdenados;


        Nodo* raiz;
		void insertarArbol(Nodo *&nodo, double precio, Producto *producto);

		void recorrerLista(std::list<Producto*> listaProductos);
		void consultarArbol(Nodo* nodo, double min, double max);	

		int altura(Nodo *nodo);

		void RSI(Nodo *&nodo);
		void RDI(Nodo *&nodo);

		void RSD(Nodo *&nodo);
		void RDD(Nodo *&nodo);

		void liberar_arbol(Nodo *nodo);


	public:



		Arbol();
        ~Arbol();
        void insertar(double precio, Producto *producto);

        void eliminar(Producto *producto);


        void consultar(double min, double max);

};
#endif
