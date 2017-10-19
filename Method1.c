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
        for(i = 0; i < aRows; i++) {

            if (pthread_create(&threads[i], NULL, multiply1, (void *)i))        // create threads
            {
                printf("Error creating thread %d\n" , i );
                exit(-1);
            }
        }
        int j;
        for (j = 0; j < aRows; j++) {
                     pthread_join(threads[j], NULL);
            }

        int l=0 , m=0;
        for(l ; l< aRows ; l++){
            m=0;
            for(m ; m<bColumns ; m++){
                    printf("%lld  ", matCMethod1[l][m]);
            }

        printf("\n");
        }
        return;
}

void *multiply1(void *rowNumber){
        int row = (int) rowNumber;
        int sumOfProduct = 0;
        int ColumnsIterator = 0;
        int bRowsIterator = 0;
        for(ColumnsIterator= 0 ; ColumnsIterator < bColumns ; ColumnsIterator++){

                    sumOfProduct = 0;
                    for(bRowsIterator=0 ; bRowsIterator < bRows ; bRowsIterator++){

                            sumOfProduct += matA[row][bRowsIterator] * matB[bRowsIterator][ColumnsIterator];
                    }

                    matCMethod1[row][ColumnsIterator] = sumOfProduct;
        }


}
