#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
// variables globales
const int CAPACIDAD = 100;

// Estructuras
typedef struct
{
    int anio;
    int mes;
} tfecha;

typedef struct
{
    tfecha fecha;
    double precipitacion;
    double temp_max;
    double temp_min;
} tDatosMeteo;

typedef tDatosMeteo tArray[CAPACIDAD];

typedef struct
{
    tArray elemento;
    int contador;
} tLista;

// prototipos
int menu();
void mostrarDatosMenu();
void registro(tLista &lista, ifstream &archivo, bool &ok);
void mostrarHistorial(const tLista &lista);
int olaCalor(const tLista& lista);
int main()
{
    int opcion;
    tDatosMeteo datos;
    tLista lista;
    lista.contador = 0;
    bool exito = false;
    ifstream archivo;

    opcion = menu();
    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
            registro(lista, archivo, exito);
            if (!exito)
            {
                cout << "Error al abrir el archivo y cargar los datos.";
            }
            else{
                mostrarHistorial(lista);
            }
            break;
        case 2:
            int duracionOlaCalor;
            duracionOlaCalor = olaCalor(lista);
            cout << "Ola de calor mas larga: " << duracionOlaCalor << endl;
            break;
        case 3:
            cout << "Opcion 3 escogida";
            break;
        }
        opcion = menu();
    }

    return 0;
}

int menu()
{
    int opcion = -1;
    while ((opcion < 0) || (opcion > 3))
    {
        mostrarDatosMenu();
        cin >> opcion;
        if ((opcion < 0) || (opcion > 3))
        {
            cout << "\nOpcion no valida." << endl;
        }
    }
    cout << "\n";
    return opcion;
}
void mostrarDatosMenu()
{
    cout << "\n======= REGISTRO METEOROLOGICO =======" << endl;
    cout << "1. Mostrar historial" << endl;
    cout << "2. Calcular ola de calor mas larga" << endl;
    cout << "3. Amplitud termica entre dos meses especificos de un anio dado" << endl;
    cout << "0. Salir" << endl;
}
void registro(tLista &lista, ifstream &archivo, bool &ok){
    archivo.open("datos.txt");
    if (!archivo.is_open())
    {
        ok = false;
    }
    else
    {
        ok = true;
        while (archivo >> lista.elemento[lista.contador].fecha.anio)
        {
            archivo >> lista.elemento[lista.contador].fecha.mes;
            archivo >> lista.elemento[lista.contador].precipitacion;
            archivo >> lista.elemento[lista.contador].temp_max;
            archivo >> lista.elemento[lista.contador].temp_min;
            lista.contador++;
        }
        archivo.close();
    }
}
void mostrarHistorial(const tLista &lista)
{
    for (int i = 0; i < lista.contador; i++)
    {
        cout << "Anio: " << lista.elemento[i].fecha.anio
             << " Mes: " << lista.elemento[i].fecha.mes
             << " Precip.: " << lista.elemento[i].precipitacion
             << " Temp. max.: " << lista.elemento[i].temp_max
             << " Temp. min.: " << lista.elemento[i].temp_min << endl;
    }
}
int olaCalor(const tLista& lista){
    int duracionMaxima = 0;
    int duracionActual = 0;
    for(int i = 0; i < lista.contador; i++){
        if(lista.elemento[i].temp_max > 30.0){
            duracionActual++;
            if(duracionActual > duracionMaxima){
                duracionMaxima = duracionActual;
            }
        }else{
            duracionActual = 0;
        }
    }

    return duracionMaxima;
}







