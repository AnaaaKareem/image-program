#include <stdio.h>
#include <stdlib.h>

#include "2DArray.h"
#include "returnCodes.h"
#include "dataStructures.h"
#include "readingFunctions.h"
#include "writingFunctions.h"
#include "comparingFunctions.h"


int compareImageNumbers(int argc, char* argv1, char* argv2) 
    { // compare image
        // allocate the ebStructre and call initializer functions
        ebData *data1 = malloc(sizeof(ebData));
        ebData *data2 = malloc(sizeof(ebData));
        ebData *ebInit(FILE *file);
    
        // Check if files are entered
        if (argc == 1) 
        { // output the usage of the commands
            printf("Usage: ebfComp file1 file2\n");
            return 0;
        } // output the usage of the commands
    
        // validate that user has enter 2 arguments (plus the executable name)
        if (argc != 3)
        { // check arg count
            printf("ERROR: Bad Arguments\n");
            return BAD_ARGS;
        } // check arg count
    
        // open the input file in read mode
        data1->inputFile = fopen(argv1, "r");

        // create a variable to store the condition of the checkFile function
        int fileChecker = checkFile(data1->inputFile, argv1);
        if (fileChecker != 0) 
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // Take file and initialize structure variables for the first file
        data1 = ebInit(data1->inputFile);
    
        // create a variable to store the condition of the checkMagicNumberEB function
        int magicNumberChecker = checkMagicNumberEB(data1, argv1);
        if (magicNumberChecker != 0) 
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error
    
        // create a variable to store the condition of the checkDimensions function
        int dimensionChecker = checkDimensions(data1, argv1);
        if (dimensionChecker != 0) 
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error
    
        // allocate image data 2D array for the first file
        data1->decimalImageData = (unsigned int **)makeInt2DArray(data1->height, data1->width);
    
        // create a variable to store the condition of the checkDecimalMalloc function
        int mallocChecker = checkDecimalMalloc(data1);
        if (mallocChecker != 0) 
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error
    
        // create a variable to store the condition of the checkDecimalValues function
        int pixelChecker = checkDecimalValues(data1, argv1, data1->inputFile);
        if (pixelChecker != 0) 
        { // if pixelChecker != 0 output error
            return BAD_DATA;
        } // if pixelChecker != 0 output error
    
        // now we have finished using the data1->inputFile we should close it
        fclose(data1->inputFile);
    
        // open the input file in read mode
        data2->inputFile = fopen(argv2, "r");
    
        // create a variable to store the condition of the checkFile function
        fileChecker = checkFile(data2->inputFile, argv2);
        if (fileChecker != 0) 
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // Take file and initialize structure variables for the second file
        data2 = ebInit(data2->inputFile);
    
        // create a variable to store the condition of the checkMagicNumberEB function
        magicNumberChecker = checkMagicNumberEB(data2, argv2);
        if (magicNumberChecker != 0) 
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error
    
        // create a variable to store the condition of the checkDimensions function
        dimensionChecker = checkDimensions(data2, argv2);
        if (dimensionChecker != 0) 
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error
    
        // caclulate total size and allocate memory for array
        data2->decimalImageData = (unsigned int **)makeInt2DArray(data2->height, data2->width);
    
        // create a variable to store the condition of the checkDecimalMalloc function
        mallocChecker = checkDecimalMalloc(data2);
        if (mallocChecker != 0) 
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error
    
        // create a variable to store the condition of the checkDecimalValues function
        pixelChecker = checkDecimalValues(data2, argv2, data2->inputFile);
        if (pixelChecker != 0) 
        { // if pixelChecker != 0 output error
            return BAD_DATA;
        } // if pixelChecker != 0 output error
    
        // now we have finished using the data2->inputFile we should close it
        fclose(data2->inputFile);
    
        // compare the data from the two files:
        int equalFiles = comparePixels(data1, data2);
        if (equalFiles == 0 || equalFiles != 0) 
        { // free memory after comparison
            // free allocated memory before exit
            free(data1->decimalImageData);
            free(data2->decimalImageData);
        }
        return SUCCESS;
    } // compare image

