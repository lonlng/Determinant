#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	fp = fopen("Test/test", "r");
	if (fp == NULL)
	{
		perror("打开文件错误");
		return (-1);
	}
	char Num[100][100];
	int x = 0, y = 0;
	int Nummm = 0;
	int cool;
	double Det_Array[100][100];
	int kk = 0;
	do
	{
		if (feof(fp))
		{
			break;
		}
		cool = fgetc(fp);
		switch (cool)
		{
		case 9:
			y++;
			kk = 0;
			break;
		case 10:
			y = 0;
			x++;
			Nummm++;
			kk = 0;
			break;
		case 32:
			break;

		default:
			Det_Array[x][y] = Det_Array[x][y] * 10 * kk + (cool - 48);
			kk = 1;
			printf("(%d,%d)=%.0f ", x, y, Det_Array[x][y]);
			break;
		}

	} while (1);
	printf("Hello world!\n");
	printf("%d\n", Nummm);

	double Row_A[Nummm];
	double Row_B[Nummm];

	double Num_A = 1;
	double Num_B = 1;
	double Num_C = 1;
	for (int i = Nummm - 1; i > 0; i--)
	{

		for (int j = 0; j < i; j++)
		{
			Num_A = Det_Array[i][i];
			Num_B = Det_Array[j][i];
			Num_C = Num_A * Num_C;

			for (int k = 0; k < Nummm; k++)
			{
				Row_A[k] = Det_Array[j][k] * Num_A;
				Row_B[k] = Det_Array[i][k] * Num_B;
				Det_Array[j][k] = Row_A[k] - Row_B[k];
			}
		}
	}

	for (int i = 0; i < Nummm; i++)
	{
		for (int j = 0; j < Nummm; j++)
		{
			printf("%f\t", Det_Array[i][j]);
		}
		printf("\n");
	}

	double Result = 1;
	for (int i = 0; i < Nummm; i++)
	{
		Result = Det_Array[i][i] * Result;
	}

	Result = Result / Num_C;
	printf("\n=%.0f\n", Result);

	return 0;
}
