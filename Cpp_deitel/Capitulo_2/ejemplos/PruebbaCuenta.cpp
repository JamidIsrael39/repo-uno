#include <iostream>
#include <string>
#include "Cuenta.h"

using namespace std;

int main() {
	Cuenta miCuenta; //crea de la clase Cuenta el objeto miCuenta
	
	//muestra que el valor inicial del nombre de miCuenta es una cadena vacia
	cout << "El nombre inicial de la cuenta es: " << miCuenta.getNombre();

	//solicitar y leer el nombre
	cout << "\nIngresa el nombre de la cuenta: ";
	string nombre;
	getline(cin, nombre); //lee una linea del texto
	miCuenta.setNombre(nombre); //colocar el nombre en miCuenta
	
	//muestra el nombre almacenado en el objeto miCuenta
	cout << "El nombre del objeto miCuenta es: "
		<< miCuenta.getNombre() << endl;

}
