/*
Problem : Add two matrix in CUDA 
Author : Projjal Gop
*/

#include<stdio.h>
#include<stdlib.h>
#define n 512

__global__ void add(int *a,int *b,int *c)
{
	c[blockIdx.x]=a[blockIdx.x]+b[blockIdx.x];
}

int main(void)
{
	int *a,*b,*c;
	int *d_a,*d_b,*d_c;
	int size=n * sizeof(int);
	 
	cudaMalloc((void **)&d_a,size);
	cudaMalloc((void **)&d_b,size);
	cudaMalloc((void **)&d_c,size);
	
	a=(int *)malloc(size); 
	b=(int *)malloc(size); 
	c=(int *)malloc(size);
	
	for(int i=0;i<n;i++)
	{
		a[i]=rand();
		printf("%d , ",a[i]);
	}
	for(int i=0;i<n;i++)
	{
		b[i]=rand();
		printf("%d , ",b[i]);
	}
		
	cudaMemcpy(d_a,a,size,cudaMemcpyHostToDevice);
	cudaMemcpy(d_b,b,size,cudaMemcpyHostToDevice);
	
	add<<<n,1>>>(d_a,d_b,d_c);
	
	cudaMemcpy(c,d_c,size,cudaMemcpyDeviceToHost);
	
	free(a); free(b); free(c);
	
	for (int i=0;i<n;i++)
		printf("%d ",c[i]);
	return 0;
}