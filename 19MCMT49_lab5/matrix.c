#include<stdio.h>
#include<stdlib.h>

int bracket[10][10];
FILE *outputFile;

//Recursive function to set paranthesis to matrices.

void parenthesis(int i, int j)
{
	if(i == j)
		fprintf(outputFile," A%d ", i);
	else
	{
		fprintf(outputFile, "(");
		parenthesis(i, bracket[i][j]);
		parenthesis(bracket[i][j]+1, j);
		fprintf(outputFile, ")");
	}
}

int main(int argc, char const *argv[])
{
	int n, i, l, k, j, value;

	//Input and output is taken in FILE.
	
	FILE *inputFile;

	inputFile = fopen(argv[1], "r");
	if(!inputFile)
	{
		printf("\nError in opening file in read mode.\n");
		exit(0);
	}
	fscanf(inputFile, "%d", &n);

	int p[n];

	for(i=0; i<=n; i++)
		fscanf(inputFile, "%d", &p[i]);
	fclose(inputFile);

	int m[n+1][n+1];
	bracket[n+1][n+1];

	//Setting 0 to single matrices.
	for(i=1; i<=n; i++)
		m[i][i] = 0;

	//Code to compute minimum number of scalar multipication iteratively.
	for(l=2; l<=n; l++)
	{
		for(i=1; i<=n-l+1; i++)
		{
			j=i+l-1;
			m[i][j] = 999999;

			for(k=i; k<=j-1; k++)
			{
				value = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

				if(value < m[i][j])
				{
					m[i][j] = value;
					bracket[i][j] = k;
				}
			}
		}
	}

	outputFile = fopen(argv[2], "w+");
	fprintf(outputFile, "The minimum number of multiplications to compute the product is %d.\n\n", m[1][n]);

        parenthesis(1, n);

	return 0;
}

