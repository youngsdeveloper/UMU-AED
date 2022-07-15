#include "Arbol.h"
#include "Producto.h"
#include <list>
#include <iostream>

#include <cstddef>
#include <algorithm>   

using namespace std;

/*
 * Estructura de datos en la que se almacenan los precios de 
 * cada uno de los productos insertados. Se trata de un 
 * árbol AVL.
*/

//Constructor y destructor
Arbol::Arbol() {
	raiz = NULL;
}
Arbol::~Arbol(){
	liberar_arbol(raiz);
}

//Creamos una función recursiva para liberar un nodo
//que luego aplicamos al árbol entero.
void Arbol::liberar_arbol(Nodo *nodo){

	if(nodo != NULL){
		liberar_arbol( (*nodo).getHijoIzq() );
		liberar_arbol( (*nodo).getHijoDer() );

		delete nodo;
	}
	
}

int Arbol::altura(Nodo *nodo){
	if(nodo==NULL){
		return -1;
	}else{
		return (*nodo).getAltura();
	}
}

//Los cuatro tipos de rotaciones que balancean el árbol.
void Arbol::RSI(Nodo *&nodo){
	
	Nodo *B = (*nodo).getHijoIzq();
	
	(*nodo).setHijoIzq( (*B).getHijoDer() );


	(*B).setHijoDer( nodo );


	int alturaIZQ = altura( (*nodo).getHijoIzq() );
	int alturaDER = altura( (*nodo).getHijoDer() );
	(*nodo).setAltura( 1 +  max( alturaIZQ, alturaDER) );

	alturaIZQ = altura( (*B).getHijoIzq() );
	alturaDER = (*nodo).getAltura();
	(*B).setAltura( 1 +  max( alturaIZQ, alturaDER) );

	nodo = B;
}

void Arbol::RDI(Nodo *&nodo){
	RSD( (*nodo).getHijoIzq() );
	RSI( nodo );
}

void Arbol::RSD(Nodo *&nodo){
	
	Nodo *B = (*nodo).getHijoDer();
	
	(*nodo).setHijoDer( (*B).getHijoIzq() );


	(*B).setHijoIzq( nodo );


	int alturaIZQ = altura( (*nodo).getHijoIzq() );
	int alturaDER = altura( (*nodo).getHijoDer() );
	(*nodo).setAltura( 1 +  max( alturaIZQ, alturaDER) );

	alturaIZQ = (*nodo).getAltura();
	alturaDER = altura( (*B).getHijoDer() );
	(*B).setAltura( 1 +  max( alturaIZQ, alturaDER) );

	nodo = B;
}

void Arbol::RDD(Nodo *&nodo){
	RSI( (*nodo).getHijoDer() );
	RSD( nodo );
	
}

void Arbol::insertarArbol(Nodo *&nodo, double precio, Producto *producto){
	//Si el precio es menor, se inserta en el subárbol izquierdo; si es mayor,
	//en el derecho y si es igual, se inserta el producto en la lista del nodo.
	
	if(nodo == NULL){
		nodo = new Nodo(precio); 
        (*nodo).insertar(producto);

    }else if(precio < (*nodo).getPrecio()){
		//Subarbol izquierdo
		
		insertarArbol( (*nodo).getHijoIzq()  , precio, producto);
		
		
		int alturaIZQ = altura( (*nodo).getHijoIzq() );
		int alturaDER = altura( (*nodo).getHijoDer() );


		
		if( alturaIZQ - alturaDER > 1){
			//Rotaciones
			if( precio <  (*(*nodo).getHijoIzq()).getPrecio() ){
				RSI(nodo);
			}else{
				RDI(nodo);
			}
		}else{
			(*nodo).setAltura( 1 +  max( alturaIZQ, alturaDER) );
		}
		
		
	}else if(precio > (*nodo).getPrecio()){
		//Subarbol izquierdo
		insertarArbol( (*nodo).getHijoDer() , precio, producto);

		int alturaIZQ = altura( (*nodo).getHijoIzq() );
		int alturaDER = altura( (*nodo).getHijoDer() );

		if(  alturaDER - alturaIZQ > 1){
			//Rotaciones
			if( precio >  (*(*nodo).getHijoDer()).getPrecio() ){
				RSD(nodo);
			}else{
				
				RDD(nodo);
			}
		}else{
			(*nodo).setAltura( 1 +  max( alturaIZQ, alturaDER) );
		}



	}else if(precio == (*nodo).getPrecio()){
		//Mismo precio
		(*nodo).insertar(producto);
	}
}

void Arbol::insertar(double precio, Producto *producto){
    insertarArbol(raiz, precio, producto);
}


void eliminarProducto(Nodo *nodo, Producto *producto){

	if(nodo != NULL){
		if( (*producto).getPrecio() < (*nodo).getPrecio()){
			//Subarbol izquierdo
			eliminarProducto( (*nodo).getHijoIzq()  ,  producto);
		}else if( (*producto).getPrecio() > (*nodo).getPrecio()){
			//Subarbol derecho
			eliminarProducto( (*nodo).getHijoDer()  ,  producto);

		}else if( (*producto).getPrecio() == (*nodo).getPrecio()){

			//Eliminar de la lista
			(*nodo).eliminarProducto(producto);
		}
	}

	
}

void Arbol::eliminar(Producto *producto){

    eliminarProducto(raiz, producto);
	

}


void Arbol::recorrerLista(list<Producto*> listaProductos){
    list<Producto*>::iterator itProductos;
    itProductos =  listaProductos.begin();
    

	list<Producto*>::iterator itProductosOrdenados;

    while (itProductos != listaProductos.end()){
		itProductosOrdenados = listProductosOrdenados.begin();


		while (itProductosOrdenados!=listProductosOrdenados.end() &&   (**itProductosOrdenados).getId() < (**itProductos).getId() )
			itProductosOrdenados++;

		if (itProductosOrdenados==listProductosOrdenados.end() ||  (**itProductosOrdenados).getId() != (**itProductos).getId() )
			listProductosOrdenados.insert(itProductosOrdenados, (*itProductos));

        itProductos++;
    }
}

void Arbol::consultarArbol(Nodo* nodo, double min, double max){


    if(nodo != NULL){
        
        double precio = (*nodo).getPrecio();
        
        int altura = (*nodo).getAltura();
        


        if(min < precio){
            //Hay que entrar en la izquierda
            consultarArbol( (*nodo).getHijoIzq(), min, max);
        }
        if(max > precio){
            //Hay que entrar en la derecha
            consultarArbol( (*nodo).getHijoDer() , min, max);

        }
        if(precio >= min && precio <= max){
            //Hay que mostrar la raiz
            recorrerLista((*nodo).getProductoList());

        }
    }
}

void Arbol::consultar(double min, double max){
    int nElementosProductos=0;
	listProductosOrdenados.clear();

    consultarArbol(raiz, min, max);

	list<Producto*>::iterator itProductosOrdenados;
	itProductosOrdenados = listProductosOrdenados.begin();

	
	
	while (itProductosOrdenados != listProductosOrdenados.end()){
		cout << nElementosProductos+1 << ". ";
		(**itProductosOrdenados).mostrar();
		
	
		nElementosProductos++;
		itProductosOrdenados++;

	}


    cout << "Total: " << nElementosProductos << " productos\n";
}
