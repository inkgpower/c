#include <stdio.h>

int main(void)
{
	int a, b, sum = 0;
	printf("정수를 입력하세요 :");
	scanf("%d", &a);
	
	for(b = 1; a > 0; b++)
	{
		printf("정수를 입력하세요 :");
		sum  += a;
		scanf("%d", &a);
		
		
	}
	printf("합 : %d\n평균값 : %.2f", sum, (float)sum/(b-1));
	 
	return 0;
}


