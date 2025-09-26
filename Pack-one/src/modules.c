#include "../include/modules.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

ReturnCode Validation(int argc, char **argv) {
    if (argc != 3 || strlen(argv[1]) != 2 || strlen(argv[2]) > 10) {
        printf("Please input correct arguments\n");
        return INVALID_ARGUMENT;
    }

    if (argv[1][0] != '/' && argv[1][0] != '-') {
        printf("Please enter correct prefix flag\n");
        return INVALID_ARGUMENT;
    }

    if (atoi(argv[2]) < 1 || strstr(argv[2], ".")) {
        printf("Please enter correct number\n");
        return INVALID_ARGUMENT;
    }

    return OK;
}

ReturnCode Exponents(const unsigned int number) {
    if (number > 10) {
        printf("You number is bad, i can't index it :(\n");
        return UNEXPECTED_INPUT; 
    }

    printf("Table of degrees of %d:\n", number);
    for (int base = 1; base != 11; ++base) {
        printf("%-11d", base);
        for (int exp = 1; exp <= number; ++exp) {
            printf("%-11.f", pow(base, exp));
        }
        printf("\n");
    }

    return OK;
}

// Recursion
// u_int64_t Factorial(const u_int64_t number) {
//     if (number < 1 || number > 100 || number == INT_MAX) {
//         printf("You number is unfit, i can't index it :(\n");
//         return INVALID_ARGUMENT;
//     }

//     if (number == 1) {
//         return number;
//     }
//     printf("%ld ", number);
//     return number * Factorial(number - 1);
    
// }

ReturnCode Factorial(const unsigned int number) {
    if (number > 20) {
        printf("You number is unfit, i can't index it :(\n");
        return UNEXPECTED_INPUT;
    }

    int x = 0;
    int64_t result = 1;
    while (x != number) {
        result *= x + 1;
        ++x;
    }
    printf("Factorial: %ld\n", result);

    return OK;
}

ReturnCode Natural(const unsigned int number) {
    int64_t result = 0;
    for (int i = 1; i <= number; ++i) {
        result += i;
    }
    printf("The Sum of natural numbers up to x: %ld\n", result);

    return OK;
}

ReturnCode IsSimple(const double number, const double Eps) {
    for (int i = 2; i != ((int) sqrt(number) + 1); ++i) {
        if ((int) number % i == 0) {
            printf("You number isn't Simple\n");
            return OK;
        } 
    }
    printf("You number is Simple\n");

    return OK;
}

ReturnCode NaturalsDivX(const unsigned int number) {
    bool flag = false;
    printf("Numbers that are multiples of %d:\n", number);
    for (int i = 1; i <= 100; ++i) {
        if (i % number == 0) {
            flag = true;
            printf("%d ", i);
        }
    }
    
    if (!flag) printf("Nothing :(");
    printf("\n");

    return OK;
}

ReturnCode HexNumber(unsigned int number) {
    printf("HEX Representation of a %d: \n", number);

    int index = 0;
    int num = number;
    char hex_represent[32];

    while (num > 0) {
        int digit = num % 16;
        if (digit < 10) {
            hex_represent[index] = '0' + digit;
        } else {
            hex_represent[index] = 'A' + (digit - 10);
        }

        index++;
        num /= 16;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%c ", hex_represent[i]);
    }
    printf("\n");

    return OK;
}