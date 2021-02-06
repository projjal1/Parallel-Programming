//Sample code to implement functions to gauge performance 

#include <omp.h>
#include <stdio.h>

int main(void)
{
    //Get execution time of code 
    printf("Execution time %g\n",omp_get_wtime());
    //Get resolution (unit) of time 
    printf("Resolution time %g",omp_get_wtick());
    return 0;
}