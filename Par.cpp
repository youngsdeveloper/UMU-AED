#include "Par.h"

#include <iostream>
#include <sstream>

#include <list>

#include "Producto.h"

using namespace std;

/*
 * Cada par representa una pareja clave, valor para la tabla de 
 * dispersión. La clave es una palabra y el valor una lista de
 * productos.	
*/

Par::Par(std::string palabra_){
	contador=0;
	palabra = palabra_;
}

std::string Par::getPalabra(){
	return palabra;
}

//Métodos para insertar y eliminar productos en la lista
//de productos del par.
void Par::insertarProducto(Producto* producto){

	list<Producto*>::iterator it = l.begin();
	while (it!=l.end() && (**it).getId() < (*producto).getId())
		it++;

	if (it==l.end() || (**it).getId() != (*producto).getId()){
		
		l.insert(it, producto);
		contador++;
	}
}


void Par::eliminarProducto(long long id){

	list<Producto*>::iterator it = l.begin();
	while (it!=l.end() && (**it).getId() < (**it).getId())
		it++;

	if (it!=l.end() && (**it).getId() == (**it).getId()){
		l.erase(it);
		contador--;
	}
}

std::list<Producto*> Par::getProductoList(){
	return l;
}

int Par::getNumProductos(){
	return contador;
}
