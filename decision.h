#ifndef DECISION_H
#define DECISION_H

#include "../../data_libs/data_stat.h"
#include <math.h>

#define GOLDEN_RATIO 0.666

int make_decision(double *data, int n);

#endif


// gcc src/yet_another_decision_module/yet_another_decision_module_entry.c \
//     src/data_libs/data_io.c \
//     src/data_libs/data_stat.c \
//     src/data_libs/decision.c \
//     -o yet_another_decision_module_entry -lm
