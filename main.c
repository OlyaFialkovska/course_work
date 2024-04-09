#include <stdio.h>
#include <stdlib.h>
const int p=3,m=3,n=4;
void Insertion_Sorting_4(int mas[p][m][n])
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
void out_mas(int mas[p][m][n])
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

    int mas [p][m][n];
    int k,i,j;

    //Input start
    srand(time(NULL));
    for(k=0; k<p; k++)
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                mas[k][i][j]=rand()%20-10;
    //Input finished

    printf("\t|Start:|\n");
    out_mas(mas);

     Insertion_Sorting_4(mas);

    printf("\n\t|Finish:|\n");
    out_mas(mas);

    return 0;
}
