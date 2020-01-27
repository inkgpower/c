#include <stdio.h>


void array1(int a[]);
void find(int b[]);

int main(void)

{
	int i;
	int array[10];
	char menu;
	
	while(1)
	{
	printf("\n1. Array에 date입력\n");
	printf("2. Array출력\n");
	printf("3. 특정 date찾기\n");
	printf("4. max, min, average 구하기\n");
	printf("5. 종료\n");
	printf("메뉴를 선택하세요 :");
	scanf("%d", &menu);
	
	switch(menu)
	{
		case 1 : 
			for(i = 0; i < 10; i++)
			{
				printf("수를 입력하세요. :");
				scanf("%d", &array[i]);
			} break;
			
		case 2 :
			array1(array);
			break;
		case 3 :
			find(array);
			break;
		case 4 :
		case 5 :
			printf("종료합니다"); break;
			
	}
	if(menu == 5) break;
	}
	return 0;
}


void array1(int a[])
{
	int i;
	printf("<first array>\n");
	for(i = 0; i < 10; i++)
	{
		printf("%-5d", a[i]);
	}
	
}

void find(int b[])
{
	int d = 0;
	int i = 0;
	
	printf("번호를 입력하세요. :");
	scanf("%d", &d);
	getchar();
	for(i = 0; i < 10; i++)
	{
		
		if(b[i] == d)
		{
		printf("%d는 몇번째 %d입니다.\n", d, i+1); return;
		}
	}
	printf("잘못입력하셨습니다.\n");
	
}
