/**
 * Modifica el código del ejercicio G para que el programa encuentre la primera ocurrencia que exista de la
 * secuencia de caracteres ‘. ‘ (un punto y un espacio). De esta manera sólo se leería la 1ª frase del
 * fichero.
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_CHAR = 232;
typedef char tArrayChar[MAX_CHAR];

void introducirCaracteresArray(tArrayChar a, string nombreArchivo);
void recorrerCaracteresArray(tArrayChar a, int indice);

int main()
{
    tArrayChar a;
    string nombreArchivo = "Lorem.txt";

    introducirCaracteresArray(a, nombreArchivo);

    return 0;
}

void introducirCaracteresArray(tArrayChar a, string nombreArchivo)
{
    ifstream archivo;
    char c, anterior = ' ', actual;
    int indice = 0;
    bool encontrado = false;

    archivo.open(nombreArchivo);

    if (archivo.is_open())
    {
        c = archivo.get();
        a[indice] = c;
        actual = a[indice];
        while ((indice < MAX_CHAR) && !encontrado)
        {
            if (anterior == '.' && actual == ' ')
            {
                encontrado = true;
                cout << "Se ha leido : " << indice - 1 << " caracteres del fichero." << endl;
                cout << "Se han encontrado los dos caracteres que se buscaban: punto y espacio." << endl;
                cout << "Solo se ha leido la primera frase contenida en el fichero." << endl;
            }
            else
            {
                anterior = actual;
                indice++;
                c = archivo.get();
                a[indice] = c;
                actual = a[indice];
            }
        }
        if(!encontrado && indice == MAX_CHAR){
            cout << "No se ha podido encontrar la secuencia";
        }

        recorrerCaracteresArray(a, indice);
        archivo.close();
    }
    else
    {
        cout << "Error al abrir el archivo.txt";
    }
}

void recorrerCaracteresArray(tArrayChar a, int indice)
{
    cout << "\n";
    for (int i = 0; i < indice; i++)
    {
        cout << a[i];
    }
}
