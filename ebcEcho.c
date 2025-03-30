#include <stdio.h>
#include <stdlib.h>
#include "echoMain.h"

/**
 * Main function that echoes an image file represented in compressed binary format using 
 * the function `echoImageCompressed` from the header file "echoMain.h".
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of strings containing the command-line arguments passed to the program.
 *             argv[1] should be the name of the input file to be echoed.
 *             argv[2] should be the name of the output file to be created.
 *
 * @return 0 if the echoing is successful, otherwise a non-zero value indicating an error.
 */

int main(int argc, char **argv) 
    { // main
    int echoImageCompressed(int argc, char* argv1, char* argv2);
    return echoImageCompressed(argc, argv[1], argv[2]);
    } // main()