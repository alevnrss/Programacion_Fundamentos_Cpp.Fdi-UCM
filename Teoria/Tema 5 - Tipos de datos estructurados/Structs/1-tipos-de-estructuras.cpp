/**
 *  - Un tipo de dato estructurado (structs), son casi lo mismo que una clase en Java. 
 *    La única diferencia real por defecto es que que los structs son PUBLICOS por defecto, al contrario que las clases en Java, donde las clases son
 *    PRIVADAS por defecto.
 * 
 *  - Un struct es un tipo de datos COMPUESTO definido por el usuario. 
 * 
 *  - Su funcion es agrupar uno o varios miembros bajo un mismo nombre.
 * 
 *  - Cada campo esta definido por un nombre en especifico.
 * 
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Definimos un struct de tipo persona -> sus propiedades son nombre, apellidos, edad y nif.
// importante definir al final el nombre del struct.    
typedef struct {
    string nombre;  // campo nombre
    string apellidos;
    int edad;
    string nif;
}tPersona;

int main(){

    // Instanciamos el struct de tipo persona 1
    tPersona persona;

    // Para poder asignarle valores a sus propiedades deberemos usar la notacion (variable.propiedad)
    persona.nombre = "Pepe";
    persona.apellidos = "Perez";
    persona.edad = 30;
    persona.nif = "12345678A";
    
    // Finalmente imprimimos la informacion
    cout << "\nInformacion de la persona: " << endl
    << "Nombre: " << persona.nombre << endl
    << "Apellidos: " << persona.apellidos << endl
    << "Edad: " << persona.edad << endl
    << "NIF: " << persona.nif << endl;

    // Podemos instanciar dicho struct a mas de una variable
    tPersona persona2, persona3;

    // Tambien podemos copiar la informacion de un struct a otro, en este caso tanto persona2 como persona3 seran iguales porque son iguales a persona1
    persona2 = persona3 = persona;

    // Si imprimimos, podemos ver que tanto persona2 como persona3 son iguales a persona1 pues los hemos copiado despues de haber dado valores a persona1
    cout << "\nInformacion de la persona 2 copiada de la persona 1: " << endl
    << "Nombre: " << persona2.nombre << endl
    << "Apellidos: " << persona2.apellidos << endl
    << "Edad: " << persona2.edad << endl
    << "NIF: " << persona2.nif << endl;

    cout << "\nInformacion de la persona 3 copiada de la persona 1: " << endl
    << "Nombre: " << persona3.nombre << endl
    << "Apellidos: " << persona3.apellidos << endl
    << "Edad: " << persona3.edad << endl
    << "NIF: " << persona3.nif << endl;


    return 0;
}