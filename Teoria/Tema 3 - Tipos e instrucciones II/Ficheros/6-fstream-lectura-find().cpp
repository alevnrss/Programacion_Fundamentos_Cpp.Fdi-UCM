/**
 * LABORATORIO 15-OCT-2025 EJERCICIO F)
 * LECTURA DE FICHEROS DE TEXTO PARTE 3: Buscar un SUBSTRING en un archivo.txt 
 * En este ejemplo se mostrara como realiza la lectura de un fichero archivo.txt y que su vez
 * se tenga que dar la busqueda con contador de cuantos SUBSTRIGN se repiten o son iguales a JUAN.
 * 
 * UTILZACION DE LA FUNCION .find() -> Esta funcion realizar la busqueda de subcadenas dentro de un String(Busqueda de substrings). Devuelve un -1 si no encuentra nada.
 * UTILIZACION DE TABULADOR PARA LA SALIDA DE DATOS POR CONSOLA -> Finalmente, para mostrar los datos se dara el uso de tabuladores para realizar
 * saltos de linea y tabulacion.
 */

#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

ifstream archivo;

int main(){
    const string BUSCA = "Juan";    // Substring que buscamos
    int contadorJuan = 0;           // contador de nombre que contienen "Juan"
    string nombreArchivo = "grupos.txt";

    archivo.open(nombreArchivo);

    if(archivo.is_open()){
        cout << "Archivo abierto correctamente" ;
        cout << "Leyendo el archivo... ";

        int grupo;
        string nombre1, nombre2;

        archivo >> grupo;
        archivo.ignore(1000, '\n');
        
        while(grupo != 0){
            getline(archivo, nombre1);
            getline(archivo, nombre2);

            cout << "Grupo: " << grupo << endl;
            cout << "\tAlumno 1: " << nombre1 << endl;
            cout << "\tAlumno 2: " << nombre2 << endl;

            if(nombre1.find(BUSCA) != -1){
                contadorJuan++;
            }
            if(nombre2.find(BUSCA) != -1){
                contadorJuan++;
            }

            archivo >> grupo;
            archivo.ignore(1000, '\n');

        }
        cout << "Centinela encontrado -> VALOR DEL CENTINELA: " << grupo ;
        cout << "Número de alumnos con '" << BUSCA << "': " << contadorJuan << endl;

        archivo.close();
    }else{
        cout << "ERROR al abrir el archivo";
        return 1;
    }


    return 0;
}