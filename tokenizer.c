#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Defining Node for Linked List
struct Node{
  //  int *truth_values = malloc( (sizeof(int)) * 5);
  char *token;
  struct node *prev;
  struct Node *next;
};
  struct Node* head;

int isWord(char *string){
  int i = 1;
  //checks if first character is an alphabet
  if(isalpha(string[0])==0){
    return 0;
  }
  while(string[i]!='\0'){
    //checks if the following character are alphanumeric
    //if a non-alphanumeric character is found then loop terminates to end the token there
    if(isalpha(string[i])==0 && isdigit(string[i])==0){
      printf("end of word");
      return 0;
    }
    i++;
  }
  return 1;
}

int isHex(char *string){
  //if first character is not zero then return false                                                                                                                                     
  if((string[0]-'0')!= 0){
    return 0;
  }
  int c = string[1];
  //if second character is not 'x' then return false                                                                                                                                     
  if(c!=88 && c!=120){
    return 0;
  }
  //check if following characters are alphanumeric                                                                                                                                       
  int i = 2;
  while(string[i]!='\0'){
     //if its not an alphabet from a-f & A-F then check its a digit, if not then return false                                                                                            
    if(string[i]<65 || (string[i]>70 && string[i]<97) || string[i]>102){
      if(isdigit(string[i])==0){
      printf("end of hex");
      return 0;
      }
    }
    i++;
  }
  return 1;
}

int isOctal(char *string){
  int i = 1;

  if((string[0]-'0')!= 0){
    return 0;
  }

while (string[i]!='\0'){

  //checking for delimitters spc, tab, newline, vertical tab, form feed and carriage return                                                          
  /* if((string[i]==32) || (string[i]==9) || (string[i]==10) || (string[i]==11) || (string[i]==12) || (string[i]==13))
      { 
	return 0;
      }
  */
//converts char to int                                                      
  int c = string[i]-'0';
//reached a character not between 0 and 7
  if (c<0 || c>7){
   return 0;
  }
  i++;
 }
 return 1;
}


int isFloat(char *string){
int i = 0;
 int t = 1;
while (string[i]!='\0'){
  //converts char to int
  int c = string[i]-'0';
  //reached a non int                                                                                                                   
  if (c<0 || c>9){
    if(i>0 && string[i]==46 && t==1){
      t=0;
      
    }
    else {
      return 0;
    }
  }
  i++;
}

  return 1;
}


//Function iterates through string to determine                                                                                                                                          
//whether it is an int                                                                                                                                                                   
//Returns 0 for false or 1 for true                                                                                                                                                      
int isInt(char *string){
int i = 0;
 if(isOctal(string)){
   return 1;
 }
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
if(isHex(currentstring)){
puts("found hex");
hex = 1;
}
if (isOctal(currentstring)){
puts("found octal");
octal = 1;
}
if(isFloat(currentstring)){
puts("found float");
floatp = 1;
}
if(isInt(currentstring)){
puts("found int");
integer = 1;
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
