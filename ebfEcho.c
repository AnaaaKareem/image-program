#include <stdio.h>
#include <stdlib.h>
#include "echoMain.h"

/**
 * Main function that echoes the contents of an image file represented as a list of numbers using 
 * the function `echoImageNumbers` from the header file "echoMain.h".
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of strings containing the command-line arguments passed to the program.
 *             argv[1] should be the name of the input file containing the list of numbers to be echoed.
 *             argv[2] should be the name of the output file where the echoed numbers will be saved.
 *
 * @return 0 if the echoing was successful, otherwise a non-zero value indicating an error occurred.
 */

int main(int argc, char **argv)
   { // main
    int echoImageNumbers(int argc, char* argv1, char* argv2);
    return echoImageNumbers(argc, argv[1], argv[2]);
   } // main()