//Uso del constructor Cuenta para inicializar el dato miembro nombre
//cada vez que se crea un objeto Cuenta
#include <iostream>
#include "Cuenta.h"

using namespace std;

int main(){
	// crea dos objetos Cuenta
	Cuenta cuenta1{"Jane Green"};
	Cuenta cuenta2{"John Blue"};

	// mostrar valor inicial de nombre de cada Cuenta
	cout << "El nombre de la cuenta1 es: " << cuenta1.getNombre() << endl;
	cout << "El nombre de la cuenta2 es: " << cuenta2.getNombre() << endl;
}
