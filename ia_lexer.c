

/*  ia_lexer.c                                         */  
/*  An intercative lexer in C.                         */ 
/*  The aim is to allow you to press the right-arrow   */ 
/*  key and move along an expression, watching the     */ 
/*  various lexemes being created.                     */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 


#include <string.h>  
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h> 

#include "ia_lexer.h"    


int main(void) 
{ 
  
  /* Create a buffer for a statement.  */ 
  buf mybuf;  
  /* Initialise the index at zero (the start of */ 
  /* the command-line). */  
  mybuf.index = 0;   
     
  char *str = "Just a nice long string....." ;    
     
  memcpy(mybuf.array,  str, 79);     
      
  
  while(1) 
  {  
       
    keyhandler(mybuf);  
         
  }         
                                      
  return 0;
	
}  






