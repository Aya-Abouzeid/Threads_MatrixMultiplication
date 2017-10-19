#include "matMult.h"

extern long aRows;                  //number of rows in Matrix A
extern long aColumns;               //Number of columns in Matrix A
extern long bRows;                  //number of rows in Matrix B
extern long bColumns;               //number of columns in Matrix B
long long **matC;                   //output matrix using no threads
int aRowsIterator = 0;               //for looping along the first rows columns
int bRowsIterator = 0;               //for looping along the second matrix rows
int bColumnsIterator = 0;            //for looping along the second matrix columns
int product = 0;                    //for computing the output array

void multiplyNoThreads(long long **matA, long long **matB){         //multiply 2 matrices without threads

         matC = malloc(aRows * sizeof(long long *));
         for(aRowsIterator ; aRowsIterator < aRows ; aRowsIterator++){

                    matC[aRowsIterator] = malloc(bColumns * sizeof(long long));
                    for(bColumnsIterator=0 ; bColumnsIterator < bColumns ; bColumnsIterator++){

                                product = 0;
                                for(bRowsIterator=0 ; bRowsIterator < bRows ; bRowsIterator++){

                                        product += matA[aRowsIterator][bRowsIterator] * matB[bRowsIterator][bColumnsIterator];
                                }

                                matC[aRowsIterator][bColumnsIterator] = product;
                    }
        }
}
