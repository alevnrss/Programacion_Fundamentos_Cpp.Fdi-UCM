/**
 * Buscar subcadena de cadenas de string en el archivo de texto.txt

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