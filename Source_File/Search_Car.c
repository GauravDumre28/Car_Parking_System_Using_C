/* File Contains Function to Search Parked Car
 * Returns: SUCCESS on Finding Car; Otherwise FAIL.
 */

#include"Header_File.h"

NODE *search_car(int **park_array, NODE *parking_details)
{
    // Declaring Variables
    int error = 0;
    int flag = 0;
    unsigned int choice = 0;
    NODE *temp_ptr = NULL;

    // Loop to Search Car
    do {
        // Condition to Limit Invalid User Input
        if(3 == error) {
            print("\n\n--> Error: Maximum Input Limit for Choice");
            return NULL;
        }

        // Printing User Options
        choice = 0;
        print("----------------------------------------\n");
        print("\n1. Parking Slot");
        print("\n2. Vehicle Number");
        print("\n\nEnter Choice: ");

        // Taking Input for User Choice
        if(FAIL == input_integer(&choice)) {
            error++;
            print("\n--> Error: Choice Search Input");
        } else {
            // Switch Case to Perform Search Operation
            switch(choice) {
                case 1:
                    temp_ptr = search_park_slot(park_array, parking_details);
                    if(NULL == temp_ptr) {
                        print("\nAlert: No Record Found for Entered Car "
                            "Details.\n");
                    }
                    flag = 1;
                    break;

                case 2:
                    temp_ptr = search_vehicle_number(park_array, 
                        parking_details);
                    if(NULL == temp_ptr) {
                        print("\nAlert: No Record Found for Entered Car "
                            "Details.\n");
                    }
                    flag = 1;
                    break;
                
                default:
                    print("\n--> Invalid Search Choice\n");
                    error++;
            }
        }
        print("\n----------------------------------------\n");
    } while(1 != flag);

    return temp_ptr;
}