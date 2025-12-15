/**
 * A. Escribe un programa que calcule la nota final de una asignatura en la convocatoria ordinaria, a partir de las
 * calificaciones obtenidas en el examen, el proyecto y las actividades adicionales.
    - La nota obtenida en el examen representa el 60% de la nota final.
    - Las notas del proyecto y actividades adicionales representan, cada una, un 20% del peso final de la nota.
   El programa pedirá al usuario cada calificación (examen, proyecto y actividades) y mostrará la nota final
   obtenida. No se tendrá en cuenta requisitos mínimos, como que cualquier nota tenga que ser mayor o
   igual a 5. 
 */

#include <iostream>
using namespace std;

float calcularNotaFinalOrdinaria(float notaExamen, float notaProyecto, float notaActividadesAdicionales);

int main(){
    float notaExamen, notaProyecto, notaActividadesAdicionales, notaFinalOrdinaria;
    cout << "Ingrese la nota del examen: ";
    cin >> notaExamen;
    cout << "Ingrese la nota del proyecto: ";
    cin >> notaProyecto;
    cout << "Ingrese la nota de las actividades adicionales: ";
    cin >> notaActividadesAdicionales;

    notaFinalOrdinaria = calcularNotaFinalOrdinaria(notaExamen, notaProyecto, notaActividadesAdicionales);

    cout << "La nota final obtenida es: " << notaFinalOrdinaria << endl;

    return 0;
}

float calcularNotaFinalOrdinaria(float notaExamen, float notaProyecto, float notaActividadesAdicionales){
    notaExamen *= 0.6;
    notaProyecto *= 0.2; 
    notaActividadesAdicionales *= 0.2;
    return notaExamen + notaProyecto + notaActividadesAdicionales;
}
