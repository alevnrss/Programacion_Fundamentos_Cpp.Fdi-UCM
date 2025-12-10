/**
 * Escribe un procedimiento en C++ que encuentre y muestre todos los números de tres cifras en los que la
suma de los cubos de sus dígitos sea igual al propio número. Ejemplo: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Variables Globales
const int MINIMO_TRES_CIFRAS = 100;
const int MAXIMO_TRES_CIFRAS = 999;
const int NUMEROS_ARMSTRONG = 4; // solo hay 4 numeros de armstrong

// Estructuras
typedef int tArrayArmstrong[NUMEROS_ARMSTRONG];

// Prototipos
void rellenartArrayArmstrong(tArrayArmstrong array, const int MINIMO, const int MAXIMO, const int NUMEROS_ARMSTRONG);
int esNumeroArmstrong(int n);
int calcularDigitoArmstrong(int n);

int main()
{

    tArrayArmstrong arrayDeArmstrong;

    rellenartArrayArmstrong(arrayDeArmstrong, MINIMO_TRES_CIFRAS, MAXIMO_TRES_CIFRAS, NUMEROS_ARMSTRONG);

    cout << "Numeros de Armstrong encontrados:" << endl;
    for (int i = 0; i < NUMEROS_ARMSTRONG; i++)
    {
        cout << arrayDeArmstrong[i] << endl;
    }

    return 0;
}

void rellenartArrayArmstrong(tArrayArmstrong array, const int MINIMO, const int MAXIMO, const int NUMEROS_ARMSTRONG)
{
    int indice = 0;

    for (int i = MINIMO; i <= MAXIMO; i++)
    {
        int resultado = esNumeroArmstrong(i);
        if ((resultado != 0) && (indice < NUMEROS_ARMSTRONG))
        {
            array[indice] = resultado;
            indice++;
        }
        if (indice == NUMEROS_ARMSTRONG)
        {
            return;
        }
    }
}

int esNumeroArmstrong(int n)
{
    int sumaCubosCalculada = calcularDigitoArmstrong(n);
    if (sumaCubosCalculada == n)
    {
        return n;
    }
    else
    {
        return 0;
    }
}

int calcularDigitoArmstrong(int n)
{
    int digito;
    int sumaCubos = 0;
    int temp = n; // no hace falta pero por si acaso no queremos modificar n.

    while (temp > 0)
    {
        // obtener el ultimo digito
        digito = temp % 10;
        sumaCubos += (int)pow(digito, 3.0);
        temp /= 10;
    }
    return sumaCubos;
}