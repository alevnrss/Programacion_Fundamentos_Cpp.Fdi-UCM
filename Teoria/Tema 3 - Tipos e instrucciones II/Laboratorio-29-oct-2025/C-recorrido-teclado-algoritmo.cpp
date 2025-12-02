/**
 * Implementa un programa que lea del teclado una secuencia de caracteres terminada en asterisco y que cuente y muestre en pantalla:
 * ₋ El número de vocales sin acentuar (mayúsculas o minúsculas).  Se puede usar las funciones tolower y toupper de la biblioteca cctype.
 * - El número de signos ( ','  ';'  ':'  '.'  ) y
 * - Los espacios que hay en la secuencia.
 * Codifica 3 funciones: vocalesSin(), signos() y espacios().
 * En estas funciones, utiliza expresiones en vez de sentencias condicionales. --> OPERADOR TERNARIO
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
    while (c != '*')
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