int compareImageBinary(int argc, char* argv1, char* argv2) 
    {
        // allocate the ebStructre and call initializer functions
        ebData *data1 = malloc(sizeof(ebData));
        ebData *data2 = malloc(sizeof(ebData));
        ebData *ebInit(FILE *file);
    
        // Check if files are entered
        if (argc == 1) 
        { // output the usage of the commands
            printf("Usage: ebuComp file1 file2\n");
            return 0;
        } // output the usage of the commands
    
        // validate that user has enter 2 arguments (plus the executable name)
        if (argc != 3)
        { // check arg count
            printf("ERROR: Bad Arguments\n");
            return BAD_ARGS;
        } // check arg count
    
        // open the input file in read mode
        data1->inputFile = fopen(argv1, "r");

        // create a variable to store the condition of the checkFile function
        int fileChecker = checkFile(data1->inputFile, argv1);
        if (fileChecker != 0) 
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // Take file and initialize structure variables for the first file
        data1 = ebInit(data1->inputFile);
    
        // create a variable to store the condition of the checkMagicNumberEU function
        int magicNumberChecker = checkMagicNumberEU(data1, argv1);
        if (magicNumberChecker != 0) 
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error
    
        // create a variable to store the condition of the checkDimensions function
        int dimensionChecker = checkDimensions(data1, argv1);
        if (dimensionChecker != 0) 
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error
    
        // allocate image data 2D array for the first file
        data1->charImageData = (unsigned char **)makeChar2DArray(data1->height, data1->width);
    
        // create a variable to store the condition of the checkBinaryMalloc function
        int mallocChecker = checkBinaryMalloc(data1);
        if (mallocChecker != 0) 
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error
    
        // create a variable to store the condition of the checkBinaryMalloc function
        int binaryChecker = checkBinaryValues(data1, argv1, data1->inputFile);
        if (binaryChecker != 0) 
        { // if binaryChecker != 0 output error
            return BAD_DATA;
        } // if binaryChecker != 0 output error
    
        // now we have finished using the data1->inputFile we should close it
        fclose(data1->inputFile);
    
        // open the input file in read mode
        data2->inputFile = fopen(argv2, "r");
    
        // create a variable to store the condition of the checkFile function
        fileChecker = checkFile(data2->inputFile, argv2);
        if (fileChecker != 0) 
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // Take file and initialize structure variables for the second file
        data2 = ebInit(data2->inputFile);
    
        // create a variable to store the condition of the checkMagicNumberEB function
        magicNumberChecker = checkMagicNumberEU(data2, argv2);
        if (magicNumberChecker != 0) 
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error
    
        // create a variable to store the condition of the checkDimensions function
        dimensionChecker = checkDimensions(data2, argv2);
        if (dimensionChecker != 0) 
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error
    
        // caclulate total size and allocate memory for array
        data2->charImageData = (unsigned char **)makeChar2DArray(data2->height, data2->width);
    
        // create a variable to store the condition of the checkBinaryMalloc function
        mallocChecker = checkBinaryMalloc(data2);
        if (mallocChecker != 0) 
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error
    
        // create a variable to store the condition of the checkBinaryValues function
        binaryChecker = checkBinaryValues(data2, argv2, data2->inputFile);
        if (binaryChecker != 0) 
        { // if binaryChecker != 0 output error
            return BAD_DATA;
        } // if binaryChecker != 0 output error
    
        // now we have finished using the data2->inputFile we should close it
        fclose(data2->inputFile);
    
        // compare the data from the two files:
        int equalFiles = compareBinary(data1, data2);
        if (equalFiles == 0 || equalFiles != 0) 
        { // free memory after comparison
            // free allocated memory before exit
            free(data1->charImageData);
            free(data2->charImageData);
        }
        return SUCCESS;
    }

