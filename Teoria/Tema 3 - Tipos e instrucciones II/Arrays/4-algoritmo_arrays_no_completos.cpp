/**
 * Este algoritmo trata sobre llenar un array con una capacidad Limite de 20 valores.
 * Este algoritmo servira para entender tres conceptos:
 *      1- El primer concepto sera entender que hacer si el array no se llena por completo porque se encontrado un valor centinela(ESQUEMA DE BUSQUEDA DE ARRAYS)
 *      2- El segundo concepto es no guardar mas elementos de los que puede el array para evitar desbordamiento.
 *      3- El ultimo concepto es entender hasta donde recorrer el array, ya que si recorremos todo, nos daran valores basura no inicializados.
 *         Para entender este utlimo debemos saber que se debe surgir una condicion: indice de for < indice que se tiene. n-1
 *         Esto es porque lo que se hace es recorrer desde 0 que es lo que se pone en el for (i = 0; i < indice ; i++) pero porque 
 *         queremos recorrer la posicion 0 hasta n-1.
 * 
 * Es importante saber que el array cuando no guarda elemento y son arrays no completos, lo mejor es ignorar la basura (posiciones vacias)
 * 
 * Este programa lo que hara sera leer una serie de numeros que se encuentran en un archivo.txt, un centinela se encontrara entre medias.
 * Si el centinela aparece antes de que se llene el array, lo que se hara es decir que hasta la posicion de antes de encontrar el centinela,
 * es la posicion que usaremos para leer el array.
 * 
 * ESTRUCTURA ALGORITMICA IMPORTANTE :
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int LIMITE_ARRAY = 20;
typedef int tArrayArchivo[LIMITE_ARRAY];

int leerArchivo(string nombreArchivo, tArrayArchivo arrayNumeros);
void mostrarElementosLeidos(const tArrayArchivo arrayNumeros, int indiceLeido);

int main() {
    int indiceLeido;
    string nombreArchivo = "numeros.txt";
    tArrayArchivo arrayNumeros;
    indiceLeido = leerArchivo(nombreArchivo, arrayNumeros);
    if(indiceLeido != -1){
        mostrarElementosLeidos(arrayNumeros, indiceLeido);
    }
    return 0;
}

int leerArchivo(string nombreArchivo, tArrayArchivo arrayNumeros){
    ifstream archivo;
    int valorLeido, contador = 0;   // valor leido: Valor de busqueda del centinela, este valor sera el que almacene todo los numeros.
                                    // valor contador: Valor que indique si se ha rellenado o no todo el array. La condicion es que si llega a ser
                                    // igual al limite 20 pues en este caso, se debe rellenar desde 0 a 19, 20 posciones, entonces el 20 como tal 
                                    // es el numero limite pues no puede ser desde 0 a 20 pues seria 21 posiciones.
                                    // si llega a ese limite ya no deja rellenar mas el array. Se da entonces que el contador es 20 LIMITE. 

    archivo.open(nombreArchivo);
    if(archivo.is_open()){
        archivo >> valorLeido;
        while((valorLeido != -1) && contador < LIMITE_ARRAY ){
            arrayNumeros[contador] = valorLeido;
            contador++;
            archivo >> valorLeido;
        }

        archivo.close();
        return contador;
    }else{
        cout << "Error al abrir el archivo.txt";
        return -1;
    }
}
void mostrarElementosLeidos(const tArrayArchivo arrayNumeros, int indiceLeido){
    cout <<"ELEMENTOS LEIDOS DEL ARCHIVO NUMEROS.TXT" << endl ;
    if(indiceLeido == LIMITE_ARRAY){    // Si el contador es 20 entonces se relleno todo el array
        cout << "El array esta lleno y se ha logrado rellenarlo entero con un total de " << indiceLeido << " elementos" << endl;
    }else{                              // si el contador no es 20 es menos, entonces no se relleno todo el array
        cout <<"El array no esta lleno y en total se han leido hasta " << indiceLeido << " elementos" << endl ;
    }
    for(int indice = 0; indice < indiceLeido; indice++){    // solo iteraremos hasta la posicion que se haya leido, si es 5 entonces debe leerse desde 0 a 4, es decir que indice < indiceLeido
        cout << "Valor del elemento de la posicion " << indice << " es: " << arrayNumeros[indice] << endl;
    }
}




