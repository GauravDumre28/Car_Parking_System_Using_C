/* File Contains Function to Search Parked Car Based on Vehicle Number
 * Returns: SUCCESS on Finding Car; 
 *      Otherwise FAIL.
 */

#include"Header_File.h"

NODE *search_vehicle_number(int **park_array, NODE *parking_details)
{
    // Declaring Variables
    int error = 0;
    int flag = 0;
    char vehicle_num[MAX] = "";

    // Creting Temporary Pointer
    NODE *temp_ptr = parking_details;

    if(NULL != parking_details) 
    {
        // Loop to Search Car
        while (1 != flag)
        {
            // Condition to Limit Invalid User Input
            if(3 == error)
            {
                return NULL;
            }

            // Taking Vehicle Number as Input from User
            print("\n\nEnter Vehicle Number to Search: ");
            if(NULL == fgets(vehicle_num, MAX, stdin))
            {
                print("\n\n--> Error: fgets Vehicle Number");
                error++;
            }
            else
            {
                flag = 1;
            }
        }
        print("\nVehicle Number: %s\n", vehicle_num);

        do
        {
            if(strcmp(vehicle_num, temp_ptr->vehicle_num))
            {
                flag = 1;
                break;
            }    
            temp_ptr = temp_ptr->next;
        }while(parking_details != temp_ptr);

        if(1 == flag)
        {
            print("\n-- Car Details --");
            print("\n\tFloor Number: %d", temp_ptr->floor_num);
            print("\n\tSlot Number: %d", temp_ptr->slot_num);
            print("\n\tDriver Name: %s", temp_ptr->driver_name);
            print("\tVehicle Number: %s", temp_ptr->vehicle_num);
        }
    }

    return temp_ptr;
}