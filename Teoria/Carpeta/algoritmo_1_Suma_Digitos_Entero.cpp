/*
 * Algoritmo del numero magico.
 */

#include <iostream>
using namespace std;

int main(){
    int n, suma = 0, digito;
    cout << "Ingrese un numero entero positivo: "; cin >> n;
    while(n != 0){
        digito = n % 10;    // obtenemos el ultimo digito
        suma += digito;     // lo sumamos
        n = n / 10;         // eliminamos el ultimo digito
    }
    cout << "La suma de los digitos es: " << suma << endl;
    return 0;
}

/**
 * Este algoritmo se utiliza para calcular la suma de los digitos de un numero entero positivo.
 * si tenemos un numero 123, la suma de sus digitos es 6.
 * Primero lo que iremos haciendo es obtener el ultimo digito. 
 * Para obtener el ultimo digito de un numero basta con coger el resto de la division entre 10.
 * Si pensamos, el numero 123 esta compuesto por 1 * 100 + 2 * 10 + 3 * 1 = 123
 * Entonces 123 % 10 = 3, es decir obtenemos el ultimo digito, que en este caso es 3.
 * Ahora que tenemos el ultimo digito, lo sumamos a la variable suma.
 * Y asi sucesivamente, obteniendo la suma de sus digitos hasta que tengamos un numero 0
 * lo que significa que hemos terminado de recorrer el numero.
 */