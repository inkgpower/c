#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void low();
void medium();
void high();

int main(void)
{
	char menu;
	do
	{
		printf("*************************************************\n");
		printf("* L/l : Low level : 1digit으로 구성된 수치연산	\n");
		printf("* M/m : Medium level : 2 digit으로 구성된 수치연산\n");
		printf("* H/h : High level : 3 digit으로 구성된 수치연산*\n");
		printf("* Q/q : Quit : Quiz program의 종료*\n");
		printf("*************************************************\n");
		printf(" 프로그램을 선택하세요 :");
		scanf("%c", &menu);
		getchar();
		switch(menu)
		{
			case 'l' : case 'L' : low(); break;
			case 'm' : case 'M' : medium(); break;
			case 'h' : case 'H' : high(); break;
			case 'q' : case 'Q' : break;
		}
		if(menu == 'q' || menu == 'Q') break;
		
	}
	while(1);
	
	return 0;
}


void low()
{
	int n1, n2;
	int x, y, xx;
	char c;
	do
	{
		int n1 = rand()%10;
		int n2 = rand()%10;
		printf("What is %d + %d = ?", n1, n2);
		scanf("%d", &x);
		getchar(); 
		xx = n1 + n2;
		if(x == xx)
		{
			printf("That's the answer!!'\n"); 
		}
		else
		{
			printf("That' incorrect!!\n");
		}
		printf("Do you want to solve another problem?(y/n)\n");
		scanf("%c", &c);
		getchar();
		if(c == 'y'||c == 'Y') continue;
		else if(c == 'n'||c =='N') break;
	}
	while(1);
}


void medium()
{
	int n1, n2;
	int x, y, xx;
	char c;
	do
	{
		int n1 = rand()%100+10;
		int n2 = rand()%100+10;
		printf("What is %d + %d = ?", n1, n2);
		scanf("%d", &x);
		getchar();
		xx = n1 + n2;
		if(x == xx)
		{
			printf("That's the answer!!'\n"); 
		}
		else
		{
			printf("That' incorrect!!\n");
		}
		printf("Do you want to solve another problem?(y/n)\n");
		scanf("%c", &c);
		getchar();
		if(c == 'y'||c == 'Y') continue;
		else if(c == 'n'||c =='N') break;
	}
	while(1);
}


void high()
{
	int n1, n2;
	int x, y, xx;
	char c;
	do
	{
		int n1 = rand()%1000+100;
		int n2 = rand()%1000+100;
		printf("What is %d + %d = ?", n1, n2);
		scanf("%d", &x);
		getchar();
		xx = n1 + n2;
		if(x == xx)
		{
			printf("That's the answer!!'\n"); 
		}
		else
		{
			printf("That' incorrect!!\n");
		}
		printf("Do you want to solve another problem?(y/n)\n");
		scanf("%c", &c);
		getchar();
		if(c == 'y'||c == 'Y') continue;
		else if(c == 'n'||c =='N') break;
	}
	while(1);
}
