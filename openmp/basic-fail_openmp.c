// OpenMP program to try to make code fail
// using C language 

// OpenMP header 
#include <omp.h> 

#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char* argv[]) 
{ 
    int numt,tid;   

	// Beginning of parallel region 
	#pragma omp parallel
	{ 

        int j;

        numt=omp_get_num_threads();
        tid=omp_get_thread_num();

        //Introduce delay to get other threads getting scheduled
        for(j=0;j<10000000;j++);

		printf("Hello World... from thread = %d of %d\n", 
			tid,numt); 
	} 
	// Ending of parallel region 
} 
