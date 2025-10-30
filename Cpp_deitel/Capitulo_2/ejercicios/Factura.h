#include <string>

class Factura {
public:
	Factura(std::string numPieza, std::string descPieza, int cantArts, int precioxArt)
	    : numeroPieza(numPieza), descripcionPieza(descPieza), cantidadArts(cantArts), precioUnitario(precioxArt){
	
	    if (cantArts < 0){
		cantidadArts = 0;
	    }
	    if (precioxArt < 0){
	    	precioUnitario = 0;
	    }
	
	}
	void setnumPieza(std::string numPieza){
		numeroPieza = numPieza;
	}
	std::string getnumPieza() const{
		return numeroPieza;
	}
	
	void setdescPieza(std::string descPieza){
		descripcionPieza = descPieza;
	}
	std::string getdescPieza() const{
		return descripcionPieza;
	}

	void setcantArts(int cantArts){
		cantidadArts = cantArts;
	}
	int getcantArts() const{
		return cantidadArts;
	}

	void setprecioxArt(int precioxArt){
		precioUnitario = precioxArt;
	}
	int getprecioxArt() const{
		return precioUnitario;
	}

	int getMontoFactura() const{
		return cantidadArts * precioUnitario;
	}

private:
	std::string numeroPieza;
	std::string descripcionPieza;
	int cantidadArts{0};
	int precioUnitario{0};
	int montoTotal;
};
