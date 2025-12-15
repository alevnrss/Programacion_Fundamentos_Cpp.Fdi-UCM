/**
 * En una copia del programa anterior(ejercicio F)
 * crea una funcion definida por el usuario llamada tabla de multiplicar
 * que muestre por pantalla la tabla de multiplicar pasandole como parametro el numero
 * leido y correcto en ese intervalo
 */
#include <iostream>
using namespace std;

void tablaMultiplicar(int numero);

int main()
{
    int numero;

    do
    {
        cout << "Introduce el numero al que quieres realizar su tabla de multiplicar (1 - 100): ";
        cin >> numero;

        if (numero >= 1 && numero <= 100)
        {
            tablaMultiplicar(numero);
            return 0;
        }
        else
        {
            cout << "Introduzca un numero correcto en el intervalo señalado" << endl;
        }

    } while (numero < 1 || numero > 100);
}

void tablaMultiplicar(int numero)
{
    cout << "\nTabla de multiplicar del " << numero << ":\n";
    cout << "---------------------------" << endl;

    // Mostrar la tabla de multiplicar del 1 al 10
    for (int i = 1; i <= 10; i++)
    {
        cout << numero << " x " << i << " = " << (numero * i) << endl;
    }

    cout << "---------------------------" << endl;
    cout << "Fin del programa." << endl;
}