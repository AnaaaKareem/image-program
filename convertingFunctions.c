#include <stdio.h>
#include <stdlib.h>

#include "dataStructures.h"

int headerConverter(ebData *data, char* argv, char code) 
    { // write magic number and dimensions
        // write the header data in one block
        int check = fprintf(data->outputFile, "e%c\n%d %d\n", code, data->height, data->width);
        // and use the return from fprintf to check that we wrote.
            if (check == 0) 
            { // check write
                fclose(data->outputFile);
                free(data->charImageData);
                printf("ERROR: Bad Output (%s)\n", argv);
                return 1; // return 1 if unsuccessful
            } // check write
        return 0; // return 0 if successful
    } // write magic number and dimensions

int readNumbers(ebData *data, char* argv) 
    { // read pixel numbers
        // read in each grey value from the file
        for (int currentRow = 0; currentRow < data->height; currentRow++) 
            { // Loop over rows
                for (int currentCol = 0; currentCol < data->width; currentCol++) 
                    { // Loop over columns
                        int check = fscanf(data->inputFile, "%hhi", &data->charImageData[currentRow][currentCol]);
                        unsigned int tmp = (unsigned int) data->charImageData[currentRow][currentCol];
                        // validate that we have captured 1 pixel value
                        if (check != 1 || tmp > 31 || tmp < 0) 
                        { // check write
                            // ensure that allocated data is freed before exit.
                            free(data->charImageData);
                            fclose(data->inputFile);
                            printf("ERROR: Bad Data (%s)\n", argv);
                            return 1; // return 1 if unsuccessful
                        } // check write
                    } // Loop over columns
            } // Loop over rows
        return 0; // return 0 if successful
    } // read pixel numbers

int readUncompressed(ebData *data, char* argv)
    { // read binary data numbers
        // read in each grey value from the file
        for (int currentRow = 0; currentRow < data->height; currentRow++)
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++) 
            { // Loop over columns
                size_t byteReader = fread(&data->charImageData[currentRow][currentCol], sizeof(unsigned char), 1, data->inputFile);
                // validate that we have captured 1 pixel value
                if (byteReader != 1 || data->charImageData[currentRow][currentCol] > 31) 
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
    } // read binary data numbers

int readCompressed(ebData *data, char* argv) 
    { // read compressed binary data numbers
        // read in each grey value from the file
        for (int currentRow = 0; currentRow < data->height; currentRow++) 
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++) 
            { // Loop over columns
                size_t byteReader = fread(&data->charImageData[currentRow][currentCol], sizeof(unsigned char), 1, data->inputFile);
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
    } // read compressed binary data numbers

int writeNumbers(ebData *data, char* argv) 
    { // write pixel numbers
        // iterate though the array and print out pixel values
        for (int currentRow = 0; currentRow < data->height; currentRow++) 
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++) 
            { // Loop over columns
                // if we are at the end of a row ((current+1)%width == 0) then write a newline, otherwise a space.
                int check = fprintf(data->outputFile, "%u%c", (unsigned int)data->charImageData[currentRow][currentCol], ((currentCol + 1) % data->width) ? ' ' : '\n');
                if (check == 0) { // check write
                    fclose(data->outputFile);
                    free(data->charImageData);
                    printf("ERROR: Bad Output (%s)\n", argv);
                    return 1; // return 1 if unsuccessful
                } // check write
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if successful
    } // write pixel numbers

int writeUncompressed(ebData *data, char* argv) 
    { // write binary data numbers
        // iterate through the array and write out pixel values
        for (int currentRow = 0; currentRow < data->height; currentRow++) 
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++) 
            { // Loop over columns
                size_t byteWritter = fwrite(&data->charImageData[currentRow][currentCol], sizeof(unsigned char), 1, data->outputFile);
                if (byteWritter == 0) 
                { // check write
                    fclose(data->outputFile);
                    free(data->charImageData);
                    printf("ERROR: Bad Output (%s)\n", argv);
                    return 1; // return 1 if unsuccessful
                } // check write
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if successful
    } // write binary data numbers

int writeCompressed(ebData *data, char* argv) 
    { // read compressed binary data numbers
        // iterate through the array and write out pixel values
        for (int currentRow = 0; currentRow < data->height; currentRow++) 
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++) 
            { // Loop over columns
                size_t byteWritter = fwrite(&data->charImageData[currentRow][currentCol], sizeof(unsigned char), 1, data->outputFile);
                if (byteWritter == 0) 
                { // check write
                    fclose(data->outputFile);
                    free(data->charImageData);
                    printf("ERROR: Bad Output (%s)\n", argv);
                    return 1; // return 1 if unsuccessful
                } // check write
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if successful
    } // read compressed binary data numbers