/**
 * A continuacion se mostrara el uso del algoritmo de busqueda para saber cuando fue el PRIMER DIA que se obtuvo unas ganancias mayores a 1000 euros en
 * esta primera semana.
 *
 * Es importante saber que aqui nuestro centinela sera el ultimo dia de la semana en este caso el domingo que la semana son 7 dias, entonces
 * para saber que no se esta en el final de la secuencia, lo que hacemos es decir que cada dia que vaya pasando, el centinela se va sumando, y si
 * sobrepasa el limite pues entonces habremos llegado al final de la secuencia, y si ademas no se ha encontrado, entonces el valor que retornara sera de -1.
 *
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
