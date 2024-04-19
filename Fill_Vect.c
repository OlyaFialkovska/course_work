#include <stdio.h>
#include <stdlib.h>
#include "Common.h" //Include header file "common.h"
// Filling the vector array in ascending order
void direct_vect_fill()
{
    for (int i = 0; i < arr_n ; i++)
        arr[i] = i + 1;
}
// Fill the vector array with random numbers from 0 to 99
void random_vect_fill()
{
    srand(time(NULL));// Initialize the random number generator
    for (int i = 0; i < arr_n; i++)
        arr[i] = rand()%100;
}
// Filling the vector array in reverse order
void back_vect_fill()
{
    for (int i = 0; i < arr_n; i++)
        arr[i] = arr_n - i;
}

