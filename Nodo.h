//Modulo Nodo

#include <list>
#include "Producto.h"


#ifndef __NODO
#define __NODO

class Nodo {
        private:
                Nodo *hijoIzquierdo;
                Nodo *hijoDerecho;
                
                std::list<Producto*> lista;
                double precio;
                int altura;

        public:
                Nodo();
                Nodo(double precio);
                ~Nodo();

                void insertar(Producto* producto);

                void eliminarProducto(Producto* producto);

                std::list<Producto*> getProductoList();

                double getPrecio();
                
                int getAltura();
				void setAltura(int altura);

                Nodo*& getHijoIzq();
                Nodo*& getHijoDer();


                void setHijoIzq(Nodo* nodo);
                void setHijoDer(Nodo* nodo);

                
};
#endif
