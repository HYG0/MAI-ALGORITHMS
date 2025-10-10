#include <limits.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <math.h>

#define MAX_INPUT_LENGTH 10
#define MAX_ORDINAL_PRIME 200000000

typedef enum ReturnCode {
    OK,
    INVALID_ARGUMENT,
    ALLOCATED_ERROR,
} ReturnCode;

typedef u_int32_t uint;

ReturnCode ArgValidation(int argc, char *argv[]);

ReturnCode PrimeNumber(uint arr_size, uint* input_value_arr, uint size_value_arr);

ReturnCode ScanInput(uint num_of_inpts, uint* max_input_num, uint* input_arr);

uint UInt32Validation(char *inpt_number);

void* MallocCheck(size_t arr_size);

void* CallocCheck(size_t arr_size, size_t elmnt_size);