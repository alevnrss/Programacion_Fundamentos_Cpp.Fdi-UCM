/**
 * Escribe un programa en C++ que calcule cuántos números perfectos hay en un archivo datos.txt (enteros,
 * cada uno en una línea y terminado en 0 como centinela). Se dice que un número (entero positivo) n es
 * perfecto, si la suma de los divisores de n entre 1 y n-1 es igual a n. Por ejemplo, 6 es un número perfecto,
 * pues sus divisores, incluyendo el 1 pero no el propio 6, son 1, 2 y 3, y suman 6.
 */
#include <iostream>
#include <fstream>
using namespace std;

// variables globales
const int MAX = 15;

// estructuras
typedef int tArrayPerfectos[MAX];

// prototipos
int esNumeroPerfecto(int numero);
int rellenarArrayNumerosPerfectos(ifstream &archivo, tArrayPerfectos &arrayEnteros, const int MAXIMO);
void mostrarArrayNumeros(const tArrayPerfectos array, const int MAXIMO, const int indice);

int main()
{
    tArrayPerfectos arrayEnteros;
    tArrayPerfectos arrayPerfectos;

    // Definimos el indice para usarlo si no se llega a completar todo el array y asi no leer basura.
    int indice = 0;
    
    ifstream archivo;

    archivo.open("datos.txt");
    if (!archivo.is_open())
    {
        cout << "ERROR al abrir el archivo datos.txt";
    }
    else
    {
        indice = rellenarArrayNumerosPerfectos(archivo, arrayEnteros, MAX);
        mostrarArrayNumeros(arrayEnteros, MAX, indice);

        archivo.close();
    }

    int numero = 6;
    esNumeroPerfecto(numero);
    return 0;
}

int rellenarArrayNumerosPerfectos(ifstream &archivo, tArrayPerfectos &arrayEnteros, const int MAXIMO)
{
    int numerosEnteros;
    int esPerfecto = 0;
    int indiceFinal = 0;

    archivo >> numerosEnteros;
    while ((numerosEnteros != 0) && indiceFinal < MAXIMO)
    {
        esPerfecto = esNumeroPerfecto(numerosEnteros);
        if (esPerfecto == numerosEnteros)
        {
            arrayEnteros[indiceFinal] = numerosEnteros;
            indiceFinal++;
        }
        archivo >> numerosEnteros;
    }
    return indiceFinal;
}

void mostrarArrayNumeros(const tArrayPerfectos array, const int MAXIMO, const int indice)
{
    if (indice == MAX)
    {
        cout << "Se ha rellenado todo el array" << endl;
    }
    else
    {
        cout << "No se ha rellenado todo el array " << endl;
    }

    for (int i = 0; i < indice; i++)
    {
        cout << array[i] << " ";
    }
}

int esNumeroPerfecto(int numero)
{
    int sumaDivisores = 0;
    int i = (numero - 1);
    for (i; i > 0; i--)
    {
        if ((numero % i) == 0)
        {
            sumaDivisores += i;
        }
    }

    return sumaDivisores;
}
