#include "Method2.h"
#include <pthread.h>

extern long long **matA;           //matrix A
extern long long **matB;           //matrix B
extern long aRows;                  //number of rows in Matrix A
extern long aColumns;               //Number of columns in Matrix A
extern long bRows;                  //number of rows in Matrix B
extern long bColumns;               //number of columns in Matrix B
extern long long **matCMethod2;            //output matrix using no threads
struct threadData {                //ThreadData
   int row;
   int column;
   int id;
};
void *multiply2(void *data);

void useMethod2(){               //use number of threads equal to number of elements in the output matrix

       pthread_t threads[aRows * bColumns];            // descriptors of threads
       int i,j, count = 0;
       for(i = 0; i < aRows; i++) {
            for(j = 0; j < bColumns; j++) {
                     struct threadData *data = (struct threadData *) malloc(sizeof(struct threadData));  //Assign a row and column for each thread
                     data-> row = i;
                     data-> column = j;
                     data-> id = i * bColumns + j;
                     if(pthread_create(&threads[i * bColumns + j],NULL,multiply2,(void *) data)){    //Create the thread
                     printf("Error creating thread %d\n" , i * bColumns + j);
                     exit(-1);
                     }

            }
        }

        for (i = 0; i < aRows; i++) {
            for (j = 0; j < bColumns; j++) {
                     pthread_join(threads[i * bColumns + j], NULL);
            }
        }

        int l=0 , m=0;
        for(l ; l< aRows ; l++){
            m=0;
            for(m ; m<bColumns ; m++){
                    printf("%lld  ", matCMethod2[l][m]);
            }

        printf("\n");
        }
        pthread_exit(0);

}

void *multiply2(void *data){            //multiply elements one at a time

        struct threadData *element = (struct threadData *) data;        //get element data
        int iterator;
        int productOfSum = 0;
        for (iterator = 0; iterator < aColumns; iterator++) {
            productOfSum += matA[(*element).row][iterator] * matB[iterator][(*element).column];     //compute elememt value
        }
        matCMethod2[(*element).row][(*element).column] = productOfSum;
        pthread_exit(NULL);

}
