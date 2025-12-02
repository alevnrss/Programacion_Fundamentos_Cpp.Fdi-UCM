#include <iostream>
using namespace std;

// tipo base    identificador  [numero de elementos del array]
// Inicializacion de un array de 7 elementos de tipo float.
float ventas[7] = {125.50, 150.75, 175.00, 200.25, 225.50, 250.75, 275.00};

// Inicializacion de un array de 5 elementos de tipo char.
char vocales[5]= {'a', 'e', 'i', 'o', 'u'};

// Una buena praxis siempre declarar el numero de elementos del array con una constante
const int MAX = 7;
void introducirVentasArray( float ventasVacio[MAX] );

int main(){
    float ventasVacio[MAX];
    
    introducirVentasArray(ventasVacio);

    // Visualizar datos del Array
    for(int i = 0; i < MAX; i++){
        cout << "Venta del dia " << i + 1 << ": " << ventasVacio[i] << endl;
    }
    return 0;
}

void introducirVentasArray( float ventasVacio[MAX] ){
    for (int i = 0; i < MAX; i++){
        cout << "Introduzca la venta del dia " << i + 1 << ": ";
        cin >> ventasVacio[i];
    }
}

