#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *create_a_person(char *name, int age, int height, int weight)
{
    struct Person *a_person = malloc(sizeof(struct Person));
    assert(a_person != NULL);
    a_person->name = strdup(name);
    a_person->age = age;
    a_person->height = height;
    a_person->weight = weight;
    return a_person;
}

void destroy_a_person(struct Person *a_person)
{
    assert(a_person != NULL);
    free(a_person->name);
    free(a_person);
}

void print_a_person(struct Person *a_person)
{
    printf("Name: %s\n", a_person->name);
    printf("\tAge: %d\n", a_person->age);
    printf("\tHeight: %d\n", a_person->height);
    printf("\tWeight: %d\n", a_person->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = create_a_person("Joe Alex", 32, 64, 140);
    struct Person *frank = create_a_person("Frank Blank", 20, 72, 180);
    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    print_a_person(joe);

    printf("Frank is at memory location %p:\n", frank);
    print_a_person(frank);
    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    print_a_person(joe);

    frank->age += 20;
    frank->weight += 20;
    print_a_person(frank);

    // destroy them both so we clean up
    destroy_a_person(joe);
    destroy_a_person(frank);

    return 0;
}
