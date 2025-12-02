// Diferencias entre getline(cin, nombre) y cin.get(lecturaCaracter)
#include <iostream>
#include <string>
using namespace std;

void codigoCorrecto();
void codigoIncorrecto();

int main(){

    cout << "Este es el codigo correcto" << endl ;
    codigoCorrecto();
    cout << "---------------------\n" ;
    cout << "Este es el codigo incorrecto" << endl ;
    codigoIncorrecto();

    return 0;
}

void codigoCorrecto(){
    string nombreApellidos;
    int edad;
    char caracter;

    cout << "Introduzca su edad: ";
    cin >> edad;

    cin.ignore(); // Limpiar el buffer (limpiamos el salto de linea, pues sino no se consume y getline() recibira una cadena vacia)

    cout << "introude tu nombre y apellidos: ";
    getline(cin, nombreApellidos); // Al limpiar el buffer, getline() no recibira una cadena vacia asi que podremos escribir.

    cout << "Introduzca un caracter: ";
    cin.get(caracter);

    cout << "La edad introducida es: " << edad << endl;
    cout << "El nombre introducido es: " << nombreApellidos << endl;
    cout << "El caracter introducido es: " << caracter << endl;
}
void codigoIncorrecto(){
    string nombreApellidos;
    int edad;
    char caracter;

    cout << "Introduzca su edad: " ;
    cin >> edad;

    // Esto es una forma de arreglarlo pero no es la mejor
    if(cin.fail()){
        cin.clear(); // Limpiar el buffer
        cin.ignore(1000, '\n');
        cin >> edad;
    }

    cout << "introude tu nombre y apellidos: " << endl;
    getline(cin, nombreApellidos); // No hemos limpiado el buffer por lo tanto getline() recibira una cadena vacia, en este caso no se va a poder escribir.

    cout << "Introduzca un caracter: ";
    cin.get(caracter);

    cout << "La edad introducida es: " << edad << endl;
    cout << "El nombre introducido es: " << nombreApellidos << endl;
    cout << "El caracter introducido es: " << caracter << endl;
}