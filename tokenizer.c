#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Defining Node for Linked List
struct Node{
 // int booleans[5] = {0,0,0,0,0}; was throwing error, commented out for now
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

int isWord(char *string){
  return 0;
}

int isOctal(char *string){
  return 0;
}

int isHex(char *string){
  return 0;
}

int isInt(char *string){
  return 0;
}

int isFloat(char *string){
  return 0;
}

int isC_Operator(char *string){
  return 0;
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


char *currentstring = malloc(sizeof(char)*(size_input_string)+1);


int i = 0;

//iterate through input string char by char until the null terminator
while(dest[i]!='\0'){
//char c = argv[1][i];
//printf("char: %c\n", c);

//each iteration, copies destination (argv[1]) into our current string, for a length of i
strncpy(currentstring,dest,i+1);

printf("Current Substring: %s\n", currentstring);
	
//substring(currentstring, dest, startofsubstring, lengthofsubstring);

if (isWord(currentstring)){
puts("found word");
}
if (isOctal(currentstring)){
puts("found octal");
}
if(isHex(currentstring)){
puts("found hex");
}
if(isInt(currentstring)){
puts("found int");
}
if(isFloat(currentstring)){
puts("found float");
}
if(isC_Operator(currentstring)){
puts("found C Operator");
}

//Token does not qualify for any cases - the largest token is the previously found token
if ((!isWord(currentstring)) && (!isOctal(currentstring)) && (!isHex(currentstring))
&& (!isInt(currentstring)) && (!isFloat(currentstring)) && (!isC_Operator(currentstring))){


//This copies the previouly found token and prints it	
//commenting out for now since we need to write our methods first

//strncpy(currentstring, dest, i);
//printf("Reached a non token, tokenizing previous token: %s", currentstring);
//must also start current string at appropriate index from here
}



i++;
}
// Token(dest[0]);	

return 0;
}
