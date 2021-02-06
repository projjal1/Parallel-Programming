//Code to calculate sum of elements in an array using OpenMP
//Optimizing flow

#include<omp.h>
#include<stdio.h>
#define size 100000

int main(void)
{
    int i,tid,numt,sum=0;
    double t1,t2;
    int a[size];

    for(i=0;i<size;i++)  a[i]=i;

    t1=omp_get_wtime();

    //Sum in parallel
    #pragma omp parallel default(shared)  private(i,tid)
    {
        //Getting information on thread_id 
        //Getting information on number_of_threads
        tid=omp_get_thread_num();
        numt=omp_get_num_threads();
        //Use alternative of critical section on summation
        int psum=0;

        //Distribute the work
        int from = (size/numt) *tid;
        int to = (size/numt)  * (tid+1) - 1;

        if (tid==numt-1)
            to=size-1;

        //Paralellizing summation
        for(i=from;i<=to;i++)    
            psum+=a[i];

        //Set clock 
        #pragma omp critical 
        sum+=psum;
    }

    t2=omp_get_wtime();

    printf("Sum of array elements is %d. Time %g\n",sum,t2-t1);

    return 0;
}