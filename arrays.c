//The arrays homework
//14.07.2022

#include <stdio.h>
#define N 7

void task1(int [][N], int);
void task2(int [], int);
void task3(int [][N], int);
void task4(int [][N], int);

int main()
{
	int array1[N];
	int array2[N][N];
	printf("Matrix with size N = %d:\n", N);
	task1(array2, N);
	printf("\n");
	task2(array1, N);
	printf("\nFill the matrix upper triangle with 0 and the down triangle with 1:\n");
	task3(array2, N);
	printf("\nSerpentine filling:\n");
	task4(array2, N);
	return 0;
}

void task1(int array[][N], int size)
{
	for(int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				array[i][j] = i*size + j +1;
				printf("%4d ", array[i][j]);
			}
			printf("\n");
		}
}

void task2(int array[], int size)
{
	printf ("Insert array elements\n");
	for(int i = 0; i<size; i++)
	{
		printf("\narray[%d]=",i);
		scanf("%d",&array[i]);
	}
	printf("\nThe matrix in reverse order:\n");
	for (int i=size-1; i>=0; i--)
		printf("%d ",array[i]);
}

void task3(int array[][N], int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(i+j+1 < size)
				array[i][j]=0;
			else
				array[i][j]=1;
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}

void task4(int array[][N], int size)
{
int corner = size;
	//int array[N][N];
	int i=0,j=0;
	int value = 1;
	for(int turnCounter=0; turnCounter<size; turnCounter++)
	{
	 	switch(turnCounter%2)
	 	{
	 		case 0:
		 	{
				for(j; j<corner; j++)
				{
					array[i][j] = value++;
				}
				corner--;
				j--;
				i++;
				for(i; i<=corner; i++)
				{
					array[i][j] = value++;
				}
				break;
		 	}
		 	case 1:
		 	{
		 		j--;
		 		i--;
				for(j; j>=size-corner-1; j--)
				{
					array[i][j] = value++;
				}
				corner--;
				j++;
				i--;
				for(i; i>=size-corner; i--)
				{
					array[i][j] = value++;
				}
				corner++;
				break;
		 	}
		 }
	}
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
			printf("%5d", array[i][j]);
		printf("\n");
	}
}

