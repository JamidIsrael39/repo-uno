//Clase Cuenta que contine al dato miembro nombre
//y funciones miembro para establecer y obtner su valor

//Clase Cuenta con los datos miembro nombre y saldo, y un constructor y una
// funcion deposito, con validacion
#include <string> //permite al programa usar datos tipo string de C++

class Cuenta {
public:
	//Constructor de cuentas con dos parametros
	Cuenta(std::string nombreCuenta, int saldoInicial)
	    : nombre{nombreCuenta}{ // asigna nombreCuenta al dato miembro nombre
	
	    // valida que saldoInicial sea mayor que 0; si no,
	    // el dato miembro saldo mantiene su valor inicial predeterminado  de 0
	    if (saldoInicial > 0) { // si saldoInicial es válido
	    saldo = saldoInicial; // asignarlo al dato miembro saldo
	    }
	}

	// funcion que deposita (suma) sólo una cantidad válida al saldo
	void deposito(int cantidadDepositada){
	    if (cantidadDepositada > 0){ // si cantidadDepositada es válida
	        saldo = saldo + cantidadDepositada; // lo suma al saldo
	    }
	}

	// regresa función del saldo de la cuenta
	int getSaldo() const {
	    return saldo;
	}

	// función que establece el nombre
	void setNombre(std::string nombreCuenta) {
	    nombre = nombreCuenta;
	}

	//función que devuelve el nombre
	std::string getNombre() const {
	    return nombre;
	}
private:
	std::string nombre; // dato miembro nombre de la clase Cuenta
	int saldo{0}; // dato miembro con valor inicial predeterminado
}; //fin de la clase cuenta


/*  Funcion basica
class Cuenta {
public:

	//el constructor inicializa el dato miembro nombre con el parámetro nombreCuenta
	explicit Cuenta(std::string nombreCuenta)
		: nombre{nombreCuenta} {//inicializador de dato miembro
	//Cuerpo vacio
	}

	//funcion miembro que establece el nombre de la cuenta en el objeto
	void setNombre(std::string nombreCuenta){
		nombre = nombreCuenta; //almacena el nombre de la cuenta
	}

	//la funcion miembro que recupera el nombre de la cuenta del objeto
	std::string getNombre() const {
	return nombre; //devuelve el valor del nombre a la funcion que la llamó
	}
private:
	std::string nombre; //dato miembro que contiene el nombre del cuentahabiente
}; //fin de la clase Cuenta
*/
