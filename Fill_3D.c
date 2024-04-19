#include <stdio.h>
#include "Common.h" //Include header file "common.h"
//Filling the 3D array in direct order
void direct_3d_fill()
{
    int c=0;
    for (int k=0; k<cross; k++)
        for (int j=0; j<column; j++)
            for (int i=0; i<row; i++)
                mas[k][i][j] = c++;

}
// Filling a 3D array with random values
void random_3d_fill()
{
    srand(time(NULL));// Initialize the random number generator
    for (int k=0; k<cross; k++)
        for (int i=0; i<row; i++)
           for (int j=0; j<column; j++)
                mas[k][i][j] = rand() % (cross*row*column);
}
// Filling the 3D array in reverse order
void back_3d_fill()
{
    int c = cross*row*column;
    for (int k=0; k<cross; k++)
        for (int j=0; j<column; j++)
            for (int i=0; i<row; i++)
                mas[k][i][j] = c--;
}

