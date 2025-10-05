#include <stdint.h>
#include <stdio.h>
#include "include/modules_lab_2.h"

int main(int argc, char *argv[]) {
    if (ArgValidation(argc, argv) == INVALID_ARGUMENT) {
        return 0;
    }
    int32_t number = atoi(argv[1]);
    ScanInput(number);

    return 0;
}