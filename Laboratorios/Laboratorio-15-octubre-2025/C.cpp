#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream archivo;
int main()
{
    archivo.open("notasNombre.txt");
    if (archivo.is_open())
    {
        cout << "El archivo de texto se abrio correctamente" << endl;

        double nota, suma = 0, media = 0;
        int contador = 0;
        string nombre;

        archivo >> nota;
        while (nota != 0)
        {
            archivo >> nombre; // no usamos getline(archivo,nombre) porque el nombre no contiene espacios
            contador++;
            suma+=nota;
            cout << contador << "  Nombre Alumno: " << nombre << " Nota: " << nota << endl;

            archivo >> nota;
        }
        if (contador > 0){
            media = suma/contador;
        }
        
        cout << "Contador de notas totales: " << contador << endl;
        cout << "media de las notas de los alumnos: " << media <<  endl;

        archivo.close();
    }
    else
    {
        cout << "Error al abrir el archivo.txt";
        return 1;
    }
    return 0;
}