#include "data_process.h"
#include <math.h>

int normalization(double *data, int n) {
    int result = 1;
    double max_value = data[0];
    double min_value = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > max_value)
            max_value = data[i];
        if (data[i] < min_value)
            min_value = data[i];
    }

    double size = max_value - min_value;

    if (fabs(size) >= EPS) {
        for (int i = 0; i < n; i++) {
            data[i] = (data[i] - min_value) / size;
        }
    } else {
        result = 0;
    }

    return result;
}
