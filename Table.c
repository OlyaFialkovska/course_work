#include <conio.h> // Include a header file to use functions to control the console
#include <windows.h> // Include a header file to use the functions to control the console window
#include "menu.h" //Include header file "menu.h"
#include "Measurement.h" //Include header file "Measurement.h"
#include "Common.h" //Include header file "Common.h"
// Frame drawing function
void frame(int x1, int y1, int x2, int y2)  //=
{
    colour(13);// Set the text color
    int i;
    GotoXY(x1, y1);
    printf("%c", '\311');
    for (i = (x1 + 1); i <= (x2 - 1); i++)
        printf("%c", '\315');
    printf("%c", '\273');
    for (i = (y1 + 1); i <= (y2 - 1); i++)
    {
        GotoXY(x1, i);
        printf("%c", '\272');
        GotoXY(x2, i);
        printf("%c", '\272');
    }
    GotoXY(x1, y2);
    printf("%c", '\310');
    for (i = (x1 + 1); i <= (x2 - 1); i++)
        printf("%c", '\315');
    printf("%c", '\274');
}
// Table output function for the vector array
void table_arr()
{
    system("cls"); // Clear the screen
    float direct, random, back;

    frame(21, 3, 64, 13); // Draw the frame
    colour(14); // Set the text color
    GotoXY(28, 3);
    printf("TABLE FOR ARRAY, length:%d ", arr_n );

    GotoXY(40, 5);
    printf("direct\trandom\tback\n");

    GotoXY(40, 7);

    insert4_arr(1);
    direct = MeasurementProcessing(); // Measure execution time direct insert4_arr

    insert4_arr(2);
    random = MeasurementProcessing(); // Measure execution time random insert4_arr

    insert4_arr(3);
    back = MeasurementProcessing(); // Measure execution time back insert4_arr
    printf("%.3f\t%.3f\t%.3f\n",direct,random,back);

    GotoXY(40, 9);
    Shell_2_arr(1);
    direct = MeasurementProcessing(); // Measure execution time direct Shell_2_arr

    Shell_2_arr(2);
    random = MeasurementProcessing(); // Measure execution time random Shell_2_arr

    Shell_2_arr(3);
    back = MeasurementProcessing();// Measure execution time back Shell_2_arr
    printf("%.3f\t%.3f\t%.3f\n",direct,random,back);

    GotoXY(40, 11);
    QSortMeasurement_vect(1);
    direct = MeasurementProcessing(); // Measure execution time direct QSortMeasurement_vect

    QSortMeasurement_vect(2);
    random = MeasurementProcessing();// Measure execution time random QSortMeasurement_vect

    QSortMeasurement_vect(3);
    back = MeasurementProcessing();// Measure execution time back QSortMeasurement_vect
    printf("%.3f\t%.3f\t%.3f\n",direct,random,back);

    GotoXY(22, 7);
    printf("Insert4\n");
    GotoXY(22, 9);
    printf("Shell_2\n");
    GotoXY(22, 11);
    printf("QuickSort\n");
    colour(13);
    GotoXY(22, 14);
    printf("Please press any key to exit\n");
    GotoXY(45, 16);
}
// Table output function for the 3D array
void table_mas()
{
    system("cls");//clear the screen
    float direct, random, back;

    frame(21, 3, 64, 13);
    colour(14);
    GotoXY(20, 3);
    printf("TABLE FOR MASSIVE, cross:%d row:%d column:%d",cross, row, column);

    GotoXY(40, 5);
    printf("direct\trandom\tback\n");

    GotoXY(40, 7);

    insert4_3d(1);
    direct = MeasurementProcessing();// Measure execution time direct insert4_3d

    insert4_3d(2);
    random = MeasurementProcessing();// Measure execution time random insert4_3d

    insert4_3d(3);
    back = MeasurementProcessing();// Measure execution time back insert4_3d
    printf("%.3f\t%.3f\t%.3f\n",direct,random,back);

    GotoXY(40, 9);
    Shell_2_3d(1);
    direct = MeasurementProcessing();// Measure execution time direct Shell_2_3d

    Shell_2_3d(2);
    random = MeasurementProcessing();// Measure execution time random Shell_2_3d

    Shell_2_3d(3);
    back = MeasurementProcessing();// Measure execution time back Shell_2_3d
    printf("%.3f\t%.3f\t%.3f\n",direct,random,back);

    GotoXY(40, 11);
    QSortMeasurement_3d(1);
    direct = MeasurementProcessing();// Measure execution time direct QSortMeasurement_3d

    QSortMeasurement_3d(2);
    random = MeasurementProcessing();// Measure execution time random QSortMeasurement_3d

    QSortMeasurement_3d(3);
    back = MeasurementProcessing();// Measure execution time back QSortMeasurement_3d
    printf("%.3f\t%.3f\t%.3f\n",direct,random,back);

    GotoXY(22, 7);
    printf("Insert4\n");
    GotoXY(22, 9);
    printf("Shell_2\n");
    GotoXY(22, 11);
    printf("QuickSort\n");
    colour(13);
    GotoXY(22, 14);
    printf("Please press any key to exit\n");
    GotoXY(45, 16);
}

