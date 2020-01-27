#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char array_product[10][20] = {"Tv", "Radio", "Tank", "Printer", "Oven", "Chair", "Desk", "phone", "Board", "Stereo"};
int array[3][10];
void a();
void b();
void c();
void d();
void p();


int main(void)
{
		
		int menu;
		int i;
	
		void p();

	
	
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
		getchar();
		
		switch(menu)
		{
			case 1 : a(); break;
			case 2 : b(); break;
			case 3 : c(); break;
			case 4 : d(); break;
		}
		}
	
			


	return 0;
}

void p()
{
	int i;
		for(i = 0; i < 10; i++)
			{
				array[0][i] = rand()%70+15;
				array[1][i] = rand()%100000+50000;
				array[2][i] = array[0][i] * array[1][i];
			}
}



void a()
{
	int i;
	
		
			printf("품목	 수량	  가격(개당)	총액\n");
			for(i = 0; i < 10; i++)
			printf("%-10s%-10d%-10d%-10d\n", array_product[i], array[0][i], array[1][i], array[2][i]);

}

void b()
{
	
	char c[1][20];
	int i, s, f = 0;
	printf("품목을 적으세요.:");
	scanf("%s", &c[0]);
	
	for(i = 0; i < 10; i++)	
		{
		if(stricmp(c[0], array_product[i]) == 0)
		printf("%s의 재고량 : %d, unit price : %d, 총액 : %d\n", array_product[i], array[0][i], array[1][i], array[2][i]);
		f = 1;
		
		if(f == 0) break;
		}
}

void c()
{
	char c[1][20];
	int i, max, min, f = 0;
	max = min = 0;
	
	for(i = 0; i < 10; i++)
	{
		if(array[0][i]>max)
		{
			max = array[0][i];
			printf("최고 재고 수량 품목 :");
			printf("%s으로 %d개의 재고", array_product[i], max);
		}
		if(array[0][i]<min)
		{
			min = array[0][i];
			printf("최저 재고 수량 품목 :");
			printf("%s으로 %d개의 재고", array_product[i], min); 
		}
	}
}

void d()
{
	int sum, i, sum1;
	sum = 0; sum1 = 0;
	for(i = 0; i < 10; i++)
		sum = sum + array[0][i];
	
	for(i = 0; i < 10; i++)
		sum1 = sum1 + array[2][i];
		
	printf("총 재고량 :");
	printf("%d\n", sum);
	printf("재고 총액 :");
	printf("%d\n", sum1); 
	
	
}
