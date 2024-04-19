#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Include a header file to use functions to control the console
#include <windows.h> // Include a header file to use the functions to control the console window
#include "Table.h" //Include header file "Table.h"
#include "Common.h" //Include header file "Common.h"
#include "Measurement.h"
//Moves the console cursor to the specified position
void GotoXY(int X, int Y)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}
//Changes the color palette of the text in the console.
void colour(int i)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut,i);
}
//Sets the visibility of the cursor in the console and its size
void ConsoleCursorVisible(int show, short size)//the visibility of the cursor
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);
}
// Function for selecting methods of working with the array
void array_methods()
{
    system("cls");//clear the console screen
    ConsoleCursorVisible(0, 100);//make the console cursor invisible

    const char* menuOptions[] = {"Insert_4_arr","Shell_2_arr","QuickSort_arr","Table_arr","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);
    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("Array methods\n");

        colour(9);
        int x = 44, y = 15;//coordinates
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s *",  menuOptions[i]);//selected option
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72://up
            if (active_menu > 0)
                active_menu--;
            break;
        case 80://down
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");//clear the console screen
                GotoXY(x, y);
                Insert_4_arr();// Method 1 -> 3 arrow
                _getch();//read a single character
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");//clear the console screen
                Shell2_arr();// Method 2 -> 3 arrow
                fflush (stdin);//clears buffer
                _getch();//read a single character
                system("CLS");
                break;
            case 2:
                colour(11);
                system("CLS");//clear the console screen
                QuickSort_arr();// Method 3 -> 3 arrow
                fflush (stdin);//clears buffer
                _getch();//read a single character
                system("CLS");
                break;
            case 3:
                colour(11);
                system("CLS");//clear the console screen
                table_arr();// Method 3 -> 3 arrow
                fflush (stdin);//clears buffer
                _getch();//read a single character
                system("CLS");
                break;
            case 4:
                colour(11);
                GotoXY(45, 24);
                menu();//past menu
                break;
            }
            break;

        }
    }
}
//menu for inserting and sorting arrays by the Insert_4 method
void Insert_4_arr()
{
    system("cls");
    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"Insert_4_arr_direct","Insert_4_arr_random","Insert_4_arr_back","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);
    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("Insert 4 for vector\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");//clear the console screen
                printf("Insert 4 direct vector\n");
                direct_arr(1);//fill direct vect with 1 method
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");//clear the console screen
                printf("Insert 4 random vector\n");
                random_arr(1);//fill random vect with 1 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2:
                colour(11);
                system("CLS");//clear the console screen
                printf("Insert 4 back vector\n");
                back_arr(1);//fill back vect with 1 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 3:
                colour(11);
                GotoXY(45, 24);
                array_methods();//past menu
                break;
            }
            break;

        }
    }
}
//array sorting option menu by the Shell 2 method
void Shell2_arr()
{
    system("cls");
    ConsoleCursorVisible(0, 100);//visibility of the cursor in the console and its size

    const char* menuOptions[] = {"Shell2_arr_direct","Shell2_arr_random","Shell2_arr_back","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);
    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("Shell 2 for vector\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");//clear the console screen
                printf("Shell 2 back vector\n");
                direct_arr(2);//fill direct vect with 2 method
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");//clear the console screen
                printf("Shell 2 back vector\n");
                random_arr(2);//fill random vect with 2 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2:
                colour(11);
                system("CLS");//clear the console screen
                printf("Shell 2 back vector\n");
                back_arr(2);//fill back vect with 2 method
                fflush (stdin); //clears buffer
                _getch();//read a single character
                system("CLS");
                break;
            case 3:
                colour(11);
                array_methods();//past menu
                break;
            }
            break;

        }
    }
}
void QuickSort_arr()
{
    system("cls");


    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"QuickSort_arr_direct","QuickSort_arr_random","QuickSort_arr_back","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;


    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("Quick Sort for vector\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }


        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                printf("Quick Sort back vector\n");
                direct_arr(3);//fill direct vect with 3 method
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                printf("Quick Sort back vector\n");
                random_arr(3);//fill random vect with 3 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2:
                colour(11);
                system("CLS");
                printf("Quick Sort back vector\n");
                back_arr(3);//fill back vect with 3 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 3:
                colour(11);
                array_methods();//past menu
                break;
            }
            break;
        }
    }
}

