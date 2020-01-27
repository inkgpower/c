/*hustar homework 문제7번
  정상원_19.10.11
  2Darray / String
  성적처리프로그램
*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_A(float a[][5], char b[]);  // 선택지 A를 출력해주는 함수 
void print_B(int c[]);  // 선택지 B를 출력해주는 함수 
void print_C(float a[][5], char b[]);  // 선택지 C를 출력해주는 함수 
void print_D(float a[][5]);  // 선택지 D를 출력해주는 함수 
void print_E(float a[][5], char b[]);  // 선택지 E를 출력해주는 함수 
void bubble(float d[][5], char e[]);  // 선택지 E에서 bubble sort를 수행하기 위한 함수 

int main(void)
{
	float arr1[30][5];  // 학생들의 성적을 저장해 놓는 배열 
	char arr2[30];  // 학생들의 학점을 저장해 놓는 배열 
	int arr3[5]={0,0,0,0,0};  // 학점별로 학점의 개수를 저장해 놓는 배열 
	int i,j;
	int hund=100;
	float avr;
	char select, command;
	
	srand(time(NULL));
	
	for(i=0; i<30; i++)  // 배열 arr1을 초기화하는 반복문 
	{
		arr1[i][0] = ++hund;
		arr1[i][1] = rand()%41+60;
		arr1[i][2] = rand()%41+60;
		arr1[i][3] = rand()%61+40;
		avr = (arr1[i][1]*0.2+arr1[i][2]*0.2+arr1[i][3]*0.6);
		arr1[i][4] = avr;
	}
	
	for(i=0; i<30; i++)  // 배열 arr2를 초기화하는 반복문 
	{
		if(arr1[i][4]>=90)
			arr2[i]='A';
		else if(arr1[i][4]>=80)
			arr2[i]='B';
		else if(arr1[i][4]>=70)
			arr2[i]='C';
		else if(arr1[i][4]>=60)
			arr2[i]='D';
		else
			arr2[i]='F';
	}
	
	for(i=0; i<30; i++)  // 배열 arr3를 초기화하는 반복문 
	{
		if(arr2[i]=='A')
			arr3[0]++;
		else if(arr2[i]=='B')
			arr3[1]++;
		else if(arr2[i]=='C')
			arr3[2]++;
		else if(arr2[i]=='D')
			arr3[3]++;
		else
			arr3[4]++;
	}
	
	while(1)  // 선택지 메뉴 출력해주고 그에 따른 배열을 출력해주는 반복문 
	{
		printf("***************Menu**************\n");
		printf("** A. 모든 학생의 성적 출력    **\n");
		printf("** B. Grade에 따른 분포도 출력 **\n");
		printf("** C. 학번에 따른 성적 출력    **\n");
		printf("** D. 총 평점 출력             **\n");
		printf("** E. 정렬된 성적 출력         **\n");
		printf("** F. 프로그램 종료            **\n");
		printf("*********************************\n\n");
		printf("원하는 menu를 선택하세요(A~F) : ");
		scanf("%c%c", &select, &command);
		printf("\n");
		
		if(select == 'A'||select == 'a')
		{
			print_A(arr1, arr2);
		}
		else if(select == 'B'||select == 'b')
		{
			print_B(arr3);
		}
		else if(select == 'C'||select == 'c')
		{
			print_C(arr1, arr2);
		}
		else if(select == 'D'||select == 'd')
		{
			print_D(arr1);
		}
		else if(select == 'E'||select == 'e')
		{
			print_E(arr1, arr2);
		}
		else if(select == 'F'||select == 'f')
		{
			break;
		}
		else
		{
			printf("잘못 입력하였습니다.\n\n");
		}
	}
}

void print_A(float a[][5], char b[])  // A를 선택했을 때 출력해주는 함수 
{
	int i, j;
	printf("ID     Exam1    Exam2    Exam3    Score    Grade\n");
	printf("------------------------------------------------\n");
	for(i=0; i<30; i++)
	{
		printf("%.0f\t", a[i][0]);
		printf("%.0f\t", a[i][1]);
		printf(" %.0f\t", a[i][2]);
		printf("  %.0f\t", a[i][3]);
		printf("  %.1f\t", a[i][4]);
		printf("     %c", b[i]);
		printf("\n");
	}
	printf("------------------------------------------------\n");
}

void print_B(int c[])  // B를 선택했을 때 출력해주는 함수 
{
	int i, j;
	printf("-------------------성적 분포도------------------\n\n");
	
	printf("A : ");
	for(i=0; i<c[0]; i++)
	{
		printf("* ");
	}
	printf("\n");
	
	printf("B : ");
	for(i=0; i<c[1]; i++)
	{
		printf("* ");
	}
	printf("\n");
	
	printf("C : ");
	for(i=0; i<c[2]; i++)
	{
		printf("* ");
	}
	printf("\n");
	
	printf("D : ");
	for(i=0; i<c[3]; i++)
	{
		printf("* ");
	}
	printf("\n");
	
	printf("F : ");
	for(i=0; i<c[4]; i++)
	{
		printf("* ");
	}
	printf("\n");
	
	printf("------------------------------------------------\n");
}

void print_C(float a[][5], char b[])  // C를 선택했을 때 출력해주는 함수 
{
	int findID, i;
	float score;
	char grade, command;
	
	printf("찾고자 하는 ID를 입력해 주세요(101~130) : ");
	scanf("%d%c", &findID, &command);
	
	if(findID>130||findID<101)
	{
		printf("찾고자 하는 학번이 없습니다.\n\n");
		return 0;
	}
		
	for(i=0;i<30;i++)
	{
		if(findID==a[i][0])
		{
			score = a[i][4];
			grade = b[i];
			break;
		}
	}
	printf("ID %d의 score : %.1f\n", findID, a[i][4]);
	printf("ID %d의 grade : %c\n\n", findID, b[i]);
}

void print_D(float a[][5])  // D를 선택했을 때 출력해주는 함수 
{
	int i;
	float sum, avr;
	float grade;
	
	for(i=0; i<30; i++)
	{
		sum += a[i][4];
	}
	
	avr = sum/30;
	
	for(i=0; i<30; i++)
	{
		if(a[i][4]>=90)
			grade=4.0;
		else if(a[i][4]>=80)
			grade=3.0;
		else if(a[i][4]>=70)
			grade=2.0;
		else if(a[i][4]>=60)
			grade=1.0;
		else
			grade=0;
	}
	
	printf("총 평점은 %.1f 입니다.\n\n", grade);
}

void print_E(float a[][5], char b[])  // E를 선택했을 때 출력해주는 함수 
{
	float ta[30][5];  // 선택지 E를 출력한 후 A를 선택했을 때 원래의 정렬로 돌아가기 위한 임시의 배열 선언 
	char tb[30]; 
	int i, j;
	
	for(i=0; i<30; i++)
	{
		for(j=0; j<5; j++)
		{
			ta[i][j] = a[i][j];
			tb[i] = b[i];
		}
	}
	
	bubble(ta, tb);
	
	printf("ID     Exam1    Exam2    Exam3    Score    Grade\n");
	printf("------------------------------------------------\n");
	for(i=0; i<30; i++)
	{
		printf("%.0f\t", ta[i][0]);
		printf("%.0f\t", ta[i][1]);
		printf(" %.0f\t", ta[i][2]);
		printf("  %.0f\t", ta[i][3]);
		printf("  %.1f\t", ta[i][4]);
		printf("     %c", tb[i]);
		printf("\n");
	}
	printf("------------------------------------------------\n");
}

void bubble(float d[][5], char e[])  // E를 선택했을 때 bubble sort를 진행해주는 함수 
{                                                                     
	int i, j;
	float t;
	char t1;
	
	for(i=1; i<30; i++)
		for(j=29; j>=i; j--)
			if(d[j-1][4]<d[j][4])
			{
				t=d[j-1][0];
				d[j-1][0]=d[j][0];
				d[j][0]=t;
				
				t=d[j-1][1];
				d[j-1][1]=d[j][1];
				d[j][1]=t;
				
				t=d[j-1][2];
				d[j-1][2]=d[j][2];
				d[j][2]=t;
				
				t=d[j-1][3];
				d[j-1][3]=d[j][3];
				d[j][3]=t;
				
				t=d[j-1][4];
				d[j-1][4]=d[j][4];
				d[j][4]=t;
				
				t1=e[j-1];
				e[j-1]=e[j];
				e[j]=t1;
			}
}
