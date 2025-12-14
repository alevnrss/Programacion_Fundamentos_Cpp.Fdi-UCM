# LISTAS DE TAMAÑO VARIABLE
Las listas pueden ser de dos tipos:
1. **_Listas de tamaño fijo_**   
    - Todas las posiciones del array se encuentran ocupadas
    - Tamaño del array es igual a la longitud de la secuenca.
2. **_Listas de tamaño variable_**   
    - No todas las posiciones del array se encuentran ocupadas
    - Tamaño del array es mayor o igual a la longitud de la secuencia

## LISTAS DE TAMAÑO VARIABLE CON ARRAYS
Con este tipo de listas podemos realizar 4 tipos de funcionalidades:
1. Recorrido.
2. Busquedas.
3. Inserccion de nuevos elementos.
4. Eliminacion de elementos existentes.

***IMPORTANTE PUNTOS 3 Y 4: ***
> Tanto en la *INSERCCION* como en la *ELIMINACION* de elementos de una lista de tamaño variable, se puede realizar dichas acciones o de un elemento final o de un
> elemento que el propio usuario quiera. 

A continuacion se vera distintos tipos de esquemas tanto de busqueda como de recorrido para arrays con centinela y para structs con array y contador.

## ARRAYS CON CENTINELA
El proposito de un centinela en un array es evitar recorrer hasta la maxima posicion del array. 
Es genial para cuando un array no se encuentra completamente lleno o simplemente no se quieran recorrer todos los valores del array.

### 1. Recorrido y Busqueda (Esquema de recorrido y busqueda de arrays con centinela)
Este algoritmo es identico al esquema de recorrido y busqueda de un array. Sin embargo, la diferencia es que estas funciones solamente recorreran hasta el centinela y no todo el array completo(VALOR MAXIMO).

**EJEMPLO 1**
En este ejemplo se muestra como recorrer un array hasta un centinela. Despues se devolveria el indice para despues usarlo como limite al mostrar el array.

```cpp
const int MAXIMO = 10;
typedef int tArray[MAXIMO];

int main(){
    tArray array;      
}

int recorrer(tArray array){
    int indice = 0;
    int centinela = -1;

    while(array[indice] != centinela){
        indice++;
    }

    return indice;  // Sirve como valor maximo para despues mostrarlo
}
```

**EJEMPLO 2**
En este segundo ejemplo se muestra como encontrar (esquema de busqueda) un valor en un array y recorrerlo hasta un centinela y no hasta el final del array.

```cpp
const int MAXIMO = 10;
typedef int tArray[MAXIMO];

int main(){
    tArray array;      
}

bool buscar(tArray array){
    int indice = 0; // Indice importante para iterar
    bool encontrado = false; // servira para salir del programa siempre y cuando se llegue a encontrar
    int centinela = -1; // valor que marca el final del array
    double buscar ; // variable la cual servira para buscar un elemento double en la lista. Se le pedira al usuario introducirlo

    cout << "Introduce el valor que desea buscar en el array: " << endl;
    cin >> buscar;
    

    while((array[indice] != centinela) && !encontrado){
        if(array[indice] == buscar){
            encontrado = true;
        }else{
            indice++;
        }
    }

    return encontrado;
}
```

## STRUCTS CON ARRAY Y CONTADOR
El uso de structs con array y contador es un concepto que sirve poder tratar un array de tamaño fijo como una lista dinamica, pero siempre manteniendo el control de CUANTOS elementos hay en la lista.
Imaginemos todo esto como una variable que tiene diversas partes.
- El struct es el contenedor que agrupa el array y el contador en una sola unidad logica y se pasa a las funciones como un solo parametro.
- El array es el almacenamiento fisico, este guarda los elementos y define la capacidad maxima.
- El contador es la longitud logica, este indica la cantidad de elementos utiles que hay actualmente en el array.

**CONTROL DE LA LONGITUD LOGICA (contador)**
> Este es el uso primordial que se le da al contador. Ya que siempre nos permitira saber cuantos elementos hay en la lista.
> Si por ejemplo llegamos a tener 15 elementos de 100, pues bastaria con recorrer hasta ese contador. (i < lista.contador)
> Tambien sirve como seguridad y prevencion de errores, mas que nada cuando se trata de añadir un elemento. Siempre que queramos añadir un elemento lo mejor siempre
> sera tratar de comprobar si nuestro contador es igual o mayor al limite maximo del array. Si es asi, entonces no dejara introducir ningun otro elemento. 

### 1. Recorrido de un struct con array y contador (FOR / WHILE)
Siempre que queramos recorrer la estructura se realizara un esquema similar a los siguientes:

