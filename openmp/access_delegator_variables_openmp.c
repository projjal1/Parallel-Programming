#include<omp.h>
#include<stdio.h>
#define size 3 
#define step 1 

int main(void)
{
    int i,sum=0;
    int a[size];
    for(i=0;i<size;i++)  a[i]=i;

    #pragma omp parallel 
    {
        int tsum=0;
        printf("[TID:%d]A(tsum)=%x\n",omp_get_thread_num(),&tsum);

        #pragma omp for 
        for(i=0;i<size;i+=step)
        {
            int j,start=i,end=i+step-1;
            printf("[TID:%d], Delegating Sum(%d,%d),A(tsum)=%x\n",
            omp_get_thread_num(),start,end,&tsum);
            
            #pragma omp task shared(tsum)
            {
                int psum=0;
                for(j=start;j<=end;j++)   psum+=a[j];
                printf("[TID:%d], Task Sum(%d,%d),A(tsum)=%x\n",
                omp_get_thread_num(),start,end,&tsum);

                #pragma omp critical
                tsum+=psum;
            }
        }
        #pragma omp critical
        sum+=tsum;
    }
    printf("Sum=%d\n",sum);
}