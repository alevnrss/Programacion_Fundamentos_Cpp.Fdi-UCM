/**
 * Calculadora de sumar y restar
 * Desarrolla un código en C++ que implemente una calculadora sencilla que solo permite sumar y restar.
 * El programa permitirá elegir la operación a realizar mediante un menú sencillo como el siguiente:
 * 1 – Sumar
 * 2 – Restar
 * En el caso de que el usuario teclee otro número distinto a 1 ó 2, el programa mostrará un mensaje de error.
 * Los operandos se pedirán por teclado y, según la operación seleccionada por el usuario, se mostrará el
 * resultado en pantalla.
El algoritmo debe estar optimizado: no repetir código.
 */
#include <iostream>
using namespace std;

void ejecutarCalculadora();
int main(){
    char continuar = 's';
    do{
        ejecutarCalculadora();
    }while(continuar == 's');
    

}
void ejecutarCalculadora(){
    int num1, num2;
    char opcion;

    cout << "Ingrese el primer numero: "; cin >> num1;
    cout << "Ingrese el segundo numero: "; cin >> num2;

    switch (opcion)
    {
    case '1':
        
        break;
    
    case '2':
        
        break;
    
    default:
        break;
    }

}