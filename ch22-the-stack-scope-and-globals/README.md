La palabra reservada `static` dentro de un fichero hace que esa variable sea solo
accesible desde ese mismo fichero. Se asemeja al funcionamiento de `private` en
otros lenguajes de programación.

Si la utilizamos dentro de una función hará el mismo efecto, esa variable solo
será accesible desde dentro del porpio método. 

Esto no se suele usar mucho, debido a que con los hilos es demasiado complicado
de usar.

Por el contrario la palabra reservada `extern`. Esta palabra si la ponemos en un
fichero`.h` suele significar que la variable existe pero está en otro fichero 
"externo", como por ejemplo un `.c`
