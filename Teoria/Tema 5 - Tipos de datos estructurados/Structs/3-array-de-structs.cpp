/**
 * A continuacion se mostrara como se realiza un ARRAY DE ESTRUCTURAS 
 * IMPORTANTE : no es ARRAYS DENTRO DE ESTRUCTURAS
 * 
 * En este ejercicio se mostrara como se puede crear un array de estructuras de tipo persona, donde llenaremos todas las personas con su informacion y donde podremos tener 
 * mas de una persona con sus propiedades.
 * 
 * En este caso, segun cuantas personas queramos asociar al array, sera nuestro tamaño del array de tipo persona.
 * 
 * Declaramos un tipo de dato creado por el usuario de tipo array de tipo persona con un tamanio de 2 personas.
 * 
 * Declararemos una variable de ese tipo de dato array para que sea nuestro array que guarde a las personas.
 * 
 * Finalmente con funciones llenaremos los arrays con la informacion de las personas y con otra funcion mostraremos los datos de las personas.
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int DIM = 2;

typedef struct {
    string dni;
    char letra;
}tNif;

typedef struct {
    string nombre;
    string apellidos;
    int edad;
    tNif nif;
}tPersona;


typedef tPersona tArray[DIM];

void rellenarArrayPersona(tArray persona);
void imprimirDatosPersona(tArray persona);

int main(){

    tArray persona;

    rellenarArrayPersona(persona);
    imprimirDatosPersona(persona);

    return 0;
}

void rellenarArrayPersona(tArray persona){

    cout << "A continuacion se pediran datos para rellenar a los usuarios" << endl;
    for(int i = 0; i < DIM; i++){
        cout << "\nIntroduzca el nombre del usuario " << i + 1 << endl;
        cin >> persona[i].nombre;
        cout << "Introduzca los apellidos del usuario " << i + 1 << endl;
        cin >> persona[i].apellidos;
        cout << "Introduzca la edad del usuario " << i + 1 << endl;
        cin >> persona[i].edad;
        cout << "Introduzca los numeros del DNI del usuario " << i + 1 << endl;
        cin >> persona[i].nif.dni;
        cout << "Introduzca la letra del DNI del usuario " << i + 1 << endl;
        cin >> persona[i].nif.letra;
    }
}

void imprimirDatosPersona(tArray persona){
    for(int i = 0; i < DIM; i++){
        cout << "\n\tINFORMACION DEL USUARIO " << i + 1 << endl <<
        persona[i].nombre << endl <<
        persona[i].apellidos << endl <<
        persona[i].edad << endl <<
        persona[i].nif.dni << persona[i].nif.letra << endl;
    }
}