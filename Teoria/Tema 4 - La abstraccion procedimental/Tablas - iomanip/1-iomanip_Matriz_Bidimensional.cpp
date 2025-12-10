/**
 * En este ejemplo se dara a entender el funcionamiento del iomanip.
 * Se hara uso de la libreria <iomanip>, donde usaremos la funcion setw() para fijar el ancho de una columna que ocupara la pantalla
 * Se trata de un manipulador de formato de salida por consola. set width
 *
 * Este tipo de formato es imprescindible para la salida de un formato tabla. Para ello deberemos saber la anchura que tendra
 * la tabla por defecto.
 *
 * Por asi decirlo se como si estuvieramos poniendo habitaciones por defecto, donde tiene espacios de caracteres.
 * Un setw(5) es poner una habitacion de 5 espacios de caracteres, por lo que maximo podra caber 12345 pero no 123456. Pero aunque
 * pase esto es importante saber que NO CORTA EL NUMERO o STRING.
 *
 *
 * LOGICA ESTRUCTURA DE TABLA N x N -> MATRIZ BIDIMENSIONAL(ALGORITMO):
 * Para realizar una tabla por ejemplo de multiplicacion, se necesita una estructura base para poder realizar dicha tabla.
 * Se deberan seguir una serie de pasos:
 *  1- Una tabla es un formato ( N x N ) donde se multiplica filas y columnas. (MATRIZ)
 *  2- FILAS(Variable i): Controla la altura de la tabla y el primer operando de la multiplicacion entre dos numeros (i x j)
 *  3- COLUMNAS(Variable j): Controla la anchura de la tabla y el segundo operando de la multiplicacion entre dos numeros (i x j)
 *
 */
#include <iostream>
#include <iomanip>
using namespace std;

void tablaMultiplicar(const int N);

int main()
{
    int num = -1;
    while ((num < 1) || (num > 10))
    {
        cout << "Indique un numero del 1 al 10 para realizar la tabla de multiplicar correspondiente : ";
        cin >> num;
        if ((num < 1) || (num > 10))
        {
            cout << "Por favor introduzca un numero entre el 1 al 10" << endl;
        }
    }

    tablaMultiplicar(num);

    return 0;
}

// MATRIZ BIDIMENSIONAL
void tablaMultiplicar(const int N)
{
    for (int i = 1; i <= N; i++)
    {                     // controla las filas y el operando 1. REPRESENTA: el inicio de una nueva fila. Poner siempre un salto de linea al final.
        int sumaFila = 0; // Esto sirve para el sumatorio de cada fila. Esto se pone al final de cada fila.
        for (int j = 1; j <= N; j++)
        { // se ejecuta N veces por cada iteracion de i. REPRESENTA: impresion lateral, i es fija siempre en cada iteracion del bucle.
            int producto = i * j;   
            cout << setw(N) << producto;    
            sumaFila += producto;
        }
        cout << setw(N) << sumaFila;
        cout << endl;
    }
}