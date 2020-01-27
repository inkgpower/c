#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

float array[30][5];
int array3[5];
char array2[30];
int i;
void a();
void b();
void grade();
void chart();
void print();
void sort();



int main(void)
{
	char menu;
	srand(time(NULL));
	a();
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
			case 'A' : case 'a' : b(); break;
			case 'B' : case 'b' : chart(); break;
			case 'C' : case 'c' : print(); break;
			case 'D' : case 'd' : grade(); break;
			case 'E' : case 'e' : sort(); break;
			
		}
	}
}
	

void a()
{	
	for(i = 0; i < 30; i++)
		{
			array[i][0] = 101 + i;
			array[i][1] = rand()%40+60;
			array[i][2] = rand()%40+60;
			array[i][3] = rand()%60+40;
			array[i][4] = array[i][1]*0.2 + array[i][2]*0.2 + array[i][3]*0.6;
		}
	for(i = 0; i < 30; i++)
		{
			if(array[i][4] >= 90)
					array2[i] = 'A';
			else if(array[i][4] >= 80)
					array2[i] = 'B';
			else if(array[i][4] >= 70)
				array2[i] = 'C';
			else if(array[i][4] >= 60)
				array2[i] = 'D';
			else
				array2[i] = 'F';
		}
	
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
}

void b()
{
	int i;
	printf("ID  exam1 exam2 exam3 score grade\n");
	printf("-----------------------------------\n");
	for(i = 0; i < 30; i++)
	printf("%-.f  %-4.f  %-4.f  %-4.f  %-4.1f   %-4c\n", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4], array2[i]);
}

void chart()
{
	printf("A :");for(i = 0; i < array3[0]; i++)printf("*");printf("\n");
	printf("B :");for(i = 0; i < array3[1]; i++)printf("*");printf("\n");
	printf("C :");for(i = 0; i < array3[2]; i++)printf("*");printf("\n");
	printf("D :");for(i = 0; i < array3[3]; i++)printf("*");printf("\n");
	printf("F :");for(i = 0; i < array3[4]; i++)printf("*");printf("\n");
}

void print()
{
	int i;
	float s;
	char c;
	printf("찾고자 하는 ID를 입력하세요<101~130> :");
	scanf("%f", &s);
	
	for(i = 0; i < 30; i++)
		{
			if(s == array[i][0])
				{
					printf("ID %.f의 score : %.1f\n", s, array[i][4]);
					printf("ID %.f의 grade : %c\n", s, array2[i]);
				}
		}
}

void grade()
{
	float all;
	all = (array3[0]*4 + array3[1]*3 + array3[2]*2 + array3[3]*1) /(float)30;
	printf("총 평점은 %.1f 입니다.\n", all);
}


void sort()
{                                                                     
	int i, j, k;
	float temp;
	char temp1;
	float n_g[30][5];
	char n_g2[30];
	
	for(i = 1; i < 30; i++)
		{
		for(j = 29; j >= i; j--)
			if(array[j-1][4] < array[j][4])
				{
					for(k = 0; k < 5; k++)
					{
						temp = array[j-1][k];
						array[j-1][k] = array[j][k];
						array[j][k] = temp;
					}
					temp1 = array2[j-1];
					array2[j-1] = array2[j];
					array2[j] = temp1;
				}
		}
	
	for(i = 0; i < 30; i++)
		{
		for(j = 0; j < 5; j++)
			{
				n_g[i][j] = array[i][j];
				n_g2[i] = array2[i];
			}
		}
		
	printf("ID  exam1 exam2 exam3 score grade\n");
	printf("-----------------------------------\n");
	for(i = 0; i < 30; i++)
	printf("%-.f  %-4.f  %-4.f  %-4.f  %-4.1f   %-4c\n", n_g[i][0], n_g[i][1], n_g[i][2], n_g[i][3], n_g[i][4], n_g2[i]);		
		
}
