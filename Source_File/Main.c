#include"Header_File.h"

int main()
{
    print("\n---- Car Parking System ----\n\n");

    // Declaring Variables
    int **park_array = NULL;
    NODE *parking_details = NULL;
    floors = 0;
    parking = 0;
    // NODE * temp_ptr = NULL;
    
    // Calling Function to Create Array with Default Value -AND-
    // Condition to Check Array is Dynamically Allocated or Not
    if(NULL == (park_array = car_parking_array()))
    {
        goto EXIT;
    }
    
    // Calling Function to Print Array
    print("\n-- Parking Summary --");
    print_array(park_array);
    print("\n----------------------------------------\n");

    // Calling Function to Manage User Interaction
    if(FAIL == switch_case(park_array, parking_details))
    {
        print("\n\n-- Invalid Choice Limit Exceeds --\n");
    }
    else
    {
        print("\n\n-- Execution Completed --\n");
    }
    
    // Calling Function to Free Dynamically Allocated Memory for Array
    free_park_array(park_array);

    // Calling Function to Free Dynamically Allocated Memory for Records
    while(NULL != parking_details)
    {
        parking_details = delete_record(parking_details);
    }
    print("\n\n-- Parking Record Memory is Free --\n");
    
    EXIT:
    print("\n----------------------------------------\n");
    print("\n\t---- EXIT ----\n");
    print("\n----------------------------------------\n");

    return SUCCESS;
}