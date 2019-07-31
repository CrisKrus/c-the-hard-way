#include <stdio.h>

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = { 23, 43, 12, 89, 2 };
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    printf("Count: %d\n", count);

    // first way using indexing
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *pointer_age = (int *)ages;
    char **pointer_name = (char **)names;

    // second way using pointers
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                *(pointer_name + i), *(pointer_age +i));
    }

    printf("---\n");

    // third way, pointers are just arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", pointer_name[i], pointer_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    for (pointer_name = names, pointer_age = ages;
            (pointer_age - ages) < count; pointer_name++, pointer_age++) {
        printf("%s lived %d years so far.\n", *pointer_name, *pointer_age);
    }

    return 0;
}
