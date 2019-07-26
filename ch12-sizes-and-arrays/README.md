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
