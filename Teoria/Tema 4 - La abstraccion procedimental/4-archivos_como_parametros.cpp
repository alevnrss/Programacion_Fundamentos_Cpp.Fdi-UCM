/**
 * Otra forma limpia de poder trabajar con archivos, es utilizar el archivo como parametro.
 * LOS ARCHIVOS SIEMPRE SE PASAN COMO PARAMETRO POR REFERENCIA.
 */

#include <iostream>
#include <fstream>
using namespace std;

void sumatorioNumerosFile(ifstream &file, int &suma);

int main(int argc, char *argv[])
{
    ifstream file;
    int sumaDeNumeros;

    file.open("file.txt");
    if (!file.is_open())
    {
        cout << "ERROR DE APERTURA" << endl;
    }
    else
    {
        sumatorioNumerosFile(file, sumaDeNumeros);
        cout << "La suma de los numeros del archivo es: " << sumaDeNumeros << endl;
        file.close();
    }

    cout << "Numero total de argumentos (argc): " << argc << endl;

    return 0;
}
void sumatorioNumerosFile(ifstream &file, int &suma)
{
    suma = 0;
    double dato;
    file >> dato;
    while (dato != -1)
    {
        file.ignore(); // por las comas, si no tuviera comas lo quitamos. IMPORTANTE, no usar el file.get(dato) pues no es un char.
        suma += dato;
        file >> dato;
    }

    return;
}