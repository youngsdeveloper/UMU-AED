#include "TablaHash.h"

#include <iostream>
#include <sstream>

#include <list>
#include <string>
#include <math.h>     


#include "Producto.h"
#include "Utils.h"

using namespace std;

/*
 * Estructura de datos en la que se almacenan las palabras del nombre
 * y la descripción de cada producto junto con la lista de productos
 * en las que aparecen.
*/

//Constructor y destructor
TablaHash::TablaHash() {
	nElem = 0;
	tabla = new list<Par>[M];
}
TablaHash::~TablaHash() {
	delete[] tabla;
}

//Utilizamos la suma posicional como función de dispersión.
unsigned long long int sumaPosicional(string palabra){
	
	unsigned long long int resultado=0;
	unsigned long long int base = 13;
		
	for(int i=0;i<palabra.length();i++){
		resultado += Utils::mod(pow(base,i) * int(palabra[i]),M);
	}
	
	return Utils::mod(resultado,M);

}

//Este es uno de los metodos que hemos utilizado para comprobar otro tipo de funciones de dispersion.
unsigned long long int extraccion(string palabra){
	
	long long int resultado=0;
	unsigned long long int base = 13;

	int ln = palabra.length();

	resultado += pow(base,0) * int(palabra[(ln-1) / 2])  + pow(base,1) * int(palabra[0]) + pow(base,2) * int(palabra[ln-1]);
		
	
	return Utils::mod(resultado,M);
	
}



//Función de dispersión. La creamos como una función aparte para
//poder probar distintas clases de funciones de dispersión.
unsigned long long int h(string palabra){
	return sumaPosicional(palabra);
}

void TablaHash::insertar(string palabra, Producto *nuevo){
	
	
	//Para cada palabra aplicamos la función de dispersión de la 
	//tabla y guardamos en la lista los productos en los que 
	//aparece.

	int dis_h = h(palabra);
	
	list<Par> lista = tabla[dis_h];
	
	

	list<Par>::iterator it;
	
	
	it=lista.begin();
	
	while (it!=lista.end() && (*it).getPalabra() < palabra)
		it++;



	if (it==lista.end() || (*it).getPalabra() != palabra ){

		Par par(palabra);
		par.insertarProducto(nuevo);

		lista.insert(it, par);

	}else if ((*it).getPalabra() == palabra){
		(*it).insertarProducto(nuevo);

	}

	tabla[dis_h] = lista;	
}


void TablaHash::eliminar(string palabra, long long id){
	
	//Para eliminar, aplicamos la función de dispersión
	//y eliminamos los productos en los que aparece.
	//Cuando ya no está en ningún producto, eliminamos
	//la palabra de la tabla.
	int dis_h = h(palabra);
	
	list<Par> lista = tabla[dis_h];
	
	list<Par>::iterator it;
	
	
	it=lista.begin();
	
	while (it!=lista.end() && (*it).getPalabra() < palabra)
		it++;


	if ( it!=lista.end() && (*it).getPalabra() == palabra){

		//Se elimina el producto del par
		(*it).eliminarProducto( id );

		//Comprobar si esta vacia y si esta vacia eliminar par de la tabla de dispersion 

		if ( (*it).getNumProductos() == 0){
			//Eliminar palabra de la lista de pares
			lista.erase(it);
		}

	}

	tabla[dis_h] = lista;	
}


//Método para mostrar en pantalla la lista de productos que
//contienen una palabra concreta.
void TablaHash::consultar (string palabra){
	
	list<Par> lista = tabla[h(palabra)];

	
	list<Par>::iterator it;
	
	
	it=lista.begin();

	
	while (it!=lista.end() && (*it).getPalabra() < palabra){
		it++;
	}

	int nProductos = 0;

	if(it!=lista.end() && (*it).getPalabra() == palabra){


		list<Producto*> listaProductos = (*it).getProductoList();


		list<Producto*>::iterator itProductos;
		itProductos =  listaProductos.begin();
		

		while (itProductos != listaProductos.end()){

			
			cout << nProductos+1 << ". ";
			(*(*itProductos)).mostrar();

			itProductos++;
			nProductos++;
		}
		
	}
	cout << "Total: " << nProductos << " productos\n";
	
	
	
}

//Funcion que hemos utilizado para comprobar como funciona la función de dispersion
//No se utiliza en produccion
void TablaHash::test(){

	int min=99999;
	int max=0;
	int maxI=12;
	int suma=0;
	int cuentaVacias=0;
	int cuentaMas100=0;

	list<int> sizeM;

	int m_med = 0;

	for(int i=0;i<M;i++){


		int n = tabla[i].size();

		if(n==0){
			cuentaVacias++;
		}

		if(n>=100){
			cuentaMas100++;
		}

		if( n < min){
			min = n;
		}

		if(n > max){
			max = n;
			maxI = i;
		}


		if(n>0){
			suma += n;
			m_med++;

		}

	}

	list<Par> lista = tabla[0];

	
	list<Par>::iterator it;
	
	
	it=lista.begin();

	
	while ( it!=lista.end() ){

		cout << "La palabra es... " << (*it).getPalabra() << "\n";

		it++;
	}



	cout << "El numero maximo de palabras/cubetas es " << max << " ID de cubeta: " << maxI << "\n";
	
	cout << "Cubetas con mas de 100 palabras: " << cuentaMas100 << "\n";
	cout << "La media de palabras/cubetas (sin contar las vacias) es " << float(suma) / float(m_med)  << "\n";
	cout << "El numero de cubetas vacias es " << cuentaVacias << "\n";

}



