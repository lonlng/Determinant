#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
		FILE *fp;
	// char ch[] = "an\n";
	fp = fopen("Test/test", "r");
		if (fp == NULL)
	{
		perror("打开文件错误");
		return (-1);
	}
	printf("Hello world!\n");
	double Det_Array[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 1}, {3, 4, 1, 2}, {4, 1, 2, 3}};

	int Det_Row = sizeof(Det_Array[0]) / sizeof(Det_Array[0][0]);
	printf("%d\n", Det_Row);

	double Row_A[Det_Row];
	double Row_B[Det_Row];

	double Num_A = 1;
	double Num_B = 1;
	double Num_C = 1;
	for (int i = Det_Row - 1; i > 0; i--)
	{

		for (int j = 0; j < i; j++)
		{
			Num_A = Det_Array[i][i];
			Num_B = Det_Array[j][i];
			Num_C = Num_A * Num_C;

			for (int k = 0; k < Det_Row; k++)
			{
				Row_A[k] = Det_Array[j][k] * Num_A;
				Row_B[k] = Det_Array[i][k] * Num_B;
				Det_Array[j][k] = Row_A[k] - Row_B[k];
			}
		}
	}

	for (int i = 0; i < Det_Row; i++)
	{
		for (int j = 0; j < Det_Row; j++)
		{
			printf("%f\t", Det_Array[i][j]);
		}
		printf("\n");
	}

	double Result = 1;
	for (int i = 0; i < Det_Row; i++)
	{
		Result = Det_Array[i][i] * Result;
	}

	Result = Result/Num_C;
	printf("\n=%.0f\n",Result);

	return 0;
}
