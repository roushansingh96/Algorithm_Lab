#include<stdio.h>
#include<time.h>

int main()
{
        long int n, i, counter=0;
	clock_t start, end;
	double cpu_time_used;

	printf("\nEnter input size for complexity N : ");
	scanf("%ld", &n);

	start = clock();

	for(i=0; i<n; i++)
		counter++;

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("\nCPU time used for complexity N : %lf\n", cpu_time_used);

        return 0;		
}

