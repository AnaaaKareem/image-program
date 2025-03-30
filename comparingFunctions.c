#include <stdio.h>
#include <stdlib.h>

#include "dataStructures.h"

// Declare the functions before their first use
int compareMagicNumber(ebData *data1, ebData *data2);
int compareDimensions(ebData *data1, ebData *data2);
int comparePixelValues(ebData *data1, ebData *data2);
int compareBinaryValues(ebData *data1, ebData *data2);
int compareCompressedValues(ebData *data1, ebData *data2);

int comparePixels(ebData *data1, ebData *data2)
    { // compare pixels
        if (compareMagicNumber(data1, data2) == 0 && compareDimensions(data1, data2) == 0 && comparePixelValues(data1, data2) == 0)
        { // check if identical
            printf("IDENTICAL\n");
            return 0; // return 0 if identical
        } // check if identical
        else
        { // check if different
            printf("DIFFERENT\n");
            return 1; // return 1 if different
        } // check if different
    } // compare pixels

int compareBinary(ebData *data1, ebData *data2)
    { // compare binary
        if (compareMagicNumber(data1, data2) == 0 && compareDimensions(data1, data2) == 0 && compareBinaryValues(data1, data2) == 0)
        { // check if identical
            printf("IDENTICAL\n");
            return 0; // return 0 if identical
        } // check if identical
        else
        { // check if different
            printf("DIFFERENT\n");
            return 1; // return 1 if different
        } // check if different
    } // compare binary

int compareCompressed(ebData *data1, ebData *data2)
    { // compare compressed binary
        if (compareMagicNumber(data1, data2) == 0 && compareDimensions(data1, data2) == 0 && compareCompressedValues(data1, data2) == 0)
        { // check if identical
            printf("IDENTICAL\n");
            return 0; // return 0 if identical
        } // check if identical
        else
        { // check if different
            printf("DIFFERENT\n");
            return 1; // return 1 if different
        } // check if different
    } // compare compressed binary

int compareMagicNumber(ebData *data1, ebData *data2)
    { // compare magic number
        if (*data1->magicNumberValue != *data2->magicNumberValue)
        { // check if the magic numbers are identical
            return 1; // return 1 if different
        } // check if the magic numbers are identical
        return 0; // return 0 if identical
    } // compare magic number

int compareDimensions(ebData *data1, ebData *data2)
    { // compare dimensions
        if ((data1->height != data2->height) || (data1->width != data2->width))
        { // check if the dimensions are identical
            return 1; // return 1 if different
        } // check if the dimensions are identical
        return 0; // return 0 if identical
    } // compare dimensions

int comparePixelValues(ebData *data1, ebData *data2)
    { // compare pixel number values
        for (int i = 0; i < data1->height; i++)
        { // Loop over rows
            for (int j = 0; j < data1->width; j++)
            { // Loop over columns
                if (data1->decimalImageData[i][j] != data2->decimalImageData[i][j])
                { // check if pixel number values are different
                    return 1; // return 1 if different
                } // check if pixel number values are different
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if identical
    } // compare pixel number values

int compareBinaryValues(ebData *data1, ebData *data2)
    { // compare binary data values
        for (int i = 0; i < data1->height; i++)
        { // Loop over rows
            for (int j = 0; j < data1->width; j++)
            { // Loop over columns
                if (data1->charImageData[i][j] != data2->charImageData[i][j]) { // check if binary data values are different
                    return 1; // return 1 if different
                } // check if binary data values are different
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if identical
    } // compare binary data values

int compareCompressedValues(ebData *data1, ebData *data2)
    { // compare compressed binary data values
        for (int i = 0; i < data1->height; i++)
        { // Loop over rows
            for (int j = 0; j < data1->width; j++)
            { // Loop over columns
                if (data1->charImageData[i][j]!=data2->charImageData[i][j]) { // check if compressed binary data values are different
                    return 1; // return 1 if different
                } // check if compressed binary data values are different
            } // Loop over columns
        } // Loop over rows
        return 0; // return 0 if identical
    } // compare compressed binary data values