/**
 * LOS EJERCICIOS 1 Y 2 SON TEST
 * Escribe un procedimiento en C++ que tenga como entrada un número entero positivo y que escriba en la
 * pantalla una tabla como la siguiente, en la que se ha supuesto que el argumento utilizado para llamar al
 * procedimiento es 4.
 */
#include <iostream>
#include <iomanip>
using namespace std;

// Variables globales
const int DIMESION_MATRIZ = 4;

// Prototipos
void matrizBidimensional(const int DIMENSION);

int main(){

    matrizBidimensional(DIMESION_MATRIZ);
    return 0;
}

void matrizBidimensional(const int DIMESION){
    for(int i = 1 ; i <= DIMESION; i++){
        int sumatorio_multiplicacion = 0;
        for(int j = 1; j <= DIMESION; j++){
            int producto;
            producto = i * j;
            cout << setw(DIMESION) << producto;
            sumatorio_multiplicacion += producto;
        }
        cout << setw(DIMESION) << sumatorio_multiplicacion;
        cout << endl;
    }
}