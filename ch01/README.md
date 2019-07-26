## Usando el Make

Podemos compilar nuestro primer ejercicio usando `make ex1` o `CFLAGS="-Wall" make ex1`.

Cuando usamos la primera opción, le estamos diciendo al `make` "Quiero crear un fichero 
con el nombre de `ex1`". Y el programa sigue el siguiente flujo:

1. Existe un fichero llamado `ex1` ahora mismo?
2. No. Vale, hay algún otro fichero que empiece por `ex1`?
3. Si. Se llama `ex1.c`? Se como compilar ficheros `.c`?
4. Si. Entonces voy a ejecutar este comando `cc ex1.c -o ex1` para compilarlo
5. Te voy a crear un `ex1` usando `cc` para construirlo desde `ex1.c`

Normalmente `make` ejecuta `cc` con la opción `-Wall` para que muestre todos los
warnings.

IMPORTANTE: en el `Makefile` no debemos mezclar espacios y tabulaciones, solamente
tabulaciones.

- - -

Si no tabulamos despues del `clean` por ejemplo nos saltará este error.

`Makefile:4: *** missing separator.  Stop.`

- - -

Si no usamos tabulaciones y ponemos espacios nos indicará que estamos poniendo
espacios y parará la compilación, debemos corregirlo antes de seguir.
