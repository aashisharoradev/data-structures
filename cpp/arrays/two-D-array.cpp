#include<iostream>
#include<new>

using namespace std;

int main(int argc, const char *argv[] ) {
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
            cout <<a[i][j];
        }
       cout <<endl;
    }
    cout << endl;
    // Diagonal elements of each element

    for ( i = 0; i < noOFRows; i++)
    {
        for(j = 0; j < noOFCloumns; j++) {
            cout << "diagnoal elements of element a[" <<i << "]["<<j <<"]" << a[i][j]<< endl;
            if(i-1 >=0 && j-1 >= 0) {
                cout << a[i-1][j-1] << endl;
            }
            if(i-1 >=0 && j+1 < noOFCloumns) {
                cout << a[i-1][j+1] << endl;
            }
            if(i+1 < noOFRows && j-1 >= 0) {
                cout << a[i+1][j-1] << endl;
            }
            if(i+1 < noOFRows && j+1 < noOFCloumns) {
                cout << a[i+1][j+1] << endl;
            }

            cout << endl;
        }

        cout << endl;
    }

    /**
     * Creating arrays in heap
     * */

    noOFRows = sizeof(b) / sizeof(int *);

    for (i = 0; i < noOFRows; i++)
    {
        b[i] = new int[4];
            for (j = 0; j < 4; j++)
            {
                b[i][j] = 2 * (i + 1)*(j + 1);
            }
    }

    for ( i = 0; i < noOFRows; i++)
    {
        for(j = 0; j < 4; j++) {
            cout << b[i][j] << endl;
        }
       cout << endl;
    }

    for (i = 0; i < noOFRows; i++) {
        if(b[i] !=NULL) {
            delete []b[i];
            b[i] = NULL;
        }
    }

    c = new int*[3];

    for (i = 0; i < 3; i++)
    {
        c[i] = new int[4];
            for (j = 0; j < 4; j++)
            {
                c[i][j] = 2 * (i + 2)*(j + 2);
            }
    }

    for ( i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++) {
            cout << c[i][j] << endl;
        }
       cout << endl;
    }

    for (i = 0; i < 3; i++) {
        if(c[i] !=NULL) {
            delete []c[i];
            c[i] = NULL;
        }
    }
    
    if(c != NULL) {
        delete []c;
        c = NULL;
    }

}