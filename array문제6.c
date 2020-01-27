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
		printf("1. ��� ��ü�� ���\n");
		printf("2. Ư�� ǰ�� ��� �����ֱ�\n");
		printf("3. �ְ�, ���� ��� ������ ���� �� ǰ�� ã��\n");
		printf("4. ��ü ǰ���� �� ��� ������ �Ѿ��� ���� �ֱ�\n");
		printf("5. ����\n");
		printf("====================================================\n");
		printf("�޴��� �����ϼ��� :");
		scanf("%d", &menu);
		if(menu > 5) printf("�ٽ� �Է��ϼ���.\n");
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
			printf("ǰ��	 ����	  ����(����) �Ѿ�(����)\n");
			for(i = 0; i < 10; i++)
			printf("%-10s%-10d%-10d%-10d\n", array_product[i], array[i][0], array[i][1], (array[i][2]+5000)/10000);
}

void b()
{
	char c[1][20];
	int i, s, f = 0;
	printf("ǰ���� ��������.:");
	scanf("%s", &c[0]);
	if(c[0] != array_product[i]) printf("�ٽ� �Է��ϼ���.\n");
	getchar();
	for(i = 0; i < 10; i++)	
		{
		if(stricmp(c[0], array_product[i]) == 0)
		printf("%s�� ��� : %d��, unit price : %d��, �Ѿ� : %d����\n", array_product[i], array[i][0], array[i][1], (array[i][2]+5000)/10000);
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
		printf("�ְ� ��� ���� ǰ�� :%s���� %d���� ���\n", array_product[j], max); 
		
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
		printf("���� ��� ���� ǰ�� :%s���� %d���� ���\n", array_product[k], min); 
}	
		
	


void d()
{
	int sum, i, sum1;
	sum = 0; sum1 = 0;
	for(i = 0; i < 10; i++)
		sum = sum + array[i][0];
	
	for(i = 0; i < 10; i++)
		sum1 = sum1 + (array[i][2]+5000)/10000;
	printf("�� ��� :");
	printf("%d��\n", sum);
	printf("��� �Ѿ� :");
	printf("%d����\n", sum1); 
}
