/**
 *
 */
#include <iostream>
using namespace std;

// variables globales
const int ERRORES = 4;
const int MAX = 6;

// estructuras
typedef enum
{
    ErrorPar,
    ErrorNegativo,
    ErrorMultiplo7,
    ErrorMultiplo19,
    Ok
} tCodigosError;

typedef int tContErrores[ERRORES]; // Array que almacenara todos los errores cometidos.
typedef int tNumeros[MAX];         // Array que contendra los numeros leidos que cumplan todo.

// prototipos
int inicializarArray(tNumeros numeros, tContErrores errores);
tCodigosError analizarNumero(int num);
string toString(int n);
void mostrarDatos(tNumeros numeros, int contador);
void mostrarErrores(tContErrores errores);

int main()
{
    tNumeros numeros;
    tContErrores errores;
    int indice = inicializarArray(numeros, errores);
    mostrarDatos(numeros, indice);
    mostrarErrores(errores);
    return 0;
}

int inicializarArray(tNumeros numeros, tContErrores errores)
{
    int numero;
    int indice = 0;
    int centinela = 0;

    tCodigosError codigo_error;

    // Inicializamos sus valores a 0.
    for (int i = 0; i < MAX; i++)
    {
        numeros[i] = 0;
    }

    for (int i = 0; i < ERRORES; i++)
    {
        errores[i] = 0;
    }

    cout << "Escribe numeros que siga las condiciones puestas por pantalla : " << endl;
    cout << "\n-Que no sea par" << endl;
    cout << "-Que no sea negativo" << endl;
    cout << "-Que no sea multiplo de 7 ni de 19" << endl;
    cout << "\n-El array solo guardara los 6 primeros digitos correctos o hasta que se lea el centinela(0)" << endl;

    cin >> numero;
    while ((indice < MAX) && (numero != centinela))
    {
        codigo_error = analizarNumero(numero);
        if (codigo_error == Ok)
        {
            numeros[indice] = numero;
            indice++;
        }
        else if (codigo_error == ErrorPar)
        {
            errores[ErrorPar] += 1;
        }
        else if (codigo_error == ErrorNegativo)
        {
            errores[ErrorNegativo] += 1;
        }
        else if (codigo_error == ErrorMultiplo7)
        {
            errores[ErrorMultiplo7] += 1;
        }
        else if (codigo_error == ErrorMultiplo19)
        {
            errores[ErrorMultiplo19] += 1;
        }
        cin >> numero;
    }

    return indice;
}

void mostrarDatos(tNumeros numeros, int contador)
{
    cout << "Lista de numeros correctos guardados en el array" << endl;
    for (int i = 0; i < contador; i++)
    {
        cout << "Dato " << i << " : " << numeros[i] << endl;
    }
}

void mostrarErrores(tContErrores errores)
{
    cout << "Se han cometido los siguientes errores :" << endl;
    for (int i = 0; i < ERRORES; i++)
    {
        cout << "Dato " << toString(i) << " : " << errores[i] << endl;
    }
}

tCodigosError analizarNumero(int num)
{
    tCodigosError codigo;
    if (num % 2 == 0)
    {
        codigo = ErrorPar;
    }
    else if (num < 0)
    {
        codigo = ErrorNegativo;
    }
    else if (num % 7 == 0)
    {
        codigo = ErrorMultiplo7;
    }
    else if (num % 19 == 0)
    {
        codigo = ErrorMultiplo19;
    }
    else
    {
        codigo = Ok;
    }
    return codigo;
}

string toString(int n)
{
    string valorEnum;
    switch (n)
    {
    case ErrorPar:
        valorEnum = "ERROR PAR";
        break;

    case ErrorNegativo:
        valorEnum = "ERROR NEGATIVO";
        break;

    case ErrorMultiplo7:
        valorEnum = "ERROR MULTIPLO DE 7";
        break;

    case ErrorMultiplo19:
        valorEnum = "ERROR MULTIPLO DE 19";
        break;

    case Ok:
        valorEnum = "OK";
        break;
    }
    return valorEnum;
}