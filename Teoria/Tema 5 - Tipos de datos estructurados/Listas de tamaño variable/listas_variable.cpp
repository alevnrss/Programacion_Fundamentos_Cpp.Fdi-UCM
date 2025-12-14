/**
 * ENUNCIADO :
 * Diseñar un programa que mantenga una lista de los estudiantes de una clase.
 * Estudiante tendra nombre, apellidos, edad, NIF y nota
 * Se desconoce el numero total de estudiantes que hay pero ponemos como que la clase puede tener un maximo de 10 estudiantes. (MAX = 10)
 * La informacion de la lista se mantiene en un archivo.clase.txt
 * Se carga al empezar y se guarda al finalizar
 * El programa ademas debe ofrecer las siguientes opciones:
 *  -   Añadir nuevo alumno
 *  -   Eliminar un alumno existente
 *  -   Calificar a los estudiantes (si su nota es -1 entonces es que falta por calificar)
 *  -   Listado de notas, identificando la mayor nota y la media de todas las notas.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// variables globales
const int MAX = 10;

// estructuras
typedef struct
{
    string nombre;
    string apellidos;
    int edad;
    string nif;
    double nota;
} tEstudiante;

typedef tEstudiante tArray[MAX];

typedef struct
{
    tArray elementos;
    int contador;
} tLista;

// prototipos
int menu();                                                               // menu del programa - devuelve la opcion elegida
void cargar(tLista &lista, bool &ok);                                     // Carga del archivo en la lista
void guardar(const tLista &lista);                                        // Guarda la lista en archivo
void leerEstudiante(tEstudiante &estudiante);                             // Lee los datos del estudiante
void insertarEstudiante(tLista &lista, tEstudiante estudiante, bool &ok); // Inserta un nuevo estudiante en la lista
void eliminarEstudiante(tLista &lista, int pos, bool &ok);                // Elimina el estudiante en una posicion determinada
string nombreCompleto(tEstudiante estudiante);                            // Devuelve en un string el nombre completo de un estudiante
void calificar(tLista &lista);                                            // Rellenar las notas de todos los estudiantes
double mediaClase(const tLista &lista);                                   // Calcula la media de las notas de todos los alumnos de la clase
int mayorNota(const tLista &lista);                                       // Devuelve el indice del estudiante con la mayor nota
void mostrarEstudiante(tEstudiante estudiante);                           // Muestra los datos de un estudiante por pantalla
void listado(const tLista &lista, double media, int mayor);               // Mostrar el listado completo de clase

int main()
{
    tLista lista;
    tEstudiante estudiante;
    bool exito;
    int posicion, opcion;
    cargar(lista, exito);
    if (!exito)
    {
        cout << "\nNo se ha podido cargar la lista." << endl;
    }
    else
    {
        opcion = menu();
        while (opcion != 0)
        {
            switch (opcion)
            {
            case 1:
                cout << "Ha elegido agregar un nuevo alumno a la clase. " << endl;
                leerEstudiante(estudiante);
                insertarEstudiante(lista, estudiante, exito);
                if (!exito)
                {
                    cout << "\nNo se puede añadir otro estudiante porque la lista se encuentra llena: " << lista.contador << " / " << MAX << endl;
                }
                break;
            case 2:
                cout << "Ha elegido eliminar un alumno existente. " << endl;
                cout << "Introduce la posicion de la cual quiera eliminar el alumno: ";
                cin >> posicion;
                eliminarEstudiante(lista, posicion, exito);
                if (!exito)
                    cout << "No se puede eliminar porque no hay ninguno o la opcion es inexistente" << endl;
                break;
            case 3:
                cout << "Ha elegido calificar a todos los estudiantes" << endl;
                calificar(lista);
                break;
            case 4:
                cout << "Ha elegido mostrar todos los estudiantes de la clase, junto a la mayor nota y la nota media" << endl;
                listado(lista, mediaClase(lista), mayorNota(lista));
                break;
            }
            opcion = menu();
        }
        guardar(lista);
        cout << "Usted ha elegido cerrar el programa" << endl;
    }

    return 0;
}
int menu()
{
    int opcion = -1;
    while ((opcion < 0) || (opcion > 4))
    {
        cout << "\nPROGRAMA MENU DE LA CLASE" << endl;
        cout << "---------------" << endl;
        cout << "1. Agregar un nuevo alumno" << endl;
        cout << "2. Eliminar un alumno existente" << endl;
        cout << "3. Calificar a los estudiantes" << endl;
        cout << "4. Listado de notas, identificando la mayor y la media de todas" << endl;
        cout << "0 para salir del programa" << endl;
        cout << "Elige una de las opciones anteriores." << endl;
        cin >> opcion;
        if ((opcion < 0) || (opcion > 4))
        {
            cout << "Opcion introducida invalida. Intentelo de nuevo." << endl;
        }
    }
    return opcion;
}

// GUARDADO Y VOLCADO DE DATOS DEL ARCHIVO = 2 Funciones
// Funcion para cargar los datos del archivo a la lista
void cargar(tLista &lista, bool &ok)
{
    ifstream archivo;
    lista.contador = 0;

    archivo.open("clase.txt");
    if (!archivo.is_open())
    {
        cout << "El archivo no se abrio correctamente" << endl;
        ok = false;
    }
    else
    {
        ok = true;
        cout << "El archivo se abrio correctamente" << endl;
        getline(archivo, lista.elementos[lista.contador].nombre);
        while ((lista.elementos[lista.contador].nombre != "xxx") && lista.contador < MAX)
        {
            getline(archivo, lista.elementos[lista.contador].apellidos);
            archivo >> lista.elementos[lista.contador].edad;
            archivo >> lista.elementos[lista.contador].nif;
            archivo >> lista.elementos[lista.contador].nota;
            archivo.ignore(1000, '\n');
            lista.contador++;
            getline(archivo, lista.elementos[lista.contador].nombre);
        }
        archivo.close();
    }
}

// Funcion para volcar los datos ya cargados.
void guardar(const tLista &lista)
{
    ofstream archivo;
    lista.contador;

    archivo.open("clase.txt");
    if (!archivo.is_open())
    {
        cout << "\nNo se abrio correctamente el archivo para volcar los datos" << endl;
    }
    else
    {
        cout << "\nSe abrio correctamente el archivo para volcar los datos" << endl;
        for (int i = 0; i < lista.contador; i++)
        {
            archivo << lista.elementos[i].nombre << endl;
            archivo << lista.elementos[i].apellidos << endl;
            archivo << lista.elementos[i].edad << endl;
            archivo << lista.elementos[i].nif << endl;
            archivo << lista.elementos[i].nota << endl;
        }
        archivo << "xxx" << endl;
        archivo.close();
    }
}

// INSERCCION DE ESTUDIANTE = 2 FUNCIONES.
// funcion necesaria para introducir un estudiante. Rellena el formulario del estudiante.
void leerEstudiante(tEstudiante &estudiante)
{
    cin.ignore(1000, '\n');
    cout << "Introduce los datos del nuevo estudiante" << endl;
    cout << "Nombre del estudiante: ";
    getline(cin, estudiante.nombre);
    cout << "Apellidos del estudiante: ";
    getline(cin, estudiante.apellidos);
    cout << "Edad: ";
    cin >> estudiante.edad;
    cout << "NIF: ";
    cin >> estudiante.nif;
    estudiante.nota = -1;
    cin.ignore(1000, '\n');
}

// Funcion para insertar un nuevo estudiante en el final de la lista
void insertarEstudiante(tLista &lista, tEstudiante estudiante, bool &ok)
{
    if (lista.contador < MAX)
    {
        ok = true;
        lista.elementos[lista.contador] = estudiante;
        lista.contador++;
    }
    else
    {
        ok = false;
    }
}

// ELIMINACION DE ESTUDIANTE = 1 FUNCION.
// Funcion para eliminar un nuevo estudiante en una posicion de la lista dada por el usuario
void eliminarEstudiante(tLista &lista, int pos, bool &ok)
{
    if (lista.contador > 0)
    {
        ok = true;
        for (int i = pos; i < lista.contador - 1; i++)
        {
            lista.elementos[i] = lista.elementos[i + 1];
        }
        lista.contador--;
    }
    else
    {
        ok = false;
    }
}

// CALIFICAR ESTUDIANTES = 2 FUNCIONES
// Funcion para juntar el nombre con los apellidos
string nombreCompleto(tEstudiante estudiante)
{
    string nombre;
    nombre = estudiante.nombre + " " + estudiante.apellidos;
    return nombre;
}

// Funcion para calificar a todos los estudiante
void calificar(tLista &lista)
{
    for (int i = 0; i < lista.contador; i++)
    {
        cout << "Introduce nota para " << nombreCompleto(lista.elementos[i]) << " : ";
        cin >> lista.elementos[i].nota;
    }
}

// Funcion para calcular la media de la clase.
double mediaClase(const tLista &lista)
{
    double sumaMedia = 0.0;
    for (int i = 0; i < lista.contador; i++)
    {
        sumaMedia += lista.elementos[i].nota;
    }

    return sumaMedia / lista.contador;
}

// Funcion para encontrar la mayor nota
int mayorNota(const tLista &lista)
{
    int mayor = 0;
    int posicion = 0;
    for (int i = 0; i < lista.contador; i++)
    {
        if (lista.elementos[i].nota > mayor)
        {
            mayor = lista.elementos[i].nota;
            posicion = i;
        }
    }
    return posicion;
}

// LISTAR ESTUDIANTES = 2 FUNCIONES
// Funcion para mostrar los datos del estudiante por cada iteracion
void mostrarEstudiante(tEstudiante estudiante)
{
    cout << nombreCompleto(estudiante) << endl;
    cout << "NIF: "<< estudiante.nif << endl;
    cout << "Anios: " << estudiante.edad << endl;
    cout << fixed << setprecision(1) << estudiante.nota;
}

// Funcion para listar todos los estudiantes
void listado(const tLista &lista, double media, int mayor)
{
    cout << "LISTA DE LA CLASE CON UN TOTAL DE " << lista.contador << " ALUMNOS." << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < lista.contador; i++)
    {
        cout << setw(3) << i << ": ";
        mostrarEstudiante(lista.elementos[i]);
        if (i == mayor)
            cout << " Mayor nota!";
        cout << endl;
    }
    cout << "Media de la clase: " << fixed << setprecision(1)
         << media << endl
         << endl;
}