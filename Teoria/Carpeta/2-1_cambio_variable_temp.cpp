/**
 * CAMBIO DE VARIABLE
 */

#include <iostream>
using namespace std;

void comparationValue(int num1, int num2, int num3, int temp);

int main (){
    int num1, num2, num3, temp; // Usaremos la variable temp (Variable temporal)
    cout << "Introduzca el primer numero" << endl;
    cin >> num1;
    cout << "Introduzca el segundo numero" << endl;
    cin >> num2;
    cout << "Introduzca el tercer numero"<< endl;
    cin >> num3;

    comparationValue(num1, num2, num3, temp);

    return 0;
}

void comparationValue(int num1, int num2, int num3, int temp){
    if(num1 > num2 ){
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if(num2 > num3){
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if(num1 > num2){
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    cout << num1 << " < " << num2 << " < " << num3 << endl;
}

/**
 * En este ejercicio la logica trata sobre que variable sera la mas pequeña y cual la mas grande.
 * Segun esto, iremos intercambiando valores hasta que podamos tener el valor mas pequeño en 
 * la variable que queremos en este caso num1 y el mas grande en num3.
 * 
 * Primer condicional (num1 > num2)
 *  -  Si num1 es mayor a num2 entonces num2 se llevara ese valor luego num1 queremos que sea el mas
 *     pequeño por lo que se quedara con el valor de num2
 * Segundo condicional (num2 > num3)
 *  -  Lo mismo que antes, queremos que num2 sea tmbn pequeño. REPETIMOS PROCESO
 * Tercer condicional (num1 > num2)
 *  -  Volvemos a comprobar porque puede ser que num2 haya cambiado de valor y eso puede
 *     afectar a nuestro orden de valores
 */