#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char array_product[10][20] = {"Tv", "Radio", "Tank", "Printer", "Oven", "Chair", "Desk", "phone", "Board", "Stereo"};
int array[10][3];
void a();
void b();
void max();
void min(); 
void d();
void p();


int main(void)
{
		int menu;
		int i;
		p();
		
		while(1)
		{
		printf("\n====================================================\n");
		printf("1. 재고 전체를 출력\n");
		printf("2. 특정 품목 재고 보여주기\n");
		printf("3. 최고, 최저 재고 수량을 갖는 두 품목 찾기\n");
		printf("4. 전체 품목의 총 재고 수량과 총액을 보여 주기\n");
		printf("5. 종료\n");
		printf("====================================================\n");
		printf("메뉴를 선택하세요 :");
		scanf("%d", &menu);
		if(menu > 5) printf("다시 입력하세요.\n");
		getchar();
		switch(menu)
		{
			case 1 : a(); break;
			case 2 : b(); break;
			case 3 : max(); min(); break;
			case 4 : d(); break;
			case 5 : if(menu == 5) break;
		}
		if(menu == 5) break;
		}
	return 0;
}


void p()
{
	int i;
		for(i = 0; i < 10; i++)
			{
				array[i][0] = rand()%70+15;
				array[i][1] = rand()%100000+50000;
				array[i][2] = array[i][0] * array[i][1];
			}
}

void a()
{
	int i;
			printf("품목	 수량	  가격(개당) 총액(만원)\n");
			for(i = 0; i < 10; i++)
			printf("%-10s%-10d%-10d%-10d\n", array_product[i], array[i][0], array[i][1], (array[i][2]+5000)/10000);
}

void b()
{
	char c[1][20];
	int i, s, f = 0;
	printf("품목을 적으세요.:");
	scanf("%s", &c[0]);
	if(c[0] != array_product[i]) printf("다시 입력하세요.\n");
	getchar();
	for(i = 0; i < 10; i++)	
		{
		if(stricmp(c[0], array_product[i]) == 0)
		printf("%s의 재고량 : %d개, unit price : %d원, 총액 : %d만원\n", array_product[i], array[i][0], array[i][1], (array[i][2]+5000)/10000);
		f = 1;
		if(f == 0) break;
		}
	
}

void max()
{
	int i, max = 0; int j=0;
	max = array[0][0];

	
	for(i = 0; i < 10; i++)
		if(max < array[i][0])
		{
		max = array[i][0];
		j = i;
		}
		printf("최고 재고 수량 품목 :%s으로 %d개의 재고\n", array_product[j], max); 
		
}

void min()
{
	int i, min = 100; int k = 0;
	min = array[0][0];

	
	for(i = 0; i < 10; i++)
		if(min > array[i][0])
		{
		min = array[i][0];
		k = i;
		}
		printf("최저 재고 수량 품목 :%s으로 %d개의 재고\n", array_product[k], min); 
}	
		
	


void d()
{
	int sum, i, sum1;
	sum = 0; sum1 = 0;
	for(i = 0; i < 10; i++)
		sum = sum + array[i][0];
	
	for(i = 0; i < 10; i++)
		sum1 = sum1 + (array[i][2]+5000)/10000;
	printf("총 재고량 :");
	printf("%d개\n", sum);
	printf("재고 총액 :");
	printf("%d만원\n", sum1); 
}
