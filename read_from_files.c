#include "read_from_files.h"
#include <stdio.h>
#include "stdlib.h"

long aRows = 0;                  //number of rows in Matrix A
long aColumns = 0;               //Number of columns in Matrix A
long bRows = 0;                  //number of rows in Matrix B
long bColumns = 0;               //number of columns in Matrix B
FILE *matAFile;                 //Matrix A file
FILE *matBFile;                 //Matrix B file
char line[1024];            //first line in the file
long long **matA;           //matrix A
long long **matB;           //matrix B
long long **matC;                   //output matrix using no threads
long long **matCMethod1;            //output matrix using no threads
long long **matCMethod2;            //output matrix using no threads
int iterator = 0;                   //for allocating rows in memory

void readMatrices(char *mat1 , char *mat2){         //read matrices files

        readMatA(mat1);
        readMatB(mat2);
        allocateRows();

}

void allocateRows(){

     matC = malloc(aRows * sizeof(long long *));
     matCMethod1 = malloc(aRows * sizeof(long long *));
     matCMethod2 = malloc(aRows * sizeof(long long *));

     for(iterator ; iterator < aRows ; iterator++){

                matC[iterator] = malloc(bColumns * sizeof(long long));  //allocating memory space for a new row in matrix C using normal multiplication
                matCMethod1[iterator] = malloc(bColumns * sizeof(long long));  //allocating memory space for a new row in matrix C of method 1
                matCMethod2[iterator] = malloc(bColumns * sizeof(long long));  //allocating memory space for a new row in matrix C of method 2

     }

}

void readMatA(char *mat){        //reading first matrix

        matAFile = fopen(mat, "r");
        if (matAFile == NULL){
                printf("%s\n", "File not found.");
        }
        else {
                fgets(line, 1024, matAFile);
                getDimentions(1);                   //extract number of columns and rows
                matA = malloc(aRows * sizeof(long long *));
                int r = 0, c = 0;
                for(r ; r < aRows ; r++) {
                    matA[r] = malloc(aColumns * sizeof(long long));
                    c=0;
                    for(c ; c < aColumns ; c++){
                        fscanf(matAFile , "%lld" , & matA[r][c]);       //reading matrix element by element
                    }
                }
                fclose(matAFile);
        }
}
void readMatB(char *mat){        //reading second matrix

        matBFile = fopen(mat, "r");
        if (matBFile == NULL){
                printf("%s\n", "File not found.");
        }
        else {
                fgets(line, 1024, matBFile);
                getDimentions(2);                   //extract number of columns and rows
                matB = malloc(bRows * sizeof(long long *));
                int r = 0, c = 0;
                for(r ; r < bRows ; r++) {
                    matB[r] = malloc(bColumns * sizeof(long long));
                    c=0;
                    for(c ; c < bColumns ; c++){
                        fscanf(matBFile , "%lld" , & matB[r][c]);      //reading matrix element by element
                    }
                }
                fclose(matBFile);
        }
}
void getDimentions(int matrix){                       // split first line of file to get the matrices size , int matrix

        int i;
        int reader =0;

        for(i =0 ; i< strlen(line) ; i++){

                if(line[i]== '=' && reader ==0){        //reader =0 means reading the row number
                        i++;
                        while(line[i] == ' ' || line[i] == '\t' )
                            i++;
                        while(line[i] != ' ' && line[i] != '\t' && line[i] != '\0' && line[i] != '\n'){

                            if(matrix == 1){        //reading rows of matA
                                aRows *= 10;
                                aRows +=   (line[i] - '0');
                            } else {                //reading rows of matB
                                bRows *= 10;
                                bRows += (line[i] - '0');
                            }

                            i++;
                        }
                        reader++;

                } else if(line[i]== '=' && reader ==1) {                                //reader = 1 meains reading th column number
                        i++;
                        while(line[i] == ' ' || line[i] == '\t' )
                            i++;
                        while(line[i] != ' ' && line[i] != '\t' && line[i] != '\0'  && line[i] != '\n' ){

                            if(matrix == 1){            //reading columns of matA
                                aColumns *= 10;
                                aColumns += (line[i] - '0');

                            } else {                    //reading columns of matB
                                bColumns *= 10;
                                bColumns += (line[i] - '0');
                            }

                            i++;
                        }
                }
        }
}
