/**
 * Escribe una función lecturaConLimites() que reciba como parámetros dos valores de tipo int. La
 * función pedirá al usuario que introduzca un número entero tantas veces como sea necesario hasta que el
 * número suministrado se encuentre dentro del intervalo determinado por los datos de entrada (puede
 * darle pistas). La función devolverá el último número leído. Escribe un programa principal que use dicha
 * función para pedir al usuario un número entre 10 y 20.
 */

#include <iostream>
using namespace std;

const int COTA_INFERIOR = 10;
const int COTA_SUPERIOR = 20;

int lecturaConLimites(const int COTA_INF, const int COTA_SUP);

int main(){
    int numeroFinal;
    numeroFinal = lecturaConLimites(COTA_INFERIOR, COTA_SUPERIOR);
    cout << "El numero que esta dentro del intervalo 10 - 20 es: " << numeroFinal;
    return 0;
}

int lecturaConLimites(const int COTA_INF, const int COTA_SUP){
    int opcion = -1;
    while((opcion < COTA_INF) || (opcion > COTA_SUP)){
        cout << "Introduce un numero detro del intervalo " << COTA_INF << " - " << COTA_SUP << endl;
        cin >> opcion;
        if((opcion < COTA_INF) || (opcion > COTA_SUP)){
            cout << "El numero debe ser dentro del intervalo (10 - 20), ambas cotas incluidas" << endl;
        }
    }
    return opcion;
}