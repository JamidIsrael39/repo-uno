#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){

	int numero_1{0}, numero_2{0};
	int resultado{0};

	cout << "Programa que calcula la suma, producto, diferencia y cociente de dos numeros\n";
	cout << "Ingrese dos numeros: ";
	cin >> numero_1 >> numero_2;

	cout << "La suma de los numeros es: " << numero_1 + numero_2 << "\n"  << endl;
	cout << "El producto de los numeros es: " << numero_1 * numero_2 << "\n" << endl;
	cout << "La diferencia de los numeros es: " << numero_1 - numero_2 << "\n" << endl;
	cout << "El cociente de los numeros es: " << numero_1 / numero_2 << "\n" << endl;

	return 0;
}
