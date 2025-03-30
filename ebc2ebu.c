#include <stdio.h>
#include <stdlib.h>
#include "convertingMain.h"

/**
 * Main function that converts compressed data to uncompressed data using the 
 * function `convertCompressed2Uncompressed` from the header file "convertingMain.h".
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of strings containing the command-line arguments passed to the program.
 *             argv[1] should be the name of the input file containing the compressed data.
 *             argv[2] should be the name of the output file where the uncompressed data will be saved.
 *
 * @return 0 if the conversion was successful, otherwise a non-zero value indicating an error occurred.
 */

int main(int argc, char **argv)
    { // main
        int convertCompressed2Uncompressed(int argc, char* argv1, char* argv2);
        return convertCompressed2Uncompressed(argc, argv[1], argv[2]);
    } // main()