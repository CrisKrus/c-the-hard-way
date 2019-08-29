# Compilar

`cc ex17.c address.c database.c error_handler.c -o ex17`

# Notas

Extraer en ficheros independientes no es buena idea el compilador da problemas si
incluyes varias veces el mismo fichero. Por ejemplo si en el fichero `connection.h`
incluimos `database.h`  el compilador nos dirá que ya está definido.

```bash
cc     ex17.c   -o ex17
In file included from connection.h:1:0,
                 from ex17.c:9:
database.h:3:8: error: redefinition of ‘struct Database’
 struct Database {
        ^~~~~~~~
In file included from ex17.c:8:0:
database.h:3:8: note: originally defined here
 struct Database {
        ^~~~~~~~
<builtin>: recipe for target 'ex17' failed
make: *** [ex17] Error 1
```

Esto ocurre porque `database.h` ya está incluido en la "clase padre".

Curiosamente si borramos la línea de `#include "database.h"` del fichero `connection.h`
y compilamos con `make ex17`, todo va bien. Si después de tener la compilación
volvemos a poner la misma línea en el mismo fichero y volvemos a compilar nos
indicará que no ha detectado cambios y no es necesario compilar de nuevo. 

Para solucionar esto en los compiladores modernos nos dan la opción de añadir en
los ficheros `.h` la opción `#pragma once` al inicio. Con esto ya el compilador
sabe que tiene que incluirlo una única vez.

En los compiladores antiguos teníamos que hacer una construcción más compleja. 
Como se puede ver en el fichero `address.h`

```c
#ifndef __ADDRESS_H__
#define __ADDRESS_H__
#include "constants.h"

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

#endif
```

Dónde `__ADDRESS_H__` es el nombre único que le damos, puede ser cualquier cosa,
por sentido común se le da el nombre del fichero con la extensión.
