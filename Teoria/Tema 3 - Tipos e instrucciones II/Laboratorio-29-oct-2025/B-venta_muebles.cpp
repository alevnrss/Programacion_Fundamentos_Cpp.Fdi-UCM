/**
 * Desarrolla un programa para una empresa de venta de muebles que simule las ventas diarias correspondientes a la primera semana del mes de octubre.
 * El programa deberá:
 * ₋ Generar aleatoriamente los valores de venta de cada día de la semana.
 * ₋ Cada valor representará la cantidad de ventas diarias y deberá encontrarse en el rango [0, 100].
 * ₋ Almacenar los valores generados en una estructura adecuada (por ejemplo, un array de enteros).
 * ₋ Mostrar en pantalla el listado de ventas diarias una vez finalizada la carga de datos.
 * Nota: No se requiere entrada por teclado; todos los datos deben ser simulados mediante generación aleatoria.
 * 
 * 
 * Para una mejor utilizacion de los dias dare uso por mi propia cuenta de los enums para poner los dias de la semana segun el valor del indice del array.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_VENTAS = 7;
typedef int tArrayVentasMuebles[MAX_VENTAS];
typedef enum
{
    lunes,
    martes,
    miercoles,
    jueves,
    viernes,
    sabado,
    domingo
} tDiasSemana;


void guardarDatosVenta(tArrayVentasMuebles arrayMuebles);
void mostrarDatosVenta(tArrayVentasMuebles arrayMuebles);
string toString(tDiasSemana diaSemana);

int main()
{
    tArrayVentasMuebles arrayMuebles;
    guardarDatosVenta(arrayMuebles);
    mostrarDatosVenta(arrayMuebles);

    return 0;
}

// Generar numeros aleatorio de 0 a 100 en total siete numeros que deberemos guardar en el array
void guardarDatosVenta(tArrayVentasMuebles arrayMuebles){
    srand(time(NULL));
    for(int i = 0; i < MAX_VENTAS ; i++){
        arrayMuebles[i] = rand()%101;
    }
}
void mostrarDatosVenta(tArrayVentasMuebles arrayMuebles){
    cout << "VENTAS PRIMERA SEMANA DE OCTUBRE: " << endl;
    for(int i = lunes; i < MAX_VENTAS; i++){
        cout << toString(tDiasSemana(i))<< " : " << arrayMuebles[i] << endl;
    }
}

string toString(tDiasSemana diaSemana)
{
    string cadena;
    switch (diaSemana)
    {
    case lunes:
        cadena = "Lunes";
        break;
    case martes:
        cadena = "Martes";
        break;
    case miercoles:
        cadena = "Miercoles";
        break;
    case jueves:
        cadena = "Jueves";
        break;
    case viernes:
        cadena = "Viernes";
        break;
    case sabado:
        cadena = "Sabado";
        break;
    case domingo:
        cadena = "Domingo";
        break;
    default:
        cadena = "No Existe";
        break;
    }
    return cadena;
}