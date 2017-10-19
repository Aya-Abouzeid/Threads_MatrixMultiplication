#include "read_from_files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

char *mat1Name;       //first matrix name
char *mat2Name;       //second matrix name
char *outMatName;     //output matrix name
extern long aRows;                  //number of rows in Matrix A
extern long aColumns;               //Number of columns in Matrix A
extern long bRows;                  //number of rows in Matrix B
extern long bColumns;               //number of columns in Matrix B

int main(int argc, char *argv[])
{

        if( argc == 4 ){        // user entered files correctly

            mat1Name = malloc (strlen (argv[1]) + 1);
            mat2Name = malloc (strlen (argv[2]) + 1);
            outMatName = malloc (strlen (argv[3]) + 1);
            strcpy(mat1Name ,argv[1]);
            strcpy(mat2Name ,argv[2]);
            strcpy(outMatName ,argv[3]);

        }
        else {      //user didn't enter file names or entered incorrect number of parameters

            mat1Name = malloc (strlen ("a.txt") + 1);
            mat2Name = malloc (strlen ("b.txt") + 1);
            outMatName = malloc (strlen ("c.out") + 1);
            strcpy(mat1Name ,"a.txt");
            strcpy(mat2Name ,"b.txt");
            strcpy(outMatName ,"c.out");

        }

         readMatrices(mat1Name , mat2Name);  //reading the 2 matrices files
         multiplyMatrices();


         pthread_exit(NULL);
    return 0;
}

void multiplyMatrices(){                    //multiply the 2 matrices using several methods

        if(aRows > 0 && aColumns > 0 && bRows > 0 && bColumns > 0 && aColumns == bRows) {       //checking for 0 dimentional matrices

            multiplyNoThreads();
//            useMethod1();
            useMethod2();

        } else {
            printf("Invalid matrices dimentions.\n");
        }

}
