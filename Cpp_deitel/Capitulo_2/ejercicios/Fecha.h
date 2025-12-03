#include <string>

class Fecha {
public:
        Fecha(int mes_c, int dia_c, int agno_c)
            : mes(mes_c), dia(dia_c), agno(agno_c){

            if (mes_c > 12){
                mes = 1;
            }
            if (mes_c < 1){
                mes = 1;
            }

        }

        void setmes(int mes_c){
                mes = mes_c;
        }
        int getmes() const{
                return mes;
        }
        void setdia(int dia_c){
                dia = dia_c;
        }
        int getdia() const{
                return dia;
        }
        void setagno(int agno_c){
                agno = agno_c;
        }
        int getagno() const{
                return agno;
        }
	void getfecha() const{
		std::cout << "\nLa fecha completa es: " << dia << "/" << mes << "/" << agno << std::endl;
	}

private:
        int mes;
        int dia;
        int agno;
};

