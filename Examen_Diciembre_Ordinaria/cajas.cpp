#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


// Constantes Globales
const int MAXIMO_CARRITOS = 10;
const int MAXIMO_CAJAS = 5;

// Estructuras
typedef struct {
	double importe;
	string senior;
	string metodoPago;
}tCarrito;

typedef tCarrito tArrayCarrito[10];

typedef struct {
	tArrayCarrito carrito;
	int contador = 0;
}tListaCarritos;

typedef tListaCarritos tCajas[MAXIMO_CAJAS];

// Prototipos
void registrarCaja(tCajas caja,ifstream& archivo ,bool& ok);
void mostrarLista(const tCajas caja);

int main()
{
	
	ifstream archivo;
	bool exito = false;
	tCajas arrayCajas = { 0 };
	tListaCarritos listaCarritos;
	tCarrito carrito;
	registrarCaja(arrayCajas,archivo, exito);

	if (!exito) {
		cout << "El archivo no se abrio correctamente" << endl;
	}
	else {
		cout << "El archivo se abrio correctamente";
        mostrarLista(arrayCajas);
	}

	return 0;
}

void registrarCaja(tCajas arrayCajas,ifstream& archivo, bool& ok) {
	archivo.open("archivo.txt");
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		ok = true;
        int contadorMenosUnos = 0;
		for (int i = 0; i < MAXIMO_CAJAS; i++) {
			archivo >> arrayCajas[i].carrito[arrayCajas[i].contador].importe;
			while (arrayCajas[i].carrito[arrayCajas[i].contador].importe != -1 && arrayCajas[i].contador < MAXIMO_CARRITOS) {
				archivo >> arrayCajas[i].carrito[arrayCajas[i].contador].senior;
				archivo >> arrayCajas[i].carrito[arrayCajas[i].contador].metodoPago;
				arrayCajas[i].contador++;
				archivo >> arrayCajas[i].carrito[arrayCajas[i].contador].importe;
			}
		}
	}

	archivo.close();
}

void mostrarLista(const tCajas caja){
    for(int i = 0; i < MAXIMO_CAJAS; i++){
        cout << "\nCaja " << i + 1 << ": " <<endl;
        if(caja[i].contador == 0){
            cout << "Esta caja se encuentra vacia " << endl;
        }
        for(int j = 0; j < caja[i].contador ; j++){
            cout << "\nCarrito " << j + 1 << " :" << endl;
            cout << "importe: "<< fixed << setprecision(2)<<caja[i].carrito[j].importe << endl;
            cout << "senior: "<< caja[i].carrito[j].senior << endl;
            cout << "metodoPago: "<< caja[i].carrito[j].metodoPago << endl;
        }
    }
}
