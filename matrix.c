#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int Det(Matrix A) 
{
	int result = 0;
	int size = A.size;
	int mult;
	if (size > 2) 
	{
		for (int i = 0; i < size; i++) 
		{
			mult = A.x[0].y[i];
			Matrix B;
			B.size = size - 1;
			B.x = (line*)malloc(B.size * sizeof(line*));
			for (int j = 0; j < B.size; j++) 
			{
				B.x[j].y = (int*)malloc(B.size * sizeof(int));
			}
			int y = 0;
			for (int j = 0; j < B.size; j++) 
			{
				for (int k = 0; k < B.size; k++)
				{
					if (i == y)
						y++;
					B.x[j].y[k] = A.x[j + 1].y[y];
					y++;
				}
				y = 0;
			}
			if ((i + 2) % 2 != 0)
				mult *= -1;
			result = Det(B) * mult + result;
			for (int j = 0; j < B.size; j++) 
			{
				free(B.x[j].y);
			}
			free(B.x);
		}
	}
	else
	{
		result = A.x[0].y[0] * A.x[1].y[1] - A.x[0].y[1] * A.x[1].y[0];
	}
	return result;
}

void MatrixInp(Matrix* A) 
{
	printf("Matrix order will be:");
	scanf_s("%d", &A->size);
	A->x = (line*)malloc(A->size * sizeof(line*));
	for (int i = 0; i < A->size; i++)
	{
		A->x[i].y = (int*)malloc(A->size * sizeof(int));
	}
	for (int i = 0; i < A->size; i++) 
	{
		for (int j = 0; j < A->size; j++) 
		{
			scanf_s("%d", &A->x[i].y[j]);
		}
	}
	return;
}

void Clear(Matrix* A) 
{
	for (int i = 0; i < A->size; i++) 
	{
		free(A->x[i].y);
	}
	free(A->x);
	return;
}

void MatrixOutp(Matrix A) 
{
	for (int i = 0; i < A.size; i++)
	{
		for (int j = 0; j < A.size; j++)
		{
			printf("%d ", A.x[i].y[j]);
		}
		printf("\n");
	}
	return;
}
