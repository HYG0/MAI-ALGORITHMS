#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/modules_lab_2.h"

int main(int argc, char *argv[]) {
    if (ArgValidation(argc, argv) == INVALID_ARGUMENT) {
        return 0;
    }
    uint arr_size = UInt32Validation(argv[1]);
    uint max_input_num = 0;
    uint* input_num_arr = (uint *)MallocCheck(arr_size * sizeof(uint));

    if (ScanInput(arr_size, &max_input_num, input_num_arr) == INVALID_ARGUMENT) {
        return 0;
    }
    printf("Counting...\n\n");

    if (PrimeNumber(max_input_num, input_num_arr, arr_size) == INVALID_ARGUMENT) {
        return 0;
    }

    free(input_num_arr);

    return 0;
}