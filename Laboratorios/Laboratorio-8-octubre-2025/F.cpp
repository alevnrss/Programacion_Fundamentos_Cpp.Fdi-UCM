/**
 * Modidica el programa anterior pero en este caso, no terminara hasta que se introduzca un
 * numero valido entre el intervalo del 1 al 100
 */
#include <iostream>
using namespace std;

int main()
{
    int numero;

    do
    {
        cout << "Introduce el numero al que quieres realizar su tabla de multiplicar (1 - 100): ";
        cin >> numero;
        
        if (numero >= 1 && numero <= 100)
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

            return 0;
        }else{
            cout << "Introduzca un numero correcto en el intervalo señalado" << endl;
        }

    } while (numero < 1 || numero > 100);
}
