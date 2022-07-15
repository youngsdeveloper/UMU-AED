#include "Nodo.h"
#include "Producto.h"

#include <iostream>

#include <cstddef>

using namespace std;

/*
 * Cada nodo del árbol AVL contiene un precio, una lista de productos, 
 * su altura y los punteros a sus dos posibles hijos.
*/

Nodo::Nodo () {
	hijoIzquierdo = NULL;
    hijoDerecho = NULL;

    precio=0;
    altura=0;
}

Nodo::Nodo (double precio_) {
		
	hijoIzquierdo = NULL;
    hijoDerecho = NULL;

    precio=precio_;
    altura=0;
}
Nodo::~Nodo () {
	
}

//Métodos para insertar y eliminar productos de la lista del nodo.
void Nodo::insertar(Producto* producto){
    lista.push_back(producto);
}

void Nodo::eliminarProducto(Producto* producto){

    list<Producto*>::iterator it = lista.begin();
	while (it!=lista.end() && (**it).getId() != (*producto).getId())
		it++;

	if (it!=lista.end() && (**it).getId() == (*producto).getId()){
		lista.erase(it);
	}
}

//Métodos de consulta y establecimiento
std::list<Producto*> Nodo::getProductoList(){
    return lista;
}

double Nodo::getPrecio(){
    return precio;
}

int Nodo::getAltura(){
	return altura;
}


void Nodo::setAltura(int altura_){
	altura = altura_;
}

Nodo*& Nodo::getHijoIzq(){
    return hijoIzquierdo;
}
Nodo*& Nodo::getHijoDer(){
    return hijoDerecho;
}


void Nodo::setHijoIzq(Nodo *nodo){
    hijoIzquierdo = nodo;
}
void Nodo::setHijoDer(Nodo *nodo){
    hijoDerecho = nodo;
}
