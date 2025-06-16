#include "data_io.h"
#include <stdio.h>

int input(double *data, int *n) {
    int count = 0;
    while (scanf("%lf", &data[count]) == 1) {
        count++;
    }
    *n = count;
    return 0;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf", data[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}
