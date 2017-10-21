#ifndef READ_FROM_FILES_H
#define READ_FROM_FILES_H
#include <stdbool.h>

bool readMatrices(char *mat1 , char *mat2);
bool readMatA(char *mat);
bool readMatB(char *mat);
bool allocateRows();
void split(int matrix);

#endif // READ_FROM_FILES_H

