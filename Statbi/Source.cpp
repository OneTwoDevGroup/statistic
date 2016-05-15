#include "stdio.h"
#include "string.h"
#include "locale.h"

#define N 32
#define l 3
#define MAXHIGH 255 // верхний предел в котором находятся буквы
#define MAXLOW  224 // нижний

int main()
{
	setlocale(LC_ALL,"rus");
	
	FILE* fp1;
	fp1 = fopen("input.txt", "r");
	int i=0, k,j;
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
			i++;
			while((ch[1]<192)||(ch[1]>255))
			{
				i++;
				ch[1] = fgetc(fp1);
			}
			if (ch[1] < MAXLOW)
				ch[1] += 32;
			ch[2] = fgetc(fp1);
			i++;
			while ((ch[2]<192) || (ch[2]>255))
			{
				i++;
				ch[2] = fgetc(fp1);
			}
			if (ch[2] < MAXLOW)
				ch[2] += 32;
			n += 2;

			for (i = i; i < 718269;)
			{
				ch[0] = ch[1];
				ch[1] = ch[2];
				ch[2] = fgetc(fp1);
				i++;
				if ((ch[2] < 192) || (ch[2]>255))
				{
					while ((ch[2] < 192) || (ch[2]>255))
					{
						ch[2] = fgetc(fp1);
						i++;
					}
				}
				if (ch[2] < MAXLOW)
					ch[2] += 32;
				if ((ch[0] - 224 == 31) && (ch[1] - 224 == 31) && (ch[2] - 224 == 31))
					i++;
				count[ch[0]-224][ch[1]-224][ch[2]-224] += 1;
				n++;
			}
	
			FILE* out = fopen("output.txt", "w");

			int best[200];
			char threegrams[200][3];
			int amount = 0;

			for (k = 224; k <= 255; k++)
			{
				for (i = 224; i <= 255; i++)
				{
					for (j = 224; j <= 255; j++)
					{
						if ((float)count[k - 224][i - 224][j - 224] / n > 0.0006) {
							//fprintf(out, "%c%c%c =  %f\n",k, i, j, (float)count[k-224][i-224][j-224] / n);

							best[amount] = count[k - 224][i - 224][j - 224];
							threegrams[amount][0] = k; threegrams[amount][1] = i; threegrams[amount][2] = j;
							amount++;
						}
							
					}
				}
			}

			char threegram[3];

			// Сортировка по возрастанию

			for (int i = 1; i < 200; i++) {

				int temp = best[i];
				memcpy(threegram, threegrams[i], sizeof(char) * 3);

				for (int j = i - 1; j >= 0; j--) {
					if (best[j] < temp) break;

					best[j + 1] = best[j];
					best[j] = temp;

					memcpy(threegrams[j + 1],threegrams[j], sizeof(char) * 3);
					memcpy(threegrams[j], threegram, sizeof(char) * 3);
				}
			}

			for (int i = 0; i < 200; i++) 
			{
				fprintf(out, "%c%c%c\n", threegrams[i][0], threegrams[i][1], threegrams[i][2]);
			}


			return 0;
			
}

//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	FILE* fp1;
//	fp1 = fopen("input.txt", "r");
//	int i, k, j;
//	unsigned char chbuff[l + 1] = { 0 }, ch[l + 1] = { 0 };
//	fseek(fp1, 0, SEEK_END);
//	int size = ftell(fp1);
//	fseek(fp1, 0, SEEK_SET);
//	int n = 0;
//	int count[256][256] = { 0 };
//
//
//	//ch[0] = 0;
//	//ch[1] = 0;
//	//ch[2] = 0;
//	//chbuff[0] = alf[k];
//	//	chbuff[1] = alf[j];
//
//	ch[1] = fgetc(fp1);
//	while ((ch[1]<192) || (ch[1]>255))
//	{
//		ch[1] = fgetc(fp1);
//	}
//	if (ch[1] < MAXLOW)
//		ch[1] += 32;
//	
//	
//	n += 1;
//	for (i = 0; i < size; i++)
//	{
//		ch[0] = ch[1];
//		
//		ch[1] = fgetc(fp1);
//
//		if ((ch[1] < 192) || (ch[1]>255))
//		{
//			while ((ch[1] < 192) || (ch[1]>255))
//			{
//				ch[1] = fgetc(fp1);
//			}
//		}
//		if (ch[1] < MAXLOW)
//			ch[1] += 32;
//		count[ch[0]][ch[1]]+= 1;
//		n++;
//	}
//
//	FILE* out = fopen("output.txt", "w");
//
//	
//		for (i = 224; i <= 255; i++)
//		{
//			for (j = 224; j <= 255; j++)
//			{
//				fprintf(out, "%c%c =  %f\n",i, j, (float)count[i ][j ] / n);
//			}
//		}
//	
//}