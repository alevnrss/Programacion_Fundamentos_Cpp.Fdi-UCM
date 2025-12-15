/**
 * B. Modifica el programa anterior para que únicamente se calcule la nota si y sólo si todas las calificaciones
 * (examen, proyecto y actividades) sean mayores que 5. En caso de que cualquiera de las calificaciones
 * tecleadas sea menor que 5, el programa informará al usuario y terminará sin realizar el cálculo de la nota final. 
 */

#include <iostream>
using namespace std;

float calcularNotaFinalOrdinaria(float notaExamen, float notaProyecto, float notaActividadesAdicionales);
int main(){
    float notaExamen, notaProyecto, notaActividadesAdicionales, notaFinalOrdinaria;
    cout << "Ingrese la nota del Examen: "; 
    cin >> notaExamen;
    cout << "Ingrese la nota del Proyecto: "; 
    cin >> notaProyecto;
    cout << "Ingrese la nota de las Actividades Adicionales: "; 
    cin >> notaActividadesAdicionales;

    notaFinalOrdinaria = calcularNotaFinalOrdinaria(notaExamen, notaProyecto, notaActividadesAdicionales);

    cout << "La nota final de la Ordinaria es: " << notaFinalOrdinaria << endl;
    return 0;
}

float calcularNotaFinalOrdinaria(float notaExamen, float notaProyecto, float notaActividadesAdicionales){
    if((notaExamen >= 5)&&(notaProyecto >= 5)&&(notaActividadesAdicionales >= 5)){
        return (notaExamen * 0.6) + (notaProyecto * 0.2) + (notaActividadesAdicionales * 0.2);
    }else{
        cout << "No se puede calcular la nota final, alguna de las calificaciones introducidas es menor de 5" << endl;
        return 0;
    }
};