#include<stdio.h>                              
#include<windows.h>
#include "matrix.h"

int main()
{
	FILE* fp;
	Matrix A;
	char select;
	printf("Select matrix input option\n a - From command line\n b - From file\n c - Generate random matrix\n");
	select = getche();
	printf("\n");
	switch (select)
	{
	case 'a':
		MatrixInp(&A);
		break;

	case 'b':
		fopen_s(&fp, "matrix.txt", "r");
		fscanf_s(fp, "%d", &A.size);
		A.x = (int*)malloc(sizeof(int) * A.size);
		for (int o = 0; o < A.size; o++)
			A.x[o].y = (int*)malloc(sizeof(int) * A.size);
		for (int i = 0; i < A.size; i++)
			for (int j = 0; j < A.size; j++)
				fscanf_s(fp, "%d", &A.x[i].y[j]);
		MatrixOutp(A);
		break;

	case 'c':
		srand(time(0));
		A.size = 2 + rand() % 10;
		A.x = (line*)malloc(A.size * sizeof(line*));
		for (int i = 0; i < A.size; i++)
		{
			A.x[i].y = (int*)malloc(A.size * sizeof(int));
		}
		for (int i = 0; i < A.size; i++)
		{
			for (int j = 0; j < A.size; j++)
			{
				A.x[i].y[j] = rand() % 20;
			}
		}
		MatrixOutp(A);
		break;
	}

		printf("Det=%d\n", Det(A));
		Clear(&A);

		system("pause");
		return 0;
	}

