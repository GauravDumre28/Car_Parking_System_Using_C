/* File Contains Function to Create Array to Store Parking Position
 * Returns: Dynamically Allocated Array Pointer
 */

#include"Header_File.h"

int **car_parking_array()
{
    // Declaring Variables
    int **board = NULL;
    int row = 0;
    int col = 0;
    int error = 0;
    int flag = 0;

    // Loop to Manage User Interaction
    do
    {
        // Condition to Verify Invalid User Input
        if(3 == error)
        {
            return NULL;
        }
        
        // Taking Input for Number of Floors
        print("\nEnter Number of Floors: ");
        if(SUCCESS == input_integer(&floors)) 
        {
            // print("\nFloors: %d", floors);

            do
            {
                // Taking Input for Number of Parkings
                print("\nEnter Number of Parkings Per Floor: ");
                if(SUCCESS == input_integer(&parking)) 
                { 
                    // print("\nParking: %d", parking);

                    // Dynamically Allocating Rows (Floors) to Array
                    board = (int **)malloc(floors * sizeof(int *));

                    // Condition to Check Dynamic Allocation of Array
                    if(NULL == board)
                    {
                        return NULL;
                    }

                    // Loop to Dynamically Allocate Parkings Slots to Array
                    for(row = 0; row < floors; row++) 
                    {
                        board[row] = (int *)malloc(parking * sizeof(int));

                        // Condition to Check Dynamic Allocation of Array
                        if(NULL == board[row])
                        {
                            return NULL;
                        }
                    }

                    // Assigning Default Value '0' to Array
                    for(row = 0; row < floors; row++)
                    {
                        for (col = 0; col < parking; col++)
                        {
                            *(board[row] + col) = 0;
                        }
                    }
                    **board = 1;    // Evaluated as *(*(board + 0) + 0) = 1;
                    flag = 1;
                }
                else
                {
                    print("\n\n--> Error: Number of Parkings Input\n");
                    error++;
                    parking = 0;
                }
            }while(1 != flag);
        }
        else
        {
            print("\n\n--> Error: Number of Floors Input\n");
            error++;
            floors = 0;
        }
    }while(1 != flag);

    return board;
}