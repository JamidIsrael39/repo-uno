#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int radio{0};

	cout << "Ingrese el radio de la circunferencia: ";
	cin >> radio;

	cout << "El diametro es: " << 2 * radio << "\n"  << endl;
	cout << "El perimetro es: " << 2 * 3.14159 * radio << "\n" << endl;
	cout << "El área es: " << 3.14159 * radio * radio << endl;


	return 0;
}
