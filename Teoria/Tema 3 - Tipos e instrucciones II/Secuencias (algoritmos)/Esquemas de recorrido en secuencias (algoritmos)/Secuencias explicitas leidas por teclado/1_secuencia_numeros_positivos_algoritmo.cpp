/**
 * ALGORITMO 1.
 * 
 * El ESQUEMA DE RECORRIDO tendra la siguiente estructura
 * inicializacion -> Mientras no llegue al final de la secuencia[(Obtener el siguiente elemento -> procesar el elemento)] -> finalizacion
 * 
 * Como no sabemos cuantos elementos hay no se debera hacer con FOR sino con el bucle WHILE.
 * 
 * IMPLEMENTACION DEL BUCLE WHILE PARA ESQUEMA DE RECORRIDO :
 * inicializacion -> obtener el primero elemento -> mientras no sea ese elemento el centinela[(Procesar el elemento -> obtener el siguiente elemento y vuelta)] -> Finalizacion
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Realizar una secuencia donde el usuario introduzca una serie de numeros tanto positivos como negativos, donde se iran sumando 
// y el programa finalizara cuando el programa lea por teclado el centinela, (-1)
// IMPORTANTE REALIZAR SIEMPRE UNA LECTURA ADELANTADA
int main (){

    double d, suma = 0;
    cout << "El programa termina cuando el usuario teclea -1(centinela)" << endl;
    cout << "Teclee los numeros que quisiera sumar" << endl;
    cin >> d;
    while(d != -1){
        suma = suma + d;
        cout << "El programa termina cuando el usuario teclea -1(centinela): ";
        cin >> d;   //obtener el siguiente elemento
    }

    cout << setw(2) <<"Este el valor de la suma: " << suma << endl;
    
    return 0;
}




