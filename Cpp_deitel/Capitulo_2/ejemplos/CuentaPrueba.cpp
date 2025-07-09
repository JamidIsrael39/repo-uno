//Visualizacion y actualización de saldos de Ceunta
#include <iostream>
#include "Cuenta.h"

using namespace std;

int main()
{
	Cuenta cuenta1{"Jane Green", 50};
	Cuenta cuenta2{"John Blue", -7};

	// muestra el saldo inicial de cada objeto
	cout << "cuenta1: " << cuenta1.getNombre() << " el saldo es $"
	   << cuenta1.getSaldo();
	cout << "\ncuenta2: " << cuenta2.getNombre() << " el saldo es $"
	   << cuenta2.getSaldo();

	cout << "\n\nIngrese el monto del deposito para la cuenta1: ";
	// esperando respuesta del usuario
	int cantidadDepositada; // obtiene la entrada del usuario
	cin >> cantidadDepositada;
	cout << "agregando " << cantidadDepositada << " al saldo de la cuenta1";
	cuenta1.deposito(cantidadDepositada); //suma al saldo de la cuenta1

	//mostrar saldos
	cout << "\n\ncuenta1: " << cuenta1.getNombre() << " el saldo es $"
	   << cuenta1.getSaldo();
	cout << "\ncuenta2: " << cuenta2.getNombre() << " el saldo es $"
	   << cuenta2.getSaldo();

	cout << "\n\nIngrese el monto del deposito para la cuenta2: " ; // prompt
	cin >> cantidadDepositada; // lee la entrada del usuario
	cout << "agregando " << cantidadDepositada << " al saldo de la cuenta2";
	cuenta2.deposito(cantidadDepositada); // sumar al saldo de la cuenta2

	// mostrar saldos
	cout << "\n\ncuenta1: " << cuenta1.getNombre() << " el saldo es $"
	   << cuenta1.getSaldo() << endl;
	cout << "cuenta2: " << cuenta2.getNombre() << " el saldo es $"
	   << cuenta2.getSaldo() << endl;
}
