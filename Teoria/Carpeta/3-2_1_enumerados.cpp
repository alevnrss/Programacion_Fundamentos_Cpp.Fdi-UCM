/**
 * Tipo de dato enumerado
 *  - Recorrer tipo de dato enumerado. 
 *  - Declaracion de tipo enumardo.
 *  - Valor de una variable definido por ese tipo de dato enumerado.
 */


#include <iostream>
using namespace std;

typedef enum tSemana {
    lunes,
    martes,
    miercoles,
    jueves,
    viernes,
    sabado,
    domingo
};

int main() {
    tSemana estaSemana, siguienteSemana;

    // Recorrer tipo de dato enumerado con FOR(2 tipos de for) y SWITCH.
    for (int i = lunes; i <= domingo; i++) {   // int i = 0 ; i <= 6 ; i++ ya que lunes es 0 y domingo es 6
        switch (i) {
            case lunes:
                cout << "Lunes";
                break;
            case martes:
                cout << "Martes";
                break;
            case miercoles:
                cout << "Miercoles";
                break;
            case jueves:
                cout << "Jueves";
                break;
            case viernes:
                cout << "Viernes";
                break;
            case sabado:
                cout << "Sabado";
                break;
            case domingo:
                cout << "Domingo";
                break;
        }
        cout << endl;
    }

    return 0;
}
