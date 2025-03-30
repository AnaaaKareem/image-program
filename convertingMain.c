#include <stdio.h>
#include <stdlib.h>

#include "2DArray.h"
#include "returnCodes.h"
#include "dataStructures.h"
#include "readingFunctions.h"
#include "writingFunctions.h"
#include "comparingFunctions.h"
#include "convertingFunctions.h"


int convertNumbers2Uncompressed(int argc, char* argv1, char* argv2)
    {
        // allocate the ebStructre and call initializer functions
        ebData *data = malloc(sizeof(ebData));
        ebData *ebInit(FILE *file);
    
        // Check if files are entered
        if (argc == 1)
        { // output the usage of the commands
            printf("Usage: ebf2ebu file1 file2\n");
            return 0;
        } // output the usage of the commands
    
        // validate that user has enter 2 arguments (plus the executable name)
        if (argc != 3)
        { // check arg count
            printf("ERROR: Bad Arguments\n");
            return BAD_ARGS;
        } // check arg count
    
        // open the input file in read mode
        data->inputFile = fopen(argv1, "r");

        // create a variable to store the condition of the checkFile function
        int fileChecker = checkFile(data->inputFile, argv1);
        if (fileChecker != 0)
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // Take file and initialize structure variables
        data = ebInit(data->inputFile);
    
        // create a variable to store the condition of the checkMagicNumberEB function
        int magicNumberChecker = checkMagicNumberEB(data, argv1);
        if (magicNumberChecker != 0)
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error
    
        // create a variable to store the condition of the checkDimensions function
        int dimensionChecker = checkDimensions(data, argv1);
        if (dimensionChecker != 0)
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error
    
        // allocate image data 2D array
        data->charImageData = (unsigned char **)makeChar2DArray(data->height, data->width);
    
        // create a variable to store the condition of the checkBinaryMalloc function
        int mallocChecker = checkBinaryMalloc(data);
        if (mallocChecker != 0)
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error
    
        // create a variable to store the condition of the readNumbers function
        int readChecker = readNumbers(data, argv1);
        if (readChecker != 0)
        { // if binaryChecker != 0 output error
            return BAD_DATA;
        } // if binaryChecker != 0 output error
    
        // now we have finished using the inputFile we should close it
        fclose(data->inputFile);
    
        // open the output file in write mode
        data->outputFile = fopen(argv2, "w");

        // assign variable to restore the condition of the checkFile function with a different file
        fileChecker = checkFile(data->outputFile, argv2);
        if (fileChecker != 0)
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error

        // assign variable to restore the condition of the headerWrite function 
        int headerWrite = headerConverter(data, argv2, 'b');
        if (headerWrite != 0)
        { // if writeHeaderChecker != 0 output error
            return BAD_OUTPUT;
        } // if writeHeaderChecker != 0 output error

        // assign variable to restore the condition of the binaryWrite function
        int binaryWrite = writeUncompressed(data, argv2);
        if (binaryWrite != 0)
        { // if printChecker != 0 output error
            return BAD_OUTPUT;
        } // if printChecker != 0 output error

        // free allocated memory before exit
        free(data->charImageData);
        // close the output file before exit
        fclose(data->outputFile);

        // print final success message and return
        printf("CONVERTED\n");
        return SUCCESS;
    }

