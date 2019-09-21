#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int argc, char const *argv[])
{
	FILE *fp;
	// char ch[] = "an\n";
	fp = fopen("Test/test", "r");
	// if ((fp = fopen("Test/test", "r")) == NULL)
	// {
	// 	printf("File cannot be opened\n");
	// }
	// else
	// {
	// 	printf("File opened for writing\n");
	// }

	char str[30];

	// fputs(ch,fp);

	// char ReadFile[];
	// fgets(ReadFile,fp)

	if (fp == NULL)
	{
		perror("打开文件错误");
		return (-1);
	}
	// int c;
	// while (1)
	// {
	// 	c = fgetc(fp);
	// 	if(feof(fp)){
	// 		break;
	// 	}
	// 	printf("%c",c);
	// }

	//======++++++++++++++++++
	// if (fgets(str, 30, fp) != NULL)
	// {
	// 	puts(str);
	// }
	// printf("\n");
	// for (int i = 0; i < strlen(str); i++)
	// {
	// 	printf("%c", str[i]);
	// }

	// char str22[10][10];

	// for (int i = 0; i < 5; i++)
	// {
	// 	for (int j = 0; j < 6; j++)
	// 	{
	// 		str22[i][j] = 65 + i + j;
	// 		printf("%c", str22[i][j]);
	// 	}
	// 	printf("\n");
	// }
	//=======+++++++++++++++

	// 	char str12[3][] = {"qwewer","asfasdasdf","fadf"};
	// int lengg = strlen(str12[1]);

	// char str333[2][20] = {"abcdefgeqwqw","hijiklmn"};
	//======================================={
	// int i = strlen(str22[0]);
	// int j = strlen(str22[1]);
	// int k = strlen(str22[2]);
	// int l = strlen(str22[3]);

	// printf("\ni=%d,j=%d,k=%d,l=%d\n", i, j, k, l);
	//===============================================}

	// if (fclose(fp) != 0)
	// {
	// 	printf("file cannot be closed \n");
	// }
	// else
	// {
	// 	printf("file is now closed \n");
	// }

	char Num[100][100];
	int x = 0, y = 0;
	int Nummm = 0;
	int cool;
	double Det_Array[100][100];
	int kk = 0;
	double Num4 = 0;
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
			printf("制y=%d表", y);
			kk = 0;
			break;
		case 10:
			y = 0;
			x++;
			Nummm++;
			kk = 0;
			printf("换x=%d行", x);
			break;
		case 32:
			break;

		default:

			// Det_Array[x][y] = cool - 48;
			Det_Array[x][y] = Det_Array[x][y] * 10 * kk + (cool - 48);
			kk = 1;
			printf("(%d,%d)=%.0f ", x, y, Det_Array[x][y]);
			break;
		}

	} while (1);

	// int x1 = strlen(Num[0]);
	// int y1 = strlen(Num[3]);
	int Det_Row = sizeof(Det_Array[0]) / sizeof(Det_Array[0][0]);
	printf("\nDet_Row=%d,\n", Nummm);
	printf("#############################\n");

	for (int i = 0; i < Nummm; i++)
	{
		for (int j = 0; j < Nummm; j++)
		{
			printf("%.0f\t", Det_Array[i][j]);
		}
		printf("\n");
	}

	fclose(fp);

	return 0;
}
