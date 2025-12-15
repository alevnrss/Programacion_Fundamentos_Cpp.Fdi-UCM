/**
 * Escribe un programa que permita introducir por pantalla dos numeros enteros
 * tales que el programa determine cual de ellos es el mayor o si son iguales
 */

#include <iostream>
using namespace std;

void numberValue(int num1, int num2);

int main(){
    int num1, num2;
    string resultado;
    cout << "Introduzca el primer numero entero" << endl;
    cin >> num1;
    cout << "Introduzca el segundo numero entero" << endl;
    cin >> num2;
    numberValue(num1, num2);
    


    return 0;
}

void numberValue(int num1, int num2){
    if(num1 == num2){
        cout << num1 << " = " << num2;
        
    }else if(num1 > num2){
        cout << num1 << " > " << num2;
        
    }else{
        cout << num2 << " > " << num1;
        
    }
}
