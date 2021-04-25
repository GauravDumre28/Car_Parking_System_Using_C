/* File Contains Function to Move Out Parked Car
 * Returns: SUCCESS on Finding Car; 
 *      Otherwise FAIL.
 */

#include"Header_File.h"

NODE *depart_car(int **park_array, NODE *parking_details)
{
    // Declaring Variables
    int error = 0;
    int flag = 0;
    NODE *temp_ptr = parking_details;

    // Loop to Search Car
    do
    {
        // Condition to Limit Invalid User Input
        if(3 == error)
        {
            return NULL;
        }

        // Calling Function to Search Car is Parked or Not
        temp_ptr = search_car(park_array, parking_details);
        
        // Condition to Verify Parking
        if(NULL == temp_ptr)
        {
            print("\n--> Car is Not Parked\n");
            break;
        }
        else
        {
            *(*(park_array + (temp_ptr->floor_num - 1)) + 
            (temp_ptr->slot_num - 1)) = 0;

            if(NULL == (temp_ptr = delete_record(temp_ptr)))
            {
                print("\n--> No Record Present\n");
                break;
            }
            else
            {
                print("\n\nCar Moved Out of Parking Area\n");
            }  
            flag = 1;         
        }

        print("\n----------------------------------------\n");
    } while (1 != flag);

    return temp_ptr;
}