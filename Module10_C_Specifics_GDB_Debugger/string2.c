#include<stdio.h>
#include<string.h>

// Task2. Build the toLower() function here.
void toLower(char a[]){
     for (int i=0; i<strlen(a); i++){
          if (65<=a[i] && a[i]<=90)
               a[i] = a[i] + 'a' -'A';
     }
}

int main(){
     char input[100];
     // Task 1. Read in user input to the char array input.
     scanf("%s", input);

     // Task 3. Call the toLower function.    
     toLower(input);

     printf("%s",input);
     return 0;
}

// compile: gcc -std=c99 string2.c -o string2