/**
 * Se realizara un algoritmo para reconocer cual es el minimo impar del array.
 */
#include <iostream>
#include <cstdlib>
using namespace std;

// Variables globales
const int MAX = 20;
const int MAX_ENTERO = 2147483647;

// Estructuras
typedef int tArray[MAX];

// prototipos
void numerosAleatoriosArray(tArray array);
void mostrarArray(const tArray array);
int minimo_impar(const tArray array);
void mostrarMinimo_impar(int minimo);

int main()
{
    tArray array;
    int minimoImpar;

    numerosAleatoriosArray(array);
    mostrarArray(array);
    minimoImpar = minimo_impar(array);
    mostrarMinimo_impar(minimoImpar);
    

    return 0;
}

// Numeros de 1 a 20 positivos
void numerosAleatoriosArray(tArray array)
{
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        array[i] = (1 + rand() % (21 - 1));
    }
}

void mostrarArray(const tArray array)
{
    cout << "Mostrando valores del array: " << endl;
    for (int i = 0; i < MAX; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Esquema de busqueda
int minimo_impar(const tArray array)
{
    int minimo;
    if (array[0] % 2 != 0){
        minimo = array[0];
    }
    else{
        minimo = MAX_ENTERO;
    }
    for(int i = 1; i < MAX; i++){
        if((array[i]%2 != 0) && array[i] < minimo){
            minimo = array[i];
        }
    }
    return minimo;
}

void mostrarMinimo_impar(int minimo)
{
    if(minimo == MAX_ENTERO){
        cout << "No se ha logrado encontrar un minimo impar en la lista. " << endl;
    }
    cout << "El minimo numero impar de este array es: " << minimo << endl;
}