/**
 *   - Declaracion de una variable de tipo enumerado.
 */

#include <iostream>
using namespace std;

typedef enum tvalores{valor1, valor2, valor3, valor4, valor5};
int main(){
    tvalores variable; // Esta variable ahora es como un tipo de dato entero.
    variable = valor1;
    cout << "Estamos cogiendo la el valor en la posicion " << variable << endl; // variable es = 0;
    if(variable == valor1) cout << "El valor de la variable es valor1" << endl;
    return 0;
}

