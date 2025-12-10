/**
 * Escribe una función en C++ que acepte un valor de tipo double y devuelva el número redondeado a la
 * centésima más cercana. Escribe un programa principal que pida al usuario un número real y lo muestre
 * en la pantalla redondeado. 
 */
#include <iostream>
#include <cmath>
using namespace std;

// prototipos
void redondearNumeroReal(double &numeroReal);

int main(){
    double numeroReal;
    redondearNumeroReal(numeroReal);
    cout << "El numero real introducido redondeado es: " << numeroReal << endl;

    return 0;
}

void redondearNumeroReal(double &numeroReal){
    cout << "Numero Real a redondear: ";
    cin >> numeroReal;
    numeroReal = round(numeroReal*100.0) / 100.0;
}