#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char array[3][3];
void matrix();


int main(void)
{
	int a, b;
	
	
		matrix();
		printf("Enter the coordinate for your X and Y(ex. 2 3) :");
		scanf("%d %d", &a, &b);
		
	return 0;
}




void matrix()
{
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			array[i][j] = ' ';
	
	
	printf(" %c : %c : %c :\n", array[0][0], array[0][1], array[0][2]);
	printf("--------------------\n");
	printf(" %c : %c : %c :\n", array[1][0], array[1][1], array[1][2]);
	printf("--------------------\n");
	printf(" %c : %c : %c :\n", array[2][0], array[2][1], array[2][2]);
	
}


