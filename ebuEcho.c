#include <stdio.h>
#include <stdlib.h>
#include "echoMain.h"

/**
 * Main function that echoes a binary image to another file using the function 
 * `echoImageBinary` from the header file "echoMain.h".
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of strings containing the command-line arguments passed to the program.
 *             argv[1] should be the name of the input binary image file.
 *             argv[2] should be the name of the output file where the echoed image will be saved.
 *
 * @return 0 if the echoing was successful, otherwise a non-zero value indicating an error occurred.
 */


int main(int argc, char **argv)
    { // main
    int echoImageBinary(int argc, char* argv1, char* argv2);
    return echoImageBinary(argc, argv[1], argv[2]);
    } // main()