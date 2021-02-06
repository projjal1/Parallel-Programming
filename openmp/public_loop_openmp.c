//Making loop variables public for OpenMP to handle 

#include<omp.h>
#include<stdio.h>
#define size 100000

int main(void)
{
    int i, sum=0;
    double t1,t2;
    int arr[size];
    for(i=0;i<size;i++)  arr[i]=i;

    t1=omp_get_wtime();

    #pragma omp pragma default(shared)
    {
        int psum=0;

        #pragma omp for
        for(int i=0;i<size;i++)
            psum+=arr[i];

        #pragma omp critical
        sum+=psum; 
    }

    t2=omp_get_wtime();

    printf("Sum of elements: %d. Time is %g\n",sum,t2-t1);

    return 0;
}