#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream archivo;

int main()
{
    archivo.open("temperaturas.txt");
    if (archivo.is_open())
    {
        cout << "Archivo abierto con exito" << endl;
        double temp, suma = 0, media;
        double contador = 0;

        
        while (archivo >> temp && temp != -1)
        {
            suma += temp;
            contador++;

        }
        if(contador > 0){
            media = suma/contador;
            cout << "temperaturas contadas: " << contador << endl;
            cout << "La media de las temperaturas es: "<< media << endl;
        }
        
        archivo.close();
    }
    else
    {
        cout << "Error al visualizar el archivo.txt" << endl;
        return 1;
    }

    return 0;
}