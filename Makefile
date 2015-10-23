# Tex settings
C_COMPILER   = gcc
C_OPTIONS    = -ggdb -Wall -std=c99 -g 

# Clean settings
GEN_EXTENSIONS = *.o *.out *.ghc

# SCM
VC_PROGRAM = hg

# Remember: $< expands to dependent file
#           $@ expands to target file

all: labb4.c file.c input.c output.c labb4.h
	$(C_COMPILER) $(C_OPTIONS) labb4.c file.c input.c output.c -o labb4.out -lm

clean:
	rm *.o *.out *.gch


file: file.c labb4.h
	$(C_COMPILER) $(C_OPTIONS) -c file.c -lm
	
input: input.c labb4.h
	$(C_COMPILER) $(C_OPTIONS) -c input.c -lm
	
output: output.c labb4.h
	$(C_COMPILER) $(C_OPTIONS) -c output.c -lm
