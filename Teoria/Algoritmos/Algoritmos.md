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


