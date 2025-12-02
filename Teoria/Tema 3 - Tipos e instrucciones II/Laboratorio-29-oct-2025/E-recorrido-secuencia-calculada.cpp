/**
 * Escribe un programa en C++ que genere y muestre por pantalla la secuencia de los cuadrados de los números naturales.
 * El programa deberá pedir al usuario cuántos términos desea calcular y luego mostrar los resultados en una sola línea separados por espacios.
 * Cada término de la secuencia se calcula con la fórmula: 𝑎 = 𝑛^2
 */

#include <iostream>
#include <cmath>
using namespace std;

void secuenciaCuadradosNaturales(int n);
int main(){
    int n ;
    cout << "Cuantos terminos de la secuencia de cuadrados deseas calcular? ";
    cin >> n;
    cout << "Secuencia de los cuadrados de los primeros " << n << " numeros naturales: " << endl;
    secuenciaCuadradosNaturales(n);
    return 0;
}

void secuenciaCuadradosNaturales(int n){
    for(int i = 1; i <= n ; i++ ){
        cout << pow(i, 2.0) << " ";
    }
}