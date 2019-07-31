# Sizes and Arrays

La función `sizeof()` devuelve el tamaño en funcion de lo que ocupe el tipo de dato.
Por ejemplo un `int` ocupa 4 bytes es por eso que si hacemos un `sizeof(int[])` el
resultado nos indicará la cantidad de __bytes__ que ocupa el array. Si queremos saber
la cantidad de elementos que tienen tendremos que dividir el resultado por `sizeof(int)`
(cuanto ocupa cada uno).

Los `strings` no existen como tal, son arrays de `char` y siempre tienen un caracter
oculto indicando el final `\0`.

En este ejercicio me pasó algo que explica bien los problemas con los punteros. Estaba
recorriendo la variable `full_name` y sin querer puse en el bucle `for` que mostraba
los caracteres como límite el tamaño de la variable `my_name`. y esto es lo que ocurrió.

```c
char full_name[] = {
    'Z', 'e', 'd',
    ' ', 'A', '.', ' ',
    'S', 'h', 'a', 'w', '\0'
}
char my_name[] = "This is my name";

int my_name_size = sizeof(my_name);

printf("My name size: %d\n", size);

for(int i = 0; i < my_name_size; i++)
{
    printf("%c", full_name[i]);
}

// output
My name size: 16
Zed A. Shaw This
```

Mostró la variable `full_name` y el inicio de `my_name`.

Esta es la razón por la que nos avisan de que tenemos que tener cuidado con los
punteros. Podemos leer de memoria datos que aparentemente están "bien" porque nada
ha fallado pero realmente ser datos que estaban en memoria. Esta vez hemos tenido
suerte y ha sido otra variable que teníamos declarada pero no siempre es así.

- - -

Cuando dicen que hay que tener cuidado con los punteros en C se refieren a cosas como esta. 

Tengo este codigo donde declaro dos variables `full_name` y `my_name` y a la hora de recorrer `full_name` me confundo y en el bucle `for` le pongo como límite el tamaño de la variable `my_name`.

```c    
char full_name[] = {
    'Z', 'e', 'd',
    ' ', 'A', '.', ' ',
    'S', 'h', 'a', 'w', '\0'
}
char my_name[] = "This is my name";

int my_name_size = sizeof(my_name);

printf("My name size: %d\n", size);

for(int i = 0; i < my_name_size; i++)
{
    printf("%c", full_name[i]);
}
printf("\n");
return 0;
```

C no se queja a la hora de compilarlo y ejecutarlo, pero por pantalla muestra esto.

```c
My name size: 16
Zed A. ShawThis
```

No se queja en ningún momento pero ha mostrado la variable `full_name` y el principio de la variable `my_name` porque hemos tenido suerte y estaba la siguiente en memoria, pero no tiene porque pasar. Podría haber pasado que mostrase otros valores aleatorios que estaban en memoria.

Es por esto que tenemos que ser cuidadosos con los punteros y saber como usarlos correctamente.

- - - 

En C no existen los `string` en su lugar se usan `arrays` de caracteres. Uno de los problemas que esto plantea es que  la variable de "*string*" realmente es un puntero al primer caracter y, si tratamos de asignar un nuevo valor, no podremos hacerlo como en otros lenguajes.

```c
char name[] = "Zedy";
// error: assignment to expression with array type
name = "Pepe";
```

Podremos hacerlo mendiante una libreria llamada `string.h`. 

```c
#include <string.h>

char name[] = "Zedy";
strcpy(name, "Pepe");
```

Además si tenemos un `array` de tamaño 4 (más carácter de final) por ejemplo y queremos actualizarlo a otro que sea de mayor tamaño estaremos generando problemas. 

Al crear la variable para un array de tamaño 4 al principio si ahora la asignamos para una de tamaño 6 lo que estaremos haciendo es borrando lo que estaba a continuación en la memoria con los dos caracteres de más y no podemos saber si este dato se mantendrá hasta que lo usemos o la variable que lo tiene reservado lo sobrescribirá y nos borrará el final. O si hemos borrado alguna información relevante sin darnos cuenta.

El compilador nos avisará con un warning.

```c
#include <string.h>

char name[] = "Zedy";

// warning: ‘__builtin_memcpy’ writing 7 bytes into a region of size 5 overflows the destination [-Wstringop-overflow=]
//      strcpy(name, "Pepito");
strcpy(name, "Pepito");
```

En este post de [Stackoverflow][strcpy-problem] lo explican bien.

[strcpy-problem]: https://stackoverflow.com/a/50424373/5732392
[strcpy-docu]:http://port70.net/~nsz/c/c11/n1570.html#7.24.2.3p2
