/* File Contains Function to Print Array */

#include"Header_File.h"

void print_array(int **park_array) 
{
    // Declaring Variables
    int row = 0;
    int col = 0;
    int count = 0;

    printf("\n\n");
    print("Details\t");
    while(count != parking) {
        printf("\t-%d-", ++count);
    }
    printf("\n");

    for(row = 0; row < floors; row++) {
        print("Floor %d:", row + 1);
        for (col = 0; col < parking; col++) {
            printf("\t %d", *(*(park_array + row) + col));
        }
        printf("\n");
    }
    printf("\n");

    return;
}