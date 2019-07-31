A la hora de trabajar con punteros podemos hacerlo de varias formas. A continuación dejo varios ejemplos de como recorrer los punteros.

Creamos los arrays que vamos a recorrer y una variable contador que nos indica cuantos elementos tenemos en el array de edades.

```c
int ages[] = { 23, 43, 12, 89, 2 };
char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
};

int count = sizeof(ages) / sizeof(int);
int i = 0;
```

La primera forma de recorrer es usando los arrays como tal con la misma variable que hemos declarado.

```c
for (i = 0; i < count; i++) {
    printf("%s has %d years alive.\n", names[i], ages[i]);
}
```

Para los siguientes ejemplos declaramos los punteros a partir de las variables que tenemos, con esto apuntamos al inicio de la variable. Es importante el casteo porque de esta forma el sistema sabe que tipo de puntero es y sabe cuanto tiene que avanzar cada vez, por ejemplo.

```c
int *pointer_age = (int *)ages;
char **pointer_name = (char **)names;
```

De esta manera cogemos el puntero y avanzamos la posición hasta el siguiente elemento de la lista con la operación `+ i`, al haber hecho el casteo en el paso anterior el sistema sabe cuantas posiciones en memoria tiene que avanzar para estar posicionado en el elemento siguiente de la lista en cuestión. Con `*` lo que hacemos es que el sistema lea y nos de el valor que está en la posición de memoria indicada en lugar de pintar la posición de memoria en sí.

```c
for (i = 0; i < count; i++) {
    printf("%s is %d years old.\n",
            *(pointer_name + i), *(pointer_age +i));
}
```

Con la siguiente opción recordamos que no dejan de ser arrays, podemos trabajar con ellos como tal.

```c
for (i = 0; i < count; i++) {
    printf("%s is %d years old again.\n", pointer_name[i], pointer_age[i]);
}
```

Esta última opción es para recordar que siempre se pueden complicar las cosas, esto funciona. En un bucle `for` usa dos variables y como condición de parada `(pointer_age - ages) < count`.

En la primera parte de la condición de parada `pointer_age - ages` nos devuelve como resultado el índice del elementto en el que nos encontramos. En el estado inicial es 0, en la primera iteración 1 y así hasta llegar a 5, nuestro `count`.

```c
for (pointer_name = names, pointer_age = ages; (pointer_age - ages) < count; pointer_name++, pointer_age++) {
    printf("%s lived %d years so far.\n", *pointer_name, *pointer_age);
}
```