***ESQUEMA DE RECORRIDO CON BUCLE FOR Y WHILE***
```cpp
typedef struct{
    tArray elemento;
    int contador;
}tLista;

int main(){
    tLista lista;

    recorrerFor(lista);
}

void recorrerFor(const tLista &lista){
    double elemento;    // Variable auxiliar para meter los datos que obtengamos al recorrer la lista. No hace falta utilizar uno si no se realizara ningun proceso.

    for(int i = 0 ; i < lista.contador ; i++){
        cout << "Elemento de la lista en la posicion " << i << ": " << lista.elemento[i];

        // si se quiere procesar el elemento se puede o no utilizar el elemento auxiliar
        elemento = lista.elemento[i];
        cout << elemento << endl;
    }
}

void recorrerWhile(const tLista &lista){
    int indice = 0;

    while(indice < lista.contador){
        cout << lista.elemento[indice];
        indice++
    }
}
```

### 2. Esquema de busqueda en un struct con array y contador (WHILE)
Siempre que queramos realizar una busqueda de algun elemento en una lista, realizaremos el siguiente esquema de busqueda:

```cpp
typedef struct{
    tArray elemento;
    int contador;
}tLista;

int main(){
    tLista lista;
    bool elemento = false;

    elemento = busqueda(lista);
}

bool busqueda(const tLita &lista){
    bool encontrado = false;
    int buscado;
    int indice = 0;

    while((indice < lista.contador) && !encontrado){
        if(lista.elemento[indice] == buscado){
            encontrado = true;
        }
        else{
            indice++;
        }
    }

    return encontrado;
}
```

### 3. Inserccion de nuevos elementos en la lista de tamaño variable.
Al ser de tamaño variable se puede realizar diferentes operaciones, entre ellas estarian: INSERCCION E ELIMMINACION de elementos.
#### INSERCCION DE ELEMENTOS en una lista de tamaño variable
Para realizar esta funcion debemos antes saber lo que realmente queremos:
- Si insertar el elemento por el final.
- Si insertar el elemento en una posicion que escoga el usuario.

***Para insertar un nuevo elemento por el final:***
Hay que asegurarse siempre que haya sitio en la lista `lista.contador < MAXIMO`. Ya que no se puede insertar si la lista esta llena.
Se trata de una operacion que se puede realizar en tan solo 2 sencillos pasos: 
1. Colocar el elemento nuevo en el primer hueco disponible. `lista.elemento[lista.contador] = elementoUser`.
2. Incrementar el contador de la lista. `lista.contador++;`.

```cpp
if(lista.contador < MAXIMO){
    lista.elemento[lista.contador] = elemento;
    lista.contador++;
}else{
    cout << "No se puede rellenar el array de elementos. LLENO";
}
```

***Para insertar un nuevo elemento en una posicion escogida por el usuario:***
Hay que asegurarse siempre que haya sitio en la lista `lista.contador < MAXIMO`. Ya que no se puede insertar si la lista esta llena.
Se trata de una operacion que se puede realizar en tan solo 3 sencillos pasos: 
1. Abrir hueco en el array. DESPLAZAR A LA DERECHA EL ELEMENTO QUE ESTA EN LA POSICION Y TODOS LOS QUE HAY DETRAS DE EL.*BUCLE FOR()*. Empezamos en la ultima posicion y vamos hacia atras.
2. Colocar el elemento en la nueva posicion.
3. Incrementar el contador de la lista. `lista.contador++;` 

```cpp
int nuevo;
int posicion;
cin >> posicion;

if(lista.contador < MAXIMO){
    for(int i = lista.contador; i > posicion; i--){ // cuando i ya no sea mayor, sino que sea igual, entonces paras.
        lista.elemento[i] = lista.elemento[i - 1]; // El elemento anterior pasa a ser el elemento actual. Es decir, si estamos en el 6, el 5 pasa a ser ahora el 6.
    }
    lista.elemento[posicion] = nuevo;
    lista.contador++;
}
```

#### ELIMINACION DE ELEMENTOS en una lista de tamaño variable
Para realizar esta funcion debemos antes saber lo que realmente queremos:
- Si eliminar el utlimo elemento existente.
- Si eliminar el elemento existente en una posicion que escoga el usuario.

***Para eliminar un elemento por el final:***
Hay que asegurarse siempre que no este vacia la lista. Esta simplemente se completa en un sencillo paso.
1. Eliminar el ultimo elemento de la lista simplemente restando el contador.

```cpp
if(lista.contador > 0){
    lista.contador--;
}
```

***Para eliminar un elemento en una posicion especifica:***
Hay que asegurarse siempre que no este vacia la lista. Esta simplemente se completa en 3 sencillos pasos.
1. Empezamos desde la posicion que queremos borrar hacia adelante. Como vamos a borrar un elemento, entonces ya de por si decimos que recorra hasta el contador actual menos uno ya que al llegar a la ultima poscion no habra mas elementos despues.
2. Ahora lo que hacemos es desplazar los elementos hacia la izquierda.
3. Finalmente restamos el contador porque ya se elimino el elemento en la primera iteracion.

```cpp
    int posicion;
    cin >> posicion;

    if(lista.contador > 0){
        for(int i = posicion; i < lista.contador - 1 ; i++){
            lista.elemento[i] = lista.elemento[i + 1];
        }
        lista.contador--;
    }else{
        cout << "La lista se encuentra vacia actualmente";
    }
```