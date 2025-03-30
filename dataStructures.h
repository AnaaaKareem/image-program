#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <stdio.h>

typedef struct fileInfoStruct {
    FILE *inputFile;
    unsigned char magicNumber[2];
    unsigned short *magicNumberValue;
    int width;
    int height;
    int EOFChecker;
    unsigned int **decimalImageData;
    unsigned char **charImageData;
    FILE *outputFile;
} ebData;
#endif /* DATASTRUCTURES_H */