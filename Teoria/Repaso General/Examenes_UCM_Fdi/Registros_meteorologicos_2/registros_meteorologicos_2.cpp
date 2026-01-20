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
int olaCalor(const tLista &lista);
double amplitudTermica(const tLista &lista, tfecha &fecha_anio, tfecha &fecha_mes1, tfecha &fecha_mes2);
int main()
{
    int opcion;
    tDatosMeteo datos;
    tfecha fecha_anio;
    tfecha fecha_mes1;
    tfecha fecha_mes2;
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
            else
            {
                mostrarHistorial(lista);
            }
            break;
        case 2:
            int duracionOlaCalor;
            duracionOlaCalor = olaCalor(lista);
            cout << "Ola de calor mas larga: " << duracionOlaCalor << endl;
            break;
        case 3:
            cout << "Analisis de la amplitud termica de dos meses de un anio: " << endl;
            double DifAmplitudTermica;
            DifAmplitudTermica = amplitudTermica(lista, fecha_anio, fecha_mes1, fecha_mes2);
            cout << "\nLa amplitud termica entre el mes " << fecha_mes1.mes << " y el mes " << fecha_mes2.mes
                 << " del anio " << fecha_anio.anio << " es: " << DifAmplitudTermica << endl;
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
void registro(tLista &lista, ifstream &archivo, bool &ok)
{
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
int olaCalor(const tLista &lista)
{
    int duracionMaxima = 0;
    int duracionActual = 0;
    for (int i = 0; i < lista.contador; i++)
    {
        if (lista.elemento[i].temp_max > 30.0)
        {
            duracionActual++;
            if (duracionActual > duracionMaxima)
            {
                duracionMaxima = duracionActual;
            }
        }
        else
        {
            duracionActual = 0;
        }
    }
    return duracionMaxima;
}

double amplitudTermica(const tLista &lista, tfecha &fecha_anio, tfecha &fecha_mes1, tfecha &fecha_mes2)
{
    double amplitudActualMes1;
    double amplitudActualMes2;
    double diferenciaAmplitudes;

    int indice_mes1;
    int indice_mes2;

    cout << "Teclea el anio: ";
    cin >> fecha_anio.anio;
    cout << "Teclea el primer mes (en numero, donde enero = 1). Rango: de 1 a 11 (se asume datos correctos)" << endl;
    cin >> fecha_mes1.mes;
    fecha_mes2.mes = 8;
    cout << "El segundo mes es: " << fecha_mes2.mes;

    for(int i = 0; i < lista.contador ; i++){
        if(lista.elemento[i].fecha.anio == fecha_anio.anio){
            if(lista.elemento[i].fecha.mes == fecha_mes1.mes){
                indice_mes1 = i;
            }
            if(lista.elemento[i].fecha.mes == fecha_mes2.mes){
                indice_mes2 = i;
            }
        }
    }

    amplitudActualMes1 = (lista.elemento[indice_mes1].temp_max - lista.elemento[indice_mes1].temp_min);
    amplitudActualMes2 = (lista.elemento[indice_mes2].temp_max - lista.elemento[indice_mes2].temp_min);
    diferenciaAmplitudes = abs(amplitudActualMes1 - amplitudActualMes2);
    return diferenciaAmplitudes;
}
