/**
 * Escribe un programa en C++ que lea el siguiente
 * fichero de texto y guarde este contenido en un array
 * de 232 caracteres. Tras la lectura, se mostrará el
 * contenido del array en pantalla.
 * Los caracteres del fichero se leerán uno a uno y se
 * irán guardando en un array de caracteres.
 * No es necesario un centinela pues se leerán
 * exactamente el número de caracteres que caben en el array.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_CHAR = 232;
typedef char tArrayChar[MAX_CHAR];

void introducirCaracteresArray( tArrayChar a, string nombreArchivo );
void recorrerCaracteresArray(tArrayChar a, int indice);


int main (){
    tArrayChar a;
    string nombreArchivo = "Lorem.txt";

    introducirCaracteresArray(a, nombreArchivo);

    return 0;
}

void introducirCaracteresArray( tArrayChar a, string nombreArchivo ){
    ifstream archivo;
    char c;
    int indice = 0;
    archivo.open(nombreArchivo);

    if(archivo.is_open()){
        while((indice < MAX_CHAR)){
            c = archivo.get();
            a[indice] = c;
            indice++;
        }

        recorrerCaracteresArray(a, indice);
        archivo.close();
    }else{
        cout << "Error al abrir el archivo.txt";
    }
}

void recorrerCaracteresArray(tArrayChar a, int indice){
    cout << "Valor del indice i tras el bucle: " << indice << endl;
        for(int i = 0; i < MAX_CHAR ; i++){
            cout << a[i];
        }
}


