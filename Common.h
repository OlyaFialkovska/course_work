#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#define cross 8 // Number of "sections" in the 3D array
#define row 3 // The number of rows in a three-dimensional array
#define column 2 // Number of columns in the 3D array
#define arr_n 14 // Size of vector array
int *** mas; // 3D array
int arr [arr_n]; // Vector array

void initialization_memory(); // Prototype function for memory initialization
void free_memory(); // Prototype function for freeing memory

#endif // COMMON_H_INCLUDED

