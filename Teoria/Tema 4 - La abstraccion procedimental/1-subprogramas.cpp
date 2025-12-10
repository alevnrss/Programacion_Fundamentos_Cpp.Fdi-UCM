/**
 * La abstraccion es una operacion intelectual que consiste en ignorar los detalles irrelevantes de algo 
 * y poder asi enfocarse en los aspectos esenciales.
 * 
 * La abstraccion procedimental enfoca dicho concepto en el codigo. 
 * La abstraccion procedimental lo podemos implementar mediante dos tipos de SUBPROGRAMAS:
 *  - FUNCIONES: Las funciones son de un tipo especifico que devuelven un valor.
 *  - PROCEDIMIENTOS: Los procedimientos son de tipo VOID y no devuelven ningun valor al realizar la tarea.
 */
#include <iostream>
using namespace std;
int main(){
    int opcion;

    // Llamada a la funcion
    opcion = menu();

    // Llamada al procedimiento
    menuProcedimiento();

    return 0;
}

int menu(){
    // FUNCION QUE DEVUELVE UN NUMERO -> OPCION QUE DIGA EL USUARIO
    // ...
    return 1;
}
void menuProcedimiento(){
    // FUNCION QUE NO DEVUELVE NADA
}
