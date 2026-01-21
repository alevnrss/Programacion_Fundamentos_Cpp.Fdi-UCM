/**
 * Para trabajar con ficheros se debe realizar los siguientes pasos:
 * 
 *  Biblioteca a utilizar: (fstream) -> #include fstream
 * 
 *  1- Abrir fichero
 *  2- Hacer operaciones 
 *  3- Cerrar fichero
 * 
 * 
 * ABRIR FICHERO :
 * Asociamos el nombre del fichero (nombre.txt) a un objeto creado por nosotros
 * Este objeto se debe definir segun para que uso le queremos dar. Leer o escribir.
 * 
 * CERRAR FICHERO :
 * Es importante cerrar el fichero para evitar posibles errores.
 * 
 *  - ifstream: leer
 *  - ofstrem: escribir
 *  - fstream: leer y escribir.
 */

#include <iostream>
#include <fstream>
using namespace std;

// Leer 
ifstream archivo;

// Escribir

ofstream archivo;

int main(){

    // centinela
    int numero;
    int centinela = 1;

    // Estructura Leer 
    archivo.open("nombreArchivo.txt");
    if(archivo.is_open()){
        while(1){
            archivo >> numero;  // Lo primero que encuentre o lea lo mete en la variable numero.
            // ...
        }
        archivo.close();
    }else{
        cout << "Error al abrir el archivo";
    }



    return 0;
}

/**
 * Extractor: >> este simbolo lee la primera cadena de string que encuentre hasta el proximo espacio en blanco.
 * archivo.get(c): Lee el siguiente caracter, sea el que sea.
 * getline(archivo, cadenaLeer): Esto lee todos los caracteres que queden por leer en la linea, incluido los espacios en blanco
 * hasta el siguiente salto de linea.
 * 
 * 
 * 
 * Sabiendo esto, tenemos que pensar lo siguiente: ¿Que es lo que quiero leer?
 *  -  si es un numero -> usamos archivo >> num
 *  -  si es un caracter -> archivo.get(c)
 *  -  si es una cadena SIN ESPACIOS -> archivo >> cad
 *  -  si es una cadena CON ESPACIOS -> getline(archivo, cadena)
 */