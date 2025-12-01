/**
 * Para la generacion de numeros aleatorios se utilizara una nueva libreria y nueva funcion
 * que sera la encargada de generar dichos numeros aleatorios.
 * Ademas, para acompañar a esta funcion se utilizara otra que sera util para no repetir los mismo numeros aleatorios.
 * 
 * LIBRERIA : <cstdlib>
 * FUNCION : rand(): esta funcion no recibira ningun parametro, su funcion es generar numeros aleatorios, pero siempre generara los mismos si no se configura.
 * FUNCION : srand(): esta funcion hara que el programa realice una nueva generacion de numeros aleatorios cada vez que se ejecute y asi no se repetiran los numeros aleatorios.
 * FUCNION : srand(time(NULL)) : es la misma funcion sino que es una nueva praxis que lo que haces es generar nuevos numeros en funcion de la hora del sistema.
 * Esta funcion srand se debera invocar SOLO UNA VEZ, es decir, que nada de ir dentro de un bucle. Ademas siempre ira al principio del programa.
 * 
 * Existe otro metodo de poner rand() que es ajustando su rango, porque claro, si nos piden numeros aleatorios entre 0 y 10 pues dejar que rand() 
 * lo haga solo no es lo comun ya que su rango es hasta 37867
 * Para ello utilizaremos la siguiente cuestion:
 *  - Si queremos desde 0 a un numero se pone rand()%numero+1;
 *  - Si queremos desde un numero inferior especifico hasta otro superior: numeroInferior + rand()%(numeroSuperior + 1 - numeroInferior)
 * 
 * A continuacion se mostrara un ejemplo de varias generaciones de numeros aleatorios segun lo que nos pidan.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

// Secuencia de 5 numeros aleatorios

// Numeros desde 0 a 10
void primeraSecuenciaNumerosAl();

// Numeros desde 1 a 58
void segundaSecuenciaNumerosAl();

// Numeros desde 353 a 673
void terceraSecuenciaNumerosAl();

// Numeros aleatorios negativos desde -10 a 1
void cuartaSecuenciaNumerosAl();

int main(){
    primeraSecuenciaNumerosAl();
    segundaSecuenciaNumerosAl();
    terceraSecuenciaNumerosAl();
    cuartaSecuenciaNumerosAl();

    return 0;
}


void primeraSecuenciaNumerosAl(){
    cout << "5 Numeros desde el 0 a 10" << endl;
    srand(time(NULL));
    for(int i = 0; i < 5 ; i++){
        cout << "Numero aleatorio numero: " << i + 1 << " : " << rand()%11 << endl;
    }
}

void segundaSecuenciaNumerosAl(){
    cout << "5 Numeros desde el 1 a 58" << endl;
    srand(time(NULL));
    for(int i = 0; i < 5 ; i++){
        cout << "Numero aleatorio numero: " << i + 1 << " : " << (1 + rand()%(59-1)) << endl;
    }
}

void terceraSecuenciaNumerosAl(){
    cout << "5 Numeros desde el 353 a 673" << endl;
    srand(time(NULL));
    for(int i = 0; i < 5 ; i++){
        cout << "Numero aleatorio numero: " << i + 1 << " : " << (353 + rand()%(674-353)) << endl;
    }
}

void cuartaSecuenciaNumerosAl(){
    cout << "5 Numeros desde el -10 a 1" << endl;
    srand(time(NULL));
    for(int i = 0; i < 5 ; i++){
        cout << "Numero aleatorio numero: " << i + 1 << " : " << (-10 + rand()%(2-(-10))) << endl;
    }
}