int compareImageCompressed(int argc, char* argv1, char* argv2)
    {
        // allocate the ebStructre and call initializer functions
        ebData *data1 = malloc(sizeof(ebData));
        ebData *data2 = malloc(sizeof(ebData));
        ebData *ebInit(FILE *file);
    
        // Check if files are entered
        if (argc == 1) 
        { // output the usage of the commands
            printf("Usage: ebcComp file1 file2\n");
            return 0;
        } // output the usage of the commands
    
        // validate that user has enter 2 arguments (plus the executable name)
        if (argc != 3)
        { // check arg count
            printf("ERROR: Bad Arguments\n");
            return BAD_ARGS;
        } // check arg count
    
        // open the input file in read mode
        data1->inputFile = fopen(argv1, "r");

        // create a variable to store the condition of the checkFile function
        int fileChecker = checkFile(data1->inputFile, argv1);
        if (fileChecker != 0) 
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // Take file and initialize structure variables for the first file
        data1 = ebInit(data1->inputFile);
    
        // create a variable to store the condition of the checkMagicNumberEC function
        int magicNumberChecker = checkMagicNumberEC(data1, argv1);
        if (magicNumberChecker != 0) 
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error
    
        // create a variable to store the condition of the checkDimensions function
        int dimensionChecker = checkDimensions(data1, argv1);
        if (dimensionChecker != 0) 
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error
    
        // allocate image data 2D array for the first file
        data1->charImageData = (unsigned char **)makeChar2DArray(data1->height, data1->width);
    
        // create a variable to store the condition of the checkBinaryMalloc function
        int mallocChecker = checkBinaryMalloc(data1);
        if (mallocChecker != 0) 
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error
    
        // create a variable to store the condition of the checkCompressedValues function
        int binaryChecker = checkCompressedValues(data1, argv1, data1->inputFile);
        if (binaryChecker != 0) 
        { // if binaryChecker != 0 output error
            return BAD_DATA;
        } // if binaryChecker != 0 output error
    
        // now we have finished using the data1->inputFile we should close it
        fclose(data1->inputFile);
    
        // open the input file in read mode
        data2->inputFile = fopen(argv2, "r");
    
        // create a variable to store the condition of the checkFile function
        fileChecker = checkFile(data2->inputFile, argv2);
        if (fileChecker != 0) 
        { // if fileChecker != 0 output error
            return BAD_FILE;
        } // if fileChecker != 0 output error
    
        // Take file and initialize structure variables for the second file
        data2 = ebInit(data2->inputFile);
    
        // create a variable to store the condition of the checkMagicNumberEC function
        magicNumberChecker = checkMagicNumberEC(data2, argv2);
        if (magicNumberChecker != 0) 
        { // if magicNumberChecker != 0 output error
            return BAD_MAGIC_NUMBER;
        } // if magicNumberChecker != 0 output error
    
        // create a variable to store the condition of the checkDimensions function
        dimensionChecker = checkDimensions(data2, argv2);
        if (dimensionChecker != 0) 
        { // if dimensionsChecker != 0 output error
            return BAD_DIM;
        } // if dimensionsChecker != 0 output error
    
        // caclulate total size and allocate memory for array
        data2->charImageData = (unsigned char **)makeChar2DArray(data2->height, data2->width);
    
        // create a variable to store the condition of the checkBinaryMalloc function
        mallocChecker = checkBinaryMalloc(data2);
        if (mallocChecker != 0) 
        { // if mallocChecker != 0 output error
            return BAD_MALLOC;
        } // if mallocChecker != 0 output error
    
        // create a variable to store the condition of the checkCompressedValues function
        binaryChecker = checkCompressedValues(data2, argv2, data2->inputFile);
        if (binaryChecker != 0) 
        { // if binaryChecker != 0 output error
            return BAD_DATA;
        } // if binaryChecker != 0 output error
    
        // now we have finished using the data2->inputFile we should close it
        fclose(data2->inputFile);
    
        // compare the data from the two files:
        int equalFiles = compareCompressed(data1, data2);
        if (equalFiles == 0 || equalFiles != 0) 
        { // free memory after comparison
            // free allocated memory before exit
            free(data1->charImageData);
            free(data2->charImageData);
        }
        return SUCCESS;
    }