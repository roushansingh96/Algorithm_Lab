#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char const *argv[])
{
	long int n, i, j, temp;
	int flag = 0;
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

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(inputs[j] > inputs[j+1])
			{
				temp = inputs[j];
				inputs[j] = inputs[j+1];
				inputs[j+1] = temp;
				flag = 1;
			}
		}

		if(flag == 0)
			break;
	}

	end = clock();
	
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	printf("CPU time used by BubbleSort : %lf\n", cpu_time_used);

        outputFile = fopen(argv[2], "w+");
  	if(outputFile == NULL)
        {
                printf("\nError in opening output file in write+ mode.\n");
                exit(0);
        }
	else
	{
		fprintf(outputFile, "Sorted elements by BubbleSort.\n\n");
		for(i=0; i<n ; i++)
			fprintf(outputFile, "%ld\n", inputs[i]);
	}
	fclose(outputFile);

	return 0;
}	
