/**
 * Siguiendo con el programa anterior, crea otra funcion que se llame
 * entrada de datos que contenga el codigo desarrollado para comprobar
 * si el numero se encuentra en el intervalo seleccionado
 */
#include <iostream>
using namespace std;

void tablaMultiplicar(int numero);
int entradaDatos();

int main()
{
    int numero;
    numero = entradaDatos();

    tablaMultiplicar(numero);
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
int entradaDatos(){
    int numero;
    do
    {
        cout << "Introduce el numero al que quieres realizar su tabla de multiplicar (1 - 100): ";
        cin >> numero;

        if (numero >= 1 && numero <= 100)
        {
            return numero;
        }
        else
        {
            cout << "Introduzca un numero correcto en el intervalo señalado" << endl;
        }

    } while (numero < 1 || numero > 100);
}