#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Defining Node for Linked List
struct Node{
  char *token;
  struct node *prev;
  struct Node *next;
};
  struct Node* head;


//Based on the first character of the string decides which Token method to send the string to
//Returns a linked list of all tokens
struct Node Token(char c){
  
    if((c>=65 && c<=90) || (c>=97 && c <= 122)){
      //go to Word method
    }

    else if(c==48){
      //go to Octal, Hex, Int and Float methods
    }
    else if(c>=49 && c<=57){
      //go to Integer and Float method 
    }
    else{
      //go to C operator method
    }

    return *head;
}

struct Node Word(char *string){
  return *head;
}

struct Node Octal(char *string){
  return *head;
}

struct Node Hex(char *string){
  return *head;
}

struct Node Int(char *string){
  return *head;
}

struct Node Float(char *string){
  return *head;
}

struct Node C_Operator(char *string){
  return *head;
}



int main(int argc, char** argv){

//gets size of input string	
int size_input_string = strlen(argv[1]);

//points to memory
//where we will copy input string into
char *dest = malloc(sizeof(char)*((size_input_string)+1));


//copy string from src and put it into destination
strcpy(dest, argv[1]);


printf("String Copied: %s\n", dest);



int i = 0;

//iterate through input string char by char until the null terminator
while(argv[1][i]!='\0'){
char c = argv[1][i];
printf("char: %c\n", c);

i++;
}
 Token(dest[0]);	

return 0;
}
