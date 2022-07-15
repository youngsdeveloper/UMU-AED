#include "Interprete.h"

#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"

#include "DiccionarioProductos.h"

using namespace std;

/*
	El intérprete se encarga de procesar todos los comandos del programa.
*/

//Constructor y destructor
Interprete::Interprete() {
	diccionarioProductos = new DiccionarioProductos();
}
Interprete::~Interprete(){
	delete diccionarioProductos;
}

//Método principal del intérprete
void Interprete::handle(string comando){

    if(comando=="insertar"){
		procesar_insertar();
	}else if(comando == "palabras"){
		procesar_palabras();
	}else if(comando == "precios"){
		procesar_precios();
	}else if(comando == "eliminar"){
		procesar_eliminar();
	}else if(comando == "producto"){
		procesar_producto();
	}
}

//Comando insertar
void Interprete::procesar_insertar(){
	
	Producto productoTemp;
	
	productoTemp.leer();
	(*diccionarioProductos).insertar(productoTemp);

}

//Comando eliminar
void Interprete::procesar_eliminar(){
	
	long int id;
	cin >> id;
	
	(*diccionarioProductos).eliminar(id);

}

//Comando palabras
void Interprete::procesar_palabras(){
	
	string palabra;
	cin >> palabra;

	cout << "palabras " << palabra << "\n";
	

	(*diccionarioProductos).palabras(palabra);

}

//Comando precios
void Interprete::procesar_precios(){
	
	double precioMinimo, precioMaximo;
	cin >> precioMinimo >> precioMaximo;

	cout <<  "precios" << " " << precioMinimo << " " << precioMaximo << "\n";
	
	(*diccionarioProductos).precios(precioMinimo, precioMaximo);
	
}

//Comando producto
void Interprete::procesar_producto(){
	
	long long int identificador;
	cin >> identificador;
	
	cout <<  "producto" << " " << identificador << "\n";
	
	(*diccionarioProductos).producto(identificador);
	
}

void Interprete::test(){
	(*diccionarioProductos).test();
}
