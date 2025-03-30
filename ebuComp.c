#include <stdio.h>
#include <stdlib.h>
#include "compMain.h"

/**
 * Main function that compares two binary images using the function `compareImageBinary` 
 * from the header file "compMain.h".
 *
 * @param argc The number of command-line arguments passed to the program.
 * @param argv An array of strings containing the command-line arguments passed to the program.
 *             argv[1] should be the name of the first binary image file.
 *             argv[2] should be the name of the second binary image file.
 *
 * @return 0 if the two binary images are identical, 1 if they are different, and a 
 *         non-zero value indicating an error occurred.
 */


int main(int argc, char **argv) 
    { // main
        int compareImageBinary(int argc, char* argv1, char* argv2);
        return compareImageBinary(argc, argv[1], argv[2]);
    } // main()