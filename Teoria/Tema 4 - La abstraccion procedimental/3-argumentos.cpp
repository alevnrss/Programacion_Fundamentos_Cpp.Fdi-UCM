/**
 * Aqui como podemos ver, los dos unicos argumentos que cambian son aquellos a los que les pusimos un ampersand de manera 
 * que ahora estan declarados al compilador como variables que este debe modificar en la funcion.
 */
#include <iostream>
using namespace std;

void divide(int op1, int op2, int &div, int &resto);

int main(){

    int cociente, resto;
    for(int j = 1; j <=4; j++){
        for(int i = 1; i <= 4; i++){
            divide(j, i, cociente, resto);
            cout << i << " entre " << j << " tiene como cociente: " << cociente << " y de resto " << resto << endl;
        }
    }

    return 0;
}

void divide(int op1, int op2, int &div, int &resto){
    div = op1/op2;
    resto = op1%op2;
}