int convertUncompressed2Numbers(int argc, char* argv1, char* argv2)
    {
        // allocate the ebStructre and call initializer functions
        ebData *data = malloc(sizeof(ebData));
        ebData *ebInit(FILE *file);
    
        // Check if files are entered
        if (argc == 1)
        { // output the usage of the commands
            printf("Usage: ebu2ebf file1 file2\n");
            return 0;
        } // output the usage of the commands

        // validate that user has enter 2 arguments (plus the executable name)
        if (argc != 3)
        { // check arg count
            printf("ERROR: Bad Arguments\n");
            return BAD_ARGS;
        } // check arg count
    
        // open the input file in read mode
        data->inputFile = fopen(argv1, "r");

        // create a variable to store the condition of the checkFile function
        int fileChecker = checkFile(data->inputFile, argv1);
        if (fileChecker != 0)
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // Take file and initialize structure variables
        data = ebInit(data->inputFile);
    
        // create a variable to store the condition of the checkMagicNumberEU function
        int magicNumberChecker = checkMagicNumberEU(data, argv1);
        if (magicNumberChecker != 0)
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error
    
        fseek(data->inputFile, 1, SEEK_CUR);
    
        // create a variable to store the condition of the checkDimensions function
        int dimensionChecker = checkDimensions(data, argv1);
        if (dimensionChecker != 0)
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error
    
        fseek(data->inputFile, 1, SEEK_CUR);
    
        // allocate image data 2D array
        data->charImageData = (unsigned char **)makeChar2DArray(data->height, data->width);
    
        // create a variable to store the condition of the checkBinaryMalloc function
        int mallocChecker = checkBinaryMalloc(data);
        if (mallocChecker != 0)
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error
    
        // create a variable to store the condition of the readUncompressed function
        int binaryChecker = readUncompressed(data, argv1);
        if (binaryChecker != 0)
        { // if binaryChecker != 0 output error
            return BAD_DATA;
        } // if binaryChecker != 0 output error
    
        // now we have finished using the inputFile we should close it
        fclose(data->inputFile);
    
        // open the output file in write mode
        data->outputFile = fopen(argv2, "w");

        // assign variable to restore the condition of the checkFile function with a different file
        fileChecker = checkFile(data->outputFile, argv2);
        if (fileChecker != 0)
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // assign variable to restore the condition of the headerConverter function 
        int headerWrite = headerConverter(data, argv2, 'b');
        if (headerWrite != 0)
        { // if writeHeaderChecker != 0 output error
            return BAD_OUTPUT;
        } // if writeHeaderChecker != 0 output error
    
        // assign variable to restore the condition of the writeNumbers function
        int printChecker = writeNumbers(data, argv2);
        if (printChecker != 0)
        { // if printChecker != 0 output error
            return BAD_OUTPUT;
        } // if printChecker != 0 output error
    
        // free allocated memory before exit
        free(data->charImageData);
        // close the output file before exit
        fclose(data->outputFile);
    
        // print final success message and return
        printf("CONVERTED\n");
        return SUCCESS;
    }

int convertUncompressed2Compressed(int argc, char* argv1, char* argv2) 
    {
        // allocate the ebStructre and call initializer functions
        ebData *data = malloc(sizeof(ebData));
        ebData *ebInit(FILE *file);
    
        // Check if files are entered
        if (argc == 1) 
        { // output the usage of the commands
            printf("Usage: ebu2ebc file1 file2\n");
            return 0;
        } // output the usage of the commands
        
        // validate that user has enter 2 arguments (plus the executable name)
        if (argc != 3) 
        { // check arg count
            printf("ERROR: Bad Arguments\n");
            return BAD_ARGS;
        } // check arg count
    
        // open the input file in read mode
        data->inputFile = fopen(argv1, "r");

        // create a variable to store the condition of the checkFile function
        int fileChecker = checkFile(data->inputFile, argv1);
        if (fileChecker != 0) 
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // Take file and initialize structure variables
        data = ebInit(data->inputFile);
    
        // create a variable to store the condition of the checkMagicNumberEU function
        int magicNumberChecker = checkMagicNumberEU(data, argv1);
        if (magicNumberChecker != 0) 
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error
    
        fseek(data->inputFile, 1, SEEK_CUR);
    
        // create a variable to store the condition of the checkDimensions function
        int dimensionChecker = checkDimensions(data, argv1);
        if (dimensionChecker != 0) 
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error
    
        fseek(data->inputFile, 1, SEEK_CUR);
    
        // allocate image data 2D array
        data->charImageData = (unsigned char **)makeChar2DArray(data->height, data->width);
    
        // create a variable to store the condition of the checkBinaryMalloc function
        int mallocChecker = checkBinaryMalloc(data);
        if (mallocChecker != 0) 
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error
    
        // create a variable to store the condition of the readUncompressed function
        int binaryChecker = readUncompressed(data, argv1);
        if (binaryChecker != 0) 
        { // if binaryChecker != 0 output error
            return BAD_DATA;
        } // if binaryChecker != 0 output error
    
        // now we have finished using the inputFile we should close it
        fclose(data->inputFile);
    
        // open the output file in write mode
        data->outputFile = fopen(argv2, "w");

        // assign variable to restore the condition of the checkFile function with a different file
        fileChecker = checkFile(data->outputFile, argv2);
        if (fileChecker != 0) 
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // assign variable to restore the condition of the headerConverter function 
        int headerWrite = headerConverter(data, argv2, 'b');
        if (headerWrite != 0) 
        { // if writeHeaderChecker != 0 output error
            return BAD_OUTPUT;
        } // if writeHeaderChecker != 0 output error
    
        // assign variable to restore the condition of the writeCompressed function
        int printChecker = writeCompressed(data, argv2);
        if (printChecker != 0) 
        { // if printChecker != 0 output error
            return BAD_OUTPUT;
        } // if printChecker != 0 output error
    
        // free allocated memory before exit
        free(data->charImageData);
        // close the output file before exit
        fclose(data->outputFile);
    
        // print final success message and return
        printf("CONVERTED\n");
        return SUCCESS;
    }
