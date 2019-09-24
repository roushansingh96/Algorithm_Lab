#include<stdio.h> 
#include<stdlib.h> 
 
int max(int maxA, int maxB) 
{  
        int findMax; 
        findMax = (maxA > maxB) ? maxA : maxB; 
        return findMax; 
} 

int main(int argc, char *argv[])
{
        int W, n, i, j, final, w, maxA, maxB, optimalCost;
        FILE *inputFile, *outputFile;
        
	// Input from file.
	
        inputFile = fopen(argv[1], "r");
        if(inputFile == NULL)
        {
                printf("\nError in opening input file in read mode.\n");
                exit(0);
        }
        fscanf(inputFile, "%d", &W);
        fscanf(inputFile, "%d", &n);

        int value[n];
        for(i=0; i<n; i++)
                fscanf(inputFile, "%d", &value[i]);

        int weight[n];
        for(i=0; i<n; i++)
                fscanf(inputFile, "%d", &weight[i]);

        fclose(inputFile);

	//  0/1 Knapsack implementation iteratively.
	int binary[n];

	for(i=0; i<n; i++)
		binary[i] = 0;

        int profit[n+1][W+1];
 
        for(i=0; i<=n ;i++) 
                profit[i][0] = 0; 
 
        for(i=0; i<=W; i++) 
                profit[0][i] = 0; 
         
        for(i=1; i<=n; i++) 
        { 
               for(j=1; j<=W; j++) 
                { 
                        if(j-weight[i] >= 0) 
                       { 
                                maxA = value[i] + profit[i-1][j-weight[i]]; 
                                maxB = profit[i-1][j]; 
 
                                profit[i][j] = max(maxA, maxB);	
                        } 
                        else
                        {
                                profit[i][j] = profit[i-1][j];
                        }
                }
        }

	optimalCost = profit[n][W];
        final = profit[n][W];
	w = W;
	for(i=n; i>0 && final>0; i--)
	{
		if(final == profit[i-1][w])
			continue;
		else
		{
		        binary[i] = 1;
			final -= value[i-1];
			w -= weight[i-1];
		}
	}

	// Output in File.
	
	outputFile = fopen(argv[2], "w+");
	if(outputFile == NULL)
	{
		printf("\nError in opening file in write+ mode.\n");
		exit(0);
	}
	fprintf(outputFile, "%d\n", optimalCost);

	for(i=0; i<n; i++)
		fprintf(outputFile, "%d " ,binary[i]);

	fprintf(outputFile, "\n");

	for(i=0; i<n; i++)
	{
		if(binary[i] == 1)
			fprintf(outputFile, "%d ", i+1);
	}

        return 0;
}



                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
                                                                                                                                                                                                                                                               
                                                                           
