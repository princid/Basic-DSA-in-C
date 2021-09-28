//Ques.5- Write a Program to compute the length of a character string.
 
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
	char Str[1000]; 
	int i; 

	printf("Enter the String: "); 
	scanf("%s", Str); 

	for (i = 0; Str[i] != '\0'; ++i); 

	printf("Length of Str is %d", i); 
	
	return 0; 
} 
