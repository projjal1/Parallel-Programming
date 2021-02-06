//Code to implement matrix-vector product using opemMP

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define size 256

int main(void)
{

    int a[size][size],b[size];
    int y[size];    
    double t1,t2;

    for(int i=0;i<size;i++)
    {
        b[i]=i;
        for (int j=0;j<size;j++)
            a[i][j]=i*j;
    }


    t1=omp_get_wtime();

    #pragma omp parallel default(shared)
    {
        int i,j;
        int* results_private = (int*)calloc(size, sizeof(int));

        #pragma omp parallel for schedule(dynamic,16)
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                results_private[i]+=a[i][j]*b[j];
            }
        }

        #pragma omp critical
        {
            for(i=0;i<size;i++)  y[i]+=results_private[i];
        }
    }

    t2=omp_get_wtime();

    for(int i=0;i<size;i++)
    {
        printf("%d\n",y[i]);
    }

    printf("Time for execution %g\n",t2-t1);

    return 0;
}
