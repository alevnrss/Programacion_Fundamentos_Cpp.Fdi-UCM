/**
 * Una empresa necesita guardar la informacion de empleados de manera que necesita guardar:
 * NIF, nombre y sueldo.
 */
// A.1 Declara un tipo de datos struct para guardar esta informacion.
// A.2 Desarrolla una funcion leerUsuario que devuelva un tipo de dato struct pero que no reciba ningun parametro
// A.3 Desarrolla una funcio mostrarUsuario que reciba como parametros un tipo de dato struct. Elegir el tipo de la funcion y como pasar los parametros
// A.4 En el main se llama a las das funciones y donde solo se podra insertar un usuario.
#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string nombreTrabajador;
    string nif;
    int sueldo;
} tEmpleado;

tEmpleado leerUsuario();
void mostrarUsuario(const tEmpleado &empleado);

int main(){
    tEmpleado empleadoMain;
    empleadoMain = leerUsuario();
    mostrarUsuario(empleadoMain);
    return 0;
}

tEmpleado leerUsuario(){
    tEmpleado empleado;
    cout << "Introduce el NIF: ";
    cin >> empleado.nif;
    cout << "Introduce el nombre: ";
    cin >> empleado.nombreTrabajador;
    cout << "Introduce el suelo anual bruto: ";
    cin >> empleado.sueldo;
    cout << endl;

    return empleado;
}

void mostrarUsuario(const tEmpleado &empleado){
    cout << "--- Datos del empleado ---" << endl;
    cout << "NIF: " << empleado.nif << endl;
    cout << "Nombre: " << empleado.nombreTrabajador << endl;
    cout << "Sueldo: " << empleado.sueldo << endl;
}
