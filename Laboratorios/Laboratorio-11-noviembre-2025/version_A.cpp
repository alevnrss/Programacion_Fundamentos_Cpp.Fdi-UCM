/**
 * A.1 Escribe un programa que permita introducir 10 números enteros por teclado y se guarden en un array
 * de 10 posiciones. Controlar que los números sean enteros positivos, distintos de cero.
 * Tras cargar el array, mostrar su contenido en pantalla.
 *
 * A.2 Escribe otro programa que permita generar aleatoriamente 10 números enteros y se guarden en un
 * array de 10 posiciones. El rango de los números será entre 1 y 10.
 * Tras cargar el array, mostrar su contenido en pantalla.
 *
 * A.3 Escribe un tercer programa que permita leer 10 números guardados en un fichero de texto llamado
 * NumerosALeer.txt y cuyo contenido se muestra a continuación. Todos los números están en una
 * misma línea, separados por un espacio en blanco. Crear el fichero de texto, leer su contenido y
 * guardar los 10 números en un array. Tras cargar el array, mostrar su contenido en pantalla.
 *
 * A.4 Desarrolla un programa que cree un menú.
 * Controla que la opción (numérica) que indique el usuario sea correcta. El programa solo se ejecutará una
 * vez, pero si la opción es incorrecta se repetirá la lectura del número hasta que sea correcto. Una vez
 * seleccionado el tipo de carga del array, utilizar una sentencia condicional múltiple para implementar las
 * distintas opciones. Reutilizar los códigos de los ejercicios anteriores y, para finalizar, mostrar el contenido
 * del array en pantalla.


 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Variables Globales
const int MAX = 10;

// Tipos de datos. Estructuras
typedef int tArrayNumeros[MAX];

// Prototipos
void menuCargaArray();
void menuFunciones();
int leerOpcion(int limInf, int limSup);
void cargaManual(tArrayNumeros numeros);
void cargaAleatoria(tArrayNumeros numeros);
void cargaDesdeFichero(ifstream &archivo, tArrayNumeros numeros);
void mostrarArray(tArrayNumeros numeros);
int calcularMenorValor(tArrayNumeros numeros);
int calcularMayorValor(tArrayNumeros numeros);
int calcularSumatorio(tArrayNumeros numeros);
int leerNumero();
bool buscarNumero(tArrayNumeros numeros, int numABuscar);
int buscarNumeroIndice(tArrayNumeros numeros, int numABuscar); // implementacion propia

int main()
{
    // Inicializacion 0 del array.
    tArrayNumeros numeros = {0};

    // Inicializacion de variables locales.
    ifstream archivo;
    string nombreArchivo = "numerosALeer.txt";
    int opcionUser;
    const int opcionInf = 1;
    int opcionSup = 4;
    menuCargaArray();
    opcionUser = leerOpcion(opcionInf, opcionSup);
    while (opcionUser != 4)
    {
        switch (opcionUser)
        {
        case 1:
            cout << "\nHas elegido : Teclear manualmente los numeros" << endl;
            cargaManual(numeros);
            mostrarArray(numeros);
            break;

        case 2:
            cout << "\nHas elegido : Generar los numeros aleatoriamente" << endl;
            cargaAleatoria(numeros);
            mostrarArray(numeros);
            break;

        case 3:
            cout << "\nHas elegido : Leer los numeros de un fichero de texto" << endl;
            archivo.open(nombreArchivo);
            if (!archivo.is_open())
            {
                cout << "El archivo con nombre " << nombreArchivo << " no se abrio correctamente." << endl;
                break;
            }
            else
            {
                cargaDesdeFichero(archivo, numeros);
                mostrarArray(numeros);
                archivo.close();
            }
            break;
        }

        opcionSup = 5;
        menuFunciones();
        opcionUser = leerOpcion(opcionInf, opcionSup);
        while (opcionUser != 5)
        {
            switch (opcionUser)
            {
            case 1:
                cout << "\nHas elegido : Identificar el menor valor del array" << endl;
                int menorValor;
                menorValor = calcularMenorValor(numeros);
                cout << "El valor menor del array es " << menorValor << endl;
                break;
            case 2:
                cout << "\nHas elegido : Identificar el mayor valor del array" << endl;
                int mayorValor;
                mayorValor = calcularMayorValor(numeros);
                cout << "El valor mayor del array es " << mayorValor << endl;
                break;
            case 3:
                cout << "\nHas elegido : Calcular el sumatorio de todos los valores del array" << endl;
                int valorSumatorio;
                valorSumatorio = calcularSumatorio(numeros);
                cout << "El valor de todo el sumatorio del array es : " << valorSumatorio << endl;
                break;
            case 4:
                cout << "\nHas elegido : Saber si un numero dado esta en el array" << endl;
                int numABuscar;
                int indice = 0; // implementacion propia
                bool encontrado = false;
                numABuscar = leerNumero();
                encontrado = buscarNumero(numeros, numABuscar);
                if (!encontrado)
                {
                    cout << "No se ha logrado encontrar el numero introducido. ";
                }
                else
                {
                    cout << "Se ha logrado encontrar el numero introducido. ";
                }
                indice = buscarNumeroIndice(numeros, numABuscar);
                if (indice == MAX)
                {
                    cout << "Se ha recorrido todo el array sin exito de busqueda" << endl;
                }
                else
                {
                    cout << "El numero se ha logrado encontrar y esta en la posicion del array con indice : " << indice << " -> " << numeros[indice] << endl;
                }
                break;
            }

            opcionSup = 5;
            menuFunciones();
            opcionUser = leerOpcion(opcionInf, opcionSup);
        }
        opcionUser = 4;
    }
    cout << "\nHa elegido : Salir." << endl;
}

// menuCargaArray() : Menu de opciones para inicializar el array.
void menuCargaArray()
{
    cout << "\nCARGA DEL ARRAY DE NUMEROS ENTEROS" << endl;
    cout << "1. Teclear manualmente los numeros" << endl;
    cout << "2. Generar los numeros aleatoriamente" << endl;
    cout << "3. Leer los numeros de un fichero de texto" << endl;
    cout << "4. Salir" << endl;
}

// menuFunciones() : Menu de opciones para operar con el array.
void menuFunciones()
{
    cout << "\nTras cargar el array, elige ahora que quieres calcular ( 5 para salir ) " << endl;
    cout << "1. Identificar el menor valor del array" << endl;
    cout << "2. Identificar el mayor valor del array" << endl;
    cout << "3. Calcular el sumatorio de todos los valores del array" << endl;
    cout << "4. Saber si un numero dado esta en el array" << endl;
    cout << "5. Salir" << endl;
}

// leerOpcion() : Logica de opcion de usuario.
int leerOpcion(const int limInf, const int limSup)
{
    int opcion = -1;
    while ((opcion < limInf) || (opcion > limSup))
    {
        cout << "Escriba el numero de la opcion : ";
        cin >> opcion;
        if ((opcion < limInf) || (opcion > limSup))
        {
            cout << "Valor introducido incorrecto. Intentalo de nuevo." << endl;
        }
    }
    return opcion;
}

// mostrarArray() : Mostrar valores del array
void mostrarArray(tArrayNumeros numeros)
{
    for (int i = 0; i < MAX; i++)
    {
        cout << "Dato del indice " << i << " : " << numeros[i] << endl;
    }
}

// cargaManual() : Inicializacion manual del array
void cargaManual(tArrayNumeros numeros)
{
    int numeroUser = 0;
    int indice = 0;

    cout << "IMPORTANTE: Este array solo puede guardar numeros enteros positivos sin incluir el 0" << endl;
    while (indice < MAX)
    {
        cout << "Introduce el valor que desea guardar en el indice " << indice << " : ";
        cin >> numeroUser;
        while (numeroUser < 1)
        {
            cout << "\nValor introducido incorrecto o fuera de rango. Vuelva a introducir el valor." << endl;
            cout << "Introduce el valor que desea guardar en el indice " << indice << " : ";
            cin >> numeroUser;
        }
        numeros[indice] = numeroUser;
        indice++;
    }
}

// cargaAleatoria() : Inicializacion de numeros entre 1 al 10.
void cargaAleatoria(tArrayNumeros numeros)
{
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        numeros[i] = (1 + rand() % (11 - 1));
    }
}

// cargaDesdeFichero() : Inicializacion de array mediante numeros leidos en un archivo.txt.
void cargaDesdeFichero(ifstream &archivo, tArrayNumeros numeros)
{
    int numerosFichero = 0;

    for (int i = 0; i < MAX; i++)
    {
        archivo >> numerosFichero; // El estractor ignora los espacios por lo que es perfecto en este caso. Si hubiese comas -> archivo >> numero -> despues archivo.ignore();
        numeros[i] = numerosFichero;
    }
}

// calcularMenorValor() : Muestra el menor valor de todos los valores del array
int calcularMenorValor(tArrayNumeros numeros)
{
    int valorMenor = numeros[0];
    for (int i = 1; i < MAX; i++)
    {
        if (numeros[i] < valorMenor)
        {
            valorMenor = numeros[i];
        }
    }
    return valorMenor;
}

// calcularMayorValor() : Muestra el mayor valor de todos los valores del array
int calcularMayorValor(tArrayNumeros numeros)
{
    int valorMayor = numeros[0];
    for (int i = 1; i < MAX; i++)
    {
        if (numeros[i] > valorMayor)
        {
            valorMayor = numeros[i];
        }
    }
    return valorMayor;
}

// calcularSumatorio() : Muestra el valor de la suma total de todos los valores del array
int calcularSumatorio(tArrayNumeros numeros)
{
    int total = 0;
    for (int i = 0; i < MAX; i++)
    {
        total += numeros[i];
    }
    return total;
}

// leerNumero() : Devuelve el numero introducido por el usuario
int leerNumero()
{
    int numero;
    cout << "Introduce el numero que desea buscar en el array: ";
    cin >> numero;
    return numero;
}

// buscarNumero() : Esquema de busqueda en array que busca un numero introducido por el usuario
bool buscarNumero(tArrayNumeros numeros, int numABuscar)
{
    int indice = 0;
    bool encontrado = false;
    while ((indice < MAX) && !encontrado)
    {
        if (numABuscar == numeros[indice])
        {
            encontrado = true;
        }
        indice++;
    }

    return encontrado;
}

// buscarNumeroIndice() : Implementacion propia para saber cual indice es el que tiene el numero.
int buscarNumeroIndice(tArrayNumeros numeros, int numABuscar)
{
    int indice = 0;
    bool encontrado = false;
    while ((indice < MAX) && !encontrado)
    {
        if (numABuscar == numeros[indice])
        {
            encontrado = true;
        }
        else
        {
            indice++;
        }
    }
    return indice;
}
