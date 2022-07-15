//Modulo producto
#include <string>


#ifndef __PRODUCTO
#define __PRODUCTO


class Producto {
	private:
		long int identificador;
		std::string nombre;
		std::string descripcion;
		double precio;
		
	public:
		Producto ();
		void leer();
		void mostrar();
		long int getId();
		double getPrecio();
		std::string getNombre();
		std::string getDescripcion();

};
#endif
