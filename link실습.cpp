#include <stdio.h>
#define maxsize 10
#define true 1
#define false 0
int push(char n);
int top = -1;
char stack[maxsize]; 

int main(void)
{
	char c, n;
	char sent[80], *p;
	printf("수식 입력 :");
	p = fgets(sent, 80, stdin);
	while(*p != '\n')
	{
		c = *p++;
		if(c == '(' || c == '{' || c == '[')
		{
			if(push(c) == -1)
			{
			printf("풀\n");
			return 1;
			}
		}
		if(c == ')' || c == '}' || c == ']')
		{
			if(push(c) == -1)
			{
			printf("에러\n");
			return 1;
			}
		}
		else 
			if(n =='('&&c!=')' || n == '{'&& c != '}' || n == ']'&& c != ']')
			{
			printf("잘못입력\n");
			return 1;
			}
	}
}


int push(char n)
{
	if(top < maxsize -1)
	{
		stack[++top] = n;
		return 0;
	}
	else
	return -1;
}




