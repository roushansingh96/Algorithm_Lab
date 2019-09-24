#include<stdio.h>
#include<time.h>

int main()
{
        long int n, i, j, counter=0;
        clock_t start, end;
        double cpu_time_used;

	printf("\nEnter input size for complexity N^2 : ");
	scanf("%ld", &n);

        start = clock();

	for(i=0; i<n ;i++)
		for(j=0; j<n; j++)
		      counter++;

        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("\nCPU time used for complexity N^2 : %lf\n", cpu_time_used);

	return 0;
}
