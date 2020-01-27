#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int array[30][5];
int array1[5];
char array2[30];
int i;
void a();
void b();
void grade();



int main(void)
{
	int i;
	srand(time(NULL));
	a();
	b();
	
	return 0;
}



void a()
{	int i;
	for(i = 0; i < 30; i++)
	{
	array[i][0] = 101 + i;
	array[i][1] = rand()%40+60;
	array[i][2] = rand()%40+60;
	array[i][3] = rand()%60+40;
	array[i][4] = array[i][1]*0.2 + array[i][2]*0.2 + array[i][3]*0.6;
	}
}


void b()
{
	printf("ID  exam1 exam2 exam3 score\n");
	printf("-----------------------------\n");
	for(i = 0; i < 30; i++)
	printf("%-4d  %-4d  %-4d  %-4d  %-4d\n", array[i][0], array[i][1], array[i][2], array[i][3], array[i][4]);
}

void grade()
{
	for(i = 0; i < 30; i++)
	{
	if(array[i][4] >= 90)
	array2[i] = {A};
	else if(array[i][4] >= 80)
	array2[i] = {B};
	else if(array[i][4] >= 70)
	array2[i] = {C};
	else if(array[i][4] >= 60)
	array2[i] = {D};
	else(array[i][4] < 60)
	array2[i] = {F};
	}
}
