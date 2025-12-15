/**
 * Guarda en un array las calificaciones de 10 alumnos y muestra finalmente su media de las notas.
 * Utilizacion de funciones. 
 */

#include <iostream>
using namespace std;

const int MAX = 10;
typedef float tNotas[MAX];
float sumaNotas = 0;
float mediaNotas = 0;

void introducirNotasArray(tNotas notasAlumnos);
float calcularMediaArray(float sumaNotas, float mediaNotas, tNotas notasAlumnos);
int main(){
    tNotas arrayNotasAlumnos = { 0 };
    introducirNotasArray(arrayNotasAlumnos);
    mediaNotas = calcularMediaArray(sumaNotas, mediaNotas, arrayNotasAlumnos);
    cout << "La media de las notas de todos los alumnos es: " << mediaNotas << endl;
    return 0;
}

// Introducimos las notas de los alumnos en los arrays
void introducirNotasArray(tNotas notasAlumnos){
    for(int i = 0; i < MAX; i++){
        cout << "Introduzca la nota del alumno " << i + 1 << ": ";
        cin >> notasAlumnos[i];
    }
}

// Los valores del array los metemos a una variable, a esa variable le aplicamos la divison con el
// tamaño maximo del array para obtener la media.
float calcularMediaArray(float sumaNotas, float mediaNotas, tNotas notasAlumnos){
    for(int i = 0; i < MAX; i++){
        sumaNotas += notasAlumnos[i];
        mediaNotas = sumaNotas / MAX;
    }
    return mediaNotas;
}