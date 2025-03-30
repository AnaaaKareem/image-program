#include <stdio.h>
#include "dataStructures.h"

int comparePixels(ebData *data1, ebData *data2);
int compareBinary(ebData *data1, ebData *data2);
int compareCompressed(ebData *data1, ebData *data2);
int compareMagicNumber(ebData *data1, ebData *data2);
int compareDimensions(ebData *data1, ebData *data2);
int comparePixelValues(ebData *data1, ebData *data2);
int compareBinaryValues(ebData *data1, ebData *data2);