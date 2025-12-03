# EXPLICACION DE ALGORITMOS IMPORTANTES
--- 
## Algoritmo 1: DIGITO MAGICO

Este algoritmo se basa en la ***RAIZ DIGITAL*** o tambien conocido como ***RESIDUO DIGITAL*** de un numero entero positivo.
La `Raiz digital` de un numero entero no negativo es el `UNICO DIGITO` resultante de un proceso `ITERATIVO` de sumar los digitos de ese numero hasta que se obtiene un numero de tan solo *una cifra*. Es decir, ***un valor entre 0 y 9***.

***IMPORTANTE***
> Si el numero es de tan solo una cifra, es decir, que ese numero sea de 1 a 9, entonces no hara su digito magico ya que 
> su digito magico resultante seria el propio numero.

Para realizar este algoritmo se da uso de dos funciones:
1. `sumaDigitos(int n);`
2. `esDigitoMagico(int n);`

**FUNCION esDigitoMagico(). (controlador)**
> Esta funcion se basa en hacer la suma de los digitos que son mayores a 9. Es decir, tiene una condicion:
>
>   1. Si `valor` no es mayor a 9, entonces  no haces nada. **Devuelve el valor tal cual es**.
>
>   2. Si `valor` si es mayor a 9, entonces es un valor de mas de una cifra. **Hace digito magico**.

**FUNCION sumaDigitos. (operador)**
> Esta funcion depende del controlador *(funcion esDigitoMagico())* .
> Esta funcion tendra un valor que sera la suma de sus digitos -> `int suma = 0;`
>
> La funcion *esDigitoMagico()* le pasara el valor que es mayor a 9. `valor de dos cifras`. Con ese valor hara las
> operaciones necesarias que seran:
>
>   1. Si `residuo o valor n` es mayor a 0, entonces  repites. **Siempre su residuo debe ser menor a 0 para asi**.
>              
>   El valor n que es el valor que le proporciona la anterior funcion tiene que ser igual a 0, ya que durante
>   su desarrollo se iran quitando valores de la cifra y si por ejemplo que da un 4 y se le quita ese 4 entonces queda 0.
>
>   - La variable suma es quien sumara todos esas cifras cogiendo siempre la ultima -> `suma += n%10;`
>   - La variable n lo que hara es quitar su ultima cifra ya sumada -> `n /= 10`;
>   - Esto se repetira hasta que la variable n se quede sin nada para quitar, es decir, cuando n = 0;
>
>   2. Si `residuo o valor n` ya no es mayor a 0, entonces devuelves el digito magico. **Termina y devuelve**.
> 
>   Finalmente lo que se retornara es esa suma que siempre sera menor a 9.

***CODIGO C++ SOBRE EL DIGITO MAGICO***
```cpp
    int esDigitoMagico(int n){  
        while(n > 9){
            n = sumaDigitos(n);
        }
        return n;
    }

    int sumaDigitos(int n){
        int sumaDigito = 0;
        while(n > 0){
            suma += n%10;
            n /= 10;
        }
        return sumaDigito;
    }
```
---
## Algoritmo 2: BUSQUEDA EN ARRAYS
Este algoritmo se basa en la ***BUSQUEDA DE ALGUN ELEMENTO*** ubicado dentro del ***ARRAY***.
La forma de poder encontrar este elemento, es recorriendo el array de manera que si cumple la condicion pare de `ITERAR` y poder asi mostrar todos lo elementos anteriores incluido el que se estaba buscando.
A esto se le denomina como `ESQUEMA DE BUSQUEDA DE ELEMENTOS EN UN ARRAY`. Este esquema es fundamental cuando lo que quieres es buscar el elemento y cuando lo encuentras solamente dejas de iterar. 
Para la demostracion de este algoritmo se dara uso del bucle `WHILE`.

El bucle `WHILE` sera el inicio de nuestro esquema de busqueda, donde antes deberemos declarar una variable `INDICE` para poder recorrer todo el array sin problemas. 
El `ESQUEMA DE BUSQUEDA EN ARRAY` se dara de la siguiente forma:
1. Creacion de las variables `int indice = 0;` y `bool encontrado = false;`
2. Condicion del while: `((indice < MAX) && !encontrado)`
Esta condicion del bucle while es importante para poder recorrer el array sin ningun problema, sus condiciones son las siguientes:
- Seguiras iterando siempre y cuando el ***INDICE*** no sea mayor al limite ***MAXIMO***, ya que si lo es indicara que hemos llegado al final de la secuencia.
- Seguiras iterando siempre y cuando la variable ***ENCONTRADO*** sea falsa, es decir, que no se haya encontrado ese valor.
*Estas condiciones siempre iran juntas y si una de las dos se rompe, entonces sale del while*.
3. Condicional, normalmente se suele crear un condicional de tipo if o un operador ternario que sirve para saber que hacer si encontramos `X` valor.
Este if lo que hara es que **SI SE CUMPLE LA CONDICION** entonces cambiaras el valor de ***ENCONTRADO*** a true y dejaras de iterar.
Si la condicion no se cumple entonces sumas el valor del ***INDICE***.

> A continuacion se mostrara un ejemplo basico donde se hara el uso del ***ESQUEMA DE BUSQUEDA DE UN ELEMENTO DE UN ARRAY*** de numeros. El objetivo de esta 
> funcion es encontrar el numero que sea menor a 5 pero con estas condiciones.
>   1. Siempre se mostrara los elementos junto a su posicion.
>   2. Cuando se encuentre dicho elemento que cumpla la condicion, lo que hara sera parar de iterar y mostrar que se ha encontrado.
>   3. Todo esto debera realizarse de manera que no siga recogiendo datos basura, solo lo necesario hasta encontrar el numero.

***CODIGO C++ SOBRE EL ESQUEMA DE BUSQUEDA DE UN ELEMENTO EN UN ARRAY***
```cpp
    // fuera del main 
    const int MAX = 10;
    typedef int tArrayNumeros[MAX];

    int main(){
        tArrayNumeros a;
        buscarDigito(a);
        return 0;
    }

    void buscarDigito(tArrayNumeros a){  
        int indice = 0;
        bool encontrado = false;
        while((indice < MAX) && !encontrado){
            if(a[indice] < 5){
                encontrado = true;
                cout << "Se encontro el numreo en la posicion :" << indice << " cuyo valor es: " <<a[indice];
            }else{
                indice++;
                cout << "Posicion: " << indice << " valor: " << a[indice] << endl;
            }
        }
    }
```



