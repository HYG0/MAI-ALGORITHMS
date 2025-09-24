#include "stdio.h"
#include <math.h>

typedef enum ReturnCode {
    OK,
    ERROR,
    UNEXPECTED_INPUT,
    INVALID_ARGUMENT,
} ReturnCode;

void PrintHello(char str[]);

ReturnCode Exponents(const unsigned int number);

ReturnCode Factorial(const unsigned int number);