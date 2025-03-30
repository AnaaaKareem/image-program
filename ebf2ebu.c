#include <stdio.h>
#include <stdlib.h>
#include "convertingMain.h"

/**
 * Main function that converts an image file represented as a list of numbers to an 
 * uncompressed binary format using the function `convertNumbers2Uncompressed` from 
 * the header file "convertingMain.h".
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of strings containing the command-line arguments passed to the program.
 *             argv[1] should be the name of the input file to be converted.
 *             argv[2] should be the name of the output file to be created.
 *
 * @return 0 if the conversion is successful, otherwise a non-zero value indicating an error.
 */

int main(int argc, char **argv)
    { // main
    int convertNumbers2Uncompressed(int argc, char* argv1, char* argv2);
    return convertNumbers2Uncompressed(argc, argv[1], argv[2]);
    } // main()