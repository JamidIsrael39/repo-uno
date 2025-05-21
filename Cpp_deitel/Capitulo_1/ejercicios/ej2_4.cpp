// Programa que calcula el producto de 3 numeros enteros
#include <iostream> // habilita el programa para realizar operaciones de entrada y salida

using std::cout; // El programa usa cout
using std::cin; // El programa usa cin
using std::endl; //El programa usa endl

// La funcion main comienza la ejecucion del programa
int main() {
	int x{0}; // primer numero entero a multiplicar
	int y{0}; // segundo numero entero a multiplicar
	int z{0}; // tercer numero entero a multiplicar
	int resultado{0}; // producto de los tres numeros enteros

	cout << "Programa que calcula el producto de tres numeros enteros\n"; // imprime un mensaje en la terminal
	cout << "Ingrese tres numeros enteros: "; //solicita los numeros al usuaro
	cin >> x >> y >> z; // lee tres numeros del usuario

	resultado = x * y * z; // multiplica los tres numeros enteros; almacena en resultado

	cout << "El producto es: " << resultado << endl; // imprime el resultado; linea finañ
	
	return 0; // indica que el programa terminó exitosamente
} // fin de la funcion main
