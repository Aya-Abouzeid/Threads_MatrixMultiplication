#include "Method2.h"
#include <pthread.h>

extern long long **matA;           //matrix A
extern long long **matB;           //matrix B
extern long aRows;                  //number of rows in Matrix A
extern long aColumns;               //Number of columns in Matrix A
extern long bRows;                  //number of rows in Matrix B
extern long bColumns;               //number of columns in Matrix B
extern long long **matCMethod2;            //output matrix using no threads
void *multiply2(void *data);

void useMethod2(){               //use number of threads equal to number of elements in the output matrix

        pthread_t threads[aRows * bColumns];            // descriptors of threads

       int i,j, count = 0;
       for(i = 0; i < aRows; i++) {
            for(j = 0; j < bColumns; j++) {
                     struct threadData *data = (struct threadData *) malloc(sizeof(struct threadData));  //Assign a row and column for each thread
                     data->i = i;
                     data->j = j;
                     pthread_t tid;       //Thread ID
                     pthread_attr_t attr; //Set of thread attributes
                     pthread_attr_init(&attr);            //Get the default attributes
                     pthread_create(&tid,&attr,multiply2,data);    //Create the thread
                     pthread_join(tid, NULL);     //parent waits for all thread to complete
            }
        }
}

void *multiply2(void *data){


}
