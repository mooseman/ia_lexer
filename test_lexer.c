
/* test_lexer.c  */ 
/* Functions to make up a lexer.  */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 


#include <string.h>  
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 
#include <ctype.h>


/* Print the character type of the char being pointed at. */ 
void chartype(char *str)
{ 
	
  printf("%s \n", str); 	
	
  while( *str != '\0' ) 	
    { 	
        if ( isalpha(*str) )  printf("alpha \n") ; 
   else if ( isdigit(*str) )  printf("digit \n") ; 
   else if ( ispunct(*str) )  printf("punct \n" ) ; 
   else if ( isspace(*str) )  printf("whitespace \n" ) ; 
   else printf("other \n" ) ; 
        str++;
   }
   
}    
   


int can_be_keyword(char c)
{ 


} 


int can_be_varname(char c) 
{ 


} 


int can_be_string(char c)
{ 
	



	
}	



int is_op(char c)
{ 


} 


int is_sep(char c)
{ 
	
	

}	


int main() 
{ 
	
char *str = "ab 5$*	,w f, g7" ; 

chartype(str); 

return 0;	
	
	
	
} 	
	
























