/**
 * Ahora la empresa quiere guardar registros de N empleados que tiene actualmente contratados.
 * El limite MAXIMO de la plantilla es de 8 empleados. Ademas el numero de empleados puede ser variable. Ahora solo estan
 * contratados 6 trabajadores y en la campaña de navidad podran ser 8 como maximo.
 * Realizar los cambio necesarios para guardar hasta un maximo de 8 empleados. Con registros de empleados. 
 * Usar un tipo de datos estructurado que sirva para controlar el numero de empleados actuales(contador), ademas tambien contendra el array que soportara
 * la lista dinamica
 */

#include <iostream>
#include <string>
using namespace std;
// Variabes globales 
const int MAX = 8;

// Tipos de datos
typedef enum
{
    fijo,
    practicas,
    eventual,
    becario
} tTipoContratacion;

typedef struct
{
    int dia;
    int mes;
    int anio;
} tFechaContratacion;

typedef struct
{
    string nombre;
    string apellidos;
    string nif;
    int sueldo;
    int edad;
    tTipoContratacion tipo;
    tFechaContratacion fecha;
} tEmpleado;

typedef tEmpleado tArray[MAX];

typedef struct{
    tArray elemento;
    int contador;
}tLista;

int main(){
    


    return 0;
}