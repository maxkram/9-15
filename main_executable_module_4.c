#include <stdio.h>
#include "../../data_libs/data_process.h"
#include "../../data_libs/data_stat.h"
#include "../../data_libs/decision.h"

#ifdef USE_MACRO_IO
#include "../../data_libs/data_io_macro.h"
#else
#include "../../data_libs/data_io.h"
#endif

int main(void) {
    double data[1000];
    int n = 0;

    printf("LOAD DATA...\n");

#ifdef USE_MACRO_IO
    INPUT(lf, data, n);
#else
    if (input(data, &n) != 0) {
        printf("n/a");
        return 0;
    }
#endif

    printf("RAW DATA:\n\t");
#ifdef USE_MACRO_IO
    OUTPUT(.2lf, data, n);
#else
    output(data, n);
#endif

    printf("\nNORMALIZED DATA:\n\t");
    if (normalization(data, n)) {
#ifdef USE_MACRO_IO
        OUTPUT(.2lf, data, n);
#else
        output(data, n);
#endif
    } else {
        printf("n/a");
        return 0;
    }

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
#ifdef USE_MACRO_IO
    OUTPUT(.2lf, data, n);
#else
    output(data, n);
#endif

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