void direct_arr(int z)
{
    system("cls");


    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"direct arr fill and show small vector","direct arr time large vector","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("direct for vector\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                GotoXY(x, y);
                if(arr_n<15)
                    fill_show_arr(z,1);//The function of filling the array, sorting and displaying the result
                else
                    printf("do less length arr<15");//condition for getting rid of a large array
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                time_arr(z,1);// Function to measure execution time of methods
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2://past menu depending on method
                colour(11);
                if(z==1)
                {
                    system("CLS");
                    Insert_4_arr();
                    system("CLS");
                    break;
                }
                else if (z==2)
                {
                    system("CLS");
                    Shell2_arr();
                    system("CLS");
                    break;
                }
                else if(z==3)
                {
                    system("CLS");
                    QuickSort_arr();
                    system("CLS");
                    break;
                }

            }
        }
    }
}

void random_arr(int z)
{
    system("cls");

    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"random arr fill and show small mas","random arr time large mas","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;


    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("random for vector\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                GotoXY(x, y);
                if(arr_n<15)
                    fill_show_arr(z,2);//The function of filling the array, sorting and displaying the result
                else
                    printf("do less length arr<15");
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                time_arr(z,2);// Function to measure execution time of methods
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2://past menu depending on method
                colour(11);
                if(z==1)
                {
                    system("CLS");
                    Insert_4_arr();
                    system("CLS");
                    break;
                }
                else if (z==2)
                {
                    system("CLS");
                    Shell2_arr();
                    system("CLS");
                    break;
                }
                else if(z==3)
                {
                    system("CLS");
                    QuickSort_arr();
                    system("CLS");
                    break;
                }
            }
        }
    }
}
void back_arr(int z)
{
    system("cls");


    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"back arr fill and show small mas","back arr time large mas","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;


    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("back for vector\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                GotoXY(x, y);
                if(arr_n<15)
                    fill_show_arr(z,3);//The function of filling the array, sorting and displaying the result
                else
                    printf("do less length arr<15");
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);//
                system("CLS");
                time_arr(z,3);// Function to measure execution time of methods
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2:
                colour(11);
                if(z==1)
                {
                    system("CLS");
                    Insert_4_arr();
                    system("CLS");
                    break;
                }
                else if (z==2)
                {
                    system("CLS");
                    Shell2_arr();
                    system("CLS");
                    break;
                }
                else if(z==3)
                {
                    system("CLS");
                    QuickSort_arr();
                    system("CLS");
                    break;
                }
            }
        }
    }
}

void fill_show_arr(int x,int r)
{
    //selection of filling depending on the parameter
    if(r==1)
        direct_vect_fill();//fill direct vect
    else if(r==2)
        random_vect_fill();//fill random vect
    else if(r==3)
        back_vect_fill();//fill back vect
    //out first
    printf("\nStart arr sort:\n");
    for ( int j=0; j<arr_n; j++)

        printf("%d\t",arr[j]);
    //choosing a method depending on the parameter
    if(x==1)
        Insert4();
    else if (x==2)
        Shell_2();
    else if(x==3)
        QuickSort(0, arr_n-1);
    //out result
    printf("\nFinish arr sort:\n");
    for (int  j=0; j<arr_n; j++)
        printf("%d\t",arr[j]);
}
void time_arr(int x,int r)//x-method r-direct/random/back
{
    float cell;
    //choosing a method depending on the parameter
    if (x==1)
        insert4_arr(r);
    else if (x==2)
        Shell_2_arr(r);
    else if (x==3)
        QSortMeasurement_vect(r);
    cell = MeasurementProcessing();
    printf("%.3f",cell);
}

void massive_methods()
{
    system("cls");

    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"Insert_4_mas","Shell_2_mas","QuickSort_mas","Table_mas","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;


    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("Massive methods\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }


        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                GotoXY(x, y);
                Insert_4_mas();// Method 1 -> 3 arrow
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                Shell_2_mas();// Method 2 -> 3 arrow
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2:
                colour(11);
                system("CLS");
                QuickSort_mas();// Method 3 -> 3 arrow
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 3:
                colour(11);
                system("CLS");
                table_mas();// table for massive
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 4:
                colour(11);
                GotoXY(45, 24);
                menu();//past menu
                break;
            }
            break;

        }
    }
}

