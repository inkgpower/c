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
	printf("\n1. Array�� date�Է�\n");
	printf("2. Array���\n");
	printf("3. Ư�� dateã��\n");
	printf("4. max, min, average ���ϱ�\n");
	printf("5. ����\n");
	printf("�޴��� �����ϼ��� :");
	scanf("%d", &menu);
	
	switch(menu)
	{
		case 1 : 
			for(i = 0; i < 10; i++)
			{
				printf("���� �Է��ϼ���. :");
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
			printf("�����մϴ�"); break;
			
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
	
	printf("��ȣ�� �Է��ϼ���. :");
	scanf("%d", &d);
	getchar();
	for(i = 0; i < 10; i++)
	{
		
		if(b[i] == d)
		{
		printf("%d�� ���° %d�Դϴ�.\n", d, i+1); return;
		}
	}
	printf("�߸��Է��ϼ̽��ϴ�.\n");
	
}
