#include "time.h" // Include a header file for working with time
#include "Common.h" //Include header file "Common.h"
// Function to sort 4 inserts for vector array
clock_t Insert4()
{
    int Elem, L, R, j;
    clock_t time_start, time_stop;
    time_start = clock();
    for(int i=1; i<=arr_n-1; i++)
    {
        Elem=arr[i];
        L=0;
        R=i;
        while (L<R)
        {
            j=(L+R)/2;
            if (arr[j]<=Elem)
            {
                L=j+1;
            }
            else R=j;
        }
        for (int k=i-1; k>=R; k--)
        {
            arr[k+1]=arr[k];
        }
        arr[R]=Elem;
    }
    time_stop = clock();
    return time_stop - time_start;
}
//Shell sorting function for vector array
clock_t Shell_2()
{
    int b, t, j, k;
    int Stages[t];
    clock_t time_start, time_stop;
    time_start = clock();
    if (arr_n<4) t=1;
    else t=(int)log2f((float)arr_n)-1;
    Stages[t-1]=1;
    for (int i=t-2; i>=0; i--)
        Stages[i]=2*Stages[i+1]+1;
    for (int p=0; p<t; p++)
    {
        k=Stages[p];
        for (int i=k; i<arr_n; i++)
        {
            j=i;
            while (j>=k && arr[j]<arr[j-k])
            {
                b=arr[j];
                arr[j]=arr[j-k];
                arr[j-k]=b;
                j=j-k;
            }
        }
    }
    time_stop = clock();
    return time_stop - time_start;
}
// Quick sort function for vector array
void QuickSort(int L, int R)
{
    int B, b, i, j;
    B=arr[(L+R)/2];
    i=L;
    j=R;
    while (i<=j)
    {
        while (arr[i] < B) i=i+1;
        while (arr[j] > B) j=j-1;
        if (i<=j)
        {
            b=arr[i];
            arr[i]=arr[j];
            arr[j]=b;
            i=i+1;
            j=j-1;
        }
    }
    if (L<j) QuickSort(L,j);
    if (i<R) QuickSort(i,R);
}
