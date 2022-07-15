FastMarket: principal.o Producto.o DiccionarioProductos.o Interprete.o TablaHash.o Par.o Nodo.o Arbol.o Utils.o
	g++ -o FastMarket principal.o	Producto.o DiccionarioProductos.o Interprete.o TablaHash.o Par.o Nodo.o Arbol.o Utils.o

Interprete.o: Interprete.cpp Interprete.h Producto.h DiccionarioProductos.h 
	g++ -c Interprete.cpp

principal.o: principal.cpp Interprete.h Producto.h DiccionarioProductos.h
	g++ -c principal.cpp
	
producto.o: Producto.cpp Producto.h 
	g++ -c Producto.cpp
DiccionarioProductos.o: DiccionarioProductos.cpp DiccionarioProductos.h TablaHash.h Arbol.h Utils.h
	g++ -c DiccionarioProductos.cpp
	
TablaHash.o: TablaHash.cpp TablaHash.h Producto.h Utils.h
	g++ -c TablaHash.cpp

Par.o: Par.cpp Par.h Producto.h
	g++ -c Par.cpp

Nodo.o: Nodo.cpp Nodo.h Producto.h
	g++ -c Nodo.cpp

Arbol.o: Arbol.cpp Arbol.h Nodo.h
	g++ -c Arbol.cpp

Utils.o: Utils.cpp Utils.h
	g++ -c Utils.cpp