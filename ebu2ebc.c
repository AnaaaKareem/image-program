#include <stdio.h>
#include <stdlib.h>
#include "convertingMain.h"

/**
 * Main function that converts an uncompressed image to a compressed image using the function 
 * `convertUncompressed2Compressed` from the header file "convertingMain.h".
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of strings containing the command-line arguments passed to the program.
 *             argv[1] should be the name of the input uncompressed image file.
 *             argv[2] should be the name of the output compressed image file.
 *
 * @return 0 if the conversion was successful, otherwise a non-zero value indicating an error occurred.
 */


int main(int argc, char **argv) 
    { // main
        int convertUncompressed2Compressed(int argc, char* argv1, char* argv2);
        return convertUncompressed2Compressed(argc, argv[1], argv[2]);
    } // main()