#include <iostream>
#include "Cuentaretiro.h"

using namespace std;

int main()
{
	Cuenta cuenta1{"Jane Green", 50, 60};

	cout << "cuenta1: " << cuenta1.getNombre() << " el saldo es $" << cuenta1.getSaldo() << endl;

	cout << "cuenta1:" << " queda la siguiente cantidad " << cuenta1.getRetiro() << endl;
}

