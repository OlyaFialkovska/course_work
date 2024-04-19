#ifndef MEASUREMENT_H_INCLUDED
#define MEASUREMENT_H_INCLUDED

#include <time.h>

#define measurements_number 28 // Number of measurements
#define rejected_number 2 // Number of measurements to discard during processing
#define min_max_number 3 // The number of largest and smallest values that will be discarded during processing
extern clock_t Res[measurements_number]; // Global array for storing measurement results

//prototype functions
float MeasurementProcessing();
void insert4_arr(int x);
void insert4_3d(int x);
void Shell_2_arr(int x);
void Shell_2_3d(int x);
void QSortMeasurement_vect(int x);
void QSortMeasurement_3d(int x);

#endif // MEASUREMENT_H_INCLUDED

