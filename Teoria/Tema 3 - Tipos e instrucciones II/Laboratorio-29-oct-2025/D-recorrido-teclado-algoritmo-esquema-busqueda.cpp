/**
 * Modifica el programa anterior para que pare cuando haya econtrado 5 espacios
 */
#include <iostream>
#include <cctype>
using namespace std;

int espacios(char c);
int signos(char c);
int vocalesSin(char c);

int main()
{
    char c;
    int contadorEspacios = 0, contadorSignos = 0, contadorVocalesSin = 0;
    cout << "A continuacion escribe una cadena de string | TERMINA SI PULSAS ASTERISCO" << endl;
    c = cin.get();
    while ((c != '*') && (contadorEspacios < 5))
    {
        contadorEspacios += espacios(c);
        contadorSignos += signos(c);
        contadorVocalesSin += vocalesSin(c);
        c = cin.get();
    }
    cout << "La cantidad de espacios que se han contado son de: " << contadorEspacios << endl;
    cout << "La cantidad de signos que se han contado son de: " << contadorSignos << endl;
    cout << "La cantidad de vocales sin acentuar que se han contado son de: " << contadorVocalesSin << endl;

    return 0;
}
int espacios(char c)
{
    int contador = 0;
    contador = (c == ' ') ? 1 : 0;
    return contador;
}

int signos(char c)
{
    int contador = 0;
    contador = (c == ',') ? 1 : (c == ';') ? 1
                            : (c == ':')   ? 1
                            : (c == '.')   ? 1
                                           : 0;
    return contador;
}
int vocalesSin(char c)
{
    char cMinuscula = tolower(c);
    int contador = 0;
    contador = (cMinuscula == 'a') ? 1 : (cMinuscula == 'e') ? 1
                                     : (cMinuscula == 'i')   ? 1
                                     : (cMinuscula == 'o')   ? 1
                                     : (cMinuscula == 'u')   ? 1
                                                             : 0;
    return contador;
}
