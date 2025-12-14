/**
 * Una vez que ya hayamos copiado todo los elementos de un archivo.txt, podemos pasarlo a otro archivo con la opcion
 * ofstream.
 * Este codigo no es del todo funcional ya que falta mas partes pero es una demostracion de la parte sobre el volcado de un array 
 * a un archivo en blanco txt.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_ESTUDIANTES = 6;

typedef struct
{
    string nombre;
    string apellidos;
    int edad;
    string nif;
    int nota;
} tEstudiante;

typedef tEstudiante tArray[MAX_ESTUDIANTES];

typedef struct
{
    tArray elementos;
    int contador;
} tLista;

int main()
{
    tLista lista;
    ofstream archivo;
    archivo.open("clase.txt");
    if(!archivo.is_open()){
        cout << "No se logro abrir el archivo correctamente" << endl;
    }else{
        for(int i = 0; i < lista.contador; i++){
            archivo << lista.elementos[i].nombre << endl;
            archivo << lista.elementos[i].apellidos << endl;
            archivo << lista.elementos[i].edad << endl;
            archivo << lista.elementos[i].nif << endl;
            archivo << lista.elementos[i].nota << endl;
        }
        archivo << "XXX" << endl;
        archivo.close();
    }
    return 0;
}
