#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int entrada{0}, resultado{0};

	cout << "Ingrese un número para determinar si es par o impar: ";
	cin >> entrada;

	resultado = entrada % 2;

	if (resultado == 0){
	cout << "El número " << entrada << " es par \n" << endl;
	}
	if (resultado != 0){
	cout << "El número " << entrada << " es impar \n" << endl;
	}

}
