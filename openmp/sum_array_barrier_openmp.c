//Code to demonstrate implementation of barrier in OpenMP
#include<omp.h>
#include<stdio.h>
#define size 600
#define step 100 

int main(void)
{
    int i,sum=0;
    int a[size];
    for(i=0;i<size;i++)  a[i]=i;

    #pragma omp parallel
    {
        #pragma omp for nowait 
        for(i=0;i<size;i+=step)
        {
            int j,start=i,end=i+step-1;
            printf("Computing sum...\n");
            #pragma omp task
            {
                int psum=0;
                printf("Task computing ...\n");
                for(j=start;j<=end;j++)
                    psum+=a[j];
                
                #pragma omp critical
                sum+=psum;
            }
        }
        #pragma omp barrier   //Tasks need to be completed before Barrier 
        printf("Sum=%d\n",sum);
    }
}