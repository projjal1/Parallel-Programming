//Code to implement dot product using opemMP

#include<omp.h>
#include<stdio.h>
#define size 10000

int main(void)
{
    int a[size],b[size];
    int i=0;
    int dot=0;
    double t1,t2;

    for(;i<size;i++)
    {
        a[i]=i;b[i]=i;
    }

    t1=omp_get_wtime();

    #pragma omp parallel private(i) 
    {
        int pdot=0;

        #pragma omp parallel for schedule(dynamic,500)
        for(i=0;i<size;i++)
            pdot+=a[i]*b[i];

        #pragma omp critical 
        dot+=pdot;
    }

    t2=omp_get_wtime();

    printf("The dot product is %d. Time is %g\n",dot,t2-t1);
}
