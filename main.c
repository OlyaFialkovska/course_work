#include <stdio.h>
#include <stdlib.h>
const int p=3,m=3,n=4;
int mas [3][3][4];
void Insertion_Sorting_4()
{
    int b[m][n],L,R,s,r,k,i,j;
    //Insertion_Sorting_4 start
    for(k=0; k<p; k++)
    {
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                b[i][j]=mas[k][i][j];
        L=0;
        R=k;
        while(L<R)
        {
            s=L+((R-L)/2);
            if(b[0][0]>=mas[s][0][0])
            {
                L=s+1;
            }
            else
            {
                R=s;
            }
        }

        for(r=k-1; r>=R; r--)
        {
            for(i=0; i<m; i++)
            {
                for(j=0; j<n; j++)
                {
                    mas[r+1][i][j]=mas[r][i][j];
                }
            }
        }
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                mas[R][i][j]=b[i][j];

    }
    //Insertion_Sorting_4 finished
}
void shell_sort()
{
    const int T=3;
    int h[T],b[m][n];
    int t,k,i,j,r,l;

    h[0]=4;
    h[1]=2;
    h[2]=1;

    for(t=0; t<T; t++)
    {
        k=h[t];

        for(l=0; l<p; l++)
        {
            for(i=0; i<m; i++)
                for(j=0; j<n; j++)
                    b[i][j]=mas[l][i][j];

            r=l;

            while(r>=k && b[0][0]<mas[r-k][0][0])
            {
                for(i=0; i<m; i++)
                    for(j=0; j<n; j++)
                        mas[r][i][j]=mas[r-k][i][j];

                r=r-k;
            }

            for(i=0; i<m; i++)
                for(j=0; j<n; j++)
                    mas[r][i][j]=b[i][j];
        }

    }

}

void QSort(int L,int R)
{
    int x,b,i,j,k,r;
    x=mas[L+(R-L)/2][0][0];
    k=L;
    r=R;

    while(k<=r)
    {
        while(mas[k][0][0]<x)
        {
            k++;
        }
        while(mas[r][0][0]>x)
        {
            r--;
        }
        if(k<=r)
        {
            for(i=0; i<m; i++)
                for(j=0; j<n; j++)
                {
                    b=mas[k][i][j];
                    mas[k][i][j]=mas[r][i][j];
                    mas[r][i][j]=b;
                }
            k++;
            r--;
        }
    }
    if(L<r)
    {
        QSort(L,r);
    }
    if(k<R)
    {
        QSort(k,R);
    }
}
void out_mas()
{
    int k,i,j;
    //Out start
    for(k=0; k<p; k++)
    {
        printf("pereris %d\n",k);
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d\t",mas[k][i][j]);
            }
            printf("\n");
        }
    }
    //Out finished
}
int main()
{
    int k,i,j,L=0,R=p-1;
    //Input start
    srand(time(NULL));
    for(k=0; k<p; k++)
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                mas[k][i][j]=rand()%20-10;
    //Input finished

    printf("\t|Start:|\n");
    out_mas();

    //Insertion_Sorting_4();
    //shell_sort();
    //QSort(L,R);

    printf("\n\t|Finish:|\n");
    out_mas();

    return 0;
}
