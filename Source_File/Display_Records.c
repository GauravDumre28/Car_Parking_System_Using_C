/* Filr Contains Function to Display All Parking Records */
#include"Header_File.h"

NODE *display_records(NODE *head)
{
    // Condition to Check Head Pointer
    if(NULL != head)
    {
        // Declaring Variables
        int count = 0;

        // Creting Temporary Pointer
        NODE *temp_ptr = head;

        print("\nHead Pointer: %p", head);

        do{
            print("\n\n--> Record %d:", ++count);
            print("\n\t> Previous Pointer: %p", temp_ptr->prev);
            print("\n\tFloor Number: %d", temp_ptr->floor_num);
            print("\n\tSlot Number: %d", temp_ptr->slot_num);
            print("\n\tDriver Name: %s", temp_ptr->driver_name);
            print("\tVehicle Number: %s", temp_ptr->vehicle_num);
            print("\t> Next Pointer: %p", temp_ptr->next);
            temp_ptr = temp_ptr->next;
        } while(head != temp_ptr);
    }

    return head;
}