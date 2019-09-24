#include<stdio.h>
#include<time.h>

int main()
{
        long int n, i, j, k, counter=0;
        clock_t start, end;
        double cpu_time_used;

	printf("\nEnter input size for complexity N^3 : ");
	scanf("%ld", &n);

        start = clock();

	for(i=0; i<n ;i++)
		for(j=0; j<n; j++)
			for(k=0; k<n; k++)
				counter++;

        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("\nCPU time used for complexity N^3 : %lf\n", cpu_time_used);

	return 0;
}
