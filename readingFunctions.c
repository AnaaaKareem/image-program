#include <stdio.h>
#include <stdlib.h>

#include "dataStructures.h" // to access the ebData structure
#include "returnCodes.h"

int checkFile(FILE *file, char* argv)
    { // check file
        if (file == NULL)
        {
            printf("ERROR: Bad File Name (%s)\n", argv);
            return 1; // return 1 if unsuccessful
        } // check file
        return 0; // return 0 if successful
    }

int checkMagicNumberEB(ebData *data, char* argv)
    { // check magic number for numbers
        // checking against the casted value due to endienness.
        if (*data->magicNumberValue != MAGIC_NUMBER_EBF)
        { // check magic number ebf
            printf("ERROR: Bad Magic Number (%s)\n", argv);
            return 1; // return 1 if unsuccessful
        } // check magic number ebf
        return 0; // return 0 if successful
    } // check magic number for numbers

int checkMagicNumberEU(ebData *data, char* argv)
    { // check magic number for binary
        // checking against the casted value due to endienness.
        if (*data->magicNumberValue != MAGIC_NUMBER_EBU)
        { // check magic number ebu
            printf("ERROR: Bad Magic Number (%s)\n", argv);
            return 1; // return 1 if unsuccessful
        } // check magic number ebu
        return 0; // return 0 if successful
    } // check magic number for binary

int checkMagicNumberEC(ebData *data, char* argv)
    { // check magic number for compressed
        // checking against the casted value due to endienness.
        if (*data->magicNumberValue != MAGIC_NUMBER_EBC)
        { // check magic number ebc
            printf("ERROR: Bad Magic Number (%s)\n", argv);
            return 1; // return 1 if unsuccessful
        } // check magic number ebc
        return 0; // return 0 if successful
    } // check magic number for compressed

int checkDimensions(ebData *data, char* argv)
    { // check dimensions
        // scan for the dimensions
        // and capture fscanfs return to ensure we got 2 values.
        int check = fscanf(data->inputFile, "%d %d", &data->height, &data->width);
        if (check != 2 || data->height < MIN_DIMENSION || data->width < MIN_DIMENSION || data->height > MAX_DIMENSION || data->width > MAX_DIMENSION)
        { // check dimensions
            // close the file as soon as an error is found
            fclose(data->inputFile);
            // print appropriate error message and return
            printf("ERROR: Bad Dimensions (%s)\n", argv);
            return 1; // return 1 if successful
        } // check dimensions
        return 0; // return 0 if successful
    } // check dimensions

int checkDecimalMalloc(ebData *data)
    { // check if 2D array for integers has been allocated or not
        // if malloc is unsuccessful, it will return a null pointer
        if (data->decimalImageData == NULL)
        { // check malloc
            fclose(data->inputFile);
            printf("ERROR: Image Malloc Failed\n");
            return 1; // return 1 if unsuccessful
        } // check malloc
        return 0; // return 0 if successful
    } // check if 2D array for integers has been allocated or not

int checkBinaryMalloc(ebData *data)
    { // check if 2D array for characters has been allocated or not
        // if malloc is unsuccessful, it will return a null pointer
        if (data->charImageData == NULL)
        { // check malloc
            fclose(data->inputFile);
            printf("ERROR: Image Malloc Failed\n");
            return 1; // return 1 if unsuccessful
        } // check malloc
        return 0; // return 0 if successful
    } // check if 2D array for characters has been allocated or not

int checkDecimalValues(ebData *data, char* argv, FILE *file)
    { // check if the pixels exists and if they are in range
        // read in each grey value from the file
        for (int currentRow = 0; currentRow < data->height; currentRow++)
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++)
            { // Loop over columns
                int check = fscanf(data->inputFile, "%u", &data->decimalImageData[currentRow][currentCol]);
                // validate that we have captured 1 pixel value
                if (check != 1 || data->decimalImageData[currentRow][currentCol] > 31 || data->decimalImageData[currentRow][currentCol] < 0)
                { // check inputted data
                    // ensure that allocated data is freed before exit.
                    free(data->decimalImageData);
                    fclose(file);
                    printf("ERROR: Bad Data (%s)\n", argv);
                    return 1; // return 1 if unsuccessful
                } // check inputted data
            } // Loop over columns
        } // Loop over rows
        unsigned int tooMuchChecker;
        // check if there is any data beyond the specified width and height
        if (fscanf(file, "%u", &tooMuchChecker) != EOF)
        { // check if there is any pixels beyond the dimensions specified
            free(data->decimalImageData);
            fclose(file);
            printf("ERROR: Bad Data (%s)\n", argv);
            return 1; // return 1 if unsuccessful
        } // check if there is any pixels beyond the dimensions specified
        else if (fscanf(file, "%u", &tooMuchChecker) == '\n')
        { // check if there is a new line at the end of the file and raise a flag
            data->EOFChecker = 1;
        } // check if there is a new line at the end of the file and raise a flag
        return 0; // return 0 if successful
    } // check if the pixels exists and if they are in range

int checkBinaryValues(ebData *data, char* argv, FILE *file)
    { // check if the binary data exists and if they are in range
        size_t byteReader = 0;
        // read in each grey value from the file
        for (int currentRow = 0; currentRow < data->height; currentRow++) { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++) { // Loop over columns
                byteReader = fread(&data->charImageData[currentRow][currentCol], sizeof(unsigned char), 1, data->inputFile);
                // validate that we have captured 1 pixel value
                if (byteReader != 1 || data->charImageData[currentRow][currentCol] > 31 || data->charImageData[currentRow][currentCol] < 0)
                { // check inputted data
                    // ensure that allocated data is freed before exit.
                    free(data->charImageData);
                    fclose(file);
                    printf("ERROR: Bad Data (%s)\n", argv);
                    return 1; // return 1 if unsuccessful
                } // check inputted data
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if successful
    } // check if the binary data exists and if they are in range

int checkCompressedValues(ebData *data, char* argv, FILE *file)
    { // check if the compressed binary data exists and if they are in range
        size_t byteReader = 0;
        // read in each grey value from the file
        for (int currentRow = 0; currentRow < data->height; currentRow++)
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++)
            { // Loop over columns
                byteReader = fread(&data->charImageData[currentRow][currentCol], sizeof(unsigned char), 1, data->inputFile);
                // validate that we have captured 1 pixel value
                if (byteReader != 1)
                { // check inputted data
                    // ensure that allocated data is freed before exit.
                    free(data->charImageData);
                    fclose(data->inputFile);
                    printf("ERROR: Bad Data (%s)\n", argv);
                    return 1; // return 1 if unsuccessful
                } // check inputted data
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if successful
    } // check if the compressed binary data exists and if they are in range