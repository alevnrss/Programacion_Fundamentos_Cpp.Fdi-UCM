/**
 * Escribe un programa en C++ que:
 * 1. Genere 10 números aleatorios enteros ( [1..100] ) y los guarde en un array de 10 posiciones.
 * 2. Muestre el contenido del array (números generados) en pantalla.
 * 3. Usando la función dígito mágico del ejercicio 11 (Hoja de Ejercicios del tema 3), calcular dicho
 * dígito para cada número aleatorio generado y guardar el dígito obtenido en sustitución del
 * número generado.
 * 4. Mostrar el contenido del array (dígitos mágicos) en pantalla
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 10;
typedef int tArrayNumerosAleatorios[MAX];

void guardarArrayNumeros(tArrayNumerosAleatorios arrayNumeros);
void mostrarArrayNumeros(tArrayNumerosAleatorios arrayNumeros);
int sumarDigitos(int n);
int digitoMagico(int n);
void calcularSumaDigitos(tArrayNumerosAleatorios arrayNumeros, tArrayNumerosAleatorios arrayDigitos);

int main()
{

    tArrayNumerosAleatorios arrayNumeros;
    tArrayNumerosAleatorios arrayDigitosMagicos;
    guardarArrayNumeros(arrayNumeros);
    mostrarArrayNumeros(arrayNumeros);
    calcularSumaDigitos(arrayNumeros, arrayDigitosMagicos);
    cout << "\nDigito magico: " << endl;
    mostrarArrayNumeros(arrayDigitosMagicos);

    return 0;
}

void guardarArrayNumeros(tArrayNumerosAleatorios arrayNumeros)
{
    srand(time(NULL));

    for (int i = 0; i < MAX; i++)
    {
        arrayNumeros[i] = (1 + rand() % (101 - 1));
    }
}

void mostrarArrayNumeros(tArrayNumerosAleatorios arrayNumeros)
{
    cout << "Numeros generados:" << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << arrayNumeros[i] << " ";
    }
}


void calcularSumaDigitos(tArrayNumerosAleatorios arrayNumeros, tArrayNumerosAleatorios arrayDigitos)
{
    for (int i = 0; i < MAX; i++)
    {
        arrayDigitos[i] = digitoMagico(arrayNumeros[i]);
    }
}

int digitoMagico(int n)
{
    // Se repite siempre y cuando el numero del array sea mayor a 9, si es 39 entonces se repite hasta que sea menor a 9.(sea > 9)
    while (n > 9)
    {
        n = sumarDigitos(n);
    }
    return n;
}

int sumarDigitos(int n)
{
    int suma = 0;
    while (n > 0)
    {
        suma += n % 10; // se suma el utlimo digito     495 -> suma + 5;
        n /= 10;    // se borra ese utlimo digito una vez sumado    -> 495 -> n = 49
    }
    return suma;
}
