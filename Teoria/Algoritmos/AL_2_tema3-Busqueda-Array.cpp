// Esta incompleto ya que el array no esta incializado pero la idea es la estructura que debe tener 
// el ESQUEMA DE BUSQUEDA EN ARRAYS y con una pequeña implementacion de RECORRIDO EN ARRAYS CON WHILE.


#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
typedef int tArrayNumerosAleatorios[MAX];
int main(){
    tArrayNumerosAleatorios arrayDigitosmagicos;
    buscarDigitoMagico(arrayDigitosmagicos);

    return 0;
}

void buscarDigitoMagico(const tArrayNumerosAleatorios arrayDigitosmagicos){
    int indice = 0;
    bool encontrado = false;
    while ((indice < MAX) && !encontrado)
    {
        if (arrayDigitosmagicos[indice] < 5)
        {
            cout << "\nPrimer digito magico menor a 5 encontrado en la posicion " << indice << " : " << arrayDigitosmagicos[indice];
            encontrado = true;
        }
        else
        {
            cout << "\nDigito magico en posicion " << indice << " : " << arrayDigitosmagicos[indice];
            indice++;
        }
    }
}