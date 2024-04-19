#include "Measurement.h" //Include header file "Measurement.h"
#include "Common.h" //Include header file "Common.h"
#include <stdio.h>
clock_t Res[measurements_number];
// Function to process the measurements and calculate the average value
float MeasurementProcessing()
{
    long int Sum;
    float AverageValue;
    clock_t buf;
    int L = rejected_number, R = measurements_number - 1;
    int k = rejected_number;
    for (int j=0; j < min_max_number; j++)
    {
        for (int i = L; i < R; i++)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        R = k;
        for (int i = R - 1; i >= L; i--)
        {
            if (Res[i] > Res[i + 1])
            {
                buf = Res[i];
                Res[i] = Res[i + 1];
                Res[i + 1] = buf;
                k = i;
            }
        }
        L = k + 1;
    }
    Sum=0;
    for (int i = rejected_number + min_max_number; i < measurements_number - min_max_number; i++)
        Sum = Sum + Res[i];
    AverageValue = (float)Sum / (float)(measurements_number - 2*min_max_number - rejected_number);
    return AverageValue;
}
//The function fills the vector array, sorts it and determines the hour of sorting
void insert4_arr(int x)
{
    for (int i = 0; i < measurements_number; i++)
    {
        if (x == 1) // direct array
        {
            direct_vect_fill();
            Res[i] = Insert4();
        }
        else if (x == 2) // random array
        {
            random_vect_fill();
            Res[i] = Insert4();
        }
        else if (x == 3) // back array
        {
            back_vect_fill();
            Res[i] = Insert4();
        }
    }
}
//the function fills a trivial array, sorts using the Insertion_Sorting_4 method
void insert4_3d(int x)
{

    for (int i = 0; i < measurements_number; i++)
    {
        if (x == 1) // direct array
        {
            direct_3d_fill();
            Res[i] = Insertion_Sorting_4();
        }
        else if (x == 2) // random array
        {
            random_3d_fill();
            Res[i] = Insertion_Sorting_4();
        }
        else if (x == 3) // back array
        {
            back_3d_fill();
            Res[i] = Insertion_Sorting_4();
        }
    }
}
//the function sorts the array using the additional Shell_2 method
void Shell_2_arr(int x)
{

    for (int i = 0; i < measurements_number; i++)
    {
        if (x == 1) // direct array
        {
            direct_vect_fill();
            Res[i] = Shell_2();
        }
        else if (x == 2) // random array
        {
            random_vect_fill();
            Res[i] = Shell_2();
        }
        else if (x == 3) // back array
        {
            back_vect_fill();
            Res[i] = Shell_2();
        }
    }
}
//the function sorts a trivial array using the shell_2_sort method
void Shell_2_3d(int x)
{

    for (int i = 0; i < measurements_number; i++)
    {
        if (x == 1) // direct array
        {
            direct_3d_fill();
            Res[i] = shell_2_sort();
        }
        else if (x == 2) // random array
        {
            random_3d_fill();
            Res[i] = shell_2_sort();
        }
        else if (x == 3) // back array
        {
            back_3d_fill();
            Res[i] = shell_2_sort();
        }
    }
}
//The function freezes the hour of sorting the array using the QuickSort method
void QSortMeasurement_vect(int x)
{
    clock_t time_start, time_stop;
    for (int i = 0; i < measurements_number; i++)
    {
        if (x == 1) // direct array
        {
            direct_vect_fill();
            time_start = clock();
            QuickSort(0, arr_n-1);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
        else if (x == 2) // random array
        {
            random_vect_fill();
            time_start = clock();
            QuickSort(0, arr_n-1);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
        else if (x == 3) // back array
        {
            back_vect_fill();
            time_start = clock();
            QuickSort(0, arr_n-1);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
    }
}
//The function freezes the time of sorting a trivial array using the QuickSort method
void QSortMeasurement_3d(int x)
{
    clock_t time_start, time_stop;
    for (int i = 0; i < measurements_number; i++)
    {
        if (x == 1) // direct array
        {
            direct_vect_fill();
            time_start = clock();
            QSort(0, cross-1);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
        else if (x == 2) // random array
        {
            random_3d_fill();
            time_start = clock();
            QSort(0, cross-1);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
        else if (x == 3) // back array
        {
            back_3d_fill();
            time_start = clock();
            QSort(0, cross-1);
            time_stop = clock();
            Res[i] = time_stop - time_start;
        }
    }
}

