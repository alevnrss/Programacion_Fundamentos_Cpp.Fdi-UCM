/**
 * Escribe un programa que pida al usuario por pantalla tres valores enteros 
 * y los muestre de menor a mayor separados por comas.
 * Por ejemplo, si el usuario introduce 10,4,6 
 * el resultado sera 4 < 6 < 10
 * Utiliza el intercambio de variables
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