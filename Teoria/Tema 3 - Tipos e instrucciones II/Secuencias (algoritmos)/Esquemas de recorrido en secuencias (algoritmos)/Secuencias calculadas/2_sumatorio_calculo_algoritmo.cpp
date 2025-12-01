/**
 * ALGORITMO 6.
 * Este se trata de un algoritmo basico que se trata de realizar uno de los ejemplos mas practicos de calculo, EL SUMATORIO.
 * Este se trata de una secuenca desde n=1 hasta un n que debera ponerlo el propio usuario pues no puede ser infinito.
 * Aqui realmente sabemos desde donde hasta donde haremos la secuencia por lo que podremos dar uso del bucle
 * for.
 * 
 * El valor de n lo dara el propio usuario.
 */
#include <iostream>
#include <string>
using namespace std;

int sumatorioNumeros(int n);

int main(){

    int n, sumatorio;
    cout << "Introduzca el valor de n que desea usted para empezar el sumatorio: ";
    cin >> n;
    sumatorio = sumatorioNumeros(n);

    cout << "El valor del sumatorio de n = " << n << " , es de : " << sumatorio << endl;

    return 0;
}
int sumatorioNumeros(int n){
    int sumatorio = 0; // servira como contador y a la vez de suma de todos los numeros que ser recorra
    for(int i = 1; i <= n; i++) {
        sumatorio = sumatorio + i;
    }

    return sumatorio;
}

