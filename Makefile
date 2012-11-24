

#  Makefile for ia_lexer     


CC = gcc

CFLAGS = -O2 -Wall -g -c $(DEFINES)


# INCPATH = -I.
INCPATH = .  

LDFLAGS = $(SYSLDFLAGS) $(MYLDFLAGS)

# LIBS = -l$(SYSLIBS) $(MYLIBS)

RM = rm -f 

HEADERS= ia_lexer.h 

OBJECTS =  keyhandler.o  funcs.o  ia_lexer.o

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

ia_lexer: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

keyhandler.o: $(HEADERS)
funcs.o: $(HEADERS)
ia_lexer.o: $(HEADERS)


.PHONY: clean
clean:
	rm *.o 



