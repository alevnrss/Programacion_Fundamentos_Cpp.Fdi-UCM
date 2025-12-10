#include <iostream>
using namespace std;

// variables globales
const int PRIMO_MENOR = 2;

// prototipos
int menu();
void escribirPrimosIntervalo(const int COTA_INFERIOR, const int COTA_SUPERIOR);
int escribirPrimerPrimo(int cota_inferior);
int escribirPrimosMenores(const int cota_superior2, const int PRIMO_MENOR);
int esPrimo(int contador);


int main()
{
    int opcion;
    opcion = menu();
    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
            int cota_inferior;
            int cota_superior;

            cout << "\nUsted ha elegido la OPCION 1.-Escribir todos los numeros primos que hay entre dos naturales dados. " << endl;        
            cout << "Introduzca el primer valor del intervalor (COTA INFERIOR)" << endl;
            cin >> cota_inferior;
            cout << "Introduzca el segundo valor del intervalor (COTA SUPERIOR)" << endl;
            cin >> cota_superior;
            escribirPrimosIntervalo(cota_inferior, cota_superior);

            break;

        case 2:
            int cota_inferior2, primerPrimo;

            cout << "\nUsted ha elegido la OPCION 2.-Escribir el primer numero primo mayor que un natural dado. " << endl;
            cout << "Introduzca el valor al que quiere buscar su mayor" << endl;
            cin >> cota_inferior2;
            primerPrimo = escribirPrimerPrimo(cota_inferior2);
            if(primerPrimo != 0){
                cout << "El primer primo mayor a " << cota_inferior2 << " es : " << primerPrimo << endl ;
            }
            break;

        case 3:
        int cota_superior2, contadorPrimosMenores;

        cout << "\nUsted ha elegido la OPCION 3.-Contar los primos menores a un numero natural dado. " << endl;
            cout << "Introduzca el valor al que quiere buscar sus menores" << endl;
            cin >> cota_superior2;
            contadorPrimosMenores = escribirPrimosMenores(cota_superior2, PRIMO_MENOR);
            cout << "\nHay " << contadorPrimosMenores << " primos menores a " << cota_superior2 << endl;
            break;
        }
        opcion = menu();
    }
    cout << "Usted ha elegido la OPCION 0.-Terminar el programa." << endl;

    return 0;
}

int menu()
{
    string mensajeError = "El numero introducido no es valido, por favor ingrese otro: ";
    cout << "\n\t---------------------------------------------------------------------------------" << endl;
    cout << "\tPROGRAMA NUMEROS PRIMOS - MENU:" << endl;

    int opcionUser = -1;

    while ((opcionUser < 0) || (opcionUser > 3))
    {
        cout << "\t---------------------------------------------------------------------------------" << endl;
        cout << "\n\tOPCION 1.-Escribir todos los numeros primos que hay entre dos naturales dados. " << endl;
        cout << "\tOPCION 2.-Escribir el primer numero primo mayor que un natural dado. " << endl;
        cout << "\tOPCION 3.-Contar los primos menores a un numero natural dado. " << endl;
        cout << "\tOPCION 0.-Terminar el programa. " << endl;
        cout << "\nIntroduzca la opcion que desea realizar:  ";
        cin >> opcionUser;
        if ((opcionUser < 0) || (opcionUser > 3))
        {
            cout << "ERROR: OPCION INVALIDA, introduzca un valor valido." << endl;
        }
    }
    return opcionUser;
}

void escribirPrimosIntervalo(const int COTA_INFERIOR, const int COTA_SUPERIOR){
    int numeroPrimo = 0;
    for(int i = COTA_INFERIOR; i <= COTA_SUPERIOR; i++){
        numeroPrimo = esPrimo(i);
        if(!(numeroPrimo == 0)){
            cout << numeroPrimo << " ";
        }
    }
}

int escribirPrimerPrimo(int cota_inferior){
    int numeroActual = cota_inferior + 1;
    bool encontrado = false;
    int resultado_primo;
    while(!encontrado){
        resultado_primo = esPrimo(numeroActual);
        if(resultado_primo > 0){
            encontrado = true;
            return resultado_primo;
        }

        numeroActual++;
    }

    return 0;
}

int escribirPrimosMenores(const int cota_superior2, const int PRIMO_MENOR){
    int inicio = cota_superior2 - 1;
    int primoMenor = 0;
    int contador = 0;
    
    for(int i = inicio; i >= 2; i--){
        primoMenor = esPrimo(i);
        if(primoMenor != 0){
            cout << primoMenor << " " ;
            contador++;
        }
    }

    return contador;
}

int esPrimo(int numero)
{
    int contador = 0;   // Es numero primo si solo tiene solamente dos divisores pero no mas ni menos.
    for (int i = numero; i >=1 ; i--)
    {
        if ((numero % i) == 0)
        {
            contador++;

        }
    }

    if((contador == 2)){
        return numero;
    }

    return 0;
       
}
