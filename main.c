#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int p=2,m=3,n=4;
    int mas [p][m][n];
    int k,i,j;

    int b[m][n],L,R,s,r;

    //Input start
    srand(time(NULL));
    for(k=0; k<p; k++)
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                mas[k][i][j]=rand()%20-10;
    //Input finished

    //Out start
    printf("Start:\n");
    for(k=0; k<p; k++)
    {
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d\t",mas[k][i][j]);
            }
            printf("\n");
        }
        printf("pereris %d\n",k);
    }
    //Out finished

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
            if(b[1][1]>=mas[s][1][1])
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
                printf("\n");
            }
            printf("p2=%d\n",k);
        }
        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
        mas[R][i][j]=b[i][j];

    }

    //Out start
    printf("Finish:\n");
    for(k=0; k<p; k++)
    {
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d\t",mas[k][i][j]);
            }
            printf("\n");
        }
        printf("pereris %d\n",k);
    }
    //Out finished
    return 0;
}
