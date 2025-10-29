#include <iostream>
#include "Cuentaretiro.h"

using namespace std;

int main()
{
	Cuenta cuenta1{"Jane Green", 50};

	cout << "cuenta1: " << cuenta1.getNombre() << " el saldo es $" << cuenta1.getSaldo() << endl;

	int cantidadRetiro;
	
	cout << "\nIngresa la cantidad a retirar: ";
	cin >> cantidadRetiro;

	cuenta1.retiro(cantidadRetiro);

	cout << "cuenta1: " << cuenta1.getNombre() << " el saldo es $" << cuenta1.getSaldo() << endl;
}

