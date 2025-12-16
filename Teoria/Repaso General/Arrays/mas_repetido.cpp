/**
 * Se realizara un algoritmo para reconocer cual es el minimo impar del array.
 */
#include <iostream>
#include <cstdlib>
#include <ctime> // Necesario para time(NULL)
using namespace std;

// Variables globales separadas para robustez
const int TAMANO_ARRAY = 20;  // Número de elementos en el array principal.
const int MAX_VALOR = 20;     // El valor máximo que un elemento puede tomar.

// Estructuras: tArrayFrecuencias es 1 unidad más grande para alojar el índice MAX_VALOR
typedef int tArrayPrincipal[TAMANO_ARRAY];
typedef int tArrayFrecuencias[MAX_VALOR + 1];

// Prototipos
void numerosAleatoriosArray(tArrayPrincipal array);
void mostrarArray(const tArrayPrincipal array);
void contarFrecuencias(const tArrayPrincipal array, tArrayFrecuencias frecuencias);
int buscarMasRepetido(const tArrayFrecuencias frecuencias);

int main()
{
    tArrayPrincipal array;
    // tArrayFrecuencias tiene 21 elementos, inicializados a 0
    tArrayFrecuencias frecuencias = {0}; 
    int mas;

    numerosAleatoriosArray(array);
    mostrarArray(array);
    contarFrecuencias(array, frecuencias);
    mas = buscarMasRepetido(frecuencias);
    
    // Aquí puedes añadir la comprobación de si masRepetido es -1 por si no hay valores positivos
    if (mas != -1) { 
        cout << "El valor mas repetido es : " << mas << endl;
    } else {
        cout << "No se encontraron valores validos (positivos) para contar." << endl;
    }

    return 0;
}

// Números de 1 a MAX_VALOR positivos
void numerosAleatoriosArray(tArrayPrincipal array)
{
    srand(time(NULL));
    for (int i = 0; i < TAMANO_ARRAY; i++)
    {
        // Genera números entre [1, MAX_VALOR]
        array[i] = (1 + rand() % MAX_VALOR); 
    }
}

void mostrarArray(const tArrayPrincipal array)
{
    cout << "Mostrando valores del array: " << endl;
    for (int i = 0; i < TAMANO_ARRAY; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void contarFrecuencias(const tArrayPrincipal array, tArrayFrecuencias frecuencias){
    for(int i = 0; i < TAMANO_ARRAY; i++){
        int valor = array[i];
        
        // Comprobación de seguridad: asegura que valor está dentro del rango del array de frecuencias
        if (valor > 0 && valor <= MAX_VALOR) {
            frecuencias[valor]++; 
        }
    }
}

int buscarMasRepetido(const tArrayFrecuencias frecuencias){
    int maxFrecuencia = -1;
    int masRepetido = -1;
    
    // Recorremos desde el índice 1 hasta MAX_VALOR (incluido)
    for(int i = 1; i <= MAX_VALOR; i++){
        int frecuenciaActual = frecuencias[i];
        
        if(frecuenciaActual > maxFrecuencia){
            maxFrecuencia = frecuenciaActual;
            masRepetido = i;
        }
        // Si hay empate, (frecuenciaActual == maxFrecuencia), conservamos el i anterior (el más bajo). ¡Esto cumple el desempate!
    }

    return masRepetido;
}
