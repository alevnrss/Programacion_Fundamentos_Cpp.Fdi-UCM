#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// variables globales
const int MAXIMO = 10;

// Estructuras
typedef struct{
    string nombre;
    string apellidos;
    int edad;
    string nif;
    int nota;
} tEstudiante;

typedef tEstudiante tArray[MAXIMO];

typedef struct{
    tArray elementos;
    int contador;
} tLista;

// prototipos
void cargarEstudiantes(tLista &lista, tEstudiante estudiante);
void mostrarEstudiantes(tLista lista);
void volcarLista(const tLista &lista, ofstream &archivo);

int main(){
    tEstudiante estudiante;
    tLista lista;
    ofstream archivo;

    cargarEstudiantes(lista, estudiante); // cargar estudiantes por teclado
    mostrarEstudiantes(lista);  // mostrar estudiantes introducidos por teclado
    
    archivo.open("clase.txt");
    if(!archivo.is_open()){
        cout << "No se ha logrado abrir el archivo correctamente" ;
    }else{
        volcarLista(lista, archivo); // pegar estudiantes al archivo
    }

    return 0;
}

// Esta funcion sirve para pegar todos los datos de nuestra lista en el archivo en blanco
// Se le pasa como parametros la lista por referencia pero constante y el archivo por referencia
// Deberemos recorrer desde el indice 0 hasta el contador.
// En cada iteracion pegamos en el archivo segun en que linea lo queremos poner
// No olvidar poner siempre un centinela final y cerrar el archivo.
void volcarLista(const tLista &lista, ofstream &archivo){
    for(int i = 0; i < lista.contador; i++){
        archivo << lista.elementos[i].nombre << endl;
        archivo << lista.elementos[i].apellidos << endl;
        archivo << lista.elementos[i].edad << endl;
        archivo << lista.elementos[i].nif << endl;
        archivo << lista.elementos[i].nota << endl;
    }
    archivo << "EOF" << endl;
    archivo.close();
}

// Siempre que queramos cargar la lista utilizaremos la variable de tipo estudiante.
// Inicializamos el contador a 0. 
// Iteraremos hasta que el contador sea igual al maximo o hasta que el usuario ponga el asterisco. (WHILE)
// Antes de entrar vemos si no quiere introducir ningun estudiante.
// Cuando finalmente recogemos hasta el final de un usuario, tenemos que meter el estudiante a la lista y despues 
// sumamos el contador.
void cargarEstudiantes(tLista &lista, tEstudiante estudiante){
    char aux;
    lista.contador = 0;

    cout << "Cargar estudiantes: MAXIMO 10. Para terminar de introducir poner un * ." << endl;
    cout << "Alumno " << lista.contador << " : ";
    cout << "Nombre del alumno: ";
    getline(cin, estudiante.nombre);
    cin.ignore(1000, '\n');
    while((lista.contador < MAXIMO) && estudiante.nombre != "*"){
        cout << "Apellidos del alumno: ";
        getline(cin, estudiante.apellidos);
        cout << "Edad del alumno: ";
        cin >> estudiante.edad;
        cout << "NIF: ";
        cin >> estudiante.nif;
        cout << "Nota: ";
        cin >> estudiante.nota;
        cin.get(aux);
        lista.elementos[lista.contador] = estudiante;
        lista.contador++;
        cout << "Nombre del alumno: ";
        getline(cin, estudiante.nombre);
    }
}

// Mostrar por pantalla los estudiantes que estan en el array.
void mostrarEstudiantes(tLista lista){
    cout << "\nTotal de alumnos en esta clase = " << lista.contador << endl;
    for(int i = 0; i < lista.contador; i++){
        cout << "-------------------------------------" << endl;
        cout << "Alumno en la posicion " << i << " : " << endl;
        cout << "Nombre: " << lista.elementos[i].nombre << endl;
        cout << "Apellidos: " << lista.elementos[i].apellidos << endl;
        cout << "Edad: " << lista.elementos[i].edad << endl;
        cout << "NIF: " << lista.elementos[i].nif << endl;
        cout << "Nota: " << lista.elementos[i].nota << endl;
    }
}
