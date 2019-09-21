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
	char Num[100];
	int x = 0, y = 0;
	int Nummm = 0;
	int cool;
	char str_3[100];
	double Det_Array[100][100];
	int kk = 0;
	do
	{
		if (feof(fp))
		{
			break;
		}
		// str_3 = fgetc(fp);
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
			//atof函数将字符串转换为double类型
			// Det_Array[x][y] = atof(str_3);
			printf("(%d,%d)=%.0f ", x, y, Det_Array[x][y]);
			break;
		}

	} while (1);
	fclose(fp);
	fp = fopen("Test/Answer", "w");
	if (fp == NULL)
	{
		perror("打开文件错误");
		return (-1);
	}
	printf("\n%d\n", Nummm);

	double Row_A[Nummm];
	double Row_B[Nummm];

	double Num_A = 1;
	double Num_B = 1;
	double Num_C = 1;
	char str_5[50] = "|========================|\n";
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
			printf("|========================|\n");
			fputs(str_5, fp);
			for (int m = 0; m < Nummm; m++)
			{
				printf("|");
				fputc('|', fp);
				for (int n = 0; n < Nummm; n++)
				{
					gcvt(Det_Array[m][n], 100, Num);
					fputs(Num, fp);
					fputc('\t', fp);
					printf("%s\t", Num);
				}
				fputs("\b\b\b\b\b\b\b|\n", fp);
				printf("\b\b\b\b\b\b\b|\n");
			}
		}
	}
	fputs(str_5, fp);

	printf("|========================|\n");
	double Result = 1;
	for (int i = 0; i < Nummm; i++)
	{

		Result = Det_Array[i][i] * Result;
		printf("%.0f*", Det_Array[i][i]);
		char Result_3[100];
		gcvt(Det_Array[i][i], 100, Result_3);
		fputs(Result_3, fp);
		fputc('*', fp);
	}

	// strcat(); 	函数？？
	// itoa();		函数？？

	fputc('/', fp);
	char Result_4[100];
	gcvt(Num_C, 100, Result_4);
	fputs(Result_4, fp);
	Result = Result / Num_C;

	printf("\b/%.0f=%.0f\n", Num_C, Result);
	char Result_2[100];
	gcvt(Result, 100, Result_2);
	fputc('=', fp);
	fputs(Result_2, fp);
	fputc('\n', fp);
	fclose(fp);
	return 0;
}
