#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int numero_1{0}, numero_2{0};

	cout << "Ingrese dos numeros: \n";
	cin >> numero_1 >> numero_2;
	
	if (numero_1 > numero_2){
		cout << numero_1 << " es mayor " << numero_2 << "\n"  << endl;
	}
	
	if (numero_2 > numero_1){
		cout << numero_2 << " es mayor " << numero_1 << "\n" << endl;
	}
	
	if (numero_1 == numero_2){
		cout << "Estos números son iguales \n";
	}

	return 0;
}
