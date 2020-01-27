#include <stdio.h>

int main(void)
{
	char a[5][10];
	int i;
	
	for(i = 0; i < 5; i++)
	gets(a[i]);
	for(i = 0; i < 5; i++)
	puts(a[i]);
	
	return 0;
}
