/* File Contains Function to Store Parking Details
 * Returns: Pointer to the Parking Records
 */

#include"Header_File.h"

NODE *park_car(int **park_array, NODE *head)
{
    // print("\n-- Park Car Function --\n");

    // Declaring Variables
    NODE *new_ptr = (NODE *)malloc(sizeof(NODE));
    NODE *temp_ptr = NULL;

    // Condition to Insert Node
    if(NULL == head)
    {
        head = new_ptr;
        head->prev = new_ptr;
        head->next = new_ptr;
    }
    else
    {
        temp_ptr = head->prev;
        new_ptr->prev = temp_ptr;
        new_ptr->next = temp_ptr->next;
        head->prev = new_ptr;
        temp_ptr->next = new_ptr;
    }
    
    // Calling Function to Insert Parking Details
    if(FAIL == parking_details(park_array, new_ptr))
    {
        print("\n\nError: Unable to Insert Record Details\n");
        if(NULL == delete_record(new_ptr))
        {
            head = NULL;
        }
    }

    return head;
}