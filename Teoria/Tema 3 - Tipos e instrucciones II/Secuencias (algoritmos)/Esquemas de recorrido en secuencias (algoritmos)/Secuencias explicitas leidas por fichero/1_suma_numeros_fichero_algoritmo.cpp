/**
 * ALGORITMO 4. 
 * Este algoritmo tratara de realizar la suma de los numeros que se encuentran en un archivo.
 * Este ejemplo se puede apreciar tambien en los ejercicios de ficheros.
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sumaFinalNumeros(string nombre_archivo);

int main(){
    string nombre_archivo="numeros.txt";
    int sumaFinal;
    sumaFinal = sumaFinalNumeros( nombre_archivo );
    cout << "La suma de los numeros del archivo.txt son" << sumaFinal << endl;

    return 0;
}

int sumaFinalNumeros(string nombre_archivo){
    fstream archivo;
    archivo.open(nombre_archivo);
    int suma = 0, numeros;

    if(archivo.is_open()){
        archivo >> numeros;
        while (numeros != 0)
        {
            suma = suma + numeros;
            archivo >> numeros;
        }
        archivo.close();

    }else{
        return 1;
    }

    return suma;
}