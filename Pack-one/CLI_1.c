#include <stdio.h>
#include <stdlib.h>
#include "include/modules.h"

int main(int argc, char *argv[]) {
    PrintHello(argv[1]);
    printf("Your year of born: %d\n", atoi(argv[2]));

    return OK;
}