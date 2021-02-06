//Code to demonstrate asynchronous thread synchronisation

#include<omp.h>
#include<stdio.h>

int main(void)
{
    int numt;
    #pragma omp parallel default(shared)
    {
        int j,tid;
        #pragma omp single nowait
        {
            for(j=0;j<1000000;j++)
            numt=omp_get_num_threads();
        }
        tid=omp_get_thread_num();
        printf("Hello World from %d of %d.\n",tid,numt);
    }
}