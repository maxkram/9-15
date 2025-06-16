#include <stdio.h>
#include "../../data_libs/data_io.h"
#include "../../data_libs/data_process.h"

int main(void) {
    double data[1000];
    int n = 0;

    if (input(data, &n) != 0) {
        printf("n/a");
        return 0;
    }

    if (normalization(data, n)) {
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}
