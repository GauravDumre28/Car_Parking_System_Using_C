/* File Contains Function to Search Parked Car Based on Park Slot
 * Returns: SUCCESS on Finding Car; 
 *      Otherwise FAIL.
 */

#include"Header_File.h"

NODE *search_park_slot(int **park_array, NODE *parking_details)
{
    // Declaring Variables
    int error = 0;
    int flag = 0;
    unsigned int floor_var = 0;
    unsigned int slot_var = 0;

    // Creting Temporary Pointer
    NODE *temp_ptr = parking_details;

    // Loop to Search Car
    while(1 != flag) {
        // Condition to Limit Invalid User Input
        if(3 == error) {
            return NULL;
        }

        //Initializing Variables
        flag = 0;
        floor_var = 0;
        slot_var = 0;

        // Taking Input for Floor Number
        print("\nEnter Floor Number: ");
        if(FAIL == input_integer(&floor_var)) {
            print("\n--> Error: Search Floor Number Input");
            error++;
        }
        
        // Condition to Validate Floor Number
        if(!((0 < floor_var) && (floors >= floor_var))) {
            error++;
            print("\n--> Invalid Floor Number\n");
        } else {
            // Taking Input for Slot Number
            do {
                // Condition to Limit Invalid User Input
                if(3 == error) {
                    break;
                }

                // Taking Input for Slot Number
                print("\nEnter Slot Number: ");
                if(FAIL == input_integer(&slot_var)) {
                    print("\n--> Error: Search Slot Number Input");
                    error++;
                }
                
                // Condition to Validate Slot Number
                if(!((0 < slot_var) && (parking >= slot_var))) {
                    error++;
                    print("\n--> Invalid Slot Number\n");
                } else {
                    if((1 == *(*(park_array + (floor_var - 1)) + slot_var - 1))
                        && (NULL != parking_details)) {
                        do {
                            if((floor_var == temp_ptr->floor_num) && 
                                (slot_var == temp_ptr->slot_num)) {
                                    flag = 1;
                                    break;
                                }    
                            temp_ptr = temp_ptr->next;
                        } while(parking_details != temp_ptr);

                        if(1 == flag) {
                            print("\n\t-- Car Details --");
                            print_car_details(temp_ptr);
                        }
                    } else {
                        return NULL;
                    }
                }
            } while(1 != flag);
        }       
    }

    return temp_ptr;
}