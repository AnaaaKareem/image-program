#include <stdio.h>
#include <stdlib.h>

#include "dataStructures.h" // to access the ebData structure
#include "returnCodes.h"

// check if the magic number and dimensions can be written into the file
int checkHeaderWrite(ebData *data, char* argv) 
    { // write magic number and dimensions
        // write the header data in one block
        int check = fprintf(data->outputFile, "e%c\n%d %d\n", data->magicNumber[1], data->height, data->width);
        if (check == 0) 
        { // check write
            // output an error if there is no permission to write to file
            fclose(data->outputFile);
            printf("ERROR: Bad Output (%s)\n", argv);
            return 1;
        } // check write
        return 0; // return 0 if successful
    } // write magic number and dimensions

// print ascii pixels to file
int printPixels(ebData *data, char* argv) 
    { // write pixel number values
        int check = 0;
        // iterate though the array and print out pixel values
        for (int currentRow = 0; currentRow < data->height; currentRow++) 
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++) 
            { // Loop over columns
                // Conditions when not reached final row and column
                if ((currentCol + 1) % data->width == 0 && currentRow + 1 != data->height) 
                { // print new line except last row
                    check = fprintf(data->outputFile, "%u\n", data->decimalImageData[currentRow][currentCol]);
                } // print new line except last row
                else if ((currentCol + 1) % data->width) 
                { // print white space after each number
                    check = fprintf(data->outputFile, "%u ", data->decimalImageData[currentRow][currentCol]);
                } // print white space after each number
                
                // Conditions when reached final row and column
                if ((currentRow + 1 == data->height) && (currentCol + 1 == data->width) && data->EOFChecker == 1) 
                { // print a new line if at the end of the file if exists
                    check = fprintf(data->outputFile, "%u\n", data->decimalImageData[currentRow][currentCol]);
                } // print a new line if at the end of the file if exists
                else if ((currentRow + 1 == data->height) && (currentCol + 1 == data->width) && data->EOFChecker != 1) 
                { // print for final pixel if there is no white spaces
                    check = fprintf(data->outputFile, "%u", data->decimalImageData[currentRow][currentCol]);
                } // print for final pixel if there is no white spaces
                
                // Condition if a pixel does not exist
                if (check == 0) 
                { // check write
                    // free memory, close file, and print an error
                    fclose(data->outputFile);
                    free(data->decimalImageData);
                    printf("ERROR: Bad Output (%s)\n", argv);
                    return 1;
                } // check write
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if successful
    } // write pixel number values

// print binary data to file
int printBinary(ebData *data, char* argv) 
    { // print binary values
        // A checker used to check if there are any binary data
        int check = 0;
        // iterate though the array and print out binary values
        for (int currentRow = 0; currentRow < data->height; currentRow++) 
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++) 
            { // Loop over columns
                // Conditions when not reached final row and column
                if ((currentCol + 1) % data->width == 0 && currentRow + 1 != data->height) 
                { // print new line except last row
                    check = fprintf(data->outputFile, "%u\n", data->charImageData[currentRow][currentCol]);
                } // print new line except last row
                else if ((currentCol + 1) % data->width) 
                { // print white space after each number
                    check = fprintf(data->outputFile, "%u ", data->charImageData[currentRow][currentCol]);
                } // print white space after each number
                
                // Conditions when reached final row and column
                if ((currentRow + 1 == data->height) && (currentCol + 1 == data->width) && data->EOFChecker == 1) 
                { // print a new line if at the end of the file if exists
                    check = fprintf(data->outputFile, "%u\n", data->charImageData[currentRow][currentCol]);
                } // print a new line if at the end of the file if exists
                else if ((currentRow + 1 == data->height) && (currentCol + 1 == data->width) && data->EOFChecker != 1) 
                { // print for final pixel if there is no white spaces
                    check = fprintf(data->outputFile, "%u", data->charImageData[currentRow][currentCol]);
                } // print for final pixel if there is no white spaces
                
                // Condition if a pixel does not exist
                if (check == 0) 
                { // check write
                    // free memory, close file, and print an error
                    fclose(data->outputFile);
                    free(data->charImageData);
                    printf("ERROR: Bad Output (%s)\n", argv);
                    return 1;
                } // check write
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if successful
    } // print binary values

// print binary after compression
int printCompressed(ebData *data, char* argv) 
    { // print compressed binary values
        size_t check = 0;
        // iterate though the array and print out pixel values
        for (int currentRow = 0; currentRow < data->height; currentRow++) 
        { // Loop over rows
            for (int currentCol = 0; currentCol < data->width; currentCol++) 
            { // Loop over columns
                check = fwrite(&data->charImageData[currentRow][currentCol], sizeof(unsigned char), 1, data->outputFile);
                // Condition if a pixel does not exist
                if (check == 0) 
                { // check write
                    fclose(data->outputFile);
                    free(data->charImageData);
                    printf("ERROR: Bad Output (%s)\n", argv);
                    return 1;
                } // check write
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if successful
    } // print compressed binary values