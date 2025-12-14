/**
 * Crear un programa que funcione como un pequeño catalogo de libros, es decir, guardaremos libros en el catalogo y despues se mostraran todos 
 * los libros del catalogo.
 * 
 * El catálogo tendrá como maximo tres libros
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

typedef struct {
    int dia;
    int mes;
    int anio;

} tFecha;

typedef struct{
    string titulo;
    string autor;
    float precio;
    tFecha fecha_publicacion;
}tLibro;

const int MAX_LIBROS = 2;

typedef tLibro tArrayCatalogo[MAX_LIBROS];

void cargarCatalogo(tArrayCatalogo catalogo);
void mostrarCatalogo(tArrayCatalogo catalogo);

int main(){

    tArrayCatalogo catalogo;
    cargarCatalogo(catalogo);
    mostrarCatalogo(catalogo);


    return 0;
}

void cargarCatalogo(tArrayCatalogo catalogo){
    cout << "CARGAR CATALOGO DE LIBROS : " << endl;
    
    for(int i = 0 ; i < MAX_LIBROS; i++){
        cout << "\nIntroduzca el titulo del libro " << i + 1 << " : " << endl;
        getline(cin, catalogo[i].titulo);
        cout << "Introduzca el nombre del autor del libro " << i + 1 << endl; 
        getline(cin, catalogo[i].autor);
        cout << "Introduzca el precio del libro " << i + 1 << endl;
        cin >> catalogo[i].precio;

        cout << "A continuacion debera introducir los datos de fecha de publicacion del libro: " << endl;
        cout << "Dia de publicacion: " << endl;
        cin >> catalogo[i].fecha_publicacion.dia;
        cout << "Mes de publicacion: " << endl;
        cin >> catalogo[i].fecha_publicacion.mes;
        cout << "Anio de publicacion: " << endl;
        cin >> catalogo[i].fecha_publicacion.anio;
        cin.ignore();
    }
}

void mostrarCatalogo(tArrayCatalogo catalogo){
    cout << "\nCATALOGO DE LIBROS DISPONIBLES: " << endl;
    for(int i = 0 ; i < MAX_LIBROS ; i++){
        cout << "Libro " << i + 1 << endl;
        cout << "Titulo: " << catalogo[i].titulo << endl;
        cout << "Autor: " << catalogo[i].autor << endl;
        cout << "Precio: " << catalogo[i].precio << endl ;
        cout << "Fecha de publicacion del libro: " << catalogo[i].fecha_publicacion.dia << "/" << catalogo[i].fecha_publicacion.mes << "/" << catalogo[i].fecha_publicacion.anio << endl ;    
    }
}