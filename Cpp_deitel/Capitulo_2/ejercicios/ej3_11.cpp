#include <iostream>
#include "Empleado.h"

using namespace std;

int main()
{
	Empleado empleado1{"juan", "sanchez", 30000};
	Empleado empleado2{"Ana", "González", 50000};
	
	cout << "El nombre del primer empleado es: " << empleado1.getprimerNombre() << " " << empleado1.getapellidoPaterno() << endl;
	cout << "Su salario mensual es de: " << empleado1.getsalarioMensual() << endl;

	cout << "El nombre del segundo empleado es: " << empleado2.getprimerNombre() << " " << empleado2.getapellidoPaterno() << endl;
        cout << "Su salario mensual es de: " << empleado2.getsalarioMensual() << endl;
	
	empleado1.getaumentoSalario(30000);
	cout << "El nuevo salario es de: " << empleado1.getsalarioMensual() << endl;

	empleado2.getaumentoSalario(50000);
        cout << "El nuevo salario es de: " << empleado2.getsalarioMensual() << endl;
}
