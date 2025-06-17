//Clase Cuenta que contine al dato miembro nombre
//y funciones miembro para establecer y obtner su valor
#include <string> //permite al programa usar datos tipo string de C++

class Cuenta {
public:
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
