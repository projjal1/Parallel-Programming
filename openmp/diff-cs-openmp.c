//Code to demostrate usage of two different critical sections

#include<omp.h>
#include<stdio.h>
#define arr_size 1000

int main(void)
{
    //define array
    int arr[arr_size];
    int i=0,sum=0,prod=0;
    for(i=0;i<arr_size;i++)  arr[i]=i;

    //Execution metrics
    double t1,t2;
    t1=omp_get_wtime();

    #pragma omp parallel default(shared)
    {
        int psum=0,pprod=0;
        #pragma omp for
        for(i=0;i<arr_size;i++)  
        {
            psum+=arr[i]; pprod*=arr[i];
        }
        //Critical section 1
        #pragma omp critical(section1)
        {
            printf("In CS 1\n");
            //Some delay
            for(int j=0;j<1000000;j++);
            sum+=psum;
            printf("Out CS 1\n");
        }
        //Critical section 2
        #pragma omp critical(section2)
        {
            printf("In CS 2\n");
            //Some delay
            for(int j=0;j<1000000;j++);
            prod*=pprod;
            printf("Out CS 2\n");
        }
    }

    t2=omp_get_wtime();

    printf("Sum is %d\n",sum);
    printf("Product is %d\n",prod);
    printf("Time for execution %g\n",t2-t1);
    return 0;
}