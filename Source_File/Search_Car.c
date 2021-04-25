/* File Contains Function to Search Parked Car
 * Returns: SUCCESS on Finding Car; 
 *      Otherwise FAIL.
 */

#include"Header_File.h"

NODE *search_car(int **park_array, NODE *parking_details)
{
    // Declaring Variables
    int error = 0;
    unsigned int choice = 0;
    NODE *temp_ptr = NULL;

    // Loop to Search Car
    do
    {
        // Condition to Limit Invalid User Input
        if(3 == error)
        {
            return NULL;
        }

        // Printing User Options
        print("\n----------------------------------------\n");
        choice = 0;
        print("\n1. Parking Slot");
        print("\n2. Vehicle Number");
        print("\n5. Exit");
        print("\n\nHow You Want to Search Car: ");

        // Taking Input for User Choice
        if(FAIL == input_integer(&choice)) 
        {
            error++;
            print("\n\n--> Error: Choice Search Input");
        }
        else
        {
            // Switch Case to Perform Search Operation
            switch(choice)
            {
                case 1:
                    temp_ptr = search_park_slot(park_array, parking_details);
                    if(NULL == temp_ptr)
                    {
                        print("\nAlert: No Record Found for Entered Car "
                            "Details.\n");
                    }
                    break;

                case 2:
                    temp_ptr = search_vehicle_number(park_array, 
                        parking_details);
                    if(NULL == temp_ptr)
                    {
                        print("\nAlert: No Record Found for Entered Car "
                            "Details.\n");
                    }
                    break;
                
                default:
                    if(5 != choice)
                    {
                        print("\n--> Invalid Search Choice\n");
                        error++;
                    }
            }
        }
        print("\n----------------------------------------\n");
    } while (5 != choice);

    return temp_ptr;
}