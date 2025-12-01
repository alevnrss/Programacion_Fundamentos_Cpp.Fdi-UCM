/**
 * A continuacion veremos uno de los usos del algoritmo de busqueda en secuencias.
 * Su propósito específico es encontrar el primer número en una secuencia que sea mayor que un valor límite dado por el usuario (numero que se ha de superar)
 * Este algoritmo utiliza un valor centinela (-1) para indicar el final de la secuencia de datos, 
 * ya que no se sabe de antemano cuántos números va a introducir el usuario.
 */

#include <iostream>
using namespace std;

int main(){

    // 1- INICIALIZACION 
    double datoActual, limite; // almacenan el datoActual y el limite que es el numero que debe superar, cuando se supere terminara dicha secuencia.
    bool encontrado = false;
    cout << "Introduzca un valor limite de superar "<< endl;
    cin >> limite;
    cout << "Introduzca el primer elemento de la secuencia" << endl;
    cin >> datoActual;

    // A continuacion entraremos al corazon del algoritmo
    // CICLO DE BUSQUEDA
    while((datoActual != -1) && !encontrado){   // primera condicion controla que no se haya llegado al final de la secuencia, segunda condicion controla que no se haya encontrado aun
        if(datoActual > limite){ // condicion de busqueda que si se cumple cambia el valor bool
            encontrado = true;  // Si la condicion se cumple entonces se cambia el valor de la variable de busqueda y sale del bucle.
            cout << "El valor de " << limite << " se ha superado " << endl;
        }else{
            cin >> datoActual;  // Si es falso se ejecuta el bloque else para poder asi seguir con la secuencia.
        }
        if((datoActual == -1) && !encontrado){
            cout << "No se ha logrado encontrar un valor que supere al limite de " << limite << endl ;
            return 1;
        }
    }

    return 0;
}

 