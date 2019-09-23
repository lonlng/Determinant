#include <stdio.h>
double * ReadWriteDetFile(char str[])
{
	FILE *fp;
	char Num[100];
	int x = 1, y = 0;
	int Nummm = 0;
	int DetElement;
	char str_3[100];
	double Det_Array[100][100];
	int kk = 0;
	int ElementSign = 1;
	fp = fopen(str, "r");

	if (fp == NULL)
	{
		perror("打开文件错误");
		return (-1);
	}

	do
	{
		if (feof(fp))
		{
			break;
		}
		DetElement = fgetc(fp);
		switch (DetElement)
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
		case 45:
			ElementSign = -1;
			break;
		case 32:
			break;
		case 0:
		case 1:
			break;

		default:
			Det_Array[x][y] = Det_Array[x][y] * 10 * kk + (DetElement - 48);
			kk = 1;
			Det_Array[x][y] = Det_Array[x][y] * ElementSign;
			ElementSign = 1;
			printf("(%d,%d)=%.0f ", x, y, Det_Array[x][y]);
			break;
		}

	} while (1);
	fclose(fp);
	Det_Array[0][0]=Nummm;
	return Det_Array;
}