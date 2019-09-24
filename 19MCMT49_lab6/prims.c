#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int v, e, i, j, k, min;
	FILE *inputFile;
	inputFile = fopen(argv[1], "r");
	if(!inputFile)
	{
		printf("\nError in opening file in read mode.\n");
		exit(0);
	}
	fscanf(inputFile, "%d", &v);
	fscanf(inputFile, "%d", &e);

	int weights[v+1][v+1];

	for(i=1; i<=v; i++)
		for(j=1; j<=v; j++)
			weights[i][j] = 0;

	for(k=0; k<e; k++)
	{
		fscanf(inputFile, "%d", &i);
		fscanf(inputFile, "%d", &j);
		fscanf(inputFile, "%d", &weights[i][j]);
		weights[j][i] = weights[i][j];
	}

	for(i=1; i<=v; i++) {
		for(j=1; j<=v; j++)
			printf("%d ", weights[i][j]);
		printf("\n");
	}

	int parent[v], key[v];

	key[1] = 0;
	parent[1] = NULL;
	for(i=2; i<=v; i++)
	{
		key[i] = 99999;
		parent[i] = NULL;
	}


		



}


