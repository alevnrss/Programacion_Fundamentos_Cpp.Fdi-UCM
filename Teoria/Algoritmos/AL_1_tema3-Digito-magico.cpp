/**
 * ALGORITMO DE CALCULO DE DIGITO MAGICO.
 * Para este ejemplo se va a hacer que el programa nos de un numero aleatorio, a ese numero aleatorio se le hara ese digito magico.
 * IMPORTANTE SABER que ese numero para que se haga tiene que ser un numero mayor a 9 o mejor dicho, un numero de dos cifras.
 * Si ese numero aleatorio es menor a 9 es decir que es de tan solo una cifra, entonces no se hara su digito magico simplemente devolvera
 * la suma de sus cifras que es el propio numero de una cifra.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int generacionNumeroAleatorio();
int esDigitoMagico(int n);
int sumaDigitos(int n);

int main(){
    int n, digitoMagico = 0;
    n = generacionNumeroAleatorio();
    digitoMagico = esDigitoMagico(n);
    
    cout << "El digito magico de " << n << " es igual a : " << digitoMagico << endl;

    return 0;
}

// Generar un numero aleatorio del intervalo [1-100]
int generacionNumeroAleatorio(){
    int numeroAleatorio = 0;
    
    srand(time(NULL));
    numeroAleatorio = (1 + rand()%(101 - 1));

    return numeroAleatorio;
}

int esDigitoMagico(int n){
    while( n > 9 ){
        n = sumaDigitos(n);
    }
    return n;
}

int sumaDigitos(int n){
    int suma = 0;
    while( n > 0 ){
        suma += n%10;
        n /= 10;
    }

    return suma;
}


