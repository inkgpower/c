#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char array[3][3];
void matrix();
void computer();
void player();
void occupied();


int main(void)
{
	int a, b, i, j;
		int f = 0;
		matrix();
	
	
		while(1)
		{
	
		int i, j;
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
				array[i][j] = ' ';
		
	
		}
		player();
		computer();
		matrix();
	
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
				if(array[i][j] = ' ');
					f = 1;
					if(f == 0) break;
		
	return 0;
}




void matrix()
{
	printf(" %c : %c : %c :\n", array[0][0], array[0][1], array[0][2]);
	printf("------------------\n");
	printf(" %c : %c : %c :\n", array[1][0], array[1][1], array[1][2]);
	printf("------------------\n");
	printf(" %c : %c : %c :\n", array[2][0], array[2][1], array[2][2]);
}

void player()
{
	int a, b;
	printf("Enter the coordinate for your X and Y(ex. 2 3) :");
	scanf("%d %d", &a, &b);
	getchar();
	array[a][b] = 'O';
}

void computer()
{
	int n1, n2;
	n1 = rand()%2;
	n2 = rand()%2;
	array[n1][n2] = 'X';
}

void occupied()
{
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(array[i][j] != ' ');
			 printf("Occupied!\n");
}
