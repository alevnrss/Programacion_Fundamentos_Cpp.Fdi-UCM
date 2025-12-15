/**
 * Reutilizando el codigo anterior...
 * C.1 Modificar el tipo de datos estructurado para que se guarden los siguientes datos en un
 * registro de empleado: nif, nombre completo, sueldo, edad, tipo de contratacion, fecha de
 * contratacion
 */

#include <iostream>
#include <string>
using namespace std;
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

tTipoContratacion stringContratoAEnumerado();
string enumContratoAString(const tTipoContratacion &tipoContrato);
void leerFecha(tFechaContratacion &fecha);
void leerEmpleado(tEmpleado &empleado);
void muestraEmpleado(const tEmpleado &empleado);
int main()
{
    tEmpleado empleado;
    leerEmpleado(empleado);
    muestraEmpleado(empleado);

    return 0;
}

tTipoContratacion stringContratoAEnumerado()
{
    string tipo;
    cin >> tipo;
    if (tipo == "fijo")
    {
        return fijo;
    }
    else if (tipo == "practicas")
    {
        return practicas;
    }
    else if (tipo == "eventual")
    {
        return eventual;
    }
    else if (tipo == "becario")
    {
        return becario;
    }
    return fijo;
}

string enumContratoAString(const tTipoContratacion &tipoContrato)
{
    string tipo;
    switch (tipoContrato)
    {
    case fijo:
        tipo = "fijo";
        break;
    case practicas:
        tipo = "practicas";
        break;
    case eventual:
        tipo = "eventual";
        break;
    case becario:
        tipo = "becario";
        break;
    }

    return tipo;
}

void leerFecha(tFechaContratacion &fecha)
{
    cout << "Introduce la fecha de contratacion: " << endl;
    cout << "Dia: ";
    cin >> fecha.dia;
    cout << "Mes: ";
    cin >> fecha.mes;
    cout << "Anio: ";
    cin >> fecha.anio;
}

void leerEmpleado(tEmpleado &empleado)
{
    cout << "Introduce el NIF: ";
    cin >> empleado.nif;
    cin.ignore(1000, '\n');
    cout << "Introduce el nombre del empleado: ";
    getline(cin, empleado.nombre);
    cout << "Introduce los apellidos del empleado: ";
    getline(cin, empleado.apellidos);
    cout << "Introduce el sueldo anual bruto: ";
    cin >> empleado.sueldo;
    cout << "Introduce la edad del empleado: ";
    cin >> empleado.edad;
    cout << "Introduce el tipo de contrato (fijo, practicas, eventual, becario): ";
    empleado.tipo = stringContratoAEnumerado();
    leerFecha(empleado.fecha);
}

void muestraEmpleado(const tEmpleado &empleado)
{
    cout << "Nombre: " << empleado.nombre
         << " Edad: " << empleado.edad
         << " Contrato: " << enumContratoAString(empleado.tipo)
         << " Desde: " << empleado.fecha.dia << "-" << empleado.fecha.mes << "-" << empleado.fecha.anio;
}