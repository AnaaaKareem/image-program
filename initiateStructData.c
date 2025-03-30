#include <stdio.h>
#include <stdlib.h>
#include "2DArray.h"
#include "dataStructures.h"


ebData *ebInit(FILE *input)
    { // initialize the ebData structue
        // Assign memory and allocate the data struct
        ebData *data;
        data = (ebData*)malloc(sizeof(ebData));
        data->inputFile = input;
    
        // get first 2 characters which should be magic number
        data->magicNumber[0] = getc(input);
        data->magicNumber[1] = getc(input);
    
        // Create a short that stores the magic number
        data->magicNumberValue = (unsigned short*)&data->magicNumber;
    
        data->width = 0;
        data->height = 0;
    
        data->EOFChecker = 0;
    
        return data;
    } // initialize the ebData structue