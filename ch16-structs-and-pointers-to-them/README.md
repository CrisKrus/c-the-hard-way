```c
void destroy_a_person(struct Person *a_person)
{
    assert(a_person != NULL);
    free(a_person->name);
    free(a_person);
}
```

Tenemos que darnos cuenta de que no solamente libera la memoria del `struct` 
("objeto") `a_person` también lo hace con el `name` puesto que no es un primitivo
es un puntero a un array de `char`

```
struct Person *joe = create_a_person("Joe Alex", 32, 64, 140);

joe->age += 20;
joe->height -= 2;
joe->weight += 40;
```

Los campos de un `struct` son todos "publicos", se pueden modificar por cualquiera
en cualquier momento.
