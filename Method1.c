#include "Method1.h"
#include <pthread.h>


extern long long **matA;           //matrix A
extern long long **matB;           //matrix B
extern long aRows;                  //number of rows in Matrix A
extern long aColumns;               //Number of columns in Matrix A
extern long bRows;                  //number of rows in Matrix B
extern long bColumns;               //number of columns in Matrix B
extern long long **matCMethod1;            //output matrix using no threads
void *multiply1(void *rowNumber);

void useMethod1(){          //use number of threads equal to number of rows in the output matrix

        pthread_t threads[aRows];               // descriptors of threads
        int i;
        for(i = 0; i < aRows; i++) {             // create threads
//            if (pthread_create(&threads[i], NULL, multiply1, (void *)i))
//            {
//                printf("Can not create a thread\n");
//                exit(1);
//            }
        }
}

void *multiply1(void *rowNumber){

//        for(bColumnsIterator=0 ; bColumnsIterator < bColumns ; bColumnsIterator++){
//
//                    sumOfProduct = 0;
//                    for(bRowsIterator=0 ; bRowsIterator < bRows ; bRowsIterator++){
//
//                            sumOfProduct += matA[aRowsIterator][bRowsIterator] * matB[bRowsIterator][bColumnsIterator];
//                    }
//
//                    matC[aRowsIterator][bColumnsIterator] = sumOfProduct;
//        }


}
