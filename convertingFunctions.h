#include <stdio.h>
#include <stdlib.h>

#include "dataStructures.h"
#include "returnCodes.h"

int headerConverter(ebData *data, char* argv, char code);
int readNumbers(ebData *data, char* argv);
int readUncompressed(ebData *data, char* argv);
int readCompressed(ebData *data, char* argv);
int writeNumbers(ebData *data, char* argv);
int writeUncompressed(ebData *data, char* argv);
int writeCompressed(ebData *data, char* argv);