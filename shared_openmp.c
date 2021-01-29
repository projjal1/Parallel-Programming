// OpenMP program to print Hello World 
// using C language 

// OpenMP header 
#include <omp.h> 

#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char* argv[]) 
{ 
    int numt,tid;   

	// Beginning of parallel region 
	#pragma omp parallel private (tid) shared (numt)
	{ 
        numt=omp_get_num_threads();
        tid=omp_get_thread_num();

		printf("Hello World... from thread = %d\n", 
			omp_get_thread_num()); 
	} 
	// Ending of parallel region 
} 
