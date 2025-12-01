/**
 * A continuacion se mostrara el uso del algoritmo de busqueda para saber cuando fue el PRIMER DIA que se obtuvo unas ganancias mayores a 1000 euros en
 * esta primera semana.
 *
 * ESTRUCTURA DE ALGORITMO DE BUSQUEDA EN ARRAYS
 * En este tipo de busqueda en arrays tendremos dos condiciones en el bucle WHILE : 
 *    1- Siempre nuestro centinela sera un INDICE = 0 (primer elemento del array siempre es 0) que se podra usar como INDICE del array 
 *    cuya condicion es que este sea MENOR al limite de elementos que puede tener nuestro array. 
 *    Esto se hace para comprobar si hemos llegado al final de la secuencia.
 *    
 *    2- La segunda condicion siempre sera que siga en el bucle siempre y cuando no se haya encontrado, se pone como (!encontrado)
 * 
 * Estas dos condiciones se deberan cumplir a la vez pues se trata de las dos condiciones fijas que siempre deben estar para tener buena praxis del algoritmo.
 * 
 * Dentro del bucle WHILE deberemos comprobar si se ha encontrado, eso lo hacemos con un IF para condicionarlo segun nos lo pidan.
 * Si se ha cumplido entonces se ha encontrado y el bucle saldra del while pues una de las dos condiciones para que no salga se ha roto (encontrado = true)
 * Si no se ha encontrado, entonces el indice se suma para comprobar el siguiente valor de la secuencia.
 * 
 * Si no se ha encontrado y la secuencia ha llegado a su fin entonces pondremos otro if que en este caso es, si no se ha encontrado entonces damos el valor de -1.
 * Si se ha encontrado devolvemos el valor del indice ya que es lo que buscabamos en si. Buscabamos ese indice del array que cumple con la condicion.
 * 
 * Finalmente, como lo que buscamos ese primer valor que sea mayor a algo y ese valor es el indice, pues ese valor de indice que no lo dara una funcion de 
 * tipo int. Lo que haremos sera cogerlo y ponerlo como indice del array para obtener ese valor encontrado.
 * 
 * IMPORTANTE SOBRE LOS ARRAYS, SIEMPRE ES BUENO PONER QUE CUANDO INTRODUCIMOS UN ARRAY EN UNA FUNCION QUE ES DE TIPO CONSTANTE PUES NO SE VA
 * A MODIFICAR Y ES PARA DEJARLO CLARO.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int LIMITE_DIAS = 7;
typedef double tVentasSemana[LIMITE_DIAS];

void rellenarVentas(tVentasSemana arrayVentas);
void mostrarVentas(tVentasSemana arrayVentas);
int buscarPrimerMayorVentas(const tVentasSemana arrayVentas);

int main()
{
   int indice;

   tVentasSemana arrayVentas;
   rellenarVentas(arrayVentas);
   mostrarVentas(arrayVentas);
   indice = buscarPrimerMayorVentas(arrayVentas);
   if(indice != -1){
      cout << "Se ha encontrado un primer valor que ha superado el valor de los 1000 euros " << endl;
      cout <<"DIA NUMERO " << indice + 1 << " -> " << arrayVentas[indice] << " EUROS > 1000 EUROS" << endl;
   }

   return 0;
}

void rellenarVentas(tVentasSemana arrayVentas)
{
   cout << "A continuacion, debera rellenar el array de ventas de la semana" << endl;
   for (int i = 0; i < LIMITE_DIAS; i++)
   {
      cout << "Dia de la semana numero " << i + 1 << " : " ;
      cin >> arrayVentas[i];
   }
   cout << "" << endl;
}
void mostrarVentas(tVentasSemana arrayVentas){
   cout << "A continuacion, se motrara todas las ventas de esta semana, desde el dia 1 hasta el dia 7 " << endl;
   for(int i = 0; i < LIMITE_DIAS ; i++){
      cout << "Dia de la semana numero " << i +1 << " se ha realizado una venta de un total de " << arrayVentas[i] << " EUROS." << endl;
   } 
}
int buscarPrimerMayorVentas(const tVentasSemana arrayVentas){
   
   int indice = 0;
   bool encontrado = false;

   while((indice < LIMITE_DIAS) && !encontrado){
      if(arrayVentas[indice] > 1000){
         encontrado = true;
      }else{
         indice++;
      }
   }

   if(!encontrado){
      cout << "No se ha encontrado ningun valor que supere los 1000 EUROS";
      return -1;
   }
   return indice;
}
