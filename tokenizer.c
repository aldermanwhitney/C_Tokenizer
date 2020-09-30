
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
 // struct Node* head;

struct C_Operator{
char *operator_name;
int operator_length;
};

enum token_type{integer, word, hexadecimal, octal, floating_point, c_operator};

struct Token{
char *token_string;
enum token_type token_type;
struct Token *next;
};
struct Token* head = NULL;


//Function takes a pointer to a struct token,
//adds this token to the front of the linked list, 
//and returns a pointer to the head
struct Token* addTokentoLinkedList(struct Token* token){	
if (head!=NULL){	
head->next=token;
}
head = token;
return head;
}


//Function takes a token string and token type
//and return a pointer to a newly malloc'ed struct token 
struct Token* createToken(char *token_string, enum token_type tt){
struct Token *token = malloc(sizeof(struct Token));
token->token_string = token_string;
token->token_type = tt;
return token;
}



int isWord(char *string){
  int i = 1;
  //checks if first character is an alphabet
  if(isalpha(string[0])==0){
    return 0;
  }
  while(string[i]!='\0'){
    //checks if the following character are alphanumeric
    //if a non-alphanumeric character is found then loop terminates to end the token there
    if(isalnum(string[i])==0){
      //printf("end of word");
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
    // if(string[i]<65 || (string[i]>70 && string[i]<97) || string[i]>102){
    // if(isdigit(string[i])==0){
    if(isxdigit(string[i])==0){
      printf("end of hex");
      return 0;
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

int decimal_count=0;
int i = 0;
	
	while (string[i]!='\0'){
		
		char c = string[i]-'0';

		//if character is not an integer or . return false
		if((string[i]!='.') && ((c<0) || c>9)){
		return 0;
		}
		//If character has a decimal, must only have one
		//And must not be at first or last index
		if ((string[i]=='.')&&(i!=strlen(string)-1) &&(i!=0)){
		decimal_count++;
		}

	i++;
	}

if (decimal_count!=1){
return 0;
}
return 1;
}



int isPossibleFloat(char *string){
int i = 0;
int t = 0;
 int s = 0;
 int e=0;
 int negative=0;

 //just added this line for compilation - compiler says negative is initialized but never used
 //and i dont see when you do anything with it other than set it to 0 or 1
 if (negative){

}

 // int k = (int)strlen(string);
 for(int j = 0;  j < strlen(string); j++){
   if(string[j]=='.' && j!=0){
     s=1;
   }
 }
 if(s==0){
   return 0;
 }
while (string[i]!='\0'){
  //converts char to int
  int c = string[i]-'0';
  //reached a non int                                                                                                                   
  if (c<0 || c>9){
    if(i>0 && string[i]==46 && t==0){
      t=1;
      
    }
    else if(e==0 && t==1 && (string[i]==69 || string[i]==101)){
      e=i;
      // printf("found e");
      //      continue;
    }
    else if(e==(i-1) && t==1 && (string[i]==45 || string[i]==43)){
      negative=1;
      // printf("found e negative/positive");
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

/**This function takes a char array, 
 * and returns a pointer to a newly malloced char array
 *this char array will contain an empty string, if the input is not a C operator
 or it will return a pointer to a string which describes the type of c operator it is
 I'm going to clean this up a bit later to optimize, but it works well
 try ./a.out test->ing
 
 */

//char* isC_Operator(char *string){

struct C_Operator* isC_Operator(char *string){

//char *c_op = malloc(sizeof(char)*50);	

struct C_Operator *c_operator_struct = malloc(sizeof(struct C_Operator));
c_operator_struct->operator_length=0;
c_operator_struct->operator_name="";

//c_op = "";

int i = 0;	
//char c = string[0];

//printf("ignore: %s\n", c_op);
//printf("%c\n", c);


//if the string is length one, choose from possible operators
if (strlen(string)==1){

c_operator_struct->operator_length=1;
switch(string[i]) {
	case '(':
		//puts("found left parenthesis");
		//c_op = "left parenthesis";	
		//return c_op;
		c_operator_struct->operator_name = "left parenthesis";
		return c_operator_struct;
        case ')':
		c_operator_struct->operator_name = "right parenthesis";
		return c_operator_struct;
        case '[': 
		c_operator_struct->operator_name = "left bracket";
		return c_operator_struct;
	case ']':
		c_operator_struct->operator_name = "right bracket";
		return c_operator_struct;
	case '.':
		c_operator_struct->operator_name = "structure member";
		return c_operator_struct;
	case ',':
		c_operator_struct->operator_name = "comma";
		return c_operator_struct;
	case '!':
		c_operator_struct->operator_name = "negate";
		return c_operator_struct;
	case '~':
		c_operator_struct->operator_name = "1s complement";
		return c_operator_struct;
	case '^':
		c_operator_struct->operator_name = "bitwise XOR";
		return c_operator_struct;
	case '|':
		c_operator_struct->operator_name = "bitwise OR";
		return c_operator_struct;
	case '+':
		c_operator_struct->operator_name = "addition";
		return c_operator_struct;
	case '/':
		c_operator_struct->operator_name = "division";
		return c_operator_struct;
	case '?':
		c_operator_struct->operator_name = "conditional true";
		return c_operator_struct;
	case ':':   		
		c_operator_struct->operator_name = "conditional false";
		return c_operator_struct;
	case '<':
		c_operator_struct->operator_name = "less than test";
		return c_operator_struct;
	case '>':
		c_operator_struct->operator_name = "greater than test";
		return c_operator_struct;
	case '=':
		c_operator_struct->operator_name = "assignment";
		return c_operator_struct;
	case '&':
		c_operator_struct->operator_name = "AND/address operator";
		return c_operator_struct;
	case '-':
		c_operator_struct->operator_name = "minus/subtract operator";
		return c_operator_struct;
	case '*':
		c_operator_struct->operator_name = "multiply/dereference operator";
		return c_operator_struct;
	default:
		c_operator_struct->operator_length=0;
		//return c_op;
		return c_operator_struct;
	}


}

if (strlen(string)==2){

c_operator_struct->operator_length=2;

char c1 = string[0];
char c2 = string[1];


if ((c1 =='-') && (c2 == '>')){	
c_operator_struct->operator_name = "structure pointer";
return c_operator_struct;
//c_op = "structure pointer";
//return c_op;
}

if ((c1 =='>') && (c2 == '>')){
c_operator_struct->operator_name = "shift right";
return c_operator_struct;
}

if ((c1 =='<') && (c2 == '<')){
c_operator_struct->operator_name = "shift left";
return c_operator_struct;
}
if ((c1 =='+') && (c2 == '+')){
c_operator_struct->operator_name = "increment";
return c_operator_struct;
}
if ((c1 =='-') && (c2 == '-')){
c_operator_struct->operator_name = "decrement";
return c_operator_struct;
}

if ((c1 =='|') && (c2 == '|')){
c_operator_struct->operator_name = "logical OR";
return c_operator_struct;
}
if ((c1 =='&') && (c2 == '&')){
c_operator_struct->operator_name = "logical AND";
return c_operator_struct;
}
if ((c1 =='=') && (c2 == '=')){
c_operator_struct->operator_name = "equality test";
return c_operator_struct;
}
if ((c1 =='!') && (c2 == '=')){
c_operator_struct->operator_name = "inequality test";
return c_operator_struct;
}
if ((c1 =='<') && (c2 == '=')){
c_operator_struct->operator_name = "less than or equal test";
return c_operator_struct;
}
if ((c1 =='>') && (c2 == '=')){
c_operator_struct->operator_name = "greater than or equal test";
return c_operator_struct;
}
if ((c1 =='+') && (c2 == '=')){
c_operator_struct->operator_name = "plus equals";
return c_operator_struct;
}
if ((c1 =='-') && (c2 == '=')){
c_operator_struct->operator_name = "minus equals";
return c_operator_struct;
}
if ((c1 =='*') && (c2 == '=')){
c_operator_struct->operator_name = "times equals";
return c_operator_struct;
}
if ((c1 =='/') && (c2 == '=')){
c_operator_struct->operator_name = "divide equals";
return c_operator_struct;
}
if ((c1 =='%') && (c2 == '=')){
c_operator_struct->operator_name = "mod equals";
return c_operator_struct;
}
if ((c1 =='&') && (c2 == '=')){	
c_operator_struct->operator_name = "bitwise AND equals";
return c_operator_struct;
}
if ((c1 =='^') && (c2 == '=')){
c_operator_struct->operator_name = "bitwise XOR equals";
return c_operator_struct;
}
if ((c1 =='|') && (c2 == '=')){
c_operator_struct->operator_name = "bitwise OR equals";
return c_operator_struct;
}

c_operator_struct->operator_length=0;
return c_operator_struct;
}


//Strings length 3
if (strlen(string)==3){

c_operator_struct->operator_length=3;
	
char c1 = string[0];
char c2 = string[1];
char c3 = string[2];
	
if ((c1 =='>') && (c2 == '>') && (c3=='=')) {
c_operator_struct->operator_name = "shift right equals";
return c_operator_struct;
}

if ((c1 =='<') && (c2 == '<')&& (c3=='=')){
c_operator_struct->operator_name = "shift left equals";
return c_operator_struct;
}



}


  c_operator_struct->operator_length=0;
  return c_operator_struct;

}


int main(int argc, char** argv){

//checks that we have the right number of arguements
if (argc!=2){
return 1;
}
	
	
//gets size of input string	
int size_input_string = strlen(argv[1]);
printf("input string size: %i\n", size_input_string);

//points to memory
//where we will copy input string into
char *dest = malloc(sizeof(char)*((size_input_string)+1));

//copy string from argv[1] and put it into destination
strncpy(dest, argv[1],size_input_string+1);
printf("String Copied: %s\n", dest);


//i is the index of the entire input string we are on
//j is the index of the substring we are currently examining
//j+1 is the length of the substring we are currently examining
int i = 0;
int j = 0;
//iterate through input string char by char until the null terminator
while(argv[1][i]!='\0'){

//printf("i: %i\n", i);
//printf("j: %i\n", j);

 if((argv[1][i]==' ')){
  i++;
  j++;
  continue;
 }

char *currentstring = malloc(sizeof(char)*(size_input_string)+1); 

//each iteration, copies destination (argv[1]) into our current string, for a length of j+1
//j will increment past a token when it is found
strncpy(currentstring,dest,j+1);
printf("Current Substring: %s\n", currentstring);
//printf("length of j+1: %i\n", (j+1));


//initialize boolean values to false
int word = 0;
int octal = 0;
int hex = 0;
int integer = 0;
int floatp = 0;
int coperator = 0;

int coperator_index_increment = 0;
 
coperator_index_increment = 0;
if (isWord(currentstring)){
puts("found word");
word = 1;

struct Token *word_token = malloc(sizeof(struct Token));
word_token->token_string =currentstring;
word_token->token_type = word;

if (head!=NULL){
head->next=word_token;
}
head = word_token;
}
if(isHex(currentstring)){
puts("found hex");
hex = 1;
struct Token *hex_token = malloc(sizeof(struct Token));
hex_token->token_string =currentstring;
hex_token->token_type = hexadecimal;

if (head!=NULL){
head->next=hex_token;
}
head = hex_token;
}
if (isOctal(currentstring)){
puts("found octal");
octal = 1;
struct Token *octal_token = malloc(sizeof(struct Token));
octal_token->token_string =currentstring;
octal_token->token_type = octal;

if (head!=NULL){
head->next=octal_token;
}
head = octal_token;
}
if(isFloat(currentstring)){
puts("found float");
floatp = 1;
struct Token *float_token = createToken(currentstring, floating_point);
head = addTokentoLinkedList(float_token);
}
if(isInt(currentstring)){
puts("found int");
integer = 1;
struct Token *int_token = createToken(currentstring, integer);
head = addTokentoLinkedList(int_token);

/*
struct Token *int_token = malloc(sizeof(struct Token));
int_token->token_string =currentstring;
int_token->token_type = integer;
printf("integer token type:%d", int_token->token_type );
if (head!=NULL){
head->next=int_token;
}
head = int_token;

*/


//printf("head token type:%d", head->token_type );
//if((head->token_type)==integer){
//puts("yes, token type is an integer");
//}

}

if (coperator_index_increment){
}

//Pointer that points to the string returned by isC_Operator
//char *str = isC_Operator(currentstring);

//Pointer that points to C_operator struct
struct C_Operator *c_operator_struct = isC_Operator(currentstring);

//if the c operator struct contains an operator length other than zero, we have found a c operator
if((c_operator_struct->operator_length)!=0){
printf("found C Operator: %s\n", (c_operator_struct->operator_name));
coperator = 1;
coperator_index_increment = (c_operator_struct->operator_length);


struct Token *c_operator_token = malloc(sizeof(struct Token));
c_operator_token->token_string =currentstring;
c_operator_token->token_type = c_operator;

if (head!=NULL){
head->next=c_operator_token;
}
head = c_operator_token;


}


//If the string returned is not empty, we have found a string operator
//will need to increment accordingly here depening on whether its 1,2 or 3 characters
//probably need another function to do that
//maybe use an enum
//if(strlen(str)!=0){
//printf("found C Operator: %s\n", str);
//coperator = 1;
//}

//Token does not qualify for any cases - the largest token is the previously found token
//OR we have reached the char just before the null terminator
if (((!word) && (!octal) && (!hex) && (!integer) && (!floatp) && (!coperator)) || (argv[1][i+1]=='\0')){


if((argv[1][i+1]=='\0')){	
strncpy(currentstring,dest,j+2);  
char *token = malloc(sizeof(char)*(size_input_string)+1);
strncpy(token, currentstring, ((strlen(currentstring)+j+1)) );
printf("Reached the end of the string:, tokenizing the rest of the token: %s\n", token);
return 0;
}

if (isPossibleFloat(currentstring)){
puts("can possibly be float - checking next index..");

char *possible_float = malloc(sizeof(char)*(size_input_string+1));
strncpy(possible_float, dest, j+2);
printf("checking this for a float:%s\n",  possible_float);

if (isFloat(possible_float)){
puts("next token will be float, continue iterations as normal");
i++;
j++;
free(possible_float);
continue;
}
free(possible_float);
}


//This copies the previouly found token and prints it	
//will obviously return this for any methods not yet written
// but it does work for test case: ./a.out 323t
// and test case ./a.out 323t456
char *token = malloc(sizeof(char)*(size_input_string)+1);  
strncpy(token, currentstring, j);
printf("Reached a non token, tokenizing previous token: %s\n", token);
printf("Token Type: %d\n",head->token_type);
printf("Token String: %s\n", head->token_string);
//printf("token length, i: %i\n", i);
//resets substring pointer to first char after token
int token_size = strlen(token);
//printf("token_size: %i\n", token_size);     
dest+=token_size;
j=-1;

//move iteration back one, to examine next token
i=i-1; //was missing this before

//clears current string memory
//currentstring = "";
free(currentstring);
}

 j++;
 i++;
}
	

free(dest);
return 0;
}
