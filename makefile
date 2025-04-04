# set up our compiler settings
# we will be compiling using gcc
CC     = gcc
# setting some useful flags:
# std=c99 is the standard which you should be using
# -Wall means 'report all warnings' which is useful to help you write better code
# -Werror means 'make all warnings into errors' which means your code doesn't compile with warnings
# this is a good idea when code quality is important
# -g enables the use of GDB
CFLAGS = -std=c99 -Wall -Werror -g
# this is your list of executables which you want to compile with all
EXE    = ebfEcho ebfComp ebuEcho ebuComp ebcEcho ebcComp ebf2ebu ebu2ebf ebu2ebc ebc2ebu

# we put 'all' as the first command as this will be run if you just enter 'make'
all: ${EXE}

# clean removes all object files - DO NOT UNDER ANY CIRCUMSTANCES ADD .c OR .h FILES
# rm is NOT REVERSIBLE.
clean: 
	rm -rf *.o ${EXE}

# this is a rule to define how .o files will be compiled
# it means we do not have to write a rule for each .o file
# ebfEcho.o will be compiled by this rule as:
# ebfEcho.o: ebfEcho.c
# gcc -c -std=c99 -g ebfEcho.c -o ebfEcho.o

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# for each executable, you need to tell the makefile the 'recipe' for your file
# at the moment, this is very simple as we are only using one .c file
# but as you refactor and add more .c and .h files
# these recipes will become more complex.

ebfEcho: ebfEcho.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@

ebfComp: ebfComp.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@

ebuEcho: ebuEcho.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@

ebuComp: ebuComp.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@

ebcEcho: ebcEcho.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@

ebcComp: ebcComp.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@

ebf2ebu: ebf2ebu.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@

ebu2ebf: ebu2ebf.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@

ebu2ebc: ebf2ebu.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@

ebc2ebu: ebu2ebf.o 2DArray.o comparingFunctions.o convertingFunctions.o initiateStructData.o readingFunctions.o writingFunctions.o echoMain.o compMain.o convertingMain.o 2DArray.h comparingFunctions.h convertingFunctions.h initiateStructData.h readingFunctions.h writingFunctions.h returnCodes.h dataStructures.h echoMain.h compMain.h convertingMain.h
	$(CC) $(CCFLAGS) $^ -o $@