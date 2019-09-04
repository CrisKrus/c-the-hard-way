A la hora de convertir el tipo de una variable hay que tener cuidado. No es lo mismo
*castear* de tipo entero `int` a tipo doble `double` que a la inversa. Cada tipo
de variable no ocupa lo mismo en memoria, no ocupa la misma cantidad de `bits`. 
Es por esto que algunos tipos son más grandes que otros por definición. 

Por ejemplo, un `double` tiene el doble de `bits` para representarse que un `int`.
Teniendo esto en cuenta no es buena idea convertir un `double` a un `int` porque
por el camino se perderán la mitad de los `bits`, perderemos información. Pero, 
en cambio, hacer el *casteo* en el sentido inverso no genera problemas.

Que sea una mala idea no significa que no se pueda hacer, si sabemos lo que estamos
haciendo y es lo que buscamos podemos hacerlo, teniendo en cuenta lo dicho, la
información se perderá por el camino.

Siguiendo este razonamiento la siguiente lista está ordenada de mayor a menor
tamaño. Siempre tendremos que hacer el *casteo* de abajo a arriba.

1. `long double`
2. `double`
3. `float`
4. `int` (but only `char` and `short int`)
5. `long`

## Operadores de datos

- `->` acceso a puntero de Struct
- `.` accesoa valor de Struct
- `& (unary)` dirección de memoria
- `* (unary)` valor de...

## Operadores de bit

- `<<` shift left
- `>>` shift right
- `^` xor
- `|` or
- `~` complementario
