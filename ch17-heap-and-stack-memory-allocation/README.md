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
