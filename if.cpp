#include <stdio.h>

int main(void)
{
	int x, a, b, c, d, f, i, count, max, min;
	a = 0; b = 0; c = 0; d = 0; f = 0;
	int sum = 0; int average = 0;
	max = x; min = 100; 
	char A, B, C, D, Grade;
	
	while (1)
	{
		printf("���� �Է�(999 �Է� �� �ߴ�) : "); 
		scanf("%d", &x);
		getchar();
		if (x == 999) break;
		count++;
		sum += x;
		if (max < x) max = x;
		if (min > x) min = x;
		if (x>=90) a++;
		else if (x >= 80) b++;
		else if (x >= 70) c++; 
		else if (x >= 60) d++;
		else f++;
	}
	average = sum/count;
	
	do
	{
		printf("*************************************************\n");
		printf("* A. �Է� �� score�� max, min, average�� ���	*\n");
		printf("* B. A ~ F�� �л� ���� ���                     *\n");
		printf("* C. grade�� ���� �л� ���� historgram���� ǥ�� *\n");
		printf("* D. ����                                       *\n");
		printf("*************************************************\n");
		printf("�� menu���� ���ϴ� �׸��� �����ϼ��� :");
		scanf("%c", &Grade);
		getchar();
		switch(Grade)
		{
			case 'A' : case 'a' :
				printf("===========================\n");
				printf("�ְ����� : %d\n", max);
				printf("�������� : %d\n", min);
				printf("������� : %d\n", average);
				printf("===========================\n");
				break ;
			case 'B' : case 'b' :
				printf("===========================\n");
				printf("A : %d\n", a);
				printf("B : %d\n", b);
				printf("C : %d\n", c);
				printf("D : %d\n", d);
				printf("F : %d\n", f);
				printf("===========================\n");
				break ;
			case 'C' : case 'c' :
				printf("A | "); for(i = 1; i <= a; i++) printf("%c", '*');
				printf("'\n'");
				printf("B | "); for(i = 1; i <= b; i++) printf("%c", '*');printf("'\n'");
				printf("C | "); for(i = 1; i <= c; i++) printf("%c", '*');printf("'\n'");
				printf("D | "); for(i = 1; i <= d; i++) printf("%c", '*');printf("'\n'");
				printf("F | "); for(i = 1; i <= f; i++) printf("%c", '*');printf("'\n'");
				break;
			case 'D' : case 'd' : break;
		}
		if(Grade == 'd' || Grade == 'D')
		{
			printf("�����մϴ�.\n"); break;
		}
	}
	while(1);		
	return 0;
}
