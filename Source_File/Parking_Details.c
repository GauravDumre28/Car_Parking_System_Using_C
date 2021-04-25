/* File Contains Function to Insert Parking Details
 * Returns: Pointer to the Parking Records
 */

#include"Header_File.h"

int parking_details(int **park_array, NODE *node_ptr)
{
    // print("\n-- Parking Details Function --\n");

    // Declaring Variables
    int error = 0;
    int flag = 0;
    int row = 0;
    int col = 0;

    // Allocating Dynamic Memory for String
    node_ptr->driver_name = (char *)malloc(sizeof(MAX * sizeof(char)));
    node_ptr->vehicle_num = (char *)malloc(sizeof(MAX * sizeof(char)));

    do
    {
        // Condition to Limit Errors
        if(3 == error)
        {
            print("\nError\n");
            return FAIL;
        }

        // Default Initialization
        node_ptr->floor_num = 0;
        node_ptr->slot_num = 0;

        __fpurge(stdin);

        print("\n\n-- Enter Details--\n");

        print("\n\t>> Available Floors for Parking:\n");
        // Loops to Find Available Floors for Parking
        for(row = 0; row < floors; row++)
        {
            for (col = 0; col < parking; col++)
            {
                if(0 == *(*(park_array + row) + col))
                {
                    print("\t\t-%d\n", row + 1);
                    break;
                }
            }
        }
        
        print("\nEnter Floor Number: ");
        // Taking Input for Floor Number
        if(FAIL == input_integer(&node_ptr->floor_num)) 
        {
            print("\n\n--> Error: Floor Number Input");
            error++;
        }
        // print("\nFloor: %d\n", node_ptr->floor_num);
        __fpurge(stdin);

        // Condition to Validate Floor Numbers
        if((0 < node_ptr->floor_num) && (floors >= node_ptr->floor_num))
        {
            print("\n\t>> Available Slots on Floor %d:\n", node_ptr->floor_num);
            // Loops to Find Available Slots for Parking
            for (col = 0; col < parking; col++)
            {
                if(0 == *(*(park_array + (node_ptr->floor_num - 1)) + col))
                {
                    print("\t\t-%d\n", col + 1);
                }
            }

            print("\nEnter Slot Number: ");
            // Taking Input for Slot Number
            if(FAIL == input_integer(&node_ptr->slot_num)) 
            {
                print("\n\n--> Error: Slot Number Input");
                error++;
            }
            // print("\nFloor: %d\n", node_ptr->slot_num);
            __fpurge(stdin);
            
            // Condition to Validate Slot Numbers
            if((0 < node_ptr->slot_num) && (parking >= node_ptr->slot_num))
            {
                // Condition to Check Available Slots
                if(SUCCESS == slot_availability(park_array, node_ptr))
                {
                    // Taking Input for Driver Name
                    print("\nEnter Driver Name: ");
                    if(NULL == fgets(node_ptr->driver_name, MAX, stdin))
                    {
                        print("\n\n--> Error: fgets Driver Name");
                        error++;
                    }
                    else
                    {
                        // print("\nDriver Name: %s", node_ptr->driver_name);
                        __fpurge(stdin);

                        // Taking for Vehicle Number
                        print("\nEnter Vehicle Number: ");
                        if(NULL == fgets(node_ptr->vehicle_num, MAX, stdin))
                        {
                            print("\n\n--> Error: fgets Vehicle Number");
                            error++;
                        }
                        else
                        {
                            // print("\nVehicle Number: %s", node_ptr->vehicle_num);
                            __fpurge(stdin);
                            flag = 1;
                        }
                    }
                }
                else
                {
                    print("\n\n-- Parking Slot is Not Available\n");
                    print("\n\n-- Available Parking Slot:");
                    print_array(park_array);
                    error++;
                }
                
            }
            else
            {
                print("\n\n-- Invalid Slot Number\n");
                error++;
            }
        }
        else
        {
            print("\n\n-- Invalid Floor Number\n");
            error++;
        }
    } while (1 != flag);

    // Condition 
    if(1 == flag)
    {
        *(*(park_array + (node_ptr->floor_num - 1)) + 
            (node_ptr->slot_num - 1)) = 1;
    }
    
    return SUCCESS;
}