#include "../include/modules_lab_2.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

uint UInt32Validation(char inpt_number[]) {
    // Number validation
    // Correct number is 1 <= number <= INT_MAX
    char* ptr_end;
    long number = strtol(inpt_number, &ptr_end, 10);

    // For not fit nums func return 0
    if (number == LONG_MAX || number > INT_MAX || number <= 0 || *ptr_end != 0) {
        return 0;
    }

    uint correct_number = number;
    return correct_number;
}

ReturnCode ArgValidation(int argc, char *argv[]) {
    // Args validation
    if (argc != 2) {
        printf("Expected one argument\n");
        return INVALID_ARGUMENT;
    }

    if (UInt32Validation(argv[1]) == 0) {
        printf("Argument not fit to requirements\n"
               "Please enter 0 < YOU_INTEGER <= 2^31\n");
        return INVALID_ARGUMENT;
    }

    return OK; 
}

void* MallocCheck(u_int64_t size) {
    // Checking the correct memory malloc
    void* array = malloc(size);
    if (!array) {
        printf("Allocated ERROR\n");
        exit(1);
    }
    return array;
}

void* CallocCheck(size_t size, size_t elmnt_size) {
    // Checking the correct memory calloc
    void* array = calloc(size, elmnt_size);
    if (!array) {
        printf("Allocated ERROR\n");
        exit(1);
    }
    return array;
}

ReturnCode ScanInput(uint num_of_inpts, uint* max_input_num, uint* input_arr) {
    uint treated_num = 0;
    // Scan Error overflow char at any nums
    char receive_num[MAX_INPUT_LENGTH];

    for (size_t i = 0; i < num_of_inpts; ++i) {
        scanf("%9s", receive_num); 
        treated_num = UInt32Validation(receive_num);
        if (treated_num == 0 || treated_num > MAX_ORDINAL_PRIME) {
            printf("Input number doesn't fit\n"
                   "Please enter 0 < YOU_INTEGER <= 200.000.000\n");
            return INVALID_ARGUMENT;
        }
        input_arr[i] = treated_num;
        *max_input_num = *max_input_num < treated_num ? treated_num : *max_input_num;
    }

    return OK;
}

ReturnCode PrimeNumber(uint max_arr_size, uint* input_value_arr, uint size_inpt_arr) {
    // num - порядковый номер простого числа
    // Conditional for upper bound prime number
    u_int64_t upper_limit = max_arr_size * (log(max_arr_size) + log(log(max_arr_size) - 1)) + 10;
    
    // An array of nums with uppper bound max prime num
    // Sieve-Array
    uint8_t *ordinal_arr = (uint8_t *)MallocCheck(upper_limit * sizeof(uint8_t));
    // Initialize value in array of 1
    for (u_int64_t v = 3; v < upper_limit; v += 2) {
        ordinal_arr[v] = 1;
    }
    ordinal_arr[0] = ordinal_arr[1] = 0;
    ordinal_arr[2] = 1;

    // Array of prime nums    
    u_int64_t *prime_num_arr = (u_int64_t *)MallocCheck(max_arr_size * sizeof(u_int64_t));

    // Решето Эратосфена
    for (u_int64_t i = 3; i * i < upper_limit; i+=2) {
        if (ordinal_arr[i]) {
            for (u_int64_t j = i * i; j < upper_limit; j += i) {
                ordinal_arr[j] = 0;
            }
        }
    }
    
    u_int64_t index = 0;    
    for (u_int64_t k = 2; k < upper_limit; ++k) {
        if (index >= max_arr_size) break;
        if (ordinal_arr[k]) {
            prime_num_arr[index] = k;
            ++index;
        }
    }

    // Вывод массива простых чисел
    // for (u_int64_t a = 0; a < max_arr_size; ++a) {
    //     printf("%ld ", prime_num_arr[a]);
    // }

    // Вывод решета решета-массива
    // for (u_int64_t a = 0; a < upper_limit; ++a) {
    //     printf("%ld - %d\n", a, ordinal_arr[a]);
    // }

    for (u_int64_t a = 0; a < size_inpt_arr; ++a) {
        printf("\nPrime number is %lu - The order is %u\n", prime_num_arr[input_value_arr[a] - 1], input_value_arr[a]);
    }

    free(ordinal_arr); 
    free(prime_num_arr);

    return OK;
}