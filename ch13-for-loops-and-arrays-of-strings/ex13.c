#include <stdio.h>
void printIfIsAVowel(char letter, int index)
{
    switch (letter) {
        case 'a':
        case 'A':
            printf("%d: 'A'\n", index);
            break;

        case 'e':
        case 'E':
            printf("%d: 'E'\n", index);
            break;

        case 'i':
        case 'I':
            printf("%d: 'I'\n", index);
            break;

        case 'o':
        case 'O':
            printf("%d: 'O'\n", index);
            break;

        case 'u':
        case 'U':
            printf("%d: 'U'\n", index);
            break;

        default:
            printf("%d: %c is not a vowel\n", index, letter);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int i = 0;
    for (i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];
        printIfIsAVowel(letter, i);
    }

    return 0;
}
