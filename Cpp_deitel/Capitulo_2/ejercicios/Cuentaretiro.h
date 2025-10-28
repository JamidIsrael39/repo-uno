#include <string>

class Cuenta {
public:
	Cuenta(std::string nombreCuenta, int saldoInicial, int cantidadRetirada)
		: nombre(nombreCuenta){
	
		if (saldoInicial > 0){
			saldo = saldoInicial;
		}
		if (cantidadRetirada < saldoInicial){
			cantidad = cantidadRetirada;
		}

	}
	void deposito(int cantidadDepositada){
		if (cantidadDepositada > 0){
			saldo = saldo + cantidadDepositada;
		}
	}
	int getSaldo() const{
		return saldo;
	}
	void setNombre(std::string nombreCuenta){
		nombre = nombreCuenta;
	}
	std::string getNombre() const{
		return nombre;
	}
	void retiroint(int saldoInicial, int cantidadRetirada){
 		cantidad = saldoInicial - cantidad;
	}
	int getRetiro() const{
		return cantidad;
	}
private:
	std::string nombre;
	int saldo{0};
	int cantidad{0};

};
