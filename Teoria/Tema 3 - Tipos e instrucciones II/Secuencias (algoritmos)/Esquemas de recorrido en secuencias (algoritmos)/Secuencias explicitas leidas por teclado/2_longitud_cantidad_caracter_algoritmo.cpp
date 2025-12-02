/**
 * ALGORITMO 2 Y 3.
 * 
 * IMPORTANTE EL USO DE CIN.GET() PARA QUE PUEDA LEER TAMBIEN ESPACIOS.
 * TAMBIEN SE PUEDE DAR USO DE OPERADORES TERNARIOS Y EVITAR LAS SENTENCIAS CONDICIONALES.
 * 
 * ALGORITMO 2.
 * Este algoritmo es para saber la longitud que tiene una cadena de caracteres utilizando char.
 * El programa finalizara siempre y cuando el usuario teclee un punto (.).
 * Lo que hara este programa sera leer todos los caracteres que vayamos introduciendo por teclado
 * hasta llegar al punto si es que hay si no seguira el bucle.
 * Es importante saber que para este algoritmo no hace falta un string ya que podemos poner espacios
 * de las cuales el propio algoritmo contara.
 * 
 * ALGORITMO 3.
 * Este algoritmo es para saber cuantas veces aparece un caracter en una cadena de caracteres utilizando char.
 * El segundo programa consistira en saber cuantas veces se teclea un caracter especifico en una cadena.
 * El usuario tecleara el caracter que quiere buscar la cual se iran sumando a las veces que aparece dicho caracter.
 * El centinela sera si el usuario teclea un asterisco.
 */

 #include <iostream>
 #include <string>
 using namespace std;

int longitud();
int cantidadBuscado(char buscar);

int main(){
int longitudTotal = longitud();
cout << "La longitud total es de " << longitudTotal << endl;

cout << "A continuacion introduce un caracter que deseas buscar" << endl;
char buscar;
cin >> buscar;
int contadorBuscarTotal = cantidadBuscado(buscar);
cout << "Las veces que se ha encontrado: "<< buscar << " es de :"<< contadorBuscarTotal << endl;

}

// ALGORITMO 2.
int longitud (){
    cout << "El programa terminara cuando el usuario teclee un punto" << endl;
    int longitud = 0;
    char c;

    c = cin.get();
    while( c!= '.'){
        longitud++;
        c = cin.get();
    }

    return longitud;
}

// ALGORITMO 3.
int cantidadBuscado(char buscar){
    int contador = 0;
    char c;     // aqui es donde escribiremos nuestra cadena, realmente es una forma de encontrar las veces que se repite sin usar string
    cout << "cadena : ";
    c = cin.get();
    while(c != '*'){
        if(c == buscar){
            contador++;
        }
        c = cin.get();
    }

    return contador;
}
