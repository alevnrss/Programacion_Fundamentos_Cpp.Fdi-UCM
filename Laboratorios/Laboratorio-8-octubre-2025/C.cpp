/**
 * Escribe un programa que pida al usuario por pantalla tres valores de tipo string
 * y los muestre de menor a mayor (orden alfabético) separados por comas.
 * Por ejemplo, si el usuario introduce "pera", "manzana", "uva"
 * el resultado será: manzana < pera < uva
 * Utiliza el intercambio de variables.
 */

#include <iostream>
#include <string>
using namespace std;

void compararStrings(string s1, string s2, string s3);

int main() {
    string s1, s2, s3;

    cout << "Introduzca la primera palabra: ";
    cin >> s1;

    cout << "Introduzca la segunda palabra: ";
    cin >> s2;

    cout << "Introduzca la tercera palabra: ";
    cin >> s3;

    compararStrings(s1, s2, s3);

    return 0;
}

void compararStrings(string s1, string s2, string s3) {
    string temp; // variable temporal para intercambiar

    if (s1 > s2) {
        temp = s1;
        s1 = s2;
        s2 = temp;
    }

    if (s2 > s3) {
        temp = s2;
        s2 = s3;
        s3 = temp;
    }

    if (s1 > s2) {
        temp = s1;
        s1 = s2;
        s2 = temp;
    }

    cout << s1 << " < " << s2 << " < " << s3 << endl;
}
