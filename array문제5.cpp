#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


char *wordlist[] = {"love", "school", "library", "store", "apple", "samsung", "factory", "computer", "keyboard", "mouse"};
char check[20];
char temp[20];
char *y, p, a;

void computer();


int main(void)
{
   int n = 10;
   int x, j;
   int i = 0; int f = 0;
   srand(time(NULL));
   
   while(1)
   {
      
      x = rand()%9;
      y = wordlist[x];
   
      for(i = 0; i < strlen(y); i++) check[i] = '_';
      check[i+1] = '\0';
      printf("the word looks like this :");
      
      for(i = 0; i < strlen(y); i++)
      printf("%c", check[i]);
      
      while(n > 0)
		{
            f = 0;
            printf("\nyou have %d guess left\n", n);
            printf("your guess :");
            p = gets(temp);
   
         for(j = 0; j < strlen(y); j++)
            {
               if(y[j] == p)
               check[i] = p;
               f = 1;
            }
         if(stricmp(y, check) == 0) printf("Good\n"); break;
         printf("\nthe word looks like this :");
         
         for(i = 0; i < strlen(y); i++) printf("%c", check[i]);
         n--;
		}

         if(n == 0)
         printf("You lose.\n");
   
         printf("\nDo you want to play the other game<y/n>?");
         scanf("%c", &a);
         getchar();
         if(a == 'Y' && a == 'y') break;
      
         
   }

	return 0;
}
