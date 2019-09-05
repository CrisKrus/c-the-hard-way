Es este capítulo te plantean el siguiente reto. Ver si eres capaz de por ti mismo
descubrir que es lo que hace el siguiente método para copiar cadenas de caracteres
respecto de una copia "normal"

```c
int normal_copy(char *from, char *to, int count)
{
    int i = 0;

    for (i = 0; i < count; i++) {
        to[i] = from[i];
    }
}

int duffs_device(char *from, char *to, int count)
{
    {
        int n = (count + 7) / 8;

        switch (count % 8) {
            case 0:
                do {
                    *to++ = *from++;
                    case 7:
                    *to++ = *from++;
                    case 6:
                    *to++ = *from++;
                    case 5:
                    *to++ = *from++;
                    case 4:
                    *to++ = *from++;
                    case 3:
                    *to++ = *from++;
                    case 2:
                    *to++ = *from++;
                    case 1:
                    *to++ = *from++;
                } while (--n > 0);
        }
    }

    return count;
}
```

Después de un rato dando vueltas he llegado a la conclusión de que todo este
despliegue de medios es para copiar el array de caracteres en "bloques" de 8
caracteres. Teniendo en cuenta que no siempre las palabras serán de una longitud
múltiplo de 8 por ello la primera vez el `switch` tiene sentido y se ejecutará
desde dónde corresponda. El resto de iteraciones hasta el final siempre será en 0.

Por ejemplo si tenemos el siguiente array `abcdefghi` de longitud `9`.
El calculo de `n` será el redondeo superior de la división de la longitud entre 8,
por tanto `9 / 8 = 2` . Al ejecutar el `switch` entrará por `case 1` debido a que
el resto de la división de `9 / 8` es de `1`. Una vez ejecutado en la sentencia
decrementamos una iteración de los bloques de 8 con `--n` y volvemos al `switch`
que a partir de ahora siempre será 0 porque ya nos hemos "quitado" lo sobrante al
no ser múltiplo de 8.

## Ejemplo grafico

Si tenemos un array de 13 como el siguiente

`char [] from = ['h', 'o', 'l', 'a', ' ', 'q', 'u', 'e', ' ', 't', 'a', 'l', '?']`

y lo queremos copiar el metodo seguirá el siguiente flujo

1. Calula el número de iteraciones con `int n = (13 + 7) / 8`
sumándo 7 nos aseguramos que siempre se haga el redondeo superior del entero en
lugar del inferior. Ya que si no hacemos esto y solo dividimos `13 / 8` el
resultado es 1 y con una sola iteración de 8 carácteres se quedarán fuera bastantes
`[' ', 't', 'a', 'l', '?']`

Al sumarle 7 la operación es la siguiente `(13 + 7) / 8 == 20 / 8 = 2`.

Una vez tenemos el numero de iteraciones que tenemos que hacer tenemos otro problema
que resolver. No podemos poner 8 veces la sentencia `*to++ = *from++;` porque en 
la última iteración al quedarnos tan solo 5 carácteres nos copiaría una zona de
memoria que no nos corresponde (con algo de suerte).

Por esta razón está el siguiente paso en el flujo del programa

2. `switch (count % 8) { ... }` al calcular el resto de la división del total de
carácteres entre 8 podremos saber cuantos restan en este caso 5. Si nos fijamos
el `switch` no tiene la sentencia `brake` despues de cada `case` por esta razón
siempre ejecutará todas las sentencias `case` hasta el final. 

Con esto logramos copiar tan solo los carácteres que nos sobrarían al final de
las iteraciones. De tal manera que ahora solo nos restan 8 y podremos ejecutar
8 veces `*to++ = *from++;` para hacer la copia.

Lo bueno de esto es que siempre se cumple sea con 13 o con 50, haz la prueba. 

`n = (50 + 7) / 8 = 57 / 8 = 7 iteraciones`
`50 % 8 = 2 restantes`
En la primera iteracíon copiamos solo 2 carácteres y nos quedan 6 iteraciones más.
`50 - 2 = 48 carácteres restantes`
`48 / 8 = 6 iteraciones restantes`

Lo malo es que no es para nada intuitivo o fácil de comprender y por ello
desaconsejable su uso. Aunque es cierto que está optimizado
en tiempo de ejecución ya que para cada 8 carácteres solo hace una comparación 
en el `while` y otra al empezar en el switch. En cambio con el bucle `for` por cada
carácter tenemos una comparación de si hemos llegado al final del array `i < count`. 
A día de hoy con la potencia de los procesadores este detalle queda más en un 
segundo plano, si bien es cierto que si trabajamos con sistemas empotrados quizás
nos interese más.
