#include <stdio.h>
#include <stdlib.h>
#include "../../data_libs/data_stat.h"
#include "../../data_libs/decision.h"

#ifdef USE_MACRO_IO
#include "../../data_libs/data_io_macro.h"
#else
#include "../../data_libs/data_io.h"
#endif

#ifndef USE_DYNAMIC
#include "../../data_libs/data_process.h"
#else
#include <dlfcn.h>
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

#ifndef USE_DYNAMIC
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
#else
    void *handle = dlopen("../../build/data_process.so", RTLD_LAZY);
    if (!handle) {
        printf("n/a");
        return 0;
    }

    int (*normalization_func)(double*, int);
    normalization_func = dlsym(handle, "normalization");
    if (!normalization_func) {
        printf("n/a");
        dlclose(handle);
        return 0;
    }

    if (normalization_func(data, n)) {
#ifdef USE_MACRO_IO
        OUTPUT(.2lf, data, n);
#else
        output(data, n);
#endif
    } else {
        printf("n/a");
        dlclose(handle);
        return 0;
    }

    dlclose(handle);
#endif

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
