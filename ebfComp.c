#include <stdio.h>
#include <stdlib.h>
#include "compMain.h"

/**
 * Main function that compares two image files represented as lists of numbers using 
 * the function `compareImageNumbers` from the header file "compMain.h".
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of strings containing the command-line arguments passed to the program.
 *             argv[1] should be the name of the first input file to be compared.
 *             argv[2] should be the name of the second input file to be compared.
 *
 * @return 0 if the images are equal, otherwise a non-zero value indicating they are different.
 */

int main(int argc, char **argv)
    { // main
        int compareImageNumbers(int argc, char* argv1, char* argv2);
        return compareImageNumbers(argc, argv[1], argv[2]);
    } // main()