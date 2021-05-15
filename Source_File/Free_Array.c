/* File Contains Function to Free Array of Parking Position */

#include"Header_File.h"

void free_park_array(int **board) 
{
     // Declaring Variables
     int row;

     // First Free Each Row
     for (row = 0; row < floors; row++) {
          free(board[row]);
     }

     // Eventually Free the Memory of the Pointers to the Rows
     free(board);

     print("\n-- Park Array Memory is Free --\n");
}