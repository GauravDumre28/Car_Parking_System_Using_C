/* Filr Contains Function to Display All Parking Records */
#include"Header_File.h"

NODE *display_records(NODE *head)
{
    // Condition to Check Head Pointer
    if(NULL != head) {
        // Declaring Variables
        int count = 0;

        // Creting Temporary Pointer
        NODE *temp_ptr = head;

        // print("\nHead Pointer: %p", head);

        do {
            print("\n\t-- Car Record: %d --", ++count);
            // print("\n> Previous Pointer: %p", temp_ptr->prev);
            // Calling Function to Print Car Details
            print_car_details(temp_ptr);
            // print("> Next Pointer: %p", temp_ptr->next);
            temp_ptr = temp_ptr->next;
        } while(head != temp_ptr);
    }

    return head;
}