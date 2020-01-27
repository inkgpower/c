#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
   char id[20];
   char name[20];
   int time;
   int pay;
   float total_pay;
} CHART;
void a(CHART a[]);
void b(CHART b[]);
void c(CHART c[]);
void d(CHART d[]);
void e(CHART e[]);
int f(CHART *f);

int n_i = 10; 

int main(void)
{
	FILE *printa;
	int i;
   char menu;
	printa = fopen("inkg.txt", "r");
	
	   
   
   CHART chart[20] =
   {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
	  {0, 0, 0, 0},
	  {0, 0, 0, 0},
	  {0, 0, 0, 0};
	  
   for(i = 0; i < n_i; i++)
   {
   if(chart[i].time > 40)
   chart[i].total_pay = 1.5*chart[i].pay * (chart[i].time-40)+chart[i].pay*40;
   else
   chart[i].total_pay = chart[i].pay * chart[i].time;
   }
   
   while(1)
   {
      printf("\n=============================\n"); 
      printf("A. �����ü ���� ���\n");
      printf("B. Ư�� ��� ���� ���\n");
      printf("C. ����� ���� ����\n");
      printf("D. ��ü �ٹ� �ð��� �� ���޾�\n");
      printf("E. �� ����� �߰�\n");
      printf("F. File�� ����\n"); 
      printf("G. ����\n");
      printf("=============================\n"); 
      printf("�޴��� �����ϼ���.:");
      scanf("%c", &menu);
      getchar();
      switch(menu)
      {
         case 'A' : case 'a' : a(chart); break;
         case 'B' : case 'b' : b(chart); break;
         case 'C' : case 'c' : c(chart); break;
         case 'd' : case 'D' : d(chart); break;
         case 'e' : case 'E' : e(chart); break;
         case 'F' : case 'f' : f(chart); break;
         case 'G' : case 'g' : exit(0);
      }
      
   }
  

       
   return 0;
}

void a(CHART a[])
{
   int i;
   printf("%10s%7s%12s%15s%20s","\n�����ȣ", "����", "�ٹ��ð�", "�ð����ӱ�","�ѱ޿�<����:��>\n");
      printf("==============================================================\n");
    for(i = 0; i < n_i; i++)
   printf("%-10s%-12s%-12d%-15d%-20.2f\n", a[i].id, a[i].name, a[i].time, a[i].pay, a[i].total_pay/10000);
}

void b(CHART b[])
{
   int i;
   int flag = 0;
   char check[1][20];
   printf("�˻��� ����� �Է��ϼ��� : %s", check[0]); 
   scanf("%s", check[0]);
   getchar();
   for(i = 0; i < n_i; i++)
   {
   if(strcmp(check[0], b[i].name) == 0)
   printf("����� :%s\n", b[i].name);
   printf("�ٹ��ð� : %d�ð�\n", b[i].time);
   printf("�ð��� �ӱ� : %d��\n", b[i].pay);
   printf("�� �ӱ� : %.2f����\n", b[i].total_pay/10000);
   flag = 1;
   if(i == 0) break;
   }
}

void c(CHART c[])
{
CHART n_chart[20], temp;

int i, j;

   
   for(i = 0; i < n_i; i++)
   n_chart[i] = c[i];

   for(i = 0; i < n_i; i++)
   {   
      for(j = n_i-1; j >= i; j--)
      if(strcmp(n_chart[j-1].name, n_chart[j].name) > 0 )
      {
      temp = n_chart[j-1];
      n_chart[j-1] = n_chart[j];
      n_chart[j] = temp;
      }
   }
   
   printf("%10s%7s%12s%15s%20s","\n�����ȣ", "����", "�ٹ��ð�", "�ð����ӱ�","�ѱ޿�<����:��>\n");
      printf("==============================================================\n");
    for(i = 0; i < 10; i++)
   printf("%-10s%-12s%-12d%-15d%-20.2f\n", n_chart[i].id, n_chart[i].name, n_chart[i].time, n_chart[i].pay, n_chart[i].total_pay/10000);

}



void d(CHART d[])
{
   int sum = 0; float sum1 = 0;
   int i;
   for(i = 0; i < n_i; i++)
   {
   sum += d[i].time;
   sum1 += d[i].total_pay;
   }
   
   printf("\n�� �ٹ� �ð� : %d�ð�\n", sum);
   printf("�� ���� �ӱ� : %.2f��\n", sum1);
}


void e(CHART e[])
{
   int i;
   
   printf("�߰��� ���ID�� �Է� :");
   scanf("%s", e[n_i].id);
   getchar();
   printf("\n�߰��� ������� �Է� :");
   scanf("%s", e[n_i].name);
   getchar();
   printf("\n�ٹ��ð� �Է� :");
   scanf("%d", &e[n_i].time);
   getchar();
   printf("\n�ð��� �ӱ� �Է� :");
   scanf("%d", &e[n_i].pay);
   getchar();
   
   if(e[n_i].time > 40)
   e[n_i].total_pay = 1.5*e[n_i].pay * (e[n_i].time-40)+e[n_i].pay*40;
   else
   e[n_i].total_pay = e[n_i].pay * e[n_i].time;
   
   n_i++;

}


int f(CHART *f)
{
	FILE *print;
	
	print = fopen("inkg1.txt","w");
	int i;
	
	if(print == NULL)
	{
		printf("��¿���\n");
		return -1;
	}
	
	for(i = 0; i < n_i; i++)
   	{
		if(f[i].time > 40)
		f[i].total_pay = 1.5*f[i].pay * (f[i].time-40)+f[i].pay*40;
		else
		f[i].total_pay = f[i].pay * f[i].time;
   	}
	
	
	fprintf(print, "%10s%7s%12s%15s%20s","\n�����ȣ", "����", "�ٹ��ð�", "�ð����ӱ�","�ѱ޿�<����:��>\n");
    fprintf(print, "==============================================================\n");
	for(i = 0; i < n_i; i++)
	fprintf(print, "%-10s%-12s%-12d%-15d%-20.2f\n", f[i].id, f[i].name, f[i].time, f[i].pay, f[i].total_pay/10000);
	
	fclose(print);
}
