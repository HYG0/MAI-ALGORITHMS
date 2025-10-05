#include "../include/modules_lab_2.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ReturnCode ArgValidation(int argc, char *argv[]) {
    // Args validation
    if (argc != 2) {
        printf("Expected one argument\n");
        return INVALID_ARGUMENT;
    }

    // Number validation
    char* ptr_end;
    long number = strtol(argv[1], &ptr_end, 10);
    if (number == LONG_MAX || number <= 0 || *ptr_end != 0) {
        printf("Argument not fit to requirements\n"
               "Please enter 0 < int and int < 2^32\n");
        return INVALID_ARGUMENT;
    }
    
    return OK; 
}

ReturnCode ScanInput(int32_t num_of_inpts) {
    int32_t* array = (int32_t *)malloc(num_of_inpts * sizeof(int32_t));
    if (!array) {
        printf("Allocated error!\n");
        return ALLOCATED_ERROR;
    }

    int32_t max_prime_num = 0;
    int32_t receive_num = 0;

    for (size_t i = 0; i < num_of_inpts; ++i) {
        scanf("%d", &receive_num);
        if (receive_num == INT_MAX || receive_num <= 0) {
            printf("Input number doesn't fit\n");
            return INVALID_ARGUMENT;
        }
        array[i] = receive_num;
        max_prime_num = max_prime_num < receive_num ? receive_num : max_prime_num;
    }
    array[num_of_inpts] = max_prime_num;

    // Вывод содержимого массива
    for (int a = 0; a <= num_of_inpts; ++a) {
        printf("%d ", array[a]);
    }

    free(array);
    return OK;
}

ReturnCode PrimeNumber(int32_t num) {
    // num - порядковый номер простого числа
    int size_arr = num * 10;

    int *ordinal_arr = (int *) calloc(size_arr,  sizeof(int));
    if (ordinal_arr == NULL) {
        printf("ERORR!\n");
    }

    ordinal_arr[0] = ordinal_arr[1] = 1;
    int ordinal_count = 0;
    
    // Решето Эратосфена
    for (size_t i = 2; i <= size_arr; ++i) {
        if (!ordinal_arr[i]) {
            for (int j = 2 * i; j <= size_arr; j += i) {
                ordinal_arr[j] = 1;
            }
            ++ordinal_count;
            printf("Count %ld\n", i);
            if (ordinal_count == num) {
                printf("Answer is %ld", i);
            }
        }
    }


    // Вывод содержимого массива
    for (int a = 0; a <= size_arr; ++a) {
        printf("%d ", ordinal_arr[a]);
    }

    // Цикл поиска простого числа под порядковым номером num
    // if (num == ordinal_count) {
    //     printf("\n%d\n", ordinal_count);
    // }

    // if (ordinal_arr[num] != 0) {
    //     printf("Number %d is prime number\n", num);
    // } else {
    //     printf("Number %d is not prime number\n", num);
    // }

    free(ordinal_arr); 

    return OK;
}