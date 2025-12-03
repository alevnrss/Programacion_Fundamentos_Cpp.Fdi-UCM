/**
 * Modifica el programa anterior según las siguientes indicaciones, aplicando un esquema de búsqueda, para
 * encontrar el primer dígito mágico que sea menor que 5:
 * 1. Genere 10 números aleatorios enteros ( [1..100] ) y los guarde en un array de 10 posiciones.
 * 2. Muestre el contenido del array (números generados) en pantalla.
 * 3. Usando la función dígito mágico del ejercicio 11 (Hoja de Ejercicios del tema 3), calcular dicho
 * dígito para cada número aleatorio generado y guardar el dígito obtenido en sustitución del
 * número generado si y sólo si el dígito mágico es mayor o igual que 5.
 * Si el dígito mágico es mayor o igual a 5, mostrarlo en pantalla.
 * En caso contrario, mostrar un mensaje al usuario indicando la posición en la que se ha encontrado
 * el primer número cuyo dígito mágico es menor que 5. El programa NO continuará con el cálculo
 * de más dígitos mágicos.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 10;
typedef int tArrayNumerosAleatorios[MAX];

void generarYguardarNumerosAleaotrios(tArrayNumerosAleatorios arrayNumerosAleatorios);
void mostrarArrayNumeros(const tArrayNumerosAleatorios array);
void arrayDigitoMagico(tArrayNumerosAleatorios arrayDigitos, tArrayNumerosAleatorios arrayNumerosAleatorios);
int esDigitoMagico(int n);
int sumaDigitos(int n);
void buscarDigitoMagico(const tArrayNumerosAleatorios arrayDigitosmagicos);

int main()
{
    int indice = 0;
    tArrayNumerosAleatorios arrayNumerosAleatorios;
    tArrayNumerosAleatorios arrayDigitosMagicos;

    generarYguardarNumerosAleaotrios(arrayNumerosAleatorios);
    mostrarArrayNumeros(arrayNumerosAleatorios);

    cout << "\nBusqueda de numero Magico menor a 5 " << endl;
    arrayDigitoMagico(arrayDigitosMagicos, arrayNumerosAleatorios);
    mostrarArrayNumeros(arrayDigitosMagicos);
    buscarDigitoMagico(arrayDigitosMagicos);

    return 0;
}

void generarYguardarNumerosAleaotrios(tArrayNumerosAleatorios arrayNumerosAleatorios)
{
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        arrayNumerosAleatorios[i] = (1 + rand() % (101 - 1));
    }
}

void mostrarArrayNumeros(const tArrayNumerosAleatorios array)
{
    cout << "Numeros generados: " << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << array[i] << " ";
    }
}
// guardar todos los digitos magicos en este array.
void arrayDigitoMagico(tArrayNumerosAleatorios arrayDigitos, tArrayNumerosAleatorios arrayNumerosAleatorios)
{
    for (int i = 0; i < MAX; i++)
    {
        arrayDigitos[i] = esDigitoMagico(arrayNumerosAleatorios[i]);
    }
}

void buscarDigitoMagico(const tArrayNumerosAleatorios arrayDigitosmagicos)
{
    int indice = 0;
    bool encontrado = false;
    while ((indice < MAX) && !encontrado)
    {
        if (arrayDigitosmagicos[indice] < 5)
        {
            cout << "\nPrimer digito magico menor a 5 encontrado en la posicion " << indice << " : " << arrayDigitosmagicos[indice];
            encontrado = true;
        }
        else
        {
            cout << "\nDigito magico en posicion " << indice << " : " << arrayDigitosmagicos[indice];
            indice++;
        }
    }
}

int esDigitoMagico(int n)
{
    while (n > 9)
    {
        n = sumaDigitos(n);
    }
    return n;
}

int sumaDigitos(int n)
{
    int sumaDigitos = 0;
    while (n > 0)
    {
        sumaDigitos += n % 10;
        n /= 10;
    }
    return sumaDigitos;
}