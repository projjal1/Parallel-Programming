/*Code demonstrating the use of explicit barrier*/

#include<omp.h>
#include<stdio.h>

int main()
{
    int numt;

    #pragma omp parallel default(shared)  
    {   
        int j;
        int tid=omp_get_thread_num();
        if(tid==0)
        {
            for(j=0;j<1000000;j++)
            numt=omp_get_num_threads();
        }
        #pragma omp barrier
        printf("Hello world from thread %d of %d.\n",tid,numt);
    }
}