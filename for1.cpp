#include <stdio.h>

int main(void)
{
	int a, b, sum = 0;
	printf("������ �Է��ϼ��� :");
	scanf("%d", &a);
	
	for(b = 1; a > 0; b++)
	{
		printf("������ �Է��ϼ��� :");
		sum  += a;
		scanf("%d", &a);
		
		
	}
	printf("�� : %d\n��հ� : %.2f", sum, (float)sum/(b-1));
	 
	return 0;
}


