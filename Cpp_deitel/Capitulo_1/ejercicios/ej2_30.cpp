#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	float pesolibras{0}, pesokilogramos{0}, alturapulgadas{0}, alturametros{0}, IMC_anglosajon{0}, IMC_internacional{0};
	int opcion{0};

	cout << "Programa que calcula el índice de masa corporal IMC\n";
	cout << "Pulse 1 si desea que el IMC se calcule a partir del sistema anglosajón de medidas\n";
	cout << "Pulse 2 si desea que el IMC se calcule a partir del sistema internacional de medidas\n";
	cin >> opcion;

	if (opcion == 1) {
		cout << "Ingresa tu altura en pulgadas: ";
		cin >> alturapulgadas;
		cout << "Ingresa tu peso en libras: ";
		cin >> pesolibras;
		IMC_anglosajon = (pesolibras * 703) / (alturapulgadas * alturapulgadas);
		cout << "Tu IMC es de: " << IMC_anglosajon << endl;
	}
	if (opcion == 2) {
		cout << "Ingresa tu altura en metros: ";
		cin >> alturametros;
		cout << "Ingresa tu peso en kilogramos: ";
		cin >> pesokilogramos;
		IMC_internacional = (pesokilogramos) / (alturametros * alturametros);
		cout << "Tu IMC es de: " << IMC_internacional << endl;
	}
}
