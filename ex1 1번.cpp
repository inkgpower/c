#include <stdio.h>
#define P 3.14

int main(void)
{
	int r;
	float a, v;

	printf("Enter radius :");
	scanf("%d", &r);
	a = P * r * r;
	printf("area :%.2f\n", a);
	v = 4.0/3.0 * P * r * r * r;
	printf("volumn :%.2f\n", v);
	return 0;
}
