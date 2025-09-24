#include <stdio.h>
#include <stdlib.h>
#include "include/modules.h"
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3 || (argv[1][0] != '/' && argv[1][0] != '-')) {
        printf("ERROR!\nPlease input correct arguments\n");
        return UNEXPECTED_INPUT;
    }
    char options = argv[1][1];
    int number = atoi(argv[2]);

    switch (options) { 
        case 'h':
            printf("----You choose flag h\n");
            break;
        case 'p':
            printf("----You choose flag p\n");
            break;
        case 's':
            printf("----You choose flag s\n");
            break;
        case 'e':
            printf("----You choose flag e\n");
            Exponents(number);
            break;
        case 'a':
            printf("----You choose flag a\n");
            break;
        case 'f':
            printf("----You choose flag f\n");
            break;
        default:
            printf("----You didn't select flag. Try again :)\n");
            break;
    }

    return OK;
}