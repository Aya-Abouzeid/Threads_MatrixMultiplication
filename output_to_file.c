#include "output_to_file.h"
#include <stdio.h>
#include "stdlib.h"

extern long long **matCMethod1;            //output matrix using no threads
extern long long **matCMethod2;            //output matrix using no threads
extern char *outMatName1;     //output matrix name for method 1
extern char *outMatName2;     //output matrix name for method 2
extern long aRows;                  //number of rows in Matrix A
extern long bColumns;               //number of columns in Matrix B
FILE *outMatFile1;                 //output matrix for method 1 file
FILE *outMatFile2;                 //iutput matrix for method 2 file

writeOutput1(int threadNumber , int time){             //print output of method 1 to file


    outMatFile1= fopen(outMatName1, "w");
    if(outMatFile1!=NULL)
    {
        fprintf(outMatFile1 , "Multiplying row by row:\n\n");
        fprintf(outMatFile1 , " Number of threads used: %d\n" , threadNumber);
        fprintf(outMatFile1," Execution time(ms): %lu\n\n" ,  time );        // execution time
        int l=0 , m=0;
        for(l ; l< aRows ; l++){
            m=0;
            for(m ; m<bColumns ; m++){
                    fprintf(outMatFile1 , "%lld  ", matCMethod1[l][m]);         //writing matrix to file
            }

        fprintf(outMatFile1 , "\n");
        }
        fclose(outMatFile1);
    }
    else
    {
        printf("%s\n", " ERROR : cann't write in file 1");
    }
}
writeOutput2(int threadNumber , int time){             //print output of method 2 to file

    outMatFile2= fopen(outMatName2, "w");
    if(outMatFile2!=NULL)
    {
        fprintf(outMatFile2 , "Multiplying element by element:\n \n");
        fprintf(outMatFile2 , " Number of threads used: %d\n" , threadNumber);
        fprintf(outMatFile2," Execution time(ms): %lu\n\n" ,  time );        // execution time
        int l=0 , m=0;
        for(l ; l< aRows ; l++){
            m=0;
            for(m ; m<bColumns ; m++){
                    fprintf(outMatFile2, "%lld  ", matCMethod2[l][m]);      //writing matrix to file
            }

        fprintf(outMatFile2 , "\n");
        }
        fclose(outMatFile2);
    }
    else
    {
        printf("%s\n", " ERROR : cann't write in file 2");
    }
}
