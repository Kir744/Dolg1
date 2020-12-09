#pragma once
#ifndef H_MATRIX
#define H_MATRIX

typedef struct 
{
	int* y;
}line;

typedef struct 
{
	int size;
	line* x;
}Matrix;

int Det(Matrix A);

void MatrixInp(Matrix* A);

void Clear(Matrix* A);

void MatrixOutp(Matrix A);

#endif

