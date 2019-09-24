#include<stdio.h>
#include<time.h>

int main()
{
        long int n, size=1, i, counter=0;
        clock_t start, end;
        double cpu_time_used;

	printf("\nEnter input size for complexity 2^N : ");
	scanf("%ld", &n);

	while(n != 0)
	{
		size *= 2;
		--n;
	}

        start = clock();

	for(i=0; i<size ;i++)
		counter++;

        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("\nCPU time used for complexity 2^N : %lf\n", cpu_time_used);

	return 0;
}

