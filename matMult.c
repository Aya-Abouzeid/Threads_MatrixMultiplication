#include "matMult.h"

extern long long **matA;           //matrix A
extern long long **matB;           //matrix B
extern long aRows;                  //number of rows in Matrix A
extern long aColumns;               //Number of columns in Matrix A
extern long bRows;                  //number of rows in Matrix B
extern long bColumns;               //number of columns in Matrix B
extern long long **matC;                   //output matrix using no threads
int aRowsIterator = 0;               //for looping along the first rows columns
int bRowsIterator = 0;               //for looping along the second matrix rows
int bColumnsIterator = 0;            //for looping along the second matrix columns
int sumOfProduct = 0;                    //for computing the output array

void multiplyNoThreads(){         //multiply 2 matrices without threads

         for(aRowsIterator ; aRowsIterator < aRows ; aRowsIterator++){

                    for(bColumnsIterator=0 ; bColumnsIterator < bColumns ; bColumnsIterator++){

                                sumOfProduct = 0;
                                for(bRowsIterator=0 ; bRowsIterator < bRows ; bRowsIterator++){

                                        sumOfProduct += matA[aRowsIterator][bRowsIterator] * matB[bRowsIterator][bColumnsIterator];
                                }

                                matC[aRowsIterator][bColumnsIterator] = sumOfProduct;
                    }
        }
        int i=0 , j=0;
        for(i ; i< aRows ; i++){
        j=0;
            for(j ; j<bColumns ; j++){
            printf("%lld  ", matC[i][j]);
            }

        printf("\n");
        }



}
