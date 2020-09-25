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

//Function iterates through string to determine 
//whether it is an int
//Returns 0 for false or 1 for true
int isInt(char *string){
int i = 0;

while (string[i]!='\0'){

//converts char to int
int c = string[i]-'0';

//reached a non int
if (c<0 || c>9){
return 0;
}
i++;
}

return 1;
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

//copy string from argv[1] and put it into destination
strcpy(dest, argv[1]);
printf("String Copied: %s\n", dest);

int i = 0;
int j = 0;
//iterate through input string char by char until the null terminator
while(argv[1][i]!='\0'){

char *currentstring = malloc(sizeof(char)*(size_input_string)+1); 

//each iteration, copies destination (argv[1]) into our current string, for a length of j+1
strncpy(currentstring,dest,j+1);
printf("Current Substring: %s\n", currentstring);
	
//initialize boolean values to false
int word = 0;
int octal = 0;
int hex = 0;
int integer = 0;
int floatp = 0;
int coperator = 0;

if (isWord(currentstring)){
puts("found word");
word = 1;
}
if (isOctal(currentstring)){
puts("found octal");
octal = 1;
}
if(isHex(currentstring)){
puts("found hex");
hex = 1;
}
if(isInt(currentstring)){
puts("found int");
integer = 1;
}
if(isFloat(currentstring)){
puts("found float");
floatp = 1;
}
if(isC_Operator(currentstring)){
puts("found C Operator");
coperator = 1;
}

//Token does not qualify for any cases - the largest token is the previously found token
if ((!word) && (!octal) && (!hex) && (!integer) && (!floatp) && (!coperator)){
	

//This copies the previouly found token and prints it	
//will obviously return this for any methods not yet written
// but it does work for test case: ./a.out 323t
// and test case ./a.out 323t456
char *token = malloc(sizeof(char)*(size_input_string)+1);  
strncpy(token, currentstring, i);
printf("Reached a non token, tokenizing previous token: %s\n", token);

//resets substring pointer to first char after token
int token_size = strlen(token);
dest+=token_size;
j=-1;

//clears current string memory
currentstring = "";
}


j++;
i++;
}
// Token(dest[0]);	

return 0;
}
