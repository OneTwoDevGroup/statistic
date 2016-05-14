#include "stdio.h"
#include "string.h"
#include "locale.h"

#define N 32
#define l 3
#define MAXHIGH 255 // верхний предел в котором находятся буквы
#define MAXLOW  224 // нижний
/*
int main()
{
	setlocale(LC_ALL,"rus");
	
	FILE* fp1;
	fp1 = fopen("input.txt", "r");
	int i, k,j;
	unsigned char chbuff[l + 1] = { 0 }, ch[l + 1] = { 0 };
	fseek(fp1, 0, SEEK_END);
	int size = ftell(fp1);
	fseek(fp1, 0, SEEK_SET);
	int n = 0;
	int count[32][32][32] = { 0 };

	
			//ch[0] = 0;
			//ch[1] = 0;
			//ch[2] = 0;
			//chbuff[0] = alf[k];
		//	chbuff[1] = alf[j];
			
			ch[1] = fgetc(fp1);
			while((ch[1]<192)||(ch[1]>255))
			{
				ch[1] = fgetc(fp1);
			}
			if (ch[1] < MAXLOW)
				ch[1] += 32;
			ch[2] = fgetc(fp1);
			while ((ch[2]<192) || (ch[2]>255))
			{
				ch[2] = fgetc(fp1);
			}
			if (ch[2] < MAXLOW)
				ch[2] += 32;
			n += 2;
			for (i = 0; i < size; i++)
			{
				ch[0] = ch[1];
				ch[1] = ch[2];
				ch[2] = fgetc(fp1);
				
				if ((ch[2] < 192) || (ch[2]>255))
				{
					while ((ch[2] < 192) || (ch[2]>255))
					{
						ch[2] = fgetc(fp1);
					}
				}
				if (ch[2] < MAXLOW)
					ch[2] += 32;
				count[ch[0]-224][ch[1]-224][ch[2]-224] += 1;
				n++;
			}
	
			FILE* out = fopen("output.txt", "w");

			for (k = 224; k <= 255; k++)
			{
				for (i = 224; i <= 255; i++)
				{
					for (j = 224; j <= 255; j++)
					{
						fprintf(out, "%c%c%c =  %f\n",k, i, j, (float)count[k-224][i-224][j-224] / n);
					}
				}
			}
}*/

int main()
{
	setlocale(LC_ALL, "rus");

	FILE* fp1;
	fp1 = fopen("input.txt", "r");
	int i, k, j;
	unsigned char chbuff[l + 1] = { 0 }, ch[l + 1] = { 0 };
	fseek(fp1, 0, SEEK_END);
	int size = ftell(fp1);
	fseek(fp1, 0, SEEK_SET);
	int n = 0;
	int count[256][256] = { 0 };


	//ch[0] = 0;
	//ch[1] = 0;
	//ch[2] = 0;
	//chbuff[0] = alf[k];
	//	chbuff[1] = alf[j];

	ch[1] = fgetc(fp1);
	while ((ch[1]<192) || (ch[1]>255))
	{
		ch[1] = fgetc(fp1);
	}
	if (ch[1] < MAXLOW)
		ch[1] += 32;
	
	
	n += 1;
	for (i = 0; i < size; i++)
	{
		ch[0] = ch[1];
		
		ch[1] = fgetc(fp1);

		if ((ch[1] < 192) || (ch[1]>255))
		{
			while ((ch[1] < 192) || (ch[1]>255))
			{
				ch[1] = fgetc(fp1);
			}
		}
		if (ch[1] < MAXLOW)
			ch[1] += 32;
		count[ch[0]][ch[1]]+= 1;
		n++;
	}

	FILE* out = fopen("output.txt", "w");

	
		for (i = 224; i <= 255; i++)
		{
			for (j = 224; j <= 255; j++)
			{
				fprintf(out, "%c%c =  %f\n",i, j, (float)count[i ][j ] / n);
			}
		}
	
}