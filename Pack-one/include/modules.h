#include "stdio.h"
#include <math.h>
#include <sys/types.h>

typedef enum ReturnCode {
    OK,
    ERROR,
    UNEXPECTED_INPUT,
    INVALID_ARGUMENT,
    NO,
    YES,
} ReturnCode;

ReturnCode Validation(int argc, char *argv[]);

ReturnCode Exponents(const unsigned int number);

ReturnCode Factorial(const unsigned int number);

ReturnCode Natural(const unsigned int number);

ReturnCode IsSimple(const double number, const double Eps);

ReturnCode NaturalsDivX(const unsigned int number);

ReturnCode HexNumber(unsigned int number);