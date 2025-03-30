#include <stdlib.h>

#include "returnCodes.h"

int **makeInt2DArray(int nRows, int nColumns) 
    { // create integer 2D array
    	// Check for non-negative row and column counts
        if (nRows < MIN_DIMENSION || nColumns < MIN_DIMENSION || nRows > MAX_DIMENSION || nColumns > MAX_DIMENSION) 
    	{ // if dimensions are out of bounds don't allocate
            return NULL;
        } // if dimensions are out of bounds don't allocate
    	
    	// allocate memory for pointersm to each row
    	int **wholeArray = (int **)malloc(nRows*sizeof(unsigned int*));
    	if (wholeArray == NULL) 
    	{ // if array is empty return null
    		return NULL;
        } // if array is empty return null
    	
    	// allocate memory for all data storage at once 
    	int *dataBlock = (int*)malloc(nRows*nColumns*sizeof(unsigned int));
    	if (dataBlock == NULL) 
    	{ // if data block is empty return null
    		free(wholeArray);
            return NULL;
        } // if data block is empty return null
    	
    	// now loop to set up pointers for each row (no malloc call)
    	for(int row = 0; row < nRows; row++) 
    	{ // allocate array
    		wholeArray[row] = dataBlock + row * nColumns;
    	} // allocate array
    	
    	// return array
    	return wholeArray;
    } // create integer 2D array

char **makeChar2DArray(int nRows, int nColumns) 
    { // create char 2D array
    
    	// Check for non-negative row and column counts
        if (nRows < MIN_DIMENSION || nColumns < MIN_DIMENSION || nRows > MAX_DIMENSION || nColumns > MAX_DIMENSION) 
        { // if dimensions are out of bounds don't allocate
            return NULL;
        } // if dimensions are out of bounds don't allocate
    	
    	// allocate memory for pointersm to each row
    	char **wholeArray = (char **)malloc(nRows*sizeof(unsigned char*));
    	if (wholeArray == NULL) 
    	{ // if array is empty return null
    		return NULL;
        } // if array is empty return null
    	
    	// allocate memory for all data storage at once 
    	char *dataBlock = (char *)malloc(nRows*nColumns*sizeof(unsigned char));
    	if (dataBlock == NULL) 
    	{ // if data block is empty return null
    		free(wholeArray);
            return NULL;
        } // if data block is empty return null
    	
    	// now loop to set up pointers for each row (no malloc call)
    	for(int row = 0; row < nRows; row++) 
    	{ // allocate array
    		wholeArray[row] = dataBlock + row * nColumns;
    	} // allocate array
    	
    	// return array
    	return wholeArray;
    } // create char 2D array