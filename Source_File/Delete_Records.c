/* File Contains Function to Delete All Records */
#include"Header_File.h"

NODE *delete_record(NODE *head)
{
    // Condition to Check Head Pointer
    if(NULL != head)
    {
        // Creating Temporary Pointer
        NODE *temp_ptr = head;

        // Condition to Check Number of Nodes
        if(head == temp_ptr->next)
        {
            head = NULL;
        }
        else
        {
            temp_ptr->next->prev = temp_ptr->prev;
            temp_ptr->prev->next = temp_ptr->next;
            head = temp_ptr->next;
        }
        
        // Calling Function to Free Dynamically Allocated Memory
        free(temp_ptr->driver_name);
        free(temp_ptr->vehicle_num);
        free(temp_ptr);
    }

    return head;
}