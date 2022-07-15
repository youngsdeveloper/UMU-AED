#include <iostream>
#include <string>
#include <sstream>

#include "DiccionarioProductos.h"
#include "Interprete.h"

using namespace std;

/*
	Desde aquí hacemos la llamada principal al programa.
	Su función es procesar todo el texto de entrada a través del intérprete.
*/

int main (void) {
	

	Interprete *interprete = new Interprete();
	
	
	string comando;	
	while (cin >> comando) {
		(*interprete).handle(comando);
	}

	(*interprete).test(); //Solo para testear. Devuelve informacion del rendimiento del programa

	//Liberamos todo al final de la ejecución del programa.
	delete interprete;
}

