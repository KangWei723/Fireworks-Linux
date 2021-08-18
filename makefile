#
# Neil Kirby: example makefile for lab2 SP21.  Shows using libfire.
#

all:  tags headers p_CompileLink p_SimpleFW p_fwclear p_fwDotStar p_inputFiles p_bitShift lab2 posVelTime bitShifting output

headers: *.c tags
	headers.sh

tags: *.c
	ctags -R .

# Prototype for lab 2
# Prototype for testing to successful link and compile.
p_CompileLink: p_CompileLink.o
	gcc -g -o $@ $^ -lncurses -L. -lfire

# Prototype for testing the fw_initialize, fw_refresh, getchar and fw_teardown.
p_SimpleFW: p_SimpleFW.o
	gcc -g -o $@ $^ -lncurses -L. -lfire

# Prototype for testing the fw_clear.
p_fwclear: p_fwclear.o
	gcc -g -o $@ $^ -lncurses -L. -lfire

#prototype for testing the fw_dot and fw_star.
p_fwDotStar: p_fwDotStar.o
	gcc -g -o $@ $^ -lncurses -L. -lfire

# Prototype for testing to read the input files. 
p_inputFiles: p_inputFiles.o
	gcc -g -o $@ $^ -lncurses -L. -lfire

# Prorortpr for testing the bit shifting and masking. 
p_bitShift: p_bitShift.o
	gcc -g -o $@ $^ -lncurses -L. -lfire


# These are all the files that generate the graphics mode and text mode of the firework.
# This file contains the main function and all the highest level function goes here. 
lab2: lab2.o posVelTime.o bitShifting.o output.o
	gcc -g -o $@ $^ -lncurses -L. -lfire

# This file is used to calculate the dt, position and velocity. It also helps to convert from second to millisecond. 
posVelTime: posVelTime.o
	gcc -g -o $@ $^ -lncurses -L. -lfire

# This file contains all the function that helps to convert the hex value to binary and decimal value.
bitShifting: bitShifting.o
	gcc -g -o $a $^

# This file is used to draw the fireworks and print the text mode of the fireworks.
output: output.o posVelTime.o bitShifting.o
	gcc -g -o $a $^ -lncurses -L. -lfire


# This will zip all the header file, c file and README_LAB2 file in a zip folder.
lab2.zip: makefile *.c *.h README_LAB2
	zip lab2.zip makefile *.c *.h README_LAB2


# this is our master compiler rule to generate .o files.
# It needs all 4 warnings

%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@