void Insert_4_mas()
{
    system("cls");

    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"Insert 4 mas direct","Insert 4 mas random","Insert 4 mas back","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("Insert 4 for massive\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }


        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                GotoXY(x, y);
                printf("Insert 4 direct massive\n");
                direct_mas(1);//fill direct massive with 1 method
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                printf("Insert 4 random massive\n");
                random_mas(1);//fill random massive with 1 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2:
                colour(11);
                system("CLS");
                printf("Insert 4 back massive\n");
                back_mas(1);//fill back massive with 1 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 3:
                colour(11);
                GotoXY(45, 24);
                massive_methods();//past menu
                break;
            }
            break;

        }
    }
}
void Shell_2_mas()
{
    system("cls");

    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"Shell 2 mas direct","Shell 2 mas random","Shell 2 mas back","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("Shell 2 for massive\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }


        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                GotoXY(x, y);
                printf("Shell 2 direct massive\n");
                direct_mas(2);//fill direct massive with 2 method
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                printf("Shell 2 random massive\n");
                random_mas(2);//fill random massive with 2 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2:
                colour(11);
                system("CLS");
                printf("Shell 2 back massive\n");
                back_mas(2);//fill back massive with 2 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 3:
                colour(11);
                GotoXY(45, 24);
                massive_methods();//past menu
                break;
            }
            break;

        }
    }
}
void QuickSort_mas()
{
    system("cls");

    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"QuickSort mas direct","QuickSort mas random","QuickSort mas back","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("Quick Sort for massive\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                GotoXY(x, y);
                printf("Quick Sort direct massive\n");
                direct_mas(3);//fill direct massive with 3 method
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                printf("Quick Sort random massive\n");
                random_mas(3);//fill random massive with 3 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2:
                colour(11);
                system("CLS");
                printf("Quick Sort back massive\n");
                back_mas(3);//fill back massive with 3 method
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 3:
                colour(11);
                GotoXY(45, 24);
                massive_methods();//past menu
                break;
            }
            break;
        }
    }
}

void direct_mas(int z)
{
    system("cls");

    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"direct mas fill and show small mas","direct mas time large mas","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;


    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("direct for massive\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                if (cross <10 && row<10 && column<10)
                    fill_show_mas(z,1);//The function of filling the array, sorting and displaying the result
                else
                    printf("do less cross<10 row<10 column<10");
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                time_mas(z,1);// Function to measure execution time of methods
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2://past menu depending on method
                colour(11);
                if(z==1)
                {
                    system("CLS");
                    Insert_4_mas();
                    system("CLS");
                    break;
                }
                else if (z==2)
                {
                    system("CLS");
                    Shell_2_mas();
                    system("CLS");
                    break;
                }
                else if(z==3)
                {
                    system("CLS");
                    QuickSort_mas();
                    system("CLS");
                    break;
                }
            }
        }
    }
}

void random_mas(int z)
{
    system("cls");

    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"random mas fill and show small mas","random mas time large mas","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("random for massive\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                if (cross <10 && row<10 && column<10)
                    fill_show_mas(z,2);//The function of filling the array, sorting and displaying the result
                else
                    printf("do less cross<10 row<10 column<10");
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                time_mas(z,2);// Function to measure execution time of methods
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2://past menu depending on method
                colour(11);
                if(z==1)
                {
                    system("CLS");
                    Insert_4_mas();
                    system("CLS");
                    break;
                }
                else if (z==2)
                {
                    system("CLS");
                    Shell_2_mas();
                    system("CLS");
                    break;
                }
                else if(z==3)
                {
                    system("CLS");
                    QuickSort_mas();
                    system("CLS");
                    break;
                }
            }
        }
    }
}

