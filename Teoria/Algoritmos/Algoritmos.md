# EXPLICACION DE ALGORITMOS IMPORTANTES

# 🧭 Índice de Algoritmos

- [**_Algoritmo 1: Dígito Mágico_**](#algoritmo-1-digito-magico)
- [**_Algoritmo 2: Búsqueda en Arrays_**](#algoritmo-2-busqueda-en-arrays)
- [**_Algoritmo 3: Búsqueda de Secuencia en Archivo.txt_**](#algoritmo-3-busqueda-de-secuencia-de-caracteres-en-un-archivo.txt)
- [**_Algoritmo 4: Libreria Iomanip - Matriz Bidimensional_**](#algoritmo-4-iomanip---matriz-bidimensional---tabla-de-multiplicar)

---

## Algoritmo 1: DIGITO MAGICO

Este algoritmo se basa en la **_RAIZ DIGITAL_** o tambien conocido como **_RESIDUO DIGITAL_** de un numero entero positivo.
La `Raiz digital` de un numero entero no negativo es el `UNICO DIGITO` resultante de un proceso `ITERATIVO` de sumar los digitos de ese numero hasta que se obtiene un numero de tan solo _una cifra_. Es decir, **_un valor entre 0 y 9_**.

**_IMPORTANTE_**

> Si el numero es de tan solo una cifra, es decir, que ese numero sea de 1 a 9, entonces no hara su digito magico ya que
> su digito magico resultante seria el propio numero.

Para realizar este algoritmo se da uso de dos funciones:

1. `sumaDigitos(int n);`
2. `esDigitoMagico(int n);`

**FUNCION esDigitoMagico(). (controlador)**

> Esta funcion se basa en hacer la suma de los digitos que son mayores a 9. Es decir, tiene una condicion:
>
> 1. Si `valor` no es mayor a 9, entonces no haces nada. **Devuelve el valor tal cual es**.
>
> 2. Si `valor` si es mayor a 9, entonces es un valor de mas de una cifra. **Hace digito magico**.

**FUNCION sumaDigitos. (operador)**

> Esta funcion depende del controlador _(funcion esDigitoMagico())_ .
> Esta funcion tendra un valor que sera la suma de sus digitos -> `int suma = 0;`
>
> La funcion _esDigitoMagico()_ le pasara el valor que es mayor a 9. `valor de dos cifras`. Con ese valor hara las
> operaciones necesarias que seran:
>
> 1. Si `residuo o valor n` es mayor a 0, entonces repites. **Siempre su residuo debe ser menor a 0 para asi**.
>
> El valor n que es el valor que le proporciona la anterior funcion tiene que ser igual a 0, ya que durante
> su desarrollo se iran quitando valores de la cifra y si por ejemplo que da un 4 y se le quita ese 4 entonces queda 0.
>
> - La variable suma es quien sumara todos los utlimos digitos del numero n -> `suma += n%10;`
> - La variable n lo que hara es quitar su ultima ultimo digito ya sumada -> `n /= 10`;
> - Esto se repetira hasta que la variable n se quede sin nada para quitar, es decir, cuando n = 0;
>
> 2. Si `residuo o valor n` ya no es mayor a 0, entonces devuelves el digito magico. **Termina y devuelve**.
>
> Finalmente lo que se retornara es esa suma que siempre sera menor a 9.

**_CODIGO C++ SOBRE EL DIGITO MAGICO_**

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

Este algoritmo se basa en la **_BUSQUEDA DE ALGUN ELEMENTO_** ubicado dentro del **_ARRAY_**.
La forma de poder encontrar este elemento, es recorriendo el array de manera que si cumple la condicion pare de `ITERAR` y poder asi mostrar todos lo elementos anteriores incluido el que se estaba buscando.
A esto se le denomina como `ESQUEMA DE BUSQUEDA DE ELEMENTOS EN UN ARRAY`. Este esquema es fundamental cuando lo que quieres es buscar el elemento y cuando lo encuentras solamente dejas de iterar.
Para la demostracion de este algoritmo se dara uso del bucle `WHILE`.

El bucle `WHILE` sera el inicio de nuestro esquema de busqueda, donde antes deberemos declarar una variable `INDICE` para poder recorrer todo el array sin problemas.
El `ESQUEMA DE BUSQUEDA EN ARRAY` se dara de la siguiente forma:

1. Creacion de las variables `int indice = 0;` y `bool encontrado = false;`
2. Condicion del while: `((indice < MAX) && !encontrado)`
   Esta condicion del bucle while es importante para poder recorrer el array sin ningun problema, sus condiciones son las siguientes:

- Seguiras iterando siempre y cuando el **_INDICE_** no sea mayor al limite **_MAXIMO_**, ya que si lo es indicara que hemos llegado al final de la secuencia.
- Seguiras iterando siempre y cuando la variable **_ENCONTRADO_** sea falsa, es decir, que no se haya encontrado ese valor.
  _Estas condiciones siempre iran juntas y si una de las dos se rompe, entonces sale del while_.

3. Condicional, normalmente se suele crear un condicional de tipo if o un operador ternario que sirve para saber que hacer si encontramos `X` valor.
   Este if lo que hara es que **SI SE CUMPLE LA CONDICION** entonces cambiaras el valor de **_ENCONTRADO_** a true y dejaras de iterar.
   Si la condicion no se cumple entonces sumas el valor del **_INDICE_**.

> A continuacion se mostrara un ejemplo basico donde se hara el uso del **_ESQUEMA DE BUSQUEDA DE UN ELEMENTO DE UN ARRAY_** de numeros. El objetivo de esta
> funcion es encontrar el numero que sea menor a 5 pero con estas condiciones.
>
> 1. Siempre se mostrara los elementos junto a su posicion.
> 2. Cuando se encuentre dicho elemento que cumpla la condicion, lo que hara sera parar de iterar y mostrar que se ha encontrado.
> 3. Todo esto debera realizarse de manera que no siga recogiendo datos basura, solo lo necesario hasta encontrar el numero.

**_CODIGO C++ SOBRE EL ESQUEMA DE BUSQUEDA DE UN ELEMENTO EN UN ARRAY_**

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

## Algoritmo 3: BUSQUEDA DE SECUENCIA DE CARACTERES EN UN ARCHIVO.TXT

Este algoritmo nos sirve para poder realizar la **_BUSQUEDA DE MAS DE UN CARACTER EN UN ARCHIVO DE TEXTO_**.
A diferencia de la funcion `find()` que es una funcion optima para encontrar una **Cadena de caracteres** en un archivo de texto, en este algoritmo se usara el algoritmo de `cambio de variable`.

Este algoritmo tendra el siguiente esquema (_este esquema puede variar segun el enunciado_)

**_CODIGO C++ SOBRE EL ESQUEMA DE BUSQUEDA DE UNA SECUENCIA DE CARACTERES EN UN ARCHIVO.TXT_**

```cpp
    ifstream archivo;
    char c, anterior = ' ', actual;
    int indice = 0;
    bool encontrado = false;

    archivo.open(nombreArchivo);

    if (archivo.is_open())
    {
        c = archivo.get();
        a[indice] = c;
        actual = a[indice];

        while ((indice < MAX_CHAR) && !encontrado)
        {
            if (anterior == '.' && actual == ' ')
            {
                encontrado = true;
                cout << "Se ha leido : " << indice - 1 << " caracteres del fichero." << endl;
                cout << "Se han encontrado los dos caracteres que se buscaban: punto y espacio." << endl;
            }
            else
            {
                anterior = actual;
                indice++;
                c = archivo.get();
                a[indice] = c;
                actual = a[indice];
            }
        }
        if(!encontrado && indice == MAX_CHAR){
            cout << "No se ha podido encontrar la secuencia";
        }

        recorrerCaracteresArray(a, indice);
        archivo.close();
    }
    else
    {
        cout << "Error al abrir el archivo.txt";
    }
```

_Nota importante_

> Se puede imprescindir del trozo `c=archivo.get() | a[indice] = c | actual = a[indice]`. Para una mejor
> implementacion de espacio se puede usar directamente sin usar `c` -> `archivo.get(a[indice])` y despues
> `actual = a[indice]`. Asi poder quitar una variable sobrante.

**EXPLICACION DEL CODIGO**
Este codigo usa: **_RECORRIDO DE UN ARRAY CON WHILE, ESQUEMA DE BUSQUEDA DE UN ARRAY(VARIANTE TXT), CAMBIO DE VARIABLE Y LECTURA DE UN ARCHIVO.TXT_**.

Explicacion de pasos a seguir:

1. _Lectura de archivo.txt_
   - Abrimos el archivo
   - Leemos el primer caracter
   - Importante inicializar antes la variable `anterior`, esta se inicializa antes debido a que no hay ningun valor anterior al actual.
   - Una vez incializado entrar al bucle.
2. _Esquema de busqueda de array_
3. _Recorrido de array con while_
4. _Condicion de cambio de variable_

## Algoritmo 4: IOMANIP - MATRIZ BIDIMENSIONAL - TABLA DE MULTIPLICAR

Este algoritmo es importante en cuanto a la impresion de elementos en forma de tabla y organizacion.
Se dara el uso de la libreria **_`<iomanip>`_**, cuya libreria nos dejara dar uso a la funcion **_setw(N)_**.

### **_FUNCION SETW(N)_**:

Esta funcion se basa en hacer espacios entre los cout donde creara una especie de dimension segun el `tamaño N`. Es como hacer una habitacion de `X` espacio, donde si colocamos un **N = 5** este creara un espacio de hasta como mucho 5 caracteres. Es decir, que si guardamos el numero 1234 quedara de la siguiente manera:

> \_1234

Y cada vez que vayamos metiendo mas caracteres se ira llenando cada vez mas dicha habitacion o anchura, por ejemplo vamos a dar dos numeros el _23_ y el _12345_.

> \_ \_ \_ 23
> 12345

_Si ademas ponemos un numero que sobrepase dichar anchura no pasa nada, utilizara lo que necesita sin cortar el numero_.

### **_MATRIZ BIDIMENSIONAL - TABLA DE MULTIPLICAR BASICA_**

En cuanto al algoritmo de la **_MATRIZ BIDIMENSIONAL_**, usaremos la logica de los for anidados.
Debemos pensar que una **_MATRIZ_** esta compuesta por `filas` y `columnas`, es decir, un **_(N x N)_**.
Si sabemos la anchura que queremos deberemos poner el valor de N como `constante`. Si no lo sabemos entonces lo pondremos como un valor N de tipo `entero`.

Tenemos que saber las funcionalidades de los dos for:

1. _FILAS `for(int i = 1; i <= N ; i++)`_.
   - Controla las filas y el primer valor del operando.
   - Al final de este siempre debe haber un `cout << endl;` para confirmar que se ha hecho bien la fila.
   - Si queremos realizar al final una suma de todo los valores obtenidos `SUMATORIO`, entonces usaremos una variable auxiliar de suma inicializada a cero para ir sumando cada vez que se opere.
2. _COLUMNAS `for(int j = 1; j <= N ; j++)`_.
   - Controla las columnas y el segundo valor del operando.
   - Este es el que va a tener siempre las operaciones, pues el valor de `i` siempre es estatico.
   - Realizara la operacion `(i X j)`.
   - Para imprimir el producto siempre usaremos la sentencia: **_`cout << setw(N) << operacion;`_**
   - Finalmente ira incrementando el sumatorio con el valor de la operacion.
3. _IMPRESION FINAL `Valor del sumatorio`_.
   - Para imprimir el valor del sumatorio simplemente usamos un **_`cout << setw(N) << SUMATORIO;`_**

**_CODIGO C++ SOBRE MATRIZ BIDIMENSIONAL - TABLA DE MULTIPLICAR_**

```cpp
    #include <iostream>
#include <iomanip>
using namespace std;

void tablaMultiplicar(const int N);

int main()
{
    int num = -1;
    while ((num < 1) || (num > 10))
    {
        cout << "Indique un numero del 1 al 10 para realizar la tabla de multiplicar correspondiente : ";
        cin >> num;
        if ((num < 1) || (num > 10))
        {
            cout << "Por favor introduzca un numero entre el 1 al 10" << endl;
        }
    }

    tablaMultiplicar(num);

    return 0;
}

// MATRIZ BIDIMENSIONAL
void tablaMultiplicar(const int N)
{
    for (int i = 1; i <= N; i++)
    {                     // controla las filas y el operando 1. REPRESENTA: el inicio de una nueva fila. Poner siempre un salto de linea al final.
        int sumaFila = 0; // Esto sirve para el sumatorio de cada fila. Esto se pone al final de cada fila.
        for (int j = 1; j <= N; j++)
        { // se ejecuta N veces por cada iteracion de i. REPRESENTA: impresion lateral, i es fija siempre en cada iteracion del bucle.
            int producto = i * j;
            cout << setw(N) << producto;
            sumaFila += producto;
        }
        cout << setw(N) << sumaFila;
        cout << endl;
    }
}
```

## Algoritmo 5: NUMEROS DE ARMSTRONG (SIMILAR A DIGITO MAGICO).

Este algoritmo es una estructura similar a la del digito magico, solamente que en este caso en vez de sumarlos deberan ser su cubos.
Segun este algoritmo, los **_tres digitos_** de un numero de **_tres cifras_**, la `SUMA` de sus `CUBOS` deberan ser igual al numero de tres cifras.
Para ello usaremos la funcion **_POW(n,3.0)_**.

**_Según Armstrong_**, solo tenemos 4 numeros que son numeros de Armstrong dentro del intervalo de tres cifras.

> Estos numeros serian el 153, 370, 371, 407

### **_EXPLICACION DE PARTES DEL ALGORIMTO_**

Este algoritmo tiene una serie de partes logicas que son las siguientes:

1. _SOLO NUMERO DE TRES CIFRAS `for(int i = 100; i <= 999 ; i++)`_.
   - Como sabemos, un numero de tres cifras son desde `100 a 999`, lo que esta fuera de ese intervalo o son de dos cifras o son de cuatro, cosa que no nos sirve para este algoritmo.
2. _¿Es Armstrong? `int esArmstrong(int n)`_.
   - Lo que hacemos en esta funcion es comprobar si ese numero de tres cifras es un numero de Armstrong, es decir, que cumpla la propiedad de que la suma de sus cubos sea igual al numero metido a la funcion. Si no es asi, entonces retorna 0. Debemos tener la condicion de que si retorna 0 que siga iterando hasta encontrar todos.
3. _SUMA CUBOS `int sumaCubos(int n)`_.
   - En esta funcion va a entrar siempre todos los numeros de 100 a 999, entonces ira haciendo la suma de los cubos de dichas cifras. **_`sumaCubos += (int)pow((n%10), 3.0))`_**.
   - Despues quitamos ese digito, **_`n /= 10;`_**.
   - Esto siempre se hara cuando el digito sea mayor a 0, si el digito es 0, es decir, que ya se le han quitado todas la cifras posibles, entonces ya se retorna la suma **_`return sumaCubos;`_**.
   - Esto lo devuelve a la funcion **_`int esArmstrong()`_**, que lo que hara sera una vez devuelvas ese numero lo compara, y si ese numero es igual al numero de tres cifras, `LO DEVUELVE`. Sino es asi retorna `0`.
4. _RELENAR ARRAY `hasta que ya encuentre cuatro numeros que son los unicos que hay`_.

**_CODIGO C++ SOBRE ALGORITMO SOBRE NUMEROS DE ARMSTRONG_**

```cpp
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Variables Globales
const int MINIMO_TRES_CIFRAS = 100;
const int MAXIMO_TRES_CIFRAS = 999;
const int NUMEROS_ARMSTRONG = 4; // solo hay 4 numeros de armstrong

// Estructuras
typedef int tArrayArmstrong[NUMEROS_ARMSTRONG];

// Prototipos
void rellenartArrayArmstrong(tArrayArmstrong array, const int MINIMO, const int MAXIMO, const int NUMEROS_ARMSTRONG);
int esNumeroArmstrong(int n);
int calcularDigitoArmstrong(int n);

int main()
{

    tArrayArmstrong arrayDeArmstrong;

    rellenartArrayArmstrong(arrayDeArmstrong, MINIMO_TRES_CIFRAS, MAXIMO_TRES_CIFRAS, NUMEROS_ARMSTRONG);

    cout << "Numeros de Armstrong encontrados:" << endl;
    for (int i = 0; i < NUMEROS_ARMSTRONG; i++)
    {
        cout << arrayDeArmstrong[i] << endl;
    }

    return 0;
}

void rellenartArrayArmstrong(tArrayArmstrong array, const int MINIMO, const int MAXIMO, const int NUMEROS_ARMSTRONG)
{
    int indice = 0;

    for (int i = MINIMO; i <= MAXIMO; i++)
    {
        int resultado = esNumeroArmstrong(i);
        if ((resultado != 0) && (indice < NUMEROS_ARMSTRONG))
        {
            array[indice] = resultado;
            indice++;
        }
        if (indice == NUMEROS_ARMSTRONG)
        {
            return;
        }
    }
}

int esNumeroArmstrong(int n)
{
    int sumaCubosCalculada = calcularDigitoArmstrong(n);
    if (sumaCubosCalculada == n)
    {
        return n;
    }
    else
    {
        return 0;
    }
}

int calcularDigitoArmstrong(int n)
{
    int digito;
    int sumaCubos = 0;
    int temp = n; // no hace falta pero por si acaso no queremos modificar n.

    while (temp > 0)
    {
        // obtener el ultimo digito
        digito = temp % 10;
        sumaCubos += (int)pow(digito, 3.0);
        temp /= 10;
    }
    return sumaCubos;
}
```
