#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H

#include <stdio.h>

#define INPUT(type, array, size)        \
    do {                                 \
        int count = 0;                   \
        while (scanf("%" #type, &array[count]) == 1) { \
            count++;                     \
        }                                \
        size = count;                    \
    } while (0)

#define OUTPUT(type, array, size)        \
    do {                                 \
        for (int i = 0; i < size; i++) { \
            printf("%" #type, array[i]); \
            if (i != size - 1) {         \
                printf(" ");             \
            }                            \
        }                                \
    } while (0)

#endif
