#include "../include/modules.h"
#include <math.h>
#include <stdio.h>
#include <limits.h>

void PrintHello(char str[]) {
    printf("Hello %s\n", str);
}

ReturnCode Exponents(const unsigned int number) {
    if (number < 1 || number > 10 || number == INT_MAX) {
        printf("You number is bad, i can't count it :(\n");
        return INVALID_ARGUMENT; 
    }
    printf("\nTable of degrees of %d:\nBase\n", number);

    for (int base = 1; base != 11; ++base) {
        printf("%-11d", base);
        for (int exp = 1; exp <= number; ++exp) {
            printf("%-11.f", pow(base, exp));
        }
        printf("\n");
    }

    return OK;
}

ReturnCode Factorial(const unsigned int number) {
    if (number < 1 || number > 10 || number == INT_MAX) {
        printf("You number is bad, i can't count it :(\n");
        return INVALID_ARGUMENT;
    }

    
    return OK;
}