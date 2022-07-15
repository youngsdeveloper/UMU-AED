#include "DiccionarioProductos.h"

#include <iostream>
#include <sstream>

#include <list>
#include "Utils.h"
#include "Producto.h"

using namespace std;

/*
	El diccionario representa la estructura principal del programa.
	Desde aquí se gestiona la tabla de dispersión de palabras y el
	árbol de precios.
*/

//Constructor y destructor
DiccionarioProductos::DiccionarioProductos () {
	//Al crear el diccionario, creamos una tabla de dispersión y
	//un árbol con memoria dinámica.
	contador=0;
	tablaHash = new TablaHash();
	arbol = new Arbol();
}

DiccionarioProductos::~DiccionarioProductos () {
	delete tablaHash;
	delete arbol;
}


void DiccionarioProductos::insertar(Producto producto){
	
	
		list<Producto>::iterator it = lista.begin();

	
		//IMPORTANTE: El diccionario de productos NO es una lista ordenada.
		it = lista.insert(it, producto);
	
		Producto* ptProducto = &(*it);


		/*
		* Por cada palabra la convertimos en minuscula, aplicamos la funcion de dispersión y lo añadimos a la tabla.
		* Del mismo modo, insertamos el precio de cada producto dentro del árbol AVL.
		*/


		string palabra;

		istringstream iss(producto.getNombre());
      	while (iss >> palabra)
        	(*tablaHash).insertar(Utils::minusculas(palabra), ptProducto);

		istringstream iss2(producto.getDescripcion());
      	while (iss2 >> palabra)
			(*tablaHash).insertar(Utils::minusculas(palabra), ptProducto);

		
		(*arbol).insertar(producto.getPrecio(), ptProducto);
		

		contador++;
	
		
	cout << contador << " productos" << "\n";	
}

void DiccionarioProductos::eliminar(long long id){
	
	
	list<Producto>::iterator it;
	
	it = lista.begin();

	while (it != lista.end() && (*it).getId() != id)
		it++;

	if ( (it != lista.end()) && (*it).getId() == id){


		//Eliminar de la tabla

		string palabra;

		istringstream iss((*it).getNombre());
      	while (iss >> palabra)
        	(*tablaHash).eliminar(Utils::minusculas(palabra), (*it).getId() );

		istringstream iss2((*it).getDescripcion());
      	while (iss2 >> palabra)
			(*tablaHash).eliminar(Utils::minusculas(palabra), (*it).getId() );


		//Eliminar del arbol

		(*arbol).eliminar( &*it );


		//Eliminar de la lista
		lista.erase(it);


		

		contador--;

	}

	cout << contador << " productos" << "\n";	

	
}

void DiccionarioProductos::producto (long long id){

	int nProductosResult = 0;
	
	//Iteramos para buscar el producto dentro del diccionario
	//y después lo mostramos.
	list<Producto>::iterator it;
	
	it = lista.begin();


	while (it != lista.end() && (*it).getId() != id)
		it++;

	if ( (it != lista.end()) && (*it).getId() == id){
		nProductosResult++;
		(*it).mostrar();
	}

	cout << "Total: " << nProductosResult << " productos" << "\n";

}

void DiccionarioProductos::precios (double min, double max){
	(*arbol).consultar(min, max);
}


void DiccionarioProductos::palabras (string palabra){
	(*tablaHash).consultar(Utils::minusculas(palabra));
}



void DiccionarioProductos::test(){
	(*tablaHash).test();
}


//Método de consulta
int DiccionarioProductos::numElem(){
	return contador;
}

