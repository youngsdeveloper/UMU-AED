#include <iostream>
#include "Producto.h"

using namespace std;

/*
	TAD para cada uno de los productos que serán insertados y administrados.
	Cada producto tiene un id, un nombre, una descripción y un precio.
*/

//Constructor
Producto::Producto () {
	identificador = 0;
	nombre = '\0';
	descripcion = '\0';
	precio = 0;
}

//Método para leer un producto
void Producto::leer() {
	cin >> identificador;
	cin.ignore();
	getline(cin, nombre);
	getline(cin, descripcion);
	cin >> precio;
	cin.ignore();
}

//Método para mostrar por pantalla un producto
void Producto::mostrar() {
	cout << nombre << " (" << identificador << ")" << endl;
	cout << "  " << descripcion << endl;
	cout << "  " << precio << " euros" << endl; 
}

//Métodos de consulta
long int Producto::getId() {
	return identificador; 
}

double Producto::getPrecio() {
	return precio; 
}

string Producto::getNombre(){
	return nombre;
}

string Producto::getDescripcion(){
	return descripcion;
}