void back_mas(int z)
{
    system("cls");

    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"back mas fill and show small mas","back mas time large mas","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 13);
        printf("random for massive\n");

        colour(9);
        int x = 45, y = 15;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                if (cross <10 && row<10 && column<10)
                    fill_show_mas(z,3);//The function of filling the array, sorting and displaying the result
                else
                    printf("do less cross<10 row<10 column<10");
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                time_mas(z,3);// Function to measure execution time of methods
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2://past menu depending on method
                colour(11);
                if(z==1)
                {
                    system("CLS");
                    Insert_4_mas();
                    system("CLS");
                    break;
                }
                else if (z==2)
                {
                    system("CLS");
                    Shell_2_mas();
                    system("CLS");
                    break;
                }
                else if(z==3)
                {
                    system("CLS");
                    QuickSort_mas();
                    system("CLS");
                    break;
                }
            }
        }
    }
}
void fill_show_mas(int x,int r)
{
    //selection of filling depending on the parameter
    if(r==1)
        direct_3d_fill();
    else if(r==2)
        random_3d_fill();
    else if(r==3)
        back_3d_fill();
    //out first
    printf("\nStart mas sort 3d:\n");
    for (int k=0; k<cross; k++)
    {
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<column; j++)
            {
                printf("%d\t",mas[k][i][j]);
            }
            printf("\n");
        }
        printf ("\n\n");
    }
    //choosing a method depending on the parameter
    if(x==1)
        Insertion_Sorting_4();
    else if (x==2)
        shell_2_sort();
    else if(x==3)
        QSort (0, cross-1);
    //out finish
    printf("\nFinish mas sort 3d:\n");
    for (int k=0; k<cross; k++)
    {
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<column; j++)
            {
                printf("%d\t",mas[k][i][j]);
            }
            printf("\n");
        }
        printf ("\n\n");
    }
}
void time_mas(int x,int r)//x-method r-direct/random/back
{
    float cell;
    //choosing a method depending on the parameter
    if (x==1)
        insert4_3d(r);
    else if (x==2)
        Shell_2_3d(r);
    else if (x==3)
        QSortMeasurement_3d(r);
    cell = MeasurementProcessing();
    printf("%.3f",cell);
}
void menu()
{
    system("cls");

    initialization_memory();// Allocation of memory for a three-dimensional array

    ConsoleCursorVisible(0, 100);

    const char* menuOptions[] = {"Array","Massive","Exit"};
    int numOptions = sizeof(menuOptions) / sizeof(menuOptions[0]);

    int active_menu = 0;

    char key;//key pressed code
    while (1)// until the loophole
    {
        colour(6);
        GotoXY(46, 10);
        printf("To switch to\n");
        GotoXY(46, 11);
        printf("another mode,\n");
        GotoXY(46, 12);
        printf("switch using\n");
        GotoXY(44, 13);
        printf("the up and down \n");
        GotoXY(44, 14);
        printf("arrows on keyboard\n");
        GotoXY(44, 15);
        printf("and press enter.\n");

        colour(9);
        int x = 45, y = 17;
        GotoXY(x, y);

        for (int i = 0; i < numOptions; i++)
        {
            GotoXY(x, y++);
            if (i == active_menu)
            {
                colour(7);
                printf("* %s * ",  menuOptions[i]);
            }
            else
                printf("  %s   ", menuOptions[i]);
            colour(9);
        }

        key = _getch();
        if (key == -32) key = _getch(); // We catch arrows//-32 arrows
        switch (key)
        {
        case 27://escape
            exit(0);//loophole
        case 72:
            if (active_menu > 0)
                active_menu--;
            break;
        case 80:
            if (active_menu < numOptions - 1)
                active_menu++;
            break;
        case 13://enter
            switch (active_menu)
            {
            case 0:
                colour(11);
                system("CLS");
                GotoXY(x, y);
                array_methods();// array 3 method 3 arrow
                _getch();
                system("CLS");
                break;
            case 1:
                colour(11);
                system("CLS");
                massive_methods();// massive 3 method 3 arrow
                fflush (stdin);
                _getch();
                system("CLS");
                break;
            case 2:
                colour(11);
                GotoXY(45, 24);
                exit(0);
                break;
            }
            break;
        }
    }
    free_memory();// Release the allocated memory for the three-dimensional array
}

