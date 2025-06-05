#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	
	char caracter;
	
	cout << "Programa que respresenta el caracter insertado a su código ASCII\n";
	cout << "Ingrese un caracter: ";
	cin >> caracter;
	cout << "El valor del caracter es: " << static_cast<int>(caracter) << "\n" << endl;
}
