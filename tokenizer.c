#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
	

return 0;
}
