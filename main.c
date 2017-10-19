#include "read_from_files.h"
#include "output_to_file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

char *mat1Name;       //first matrix name
char *mat2Name;       //second matrix name
char *outMatName1;     //output matrix name for method 1
char *outMatName2;     //output matrix name for method 2
extern long aRows;                  //number of rows in Matrix A
extern long aColumns;               //Number of columns in Matrix A
extern long bRows;                  //number of rows in Matrix B
extern long bColumns;               //number of columns in Matrix B
struct timeval stop, start;
int time1;      //time for method 1 execution
int time2;      //time for method 2 execution
int main(int argc, char *argv[])
{

        if( argc == 4 ){        // user entered files correctly

            mat1Name = malloc (strlen (argv[1]) + 1);
            mat2Name = malloc (strlen (argv[2]) + 1);
            outMatName1 = malloc (strlen (argv[3]) + 2);
            outMatName2 = malloc (strlen (argv[3]) + 2);
            strcpy(mat1Name ,argv[1]);
            strcpy(mat2Name ,argv[2]);
            strcpy(outMatName1 ,argv[3]);
            strcat(outMatName1,"1");
            strcpy(outMatName2 ,argv[3]);
            strcat(outMatName2,"2");

        }
        else {      //user didn't enter file names or entered incorrect number of parameters

            mat1Name = malloc (strlen ("a.txt") + 1);
            mat2Name = malloc (strlen ("b.txt") + 1);
            outMatName1 = malloc (strlen ("c1.out") + 1);
            outMatName2 = malloc (strlen ("c2.out") + 1);
            strcpy(mat1Name ,"a.txt");
            strcpy(mat2Name ,"b.txt");
            strcpy(outMatName1 ,"c1.out");
            strcpy(outMatName2 ,"c2.out");

        }

         readMatrices(mat1Name , mat2Name);  //reading the 2 matrices files
         multiplyMatrices();
         free(mat1Name);
         free(mat2Name);
         free(outMatName1);
         free(outMatName2);

         pthread_exit(NULL);
    return 0;
}

void multiplyMatrices(){                    //multiply the 2 matrices using several methods

        if(aRows > 0 && aColumns > 0 && bRows > 0 && bColumns > 0 && aColumns == bRows) {       //checking for 0 dimentional matrices

            noThreads();
            rowByRow();
            elementByElement();
            writeOutput1(aRows, time1);             //print output of method 1 to file
            writeOutput2(aRows*bColumns , time2);             //print output of method 2 to file

        } else {
            printf("Invalid matrices dimentions.\n");
        }

}

void noThreads(){

        printf("A- Multiplying using no threads:\n");
        gettimeofday(&start, NULL);         //start time
        multiplyNoThreads();
        gettimeofday(&stop, NULL);          //End time
        printf("   Execution time(ms): %lu\n" ,  stop.tv_usec - start.tv_usec );        //computing execution time


}
void rowByRow(){

        printf("\nB- Multiplying row by row:\n");
        printf("   Number of threads used: %d\n" , aRows);
        gettimeofday(&start, NULL);         //start time
        useMethod1();
        gettimeofday(&stop, NULL);          //End time
        time1 = stop.tv_usec - start.tv_usec ;
        printf("   Execution time(ms): %lu\n" ,  stop.tv_usec - start.tv_usec );        //computing execution time
}
void elementByElement(){

        printf("\nC- Multiplying element by element:\n");
        printf("   Number of threads used: %d\n" , aRows*bColumns);
        gettimeofday(&start, NULL);         //start time
        useMethod2();
        gettimeofday(&stop, NULL);          //End time
        time2 = stop.tv_usec - start.tv_usec ;
        printf("   Execution time(ms): %lu \n" ,  stop.tv_usec - start.tv_usec );       //computing execution time

}
