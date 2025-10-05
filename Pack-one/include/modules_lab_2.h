#include <limits.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum ReturnCode {
    OK,
    INVALID_ARGUMENT,
    ALLOCATED_ERROR,
} ReturnCode;

ReturnCode ArgValidation(int argc, char *argv[]);

ReturnCode PrimeNumber(int32_t num);

ReturnCode ScanInput(int32_t num_of_inpts);