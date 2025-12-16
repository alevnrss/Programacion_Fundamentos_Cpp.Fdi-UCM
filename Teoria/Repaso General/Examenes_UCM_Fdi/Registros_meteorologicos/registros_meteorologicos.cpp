// HISTORIAL DE REGISTROS METEOROLOGICOS MENSUALES
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
// Variables globales
const int MAXIMO = 5;

// Tipos de datos estructurados
typedef struct
{
    int mes;
    int anio;
} tFecha;

typedef struct
{
    tFecha fecha;
    double precipitacion;
    double temp_max;
    double temp_min;
} tMeteorologico;

typedef tMeteorologico tArray[MAXIMO];

typedef struct
{
    tArray elementos;
    int contador;
} tLista;

// Prototipos
int menu();
void cargar(tLista &lista, ifstream &archivo, bool &ok);
void mostrar(const tLista &lista);
void insertar(tLista& lista, tMeteorologico& registro);
void registroMeteo(tMeteorologico& registro);
int numFechasMasLluviosas(const tLista& lista, tFecha& fecha);
int posFecha(const tLista& lista, tFecha& fecha, bool& busca);
int maxDifTemp(const tLista& lista, bool& ok, double& maximo);

int main()
{
    tLista lista;
    tMeteorologico registro;
    tFecha fecha;
    ifstream archivo;
    bool exito = false;
    int opcionUser;

    cargar(lista, archivo, exito);
    if (!exito)
    {
        cout << "No se ha podido abrir el historial.txt correctamente" << endl;
    }
    else
    {
        cout << "Exito al cargar el historial.txt" << endl;
        opcionUser = menu();
        while (opcionUser != 0)
        {
            switch (opcionUser)
            {
            case 1:
                
                mostrar(lista);
                break;
            case 2:
                
                insertar(lista, registro);
                break;
            case 3:
                int numFecha;
                numFecha = numFechasMasLluviosas(lista, fecha);
                cout << "Numero de fechas mas lluviosas: " << numFecha << endl;
                break;
            case 4:
                int indiceMayor;
                double diferencia;
                indiceMayor = maxDifTemp(lista,exito, diferencia);
                if(!exito){
                    cout << "Lista Vacia" << endl;
                }else{
                    cout << "Anio: " << lista.elementos[indiceMayor].fecha.anio
                        << " Mes: " << lista.elementos[indiceMayor].fecha.mes
                        << " Diferencia: " << diferencia << endl;
                }
                break;
            }
            opcionUser = menu();
        }
    }

    return 0;
}

void cargar(tLista &lista, ifstream &archivo, bool &ok)
{
    archivo.open("historial.txt");
    if (!archivo.is_open())
    {
        ok = false;
    }
    else
    {
        lista.contador = 0;
        while (archivo >> lista.elementos[lista.contador].fecha.anio && lista.contador < MAXIMO)
        {
            archivo >> lista.elementos[lista.contador].fecha.mes;
            archivo >> lista.elementos[lista.contador].precipitacion;
            archivo >> lista.elementos[lista.contador].temp_max;
            archivo >> lista.elementos[lista.contador].temp_min;
            lista.contador++;
        }
        ok = true;
        archivo.close();
    }
}

int menu()
{
    int opcion = -1;
    while ((opcion < 0) || (opcion > 4))
    {
        cout << "\n1. Mostrar historial" << endl;
        cout << "2. Insertar" << endl;
        cout << "3. Fechas mas lluviosas que una dada" << endl;
        cout << "4. Maxima diferencia de temperaturas" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        if ((opcion < 0) || (opcion > 4))
        {
            cout << "\nEliga una opcion correcta" << endl;
        }else{
            cout << "\n";
        }
    }
    return opcion;
}

void mostrar(const tLista &lista)
{
    for (int i = 0; i < lista.contador; i++)
    {
        cout << "Anio: " << lista.elementos[i].fecha.anio
             << " Mes: " << lista.elementos[i].fecha.mes
             << " Precip: " << lista.elementos[i].precipitacion
             << " Temp.max: " << lista.elementos[i].temp_max
             << " Temp. min: " << lista.elementos[i].temp_min << endl;
    }
}

void insertar(tLista& lista, tMeteorologico& registro){
    if(lista.contador < MAXIMO){
        registroMeteo(registro);
      lista.elementos[lista.contador] = registro;
      lista.contador++;
    }else{
        cout << "Historial lleno" << endl;
    }
}

void registroMeteo(tMeteorologico& registro){
    cout << "Introduce anio: ";
    cin >> registro.fecha.anio;
    cout << "Introduce mes: ";
    cin >> registro.fecha.mes;
    cout << "Introduce precipitacion: ";
    cin >> registro.precipitacion;
    cout << "Introduce temperatura maxima: ";
    cin >> registro.temp_max;
    cout << "Introduce temperatura minima: ";
    cin >> registro.temp_min;
}

int numFechasMasLluviosas(const tLista& lista, tFecha& fecha){
    bool encontrado = false;
    int contadorFechas = 0;
    int indiceFechaBuscada;

    cout << "Introduce anio: ";
    cin >> fecha.anio;
    cout << "Introduce mes: ";
    cin >> fecha.mes;

    indiceFechaBuscada = posFecha(lista, fecha, encontrado);
    if(!encontrado){
        cout << "No se ha encontrado la fecha" << endl;
    }else{
        cout << "Fecha encontrada en la posicion: " << indiceFechaBuscada << endl;
        for(int i = 0; i < lista.contador; i++){
            if(lista.elementos[i].precipitacion > lista.elementos[indiceFechaBuscada].precipitacion){
                contadorFechas++;
            }
        }

    }

    return contadorFechas;
}

int posFecha(const tLista& lista, tFecha& fecha, bool& busca){
    int indice = 0;
    while(indice < lista.contador && !busca){
        if((fecha.anio == lista.elementos[indice].fecha.anio) && (fecha.mes == lista.elementos[indice].fecha.mes)){
            busca = true;
        }else{
            indice++;
        }
    }

    return indice;
}

int maxDifTemp(const tLista& lista, bool& ok, double& maximo){
    int indice;
    maximo = (abs(lista.elementos[0].temp_max) - abs(lista.elementos[0].temp_min));
    abs(maximo);
    if(lista.contador > 0){
        ok = true;
        for(int i = 1; i < lista.contador; i++){
            int diferencia;
            diferencia = (lista.elementos[i].temp_max - lista.elementos[i].temp_min);
            abs(diferencia);
            if(diferencia > maximo){
                maximo = diferencia;
                indice = i;
            }
        }
    }else{
        ok = false;
    }
    return indice;
}


