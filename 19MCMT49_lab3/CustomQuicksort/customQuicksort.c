#include<stdio.h>
#include<stdlib.h>

int comparison=0, swap=0;

void swapNumbers(int *a, int *b)
{
       int temp;
	temp = *a;
	*a   = *b;
	*b   = temp;
}


int partition(int storeInput[], int startIndex, int endIndex)
{
      int pivot, i, j, k;
      pivot = storeInput[endIndex];
      i = startIndex;
      j = endIndex-1;

      for(k=startIndex; k<=endIndex-1; k++)
      {
	      while(storeInput[i] < pivot)
	      {
		      comparison++;
		      i++;
	      }
	      comparison++;

	      while(storeInput[j] > pivot)
	      {
		      comparison++;
		      j--;
	      }
	      comparison++;

	      if(i < j)
	      {
		      swap++;
		      swapNumbers(&storeInput[i], &storeInput[j]);
	      }
	      else
		      break;
      }
      swapNumbers(&storeInput[i], &storeInput[endIndex]);
      swap++;

      return i;
}
				       
				       	       
void quicksort(int storeInput[], int startIndex, int  endIndex)
{
        int partitionIndex;
	if(startIndex < endIndex)
	{
               partitionIndex =	partition(storeInput, startIndex, endIndex);
	       quicksort(storeInput, startIndex, partitionIndex - 1);
	       quicksort(storeInput, partitionIndex + 1, endIndex);
	}
}

int main(int argc, char const *argv[])
{
	int limit, i, startIndex, endIndex;
	FILE *inputFile, *outputFile;

	inputFile = fopen(argv[1], "r");
	if(inputFile == NULL)
	{
		printf("\nError in opening input file.\n");
		exit(0);
	}
	fscanf(inputFile, "%d", &limit);
        
        int storeInput[limit];
        for(i=0; i<limit; i++)
	{
	        fscanf(inputFile, "%d\n", &storeInput[i]);
	}

	fclose(inputFile);

	startIndex = 0;
	endIndex = limit-1;

	quicksort(storeInput, startIndex, endIndex);

	printf("\nNumber of comparisons in quicksort : %d\n", comparison);
	printf("\nNumber of swaps in quicksort : %d\n", swap);

	outputFile = fopen(argv[2], "w+");
        if(outputFile == NULL)
        {
   	        printf("\nError in opening output file in write+ mode.\n");
                exit(0);
        }
	else
	{
		fprintf(outputFile, "Sorted elements by custom Quick Sort.\n\n");
		for(i=0; i<limit ; i++)
			fprintf(outputFile, "%d\n", storeInput[i]);
	}
	fclose(outputFile);

	return 0;
}

