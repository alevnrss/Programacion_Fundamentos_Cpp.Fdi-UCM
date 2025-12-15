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

typedef struct
{
    tArray elemento;
    int contador;
} tLista;

// Prototipos
tTipoContratacion stringContratoAEnumerado();
string enumContratoAString(const tTipoContratacion &tipoContrato);
void leerFecha(tFechaContratacion &fecha);
void leerPlantilla(tLista &lista, int numeroEmpleadosALeer);
void mostrarPlantilla(const tLista &lista);
int main()
{
    tLista lista;
    int numero;
    cout << "Introduce un numero de empleados a registrar (1-8): ";
    cin >> numero;
    leerPlantilla(lista, numero);
    mostrarPlantilla(lista);

    return 0;
}

void leerPlantilla(tLista &lista, int numeroEmpleadosALeer)
{
    if (numeroEmpleadosALeer == 8)
    {
        lista.contador == MAX;
    }
    else
    {
        lista.contador = numeroEmpleadosALeer;
    }
    for (int i = 0; i < lista.contador; i++)
    {
        cout << "\n=== Empleado " << i + 1 << " ===" << endl;
        cout << "Introduce el NIF: ";
        cin >> lista.elemento[i].nif;
        cin.ignore(1000, '\n');
        cout << "Introduce el nombre: ";
        getline(cin, lista.elemento[i].nombre);
        cout << "Introduce los apellidos: ";
        getline(cin, lista.elemento[i].apellidos);
        cout << "Introduce el sueldo anual bruto: ";
        cin >> lista.elemento[i].sueldo;
        cout << "Introduce la edad: ";
        cin >> lista.elemento[i].edad;
        cout << "Introduce el tipo de contrato (fijo, practicas, eventual, becario): ";
        lista.elemento[i].tipo = stringContratoAEnumerado();
        leerFecha(lista.elemento[i].fecha);
    }
}

void mostrarPlantilla(const tLista &lista)
{
    cout << "\n============= PLANTILLA COMPLETA =============" << endl;
    for (int i = 0; i < lista.contador; i++)
    {
        cout << "\nEmpleado: " << i + 1 << ": "
             << " Nombre: " << lista.elemento[i].nombre +" "+lista.elemento[i].apellidos 
             << " Edad: " << lista.elemento[i].edad
             << " Contrato: " << enumContratoAString(lista.elemento[i].tipo)
             << " Desde: " << lista.elemento[i].fecha.dia << "-" << lista.elemento[i].fecha.mes << "-" << lista.elemento[i].fecha.anio << endl;
    }
    cout << "\nTotal empleados: " << lista.contador << endl;
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
    cout << "\n\tDia: ";
    cin >> fecha.dia;
    cout << "\tMes: ";
    cin >> fecha.mes;
    cout << "\tAnio: ";
    cin >> fecha.anio;
}