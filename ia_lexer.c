

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
#include <termios.h> 


/* This implementation of getch() is from here - */ 
/* http://wesley.vidiqatch.org/                  */ 
/* Thanks, Wesley!                               */  
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new = old; /* make new settings same as old settings */
    new.c_lflag &= ~ICANON; /* disable buffered i/o */
    new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}


/* Restore old terminal i/o settings */
void resetTermios(void) 
{
    tcsetattr(0, TCSANOW, &old);
}


/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}


/* Read 1 character without echo */
char getch(void) {
    return getch_(0);
}


/* Read 1 character with echo */
char getche(void) {
    return getch_(1);
} 



/*  Buffer.  */ 
typedef struct { 
	int index; 
	char array[80] ; 
} buf;  


/*  Key-handler function.  */ 
void keyhandler(buf b)
{ 
    int key = getch(); 

    /* An escape key-sequence */                           
    if(key == 27) 
        {
           key = getch(); 
           if(key == 91)               
           key = getch(); 
                		  
		  if(key == 67)  /* Left arrow */ 
          { 	
			 /* Move one character to the left. */ 				 
			  printf("\033[1C"); 
          }
          
          if(key == 68)  /* Right arrow */ 
          { 	
			/* Move one character to the right. */ 					  
			  printf("\033[1D"); 
          }
		 		  	  		
      }  /* End of key=27 key sequence. */ 
					  			                                                   
                                                 
     /* The Enter key exits. Enter is 10 decimal */	  
        else if(key == 10)  
		{ 			 
			 puts("\n");  
			 puts("Exiting... \n"); 	
			 exit(0); 				  					               
        }  /* Key = Enter */   
             		
} 	



int main(void) 
{ 
  
  /* Create a buffer for a statement.  */ 
  buf mybuf;  
  /* Initialise the index at zero (the start of */ 
  /* the command-line). */  
  mybuf.index = 0;   
     
  char *str = "select var1 from mytable where city = \"Sydney\" ; " ;    
     
  memcpy(mybuf.array,  str, 79);     
  
  /* Print the array. */  
  printf("%s", mybuf.array);      
  
  /* Position cursor at start of line.  */ 
  printf("\033[80D");   
  
  while(1) 
  {  
       
    keyhandler(mybuf);  
         
  }         
                                      
  return 0;
	
}  






