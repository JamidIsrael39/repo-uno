#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int entero{0};

	cout << "Ingrese un entero: ";
	cin >> entero;
	
	cout << entero % 100000 / 10000 << "   "; //Genera el primer numero a imprimir
	cout << entero % 10000 / 1000 << "   "; //Genera el segundo numero a imprimir
	cout << entero % 1000 / 100 << "   "; //Genera el tercero numero a imprimir
	cout << entero % 100 / 10 << "   "; //Genera el cuarto numero a imprimir
	cout << entero % 10 << endl; //Genera el ultimo numero a imprimir

}
