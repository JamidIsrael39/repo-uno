#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int entrada_1{0}, entrada_2{0}, resultado{0};

	cout << "Ingrese dos números: ";
	cin >> entrada_1 >> entrada_2;

	resultado = entrada_1 % entrada_2;

	if (resultado == 0){
	cout << "Los números son múltiplos\n" << endl;
	}
	if (resultado != 0){
	cout << "Los números no son múltiplos\n" << endl;
	}

}
