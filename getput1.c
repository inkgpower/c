#include <stdio.h>


void read(char n[][10]);
void print(char n[][10]);
void search(char n[][10]);

int main(int argc, char *argv[])
{
	
	char names[5][10];
	char *n;
	
	read(names);
	print(names);
	n = search(names);
	puts(n);
	
	
	return 0;
}


void read(char n[][10])
{
	int i = 0;
	for(i = 0; i < 5; i++)
		gets(n[i]);
}

void print(char n[][10])
{
	int i = 0;
	for(i = 0; i < 5; i++)
		puts(n[i]);
}

void search(char n[][10])
{
	char a[10];
	int i;
	
	
	for(i = 0; i < 5; i++)
	strstr(n[i], a);
	
}

sort(char n[][10])
{
	
	
	
}
