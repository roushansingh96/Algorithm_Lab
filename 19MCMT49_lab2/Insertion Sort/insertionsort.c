#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char const *argv[])
{
	long int n, i, j, key;
	clock_t start, end;
	double cpu_time_used;

        FILE *inputFile, *outputFile;

        inputFile = fopen(argv[1], "r");
        if(inputFile == NULL)
        {
                printf("\nError in opening input file in read mode.\n");
                exit(0);
        }
        fscanf(inputFile, "%ld", &n);

        long int inputs[n];

        for(i=0; i<n; i++)
        {
                fscanf(inputFile, "%ld\n", &inputs[i]);
        }

        fclose(inputFile);

	start = clock();

	for(i=1; i<n; i++)
	{
		key = inputs[i];
		j = i-1;

		while(j >= 0 && inputs[j] > key)
		{
			inputs[j+1] = inputs[j];
			j -= 1;
		}

		inputs[j+1] = key;
	}

	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("CPU time used by InsertionSort : %lf\n", cpu_time_used);

	outputFile = fopen(argv[2], "w+");
        if(outputFile == NULL)
        {
   	        printf("\nError in opening output file in write+ mode.\n");
                exit(0);
        }
	else
	{
		fprintf(outputFile, "Sorted elements by Insertion Sort.\n\n");
		for(i=0; i<n ; i++)
			fprintf(outputFile, "%ld\n", inputs[i]);
	}
	fclose(outputFile);

	return 0;
}
