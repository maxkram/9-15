#include <stdio.h>
#include "../../data_libs/data_io.h"
#include "../../data_libs/data_process.h"
#include "../../data_libs/data_stat.h"
#include "../../data_libs/decision.h"

int main(void) {
    double data[1000];
    int n = 0;

    printf("LOAD DATA...\n");
    if (input(data, &n) != 0) {
        printf("n/a");
        return 0;
    }

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    if (normalization(data, n)) {
        output(data, n);
    } else {
        printf("n/a");
        return 0;
    }

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
