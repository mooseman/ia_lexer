

/*  ia_lexer.h                                         */  
/*  Header file for ia_lexer.                          */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 


/*  Buffer typedef.  */ 
typedef struct { 
	int index; 
	char array[80] ; 
} buf;  


/*  Termios funcs.  */ 
void initTermios(int echo) ;
void resetTermios(void) ;
char getch_(int echo);
char getch(void);
char getche(void);


/*  Buffer funcs. */ 
void error(void); 
void show(buf b);

char get(buf b, int i); 

char left(buf b); 
char right(buf b); 
buf delch(buf b); 
buf insch(buf b); 
void enter(void);  
int range(int rstart, int rend, int i);
int type(int i); 


/*  Special key handling.  */ 
void spec(buf b); 


/*  Other funcs.  */  
void keyhandler(buf b);  









