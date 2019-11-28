#include<stdio.h>
#include<stdlib.h>

int main(int argc, const char *argv[]) {
    int i = 0,j = 0;
    /**
     * Here 3 represents number of rows and 4 repersents number of columns
     */ 
    int a[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int *b[3]; // this will create 3 rows array in stack memory and sub arrays in heap
    int **c;  // this will create complete array in heap

    int noOFRows = sizeof(a)/sizeof(a[0]); //here we took sizeOf(a[0]) to determine number of columns
    int noOFCloumns = sizeof(a[0])/sizeof(int);
    
    for ( i = 0; i < noOFRows; i++)
    {
        for(j = 0; j < noOFCloumns; j++) {
            printf("%d ", a[i][j]);
        }
       printf("\n");
    }
    printf("\n");
    // Diagonal elements of each element

    for ( i = 0; i < noOFRows; i++)
    {
        for(j = 0; j < noOFCloumns; j++) {
            printf("diagnoal elements of element a[%d][%d] (%d) = ", i, j, a[i][j]);
            if(i-1 >=0 && j-1 >= 0) {
                printf("%d ", a[i-1][j-1]);
            }
            if(i-1 >=0 && j+1 < noOFCloumns) {
                printf("%d ", a[i-1][j+1]);
            }
            if(i+1 < noOFRows && j-1 >= 0) {
                printf("%d ", a[i+1][j-1]);
            }
            if(i+1 < noOFRows && j+1 < noOFCloumns) {
                printf("%d ", a[i+1][j+1]);
            }

            printf("\n");
        }

        printf("\n");
    }

    /**
     * Creating arrays in heap
     * */

    noOFRows = sizeof(b) / sizeof(int *);

    for (i = 0; i < noOFRows; i++)
    {
        b[i] = (int *)malloc(4 * sizeof(int));
            for (j = 0; j < 4; j++)
            {
                b[i][j] = 2 * (i + 1)*(j + 1);
            }
    }

    for ( i = 0; i < noOFRows; i++)
    {
        for(j = 0; j < 4; j++) {
            printf("%d ", b[i][j]);
        }
       printf("\n");
    }

    for (i = 0; i < noOFRows; i++) {
        if(b[i] !=NULL) {
            printf("Cleaning up b[%d] \n" , i);
            free(b[i]);
            b[i] = NULL;
        }
    }

    c = (int **)malloc(3 * sizeof(int *));

    for (i = 0; i < 3; i++)
    {
        c[i] = (int *)malloc(4 * sizeof(int));
            for (j = 0; j < 4; j++)
            {
                c[i][j] = 2 * (i + 2)*(j + 2);
            }
    }

    for ( i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++) {
            printf("%d ", c[i][j]);
        }
       printf("\n");
    }

    for (i = 0; i < 3; i++) {
        if(c[i] !=NULL) {
            printf("Cleaning up c[%d] \n" , i);
            free(c[i]);
            c[i] = NULL;
        }
    }
    
    if(c != NULL) {
        printf("Cleaning up c \n");
        free(c);
        c = NULL;
    }
}
