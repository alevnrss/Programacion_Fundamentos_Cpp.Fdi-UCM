#include <iostream>
using namespace std;

const int MAX= 5;
typedef float tNotas[MAX];  // Declaracion de un tipo definido por el usuario
                            // Declaracion de un tipo array de 5 elementos de tipo float

int main(){
    tNotas notasAlumnos = { 0 }; // notasAlumnos es un array de 5 elementos de tipo float
    float mediaNotas = 0;
    float menor = 10; // Siendo 10 la mayor calificacion posible
    float mayor = 0;  // Siendo 0 la menor calificacion posible

    // Meter elementos en el array
    cout << "Introduzca las "<< MAX <<" notas de los alumnos: " << endl;
    for(int i=0; i<MAX; i++){
        cout << "Alumno: "<< i + 1 << endl;
        cin >> notasAlumnos[i];
    }

    // Recorrer el array y mostrar elementos
    cout << "Las notas de los " << MAX << " alumnos son:"<< endl;
    for(int i=0; i<MAX; i++){
        cout << notasAlumnos[i] << "|";
    }
    cout << endl;

    // Mostrar la media total de las notas de los alumnos
    for(int i=0; i<MAX; i++){
        mediaNotas += notasAlumnos[i];
    }
    cout << "La media de las notas es: " << (mediaNotas/MAX) << endl;
    cout << endl;

    // Comparacion de datos/notas del array - Mostrar la menor y mayor nota de todas las notas de los alumnos.
    for(int i=0; i<MAX; i++){
        if(notasAlumnos[i] < menor){
            menor = notasAlumnos[i];
        }
        if(notasAlumnos[i] > mayor ){
            mayor = notasAlumnos[i];
        }
    }
    cout << "La menor nota es: " << menor << endl;
    cout << "La mayor nota es: " << mayor << endl;

    return 0;
}