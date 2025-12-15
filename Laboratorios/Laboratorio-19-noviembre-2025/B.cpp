// Reutilizando el codigo anterior...
// B.1 Recodifica la funcion leerUsuario() pero que en este caso sea un procedimiento y no una funcion.Utiliza el paso por parametros
// adecuado para este procedimiento. No hay cambios en la funcionalidad: Leer los 3 datos de un usuario y guardarlos en un 
// tipo de datos estructurado
#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

typedef struct{
    string nombreTrabajador;
    string nif;
    int sueldo;
} tEmpleado;

typedef tEmpleado tArray[MAX];

void leerUsuario(tEmpleado &empleado);
void leerTodosLosUsarios(tArray &array);
void MostrarArrayUsuarios(const tArray &array);
int main(){
    tArray arrayEmpleados;
    leerTodosLosUsarios(arrayEmpleados);
    MostrarArrayUsuarios(arrayEmpleados);
    return 0;
}

void leerUsuario(tEmpleado &empleado){
    cout << "Introduce el NIF: ";
    cin >> empleado.nif;
    cout << "Introduce el nombre: ";
    cin >> empleado.nombreTrabajador;
    cout << "Introduce el suelo anual bruto: ";
    cin >> empleado.sueldo;
}
void leerTodosLosUsarios(tArray &array){
    for(int i = 0; i < MAX; i++){
        leerUsuario(array[i]);
    }
}
void MostrarArrayUsuarios(const tArray &array){
    cout << "--- Datos de los empleados ---" << endl;
    for(int i = 0; i < MAX; i++){
        cout << "Empleado " << i + 1 << ": ";
        cout << "NIF: " << array[i].nif << " ";
        cout << "Nombre: " << array[i].nombreTrabajador << " ";
        cout << "Sueldo anual: " << array[i].sueldo << endl;
    }
}