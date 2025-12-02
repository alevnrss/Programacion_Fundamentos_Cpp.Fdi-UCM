/**
 * Modifica el programa anterior para que haga una búsqueda del primer número cuadrado que supere un valor dado por el usuario,
 * respetando un límite superior.
 * ₋ En primer lugar, el usuario introduce un valor (entero positivo mayor que cero) límite ( [1..3000] )
 * que representa un valor máximo que los cuadrados no deben superar.
 *
 * ₋ A continuación, se pedirá el valor valorBusqueda a partir del cual queremos encontrar el primer cuadrado mayor.
 * ₋ El programa generará los cuadrados n² de los números naturales, deteniéndose si
 * 1) el cuadrado supera el límite
 * 2) se encuentra el primer cuadrado mayor que valorBusqueda.
 * ₋ Para finalizar, se mostrará la secuencia generada hasta ese punto y cuál fue el primer número que supera valorBusqueda, si existiese.
 */
#include <iostream>
#include <cmath>
using namespace std;

int limiteIntroducido(int limite);

int main()
{
    int limite = 0 ;    // guardara el limite 
    int valorBuscar;    // guardara el numero que queremos buscar
    int n = 1;          // sera el valor de los numeros naturales, empieza desde uno ya que el cuadrado de 0 es 0 y no se cuenta dentro de los naturales. Este se sumara.
    int valorCuadrado = 1;  // Sera quien guarde el cuadrado de n
    int cuadradoEncontrado = -1;    // Este es un valor que sirve para hacer una condicion donde siempre se cumplira, pero sera clave para guardar ese valor encontrado
    bool encontrado = false;    // valdra para saber si se ha encontrado pero sino seguir siendo false.


    limite = limiteIntroducido(limite);
    cout << "Introduce el valor a buscar (primer cuadrado mayor que este valor) : ";
    cin >> valorBuscar;

    while ((valorCuadrado <= limite) && !encontrado)
    {
        cout << valorCuadrado << " ";
        if (valorCuadrado > valorBuscar && (cuadradoEncontrado == -1))
        {
            encontrado = true;
            cuadradoEncontrado = valorCuadrado;
        }
        n++;
        valorCuadrado = n * n;
    }

    if(encontrado){
        cout << "" << endl;
        cout << "El primer numero mayor a " << valorBuscar << " es " << cuadradoEncontrado << endl;
    }else{
        cout << "" << endl;
        cout << "No se ha encontrado ningun cuadrado mayor que " << valorBuscar << " dentro del limite " << limite << endl;
    }

    return 0;
}

int limiteIntroducido(int limite)
{
    while (limite <= 0 || limite >= 3000)
    {
        cout << "Introduce un numero límite (entero positivo mayor que cero) para los cuadrados del siguiente intervalo [1-1000] : " << endl;
        cin >> limite;
        if (limite <= 0 || limite >= 3000)
        {
            cout << "Valor introducido es incorrecto" << endl;
        }
    }
    return limite;
}
