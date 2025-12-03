#include <iostream>
#include "Fecha.h"

using namespace std;

int main()
{
	//El orden es (mes, dia, año)
	Fecha Fecha_1{5, 10, 1996};

	cout << "El mes es " << Fecha_1.getmes() << endl;
	cout << "El dia es " << Fecha_1.getdia() << endl;
	cout << "El año es " << Fecha_1.getagno() << endl;
	//El orden es (dia, mes, año)
	Fecha_1.getfecha();


}


