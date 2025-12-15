/**
 * Escribe un programa que muestre por pantalla la tabla de multiplicar
 * desde el 1 al 10 del numero que segun el usuario ingrese por pantalla.
 * Sin embargo, este numero debera estar comprendido entre 1 y 100.
 * Si no esta en este intevalo el programa finalizara.
 * La salida debera estar bien formateada.
 */

#include <iostream>
using namespace std;

int main()
{
    int numero;

    cout << "Introduce el numero al que quieres realizar su tabla de multiplicar (1 - 100): ";
    cin >> numero;

    if (numero < 1 || numero > 100)
    {
        cout << "El numero no esta en el rango permitido (1 - 100). Programa finalizado." << endl;
        return 0;
    }

    cout << "\nTabla de multiplicar del " << numero << ":\n";
    cout << "---------------------------" << endl;

    // Mostrar la tabla de multiplicar del 1 al 10
    for (int i = 1; i <= 10; i++) {
        cout << numero << " x " << i << " = " << (numero * i) << endl;
    }

    cout << "---------------------------" << endl;
    cout << "Fin del programa." << endl;

    return 0;

}
