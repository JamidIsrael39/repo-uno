#include <iostream>
#include "Factura.h"

using namespace std;

int main()
{
	Factura factura1{"T-2", "Tornillo", 33, 2};
	cout << "Clave de pieza: " << factura1.getnumPieza() << endl;
	cout << "Descripción: " << factura1.getdescPieza() << endl;
	cout << "Se compraran un total de: " << factura1.getcantArts() << " " << factura1.getdescPieza() << "(s)" << endl;
	cout << "El precio unitario es de: " << factura1.getprecioxArt() << endl;

	cout << "Precio total: " << factura1.getMontoFactura() << endl;
}
