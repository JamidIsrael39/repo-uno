// Programa que realiza el cálculo de nómina
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
	
	int a{0}, b{0}, c{0};
	
	cout << "Ingrese dos nuemros: ";
	cin  >> b >> c;
	
	a = b * c;

	cout << "El producto es: " << a  << endl;
	//cout << b + b;

	return 0;
}
