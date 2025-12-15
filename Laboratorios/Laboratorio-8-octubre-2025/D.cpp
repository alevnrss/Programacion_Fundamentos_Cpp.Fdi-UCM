/**
 * Escriba un programa que lea los caracteres introducidos por el usuario
 * y que termine cuando el usuario introduzca un asterisco
 * Los caracteres se solicitan y se introducen uno por uno
 * El programa debera excluir los caracteres como el espacio o el asterisco.
 * finalmente el programa debera mostrar por pantalla el numero de caracteres que ha leido.
 */
#include <iostream>
using namespace std;

int main(){
    char userCharacterValue;
    int contador = 0;
    cout << "Sunatorio de caracteres" << endl;
    cout << "Introduzca caracteres, si desea terminar la ejecucion introduzca un asterisco"<< endl;
    do{
        cin >> userCharacterValue;
        if(userCharacterValue != ' ' && userCharacterValue != '*'){         // contamos si no es espacio ni asterisco
            contador++;
        }
    }while(userCharacterValue != '*');

    cout << "La cantidad de caracteres introducido por el usuario sin espacios fueron: " << contador << " caracteres";



    return 0;
}