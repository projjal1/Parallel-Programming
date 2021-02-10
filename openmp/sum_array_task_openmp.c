//Code in OpenMP to calculate sum of array using OpenMP tasks

#include<omp.h>
#include<stdio.h>
#define size 600
#define step_size 100

int main(void){
    int i,sum=0;
    int a[size];
    
    double t1,t2;

    t1=omp_get_wtime();

    for(int i=0;i<size;i++)  a[i]=i;

    #pragma omp parallel
    {
        #pragma omp for schedule(dynamic,200)
        for(i=0;i<size;i+=step_size)
        {
            int j,start=i,end=i+step_size-1;
            printf("Computing sum (%d,%d) from %d of %d\n",start,end,
                   omp_get_thread_num(),omp_get_num_threads());

            #pragma omp task
            {
                int psum=0;
                for(j=start;j<=end;j++)
                    psum+=a[j];

                #pragma omp critical
                sum+=psum;
            }
        }
    }

    t2=omp_get_wtime();

    printf("Sum = %d. Time is %g\n",sum,t2-t1);
}
