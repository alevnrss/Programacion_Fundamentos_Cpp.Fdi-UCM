/**
 * Existen dos tipos de parametros:
 * -PARAMETROS POR VALOR :
 * Recibe una copia de la variable y no cambia el valor de la misma al terminar el subprograma.
 * Es decir, que todo lo que pase dentro de la funcion no cambiara el valor fuera del subprograma     
 * -PARAMETROS POR REFERENCIA o POR VARIABLE :
 * Recibe una variable con un AMPERSAND (&) que indica al compilador que esa variable es un alias o referencia al dato original.
 * Es decir, que cualquier modificacion que se haga dentro de la funcion tambien modificara el valor de fuera.
 */

#include <iostream>
using namespace std;
void cambiarNumeroReferencia(int &a);

int main(){
    int numero1 = 10;
    cambiarNumeroReferencia(numero1);
    cout << "El valor del numero1 ahora es: " << numero1 << endl;
    cambiarNumeroReferencia(numero1);
    cout << "El valor del numero1 ahora es: " << numero1 << endl;
    cambiarNumeroReferencia(numero1);
    cout << "El valor del numero1 ahora es: " << numero1 << endl;
    return 0;
}
void cambiarNumeroReferencia(int &a){
    cout << "Introduce un valor que deseas cambiar al valor del numero " << endl;
    cin >> a;
}

// Aqui si quitamos el ampersand, siempre el resultado sera 10.