#include <stdio.h>
#include "dataStructures.h" // To pass structure as a parameter
#include "returnCodes.h"

int checkArgCount(int argc);
int checkFile(FILE *file, char* argv);
int checkMagicNumberEB(ebData *data, char* argv);
int checkMagicNumberEU(ebData *data, char* argv);
int checkMagicNumberEC(ebData *data, char* argv);
int checkDimensions(ebData *data, char* argv);
int checkDecimalMalloc(ebData *data);
int checkBinaryMalloc(ebData *data);

int checkDecimalValues(ebData *data, char* argv, FILE *file);
int checkBinaryValues(ebData *data, char* argv, FILE *file);
int checkCompressedValues(ebData *data, char* argv, FILE *file);