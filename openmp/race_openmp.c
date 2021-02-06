//Program to use race conditions

#include<omp.h>
#include<stdio.h>

int main(void)
{
    int numt;
    
    #pragma omp parallel default(shared)
    {
        int j;
        int tid=omp_get_thread_num();

        //Initialize numt if tid == 0 
        if(tid==0)
        {
            for(j=0;j<1000000;j++);
            numt=omp_get_num_threads();
        }
    }

    #pragma omp parallel default(shared)
    {
        int tid=omp_get_thread_num();
        printf("Hello world from thread %d of %d\n",tid,numt);
    }
}