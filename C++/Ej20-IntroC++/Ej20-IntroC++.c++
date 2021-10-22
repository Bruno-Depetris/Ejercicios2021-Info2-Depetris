#include "iostream"

using namespace std;
int main(){
	
	char nombre[20],ciudad[20],estado[20],domicilio[20];
	int codpostal;
	
	cout << "Ingresar nombre:";
	cin >> nombre;
	cout << "\n"<< "Ingresar ciudad:";
	cin >> ciudad;
	cout << "\n"<< "Ingresar estado:";
	cin >> estado;
	cout << "\n"<< "Ingresar domicilio:";
	cin >> domicilio;
	cout << "\n"<< "Ingresar codigopostal:";
	cin >> codpostal;
	
    cout << "\n"<< "nombre:" << nombre;
    cout << "\n"<< "domicilio:" << domicilio;
    cout << "\n"<< "ciudad:" << domicilio << "\t"<<"estado:" << estado <<"\t"<< "codigo postal" << codpostal;

	return 0;
}
