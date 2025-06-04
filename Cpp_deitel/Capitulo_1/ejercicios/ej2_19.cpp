#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int numero_1{0}, numero_2{0}, numero_3{0};

	cout << "Ingrese tres numeros enteros diferentes: ";
	cin >> numero_1 >> numero_2 >> numero_3;

	cout << "La suma es: " << numero_1 + numero_2 + numero_3 << "\n"  << endl;
	cout << "El producto es: " << numero_1 * numero_2 * numero_3 << "\n" << endl;
	cout << "El promedio es: " << (numero_1 + numero_2 + numero_3) / 3 << "\n" << endl;

	if (numero_1 < numero_2){
                if (numero_1 < numero_3){
                        cout << "El mas pequeño es: " << numero_1 << "\n"  << endl;
                }
        }
	if (numero_2 < numero_1){
                if (numero_2 < numero_3){
                        cout << "El mas pequeño es: " << numero_2 << "\n" << endl;
                }
        }
        if (numero_3 < numero_2){
                if (numero_3 < numero_1){
                        cout << "El mas pequeño es: " << numero_3 << "\n" << endl;
                }
        }

        if (numero_1 > numero_2){
                if (numero_1 > numero_3){
                        cout << "El mayor es: " << numero_1 << "\n"  << endl;
                }
        }
        if (numero_2 > numero_1){
                if (numero_2 > numero_3){
                        cout << "El mayor es: " << numero_2 << "\n" << endl;
                }
        }
        if (numero_3 > numero_2){
                if (numero_3 > numero_1){
                        cout << "El mayor es: " << numero_3 << "\n" << endl;
                }
        }


	return 0;
}

