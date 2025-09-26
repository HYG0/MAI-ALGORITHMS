#include "include/modules.h"
#include <stdint.h>
#include <stdlib.h>
#include <float.h>

int main(int argc, char *argv[]) {
    if (Validation(argc, argv) == INVALID_ARGUMENT) {
        return 0;
    }

    const double EPSILON = DBL_EPSILON;
    char options = argv[1][1];
    int32_t number = atoi(argv[2]);

    switch (options) { 
        case 'h':
            NaturalsDivX(number);
            break;
        case 'p':
            IsSimple(number, EPSILON);
            break;
        case 's':
            HexNumber(number);
            break;
        case 'e':
            Exponents(number);
            break;
        case 'a':
            Natural(number);
            break;
        case 'f':
            Factorial(number);
            break;
        default:
            printf("Enter the available flag\n");
            break;
    }

    return OK;
}