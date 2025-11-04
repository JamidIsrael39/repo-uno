#include <string>

class Empleado {
public:
	Empleado(std::string nombre, std::string apellido, int salario)
	    : primerNombre(nombre), apellidoPaterno(apellido), salarioMensual(salario){

	    if (salario < 0){
	    	salarioMensual = 0;
	    }
	}

	void setprimerNombre(std::string nombre){
		primerNombre = nombre;
	}
	std::string getprimerNombre() const{
		return primerNombre;
	}
	
	void setapellidoPaterno(std::string apellido){
		apellidoPaterno = apellido;
	}
	std::string getapellidoPaterno() const{
		return apellidoPaterno;
	}

	void setsalarioMensual(int salario){
		salarioMensual = salario;
	}
	int getsalarioMensual() const{
		return salarioMensual;
	}

	void getaumentoSalario(int salarioM) {
		
		salarioMensual = ((salarioM/10) + salarioM);
		//return salarioMensual;
	}

private:
	std::string primerNombre;
	std::string apellidoPaterno;
	int salarioMensual;
};
