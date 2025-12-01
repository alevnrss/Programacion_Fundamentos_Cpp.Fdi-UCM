/**
 * ALGORITMO 5.
 * Este algoritmo se trata de un problema basico de calculo que tratara sobre realizar la secuenca de 
 * recurrencia de los numeros de fibonacci.
 * Aqui los numeros de fibonacci tenemos que saber dos cosas: Cual es su comienzo y cual es su funcion.
 * 
 * - Empieza por dos numeros FIJOS que son el 0 y el 1, despues de estos dos numeros iniciales, se da
 *   la suma de los numeros anteriores asi sucesivamente.
 * - La suma de los anteriores se debera hacer con el algoritmo de cambio de variable. Pues cada vez que queramos
 *   remplazar el valor de una variable para poder dar comienzo a la iteracion deberemos recurrir a dicho algoritmo.
 */
#include <iostream>

using namespace std;

// Función para generar la sucesión de Fibonacci hasta 'n' términos
void generarFibonacciIterativo(int n);

int main() {
    int num_terminos = 10;
    generarFibonacciIterativo(num_terminos);
    // Salida: 0 1 1 2 3 5 8 13 21 34 
    return 0;
}

void generarFibonacciIterativo(int n) {
    if (n <= 0) {
        cout << "El número de términos debe ser positivo." << endl;
        return;
    }

    // Inicializamos los dos primeros términos
    long long a = 0; // F_0
    long long b = 1; // F_1
    long long siguiente_termino;

    cout << "Serie de Fibonacci (" << n << " términos):" << endl;

    for (int i = 0; i < n; i++) {
        // Imprimimos el término actual (a)
        cout << a << " ";

        // Si ya hemos generado el término 0 y 1, calculamos el siguiente
        if (i == 0) {
            siguiente_termino = 1; // El siguiente término después de 0 es 1
        } else {
            // Calculamos el siguiente término: F_n = F_{n-1} + F_{n-2}
            siguiente_termino = a + b;
        }
        
        // Actualizamos los valores para la siguiente iteración
        // El anterior (a) se convierte en el segundo anterior (b)
        // El segundo anterior (b) se convierte en el nuevo término (siguiente_termino)
        b = a; // Ojo: Se actualizan de esta forma para mantener el flujo correcto en la inicialización
        a = siguiente_termino;
    }
    cout << endl;
}
