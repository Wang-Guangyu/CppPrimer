#include <stdio.h>
int main(){
   char name[100];
   printf("What is your name?\n");
   scanf("%s",name);
   getchar();
   printf("Hello,%s,nice to meet you!\n",name);
   return -1;
}