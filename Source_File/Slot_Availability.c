/* File Contains Function to Insert Parking Details
 * Returns: SUCCESS on Slot Availablity; 
 *      Otherwise FAIL.
 */

#include"Header_File.h"

int slot_availability(int **park_array, NODE *node_ptr)
{
    unsigned int row = node_ptr->floor_num - 1;
    unsigned int col = node_ptr->slot_num - 1;
    
    // print("\n\nRow: %d\nCol: %d\n", row, col);

    if(0 == *(*(park_array + row) + col)) {
        return SUCCESS;
    }
    
    return FAIL;
}