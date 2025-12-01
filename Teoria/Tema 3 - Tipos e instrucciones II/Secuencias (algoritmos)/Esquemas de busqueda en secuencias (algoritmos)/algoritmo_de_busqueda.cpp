/**
 * ALGORITMO IMPORTANTE SOBRE BUSQUEDA EN SECUENCIAS.
 * En cuanto a algoritmos de busqueda, se dara uno que es bastante fundamental en cuanto 
 * a busqueda secuencial.
 * 
 * Este esquema de busqueda se basara mediante el siguiente titulo: LOCALIZACION DEL PRIMER ELEMENTO CON UNA PROPIEDAD.
 * A continuacion mostrare los pasos que se debe seguir para completar dicho esquema de busqueda:
 * 
 * 1- INICIALIZACION 
 * Lo que se hace en este esquema es definir donde comenzar la busqueda y se establece una forma de saber si ya se encontro.
 * 
 * Las variables tipicas de este tipo de esquemas suelen ser o punteros o una bandera, flag o centinela de tipo booleana
 * que se inicializara de tipo encontrado = falso pero que cambiara cuando se encuentre.
 * 
 * 2- CICLO DE BUSQUEDA (nucleo del algoritmo)
 * En cuanto al nucleo del algoritmo se basara en que hacer mientras que no se encuentre el elemento.
 * Es IMPORTANTE saber que la condicion para que el ciclo continue debe ser DOBLE :
 *          1- Mientras NO se encuentre el elemento 
 *          2- Mientras que NO estemos/encontremos al final de la secuencia (es decir que aun queden elementos por revisar) eso es que el valor no debe ser el valor del centinela
 * Ademas, tambien debremos realizar despues dos pasos: Obtener el siguiente elemento o comprobar si el elemento satisface la condicion.
 * 
 * 3- FINALIZACION 
 * Una vez llegado a la finalizacion pueden haber ocurrido dos cosas:
 *      -Si el elemento se encontro, se procede a tratar ese elemento encontrado (ocurre porque la condicion se cumplio)
 *      -Si el elemento NO fue encontrado, simplemente procedemos a indicar que no se encontro devolviendo algun valor especial como -1 o null.
 *       (este ultimo ocurre porque se llego al final de la secuencia)
 * 
 * 
 * 
 */