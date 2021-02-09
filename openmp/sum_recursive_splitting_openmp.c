//Code to demonstrate recursive splitting in OpenMP
#include<omp.h>
#include<stdio.h>
#define size 10 
#define step 2

int do_sum(int a[],int start,int end)
{
    int mid,x,y,res;
    if(end==start)
        res=a[start];
    else
    {
        mid=(end+start)/2;
        printf("[TID:%d] Sum(%d,%d)= Sum(%d,%d)+Sum(%d,%d)\n",omp_get_thread_num(),
        start,end,start,mid,mid+1,end);

        #pragma omp task shared(x)
        x=do_sum(a,start,mid);

        #pragma omp task shared(y)
        y=do_sum(a,mid+1,end);

        #pragma omp taskwait
        res=x+y;
    }
    printf("[TID:%d] Sum(%d,%d)= %d\n",omp_get_thread_num(),
        start,end,res);
    return res;
}

int main()
{
    int i,sum=0;
    int a[size];
    for(i=0;i<size;i++)   a[i]=i;

    #pragma omp parallel 
    #pragma omp single
    sum=do_sum(a,0,size-1);

    printf("Sum=%d\n",sum);
    return 0;
}