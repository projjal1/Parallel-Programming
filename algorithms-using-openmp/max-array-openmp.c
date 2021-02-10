//Finding maximum in array using C (normal task)

#include<omp.h>
#include<stdio.h>
#define arr_size 500000
#define step_size 1000


int main()
{
    int a[arr_size];
    int max=0;
    int i=0;
    double t1,t2;  //Keep track of execution time

    //Initializing with default nos.
    for(i=0;i<arr_size;i++)
        a[i]=i;

    t1=omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp for schedule(dynamic,1500)
        for(i=0;i<arr_size;i+=step_size)
        {
            int start=i,end=i+step_size-1;
            int j;
            
            #pragma omp task
            {
                int pmax=0;
                for(j=start;j<=end;j++)
                {
                    if(a[j]>pmax)  pmax=a[j];
                }

                #pragma omp critical
                if(pmax>max)  max=pmax;
            }
        }
    }

    t2=omp_get_wtime();

    printf("Maximum element is %d\n",max);
    printf("Task completed in time:%g\n",t2-t1);
    return 0;
}