int convertCompressed2Uncompressed(int argc, char* argv1, char* argv2)
    {
        // allocate the ebStructre and call initializer functions
        ebData *data = malloc(sizeof(ebData));
        ebData *ebInit(FILE *file);

        // Check if files are entered
        if (argc == 1)
        { // output the usage of the commands
            printf("Usage: ebc2ebu file1 file2\n");
            return 0;
        } // output the usage of the commands

        // validate that user has enter 2 arguments (plus the executable name)
        if (argc != 3)
        { // check arg count
            printf("ERROR: Bad Arguments\n");
            return BAD_ARGS;
        } // check arg count

        // open the input file in read mode
        data->inputFile = fopen(argv1, "r");

        // create a variable to store the condition of the checkFile function
        int fileChecker = checkFile(data->inputFile, argv1);
        if (fileChecker != 0)
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error

        // Take file and initialize structure variables
        data = ebInit(data->inputFile);

        // create a variable to store the condition of the checkMagicNumberEC function
        int magicNumberChecker = checkMagicNumberEC(data, argv1);
        if (magicNumberChecker != 0)
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error

        // create a variable to store the condition of the checkDimensions function
        int dimensionChecker = checkDimensions(data, argv1);
        if (dimensionChecker != 0)
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error

        // allocate image data 2D array
        data->charImageData = (unsigned char **)makeChar2DArray(data->height, data->width);

        // create a variable to store the condition of the checkBinaryMalloc function
        int mallocChecker = checkBinaryMalloc(data);
        if (mallocChecker != 0)
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error

        // create a variable to store the condition of the readCompressed function
        int readChecker = readCompressed(data, argv1);
        if (readChecker != 0)
        { // if binaryChecker != 0 output error
            return BAD_DATA;
        } // if binaryChecker != 0 output error

        // now we have finished using the inputFile we should close it
        fclose(data->inputFile);

        // open the output file in write mode
        data->outputFile = fopen(argv2, "w");

        // assign variable to restore the condition of the checkFile function with a different file
        fileChecker = checkFile(data->outputFile, argv2);
        if (fileChecker != 0)
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error

        // assign variable to restore the condition of the headerConverter function 
        int headerWrite = headerConverter(data, argv2, 'b');
        if (headerWrite != 0)
        { // if writeHeaderChecker != 0 output error
            return BAD_OUTPUT;
        } // if writeHeaderChecker != 0 output error

        // assign variable to restore the condition of the writeUncompressed function
        int binaryWrite = writeUncompressed(data, argv2);
        if (binaryWrite != 0)
        { // if printChecker != 0 output error
            return BAD_OUTPUT;
        } // if printChecker != 0 output error

        // free allocated memory before exit
        free(data->charImageData);
        // close the output file before exit
        fclose(data->outputFile);

        // print final success message and return
        printf("CONVERTED\n");
        return SUCCESS;
    }