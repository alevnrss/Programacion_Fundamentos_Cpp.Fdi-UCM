/**
 * El operador ternario es una forma de evitar usar sentencias condicionales y usar EXPRESIONES CONDICIONALES.
 * El operador ternario se trata de un if pero sin usar llaves ni parentesis. Es un condicional que nos puede ayudar a no usar tantos if anidados
 * y hacer que no se entienda casi el codigo.
 * 
 * El operador ternario tendra la siguiente estructura:
 * condicion ? valorSiEsTrue : valorSiEsFalse;
 * 
 * El operador ternario ademas se puede anidar de manera que se puede crear mas condiciones como un if()else if()else{}.
 * 
 * El operador ternario anidado siempre debera llevar una condicion de true y otra de false en las primeras donde la false es la condicion para hacer la segunda
 * pero al final siempre deberemos dar el resultado de false.
 * A continuacion una breve explicacion de como se usa un operador ternario basico para el algoritmo de saber cuantos signos hay en una cadena de caracteres.
 */

#include <iostream>
using namespace std;

int buscarSignos(char c);
int main (){

    char c;
    int contadorSignos = 0;
    cout << "A continuacion introduzca por favor la cadena de caracteres que desea usted saber la cantidad de signos que hay:" << endl;
    cout << "CADENA: " ;
    c = cin.get();
    while(c != '*'){
        contadorSignos += buscarSignos(c);
        c = cin.get();
    }

    cout << "Total de signos encontrados en la cadena son de: " << contadorSignos << endl;

    return 0;
}

int buscarSignos(char c){
int contador = 0;
contador = (c == ';') ? 1 : (c == '.') ? 1 : (c == ':') ? 1 : 0;
return contador;
}