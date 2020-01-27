#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *inkg;
typedef struct linked_list
{
	char name[120];
	int quiz1;
	int quiz2;
	int mid;
	int final;
	int score;
	char grade;
	struct linked_list *next;
	
} LIST;

void disp(LIST *n);
void input(LIST *n);
void search(LIST *n);

int main(void)
{
	
	int i, j, menu;
	
	LIST *head;
	head = (LIST*)malloc(sizeof(LIST));
	head -> next = NULL;
	while(1)
	{
	printf("\n1. display\n2. search by name\n3. add\n4. delete\n5. save\n6. quit\n메뉴를 선택하세요 :");
	scanf("%d", &menu);
	getchar();
	input(head);
	switch(menu)
	{
		case 1 : disp(head); break;
		case 2 : search(head); break;
	}
	

	
	}
	
	return 0;
}



void input(LIST *n)
{
	inkg = fopen("inkg.txt", "r");
	LIST *h = n;
	
	while(!feof(inkg))
	{
		
		fscanf(inkg, "%s %d %d %d %d", h->name, &h->quiz1, &h->quiz2, &h->mid, &h->final);
		
		h->score = 0.15*h->quiz1 + 0.15*h->quiz2 + 0.3*h->mid + 0.4*h->final;
		
		if(h->score >= 90) h->grade = 'A';
		else if(h->score >= 80) h->grade = 'B';
		else if(h->score >= 70) h->grade = 'C';
		else if(h->score >= 60) h->grade = 'D';
		else if(h->score < 60) h->grade = 'F';	
		
		h -> next = (LIST*)malloc(sizeof(LIST));
		h = h -> next;
		h -> next = NULL;
		
	}
	fclose(inkg);
}


void disp(LIST *n)
{
	
	LIST *h = n;
	while(h!=NULL)
	{
	printf("%-3s %-3d %-3d %-3d %-3d %-3d %-3c\n", h->name, h->quiz1, h->quiz2, h->mid, h->final, h->score, h->grade);
	h = h->next;
	}
}

void search(LIST *n)

{
	char temp;
	LIST *h = n;
	
	printf("이름을 입력하세요 :");
	scanf("%s", &temp);
	if(strcmp(h->name, temp) == 0)
	printf("%s %d %c", h->name, h->score, h->grade);
	
	
	
	
}
