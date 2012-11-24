

/*  funcs.c                                          */ 
/*  Functions to handle cursor movement for          */ 
/*  ia_lexer.                                        */      
/*  This code is released to the public domain.      */ 
/*  "Share and enjoy...."  ;)                        */  
/*  See the UNLICENSE file for details.              */ 


#include <string.h>   
#include <stdio.h> 
#include <stdlib.h> 
#include "ia_lexer.h"  


/*  Error function.  */ 
void error(void)
{ 
   printf("Error \n"); 	
} 	



/*  Display the buffer  */ 
void show(buf b)
{ 
   printf("%s", b.array); 			
} 	



/*  Return a character from the buffer, given an increment. */ 
char get(buf b, int i)
{ 
   char c = b.array[b.index+i] ;  
   return c;		
}	 




/* Move cursor to left. */ 
char left(buf b) 
{


} 


/* Move cursor to right. */ 
char right(buf b) 
{ 


} 



void enter(void) 
{ 
	printf("Enter ");   		
} 	



/* Find if a number is in a given range. */ 
int range(int rstart, int rend, int i)
{
   if ( (rstart <= i) && (i <= rend) ) return 1;
   else return 0;	
	
} 	


/* Assign a type depending on the range that a  */ 
/* number is in.                                */ 
int type(int i)
{ 
   int ret; 
   
        if ( range(0, 9, i) == 1 )       ret = 1; 
   else if ( range(10, 10, i) == 1 )     ret = 2; 
   else if ( range(27, 27, i) == 1 )     ret = 3; 
   else if ( range(32, 126, i) == 1 )    ret = 4;  	   
   else if ( range(127, 127, i) == 1 )   ret = 5;
   else ret = 6;  	   
    
   return ret; 
   
}     
	

/*  Function for special key combinations  */ 
/*  (Ctrl, Alt, function keys.             */ 
void spec(buf b)
{ 
	
  int j = getch();  
    
       if ( ( j == 65 )	)  printf("Up "); 
  else if ( ( j == 66 )	)  printf("Down "); 
  else if ( ( j == 67 )	)  printf("Right "); 
  else if ( ( j == 68 )	)  printf("Left "); 
   		
} 	





