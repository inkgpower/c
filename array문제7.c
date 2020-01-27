#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



void a();
void b();
void print();
void chart();
void grade();
void sort();


int main(void)
{
	float array[30][5];
	char array2[30];
	int array3[5] = {0, 0, 0, 0, 0};
	char menu;
	int i;
	srand(time(NULL));
	a(array, array2);
	for(i = 0; i < 30; i++) 
	{
		if(array2[i] == 'A')
			array3[0]++;
		else if(array2[i] == 'B')
			array3[1]++;
		else if(array2[i] == 'C')
			array3[2]++;
		else if(array2[i] == 'D')
			array3[3]++;
		else
			array3[4]++;
	}
	while(1)
	{
		printf("\n-----------------------------------\n");
		printf("A. 모든 학생의 성적 출력\n");
		printf("B. grade에 따른 분포\n");
		printf("C. 학번에 따른 성적 출력\n");
		printf("D. 총 평점 계산\n");
		printf("E. 정렬된 성적 출력\n");
		printf("F. 종료\n");
		printf("메뉴를 선택하세요. :");
		scanf("%c", &menu);
		getchar();
			
		switch(menu) 
		{
			case 'A' : case 'a' : b(array, array2); break;
			case 'B' : case 'b' : chart(array3); break;
			case 'C' : case 'c' : print(array, array2); break;
			case 'D' : case 'd' : grade(array3); break;
			case 'E' : case 'e' : sort(array, array2); break;
			case 'F' : case 'f' : exit(0);
			
		}
	}
	
	return 0;
}


void a(float a1[][5], char a2[])
{	
	int i, a_c, b_c, c_c, d_c, f_c;
	
	for(i = 0; i < 30; i++)
	{
	a1[i][0] = 101 + i;
	a1[i][1] = rand()%40 + 60;
	a1[i][2] = rand()%40 + 60;
	a1[i][3] = rand()%60 + 40;
	a1[i][4] = a1[i][1] * 0.2 + a1[i][2] * 0.2 + a1[i][3] * 0.6;
	}
	
	for(i = 0; i < 30; i++)
	{
		if(a1[i][4] >= 90)
		a2[i] = 'A';
		else if(a1[i][4] >= 80)
		a2[i] = 'B';
		else if(a1[i][4] >= 70)
		a2[i] = 'C';
		else if(a1[i][4] >= 60)
		a2[i] = 'D';
		else
		a2[i] = 'F';
	}
}

void b(float b1[][5], char b2[])
{
	int i;
	printf("ID  exam1 exam2 exam3 score grade\n");
	printf("-----------------------------------\n");
	for(i = 0; i < 30; i++)
	printf("%-.f  %-4.f  %-4.f  %-4.f  %-4.1f   %-4c\n", b1[i][0], b1[i][1], b1[i][2], b1[i][3], b1[i][4], b2[i]);
}


void chart(int c[])
{
	int i, a_c, b_c, c_c, d_c, f_c;
	printf("A :");for(i = 0; i < c[0]; i++)printf("*");printf("\n");
	printf("B :");for(i = 0; i < c[1]; i++)printf("*");printf("\n");
	printf("C :");for(i = 0; i < c[2]; i++)printf("*");printf("\n");
	printf("D :");for(i = 0; i < c[3]; i++)printf("*");printf("\n");
	printf("F :");for(i = 0; i < c[4]; i++)printf("*");printf("\n");
}

void print(float d[][5], char d2[])
{
	int i;
	int s;
	printf("찾고자 하는 ID를 입력하세요<101~130> :");
	scanf("%d", &s);
	if(s < 130 || s > 101) printf("찾고자 하는 학번이 없습니다.\n");
	for(i = 0; i < 30; i++)
	{
	if(s == d[i][0])
	{
	printf("ID %d의 score : %.1f\n", s, d[i][4]);
	printf("ID %d의 grade : %c\n", s, d2[i]);
	}
	}
}

void grade(int e[])
{
	float all;
	all = (e[0]*4 + e[1]*3 + e[2]*2 + e[3]*1) / (float)30;
	printf("총 평점은 %.1f 입니다.\n", all);
}

void sort(float f[][5], char f2[])
{                                                                     
	int i, j, k;
	float temp;
	char temp1;
	float n_g[30][5];
	char n_g2[30];
	
	for(i = 1; i < 30; i++)
		{
		for(j = 29; j >= i; j--)
			if(f[j-1][4] < f[j][4])
			{
				for(k = 0; k < 5; k++)
				{
					temp = f[j-1][k];
					f[j-1][k] = f[j][k];
					f[j][k] = temp;
				}
				temp1 = f2[j-1];
				f2[j-1] = f2[j];
				f2[j] = temp1;
			}
		}
	
		for(i = 0; i < 30; i++)
			{
			for(j = 0; j < 5; j++)
				{
				n_g[i][j] = f[i][j];
				n_g2[i] = f2[i];
				}
			}
		
	printf("ID  exam1 exam2 exam3 score grade\n");
	printf("-----------------------------------\n");
	for(i = 0; i < 30; i++)
	printf("%-.f  %-4.f  %-4.f  %-4.f  %-4.1f   %-4c\n", n_g[i][0], n_g[i][1], n_g[i][2], n_g[i][3], n_g[i][4], n_g2[i]);		
		
}


