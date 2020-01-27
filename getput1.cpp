#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

void read(char n[][10]);
void print(char n[][10]);

int main(void)
{
	char names[5][10];
	char *n;
	read(names);
	print(names);
	
	
	return 0;
}


void read(char n[][10])
{
	int i = 0;
	for(i = 0; i < 5; i++)
		gets(char n[i]);
}

void print(char n[][10])
{
	int i = 0;
	for(i = 0; i < 5; i++)
		puts(char n[i]);
}


