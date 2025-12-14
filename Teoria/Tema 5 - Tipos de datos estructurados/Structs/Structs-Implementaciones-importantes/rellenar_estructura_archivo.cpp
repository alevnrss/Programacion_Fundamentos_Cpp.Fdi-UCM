/**
 * A continuacion se da un archivo de texto con la informacion de cada estudiante.
 * Cada estudiante tendra nombre, apellidos, DNI, nota.
 * Si la nota es un -1 significa que no ha sido calificado.
 * El archivo esta delimitado por un CENTINELA que en este caso seria un XXX como nombre.
 * 
 * Este programa trata de llenar todos los elementos que se encuentran en el archivo y pegarlos en el propio array.
 */
#include <iostream>
#include <fstream>
#include <string>
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
    ifstream archivo;
    tEstudiante estudiante;
    tArray arrayEstudiantes = {0};
    tLista lista;
    lista.contador = 0;

    archivo.open("clase.txt");
    if (!archivo.is_open())
    {
        cout << "Error al ejecutar el archivo" << endl;
    }
    else
    {
        getline(archivo, estudiante.nombre);
        while ((estudiante.nombre != "XXX") && (lista.contador < MAX_ESTUDIANTES))
        {
            getline(archivo, estudiante.apellidos);
            archivo >> estudiante.edad;
            archivo >> estudiante.nif;
            archivo >> estudiante.nota;
            archivo.ignore(1000, '\n');
            lista.elementos[lista.contador] = estudiante;
            lista.contador++;
            getline(archivo, estudiante.nombre);
        }
        archivo.close();
    }

    for (int i = 0; i < lista.contador; i++)
    {
        cout << "Estudiante en la posicion : " << i << endl;
        cout << "Nombre del estudiante :" << lista.elementos[i].nombre << endl;
        cout << "Apellidos: " << lista.elementos[i].apellidos << endl;
        cout << "Edad: " << lista.elementos[i].edad << " anios" << endl;
        cout << "NIF: " << lista.elementos[i].nif << endl;
        cout << "Nota: " << lista.elementos[i].nota << endl;
    }

    return 0;
}
