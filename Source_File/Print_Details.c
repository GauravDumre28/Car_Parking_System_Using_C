/* File Contains Function to Print Car Details 
 */

#include"Header_File.h"

// Function to Print Car Details 
void print_car_details (NODE *node)
{
    // Printing Car Details
    print("\nFloor Number: %d", node->floor_num);
    print("\nSlot Number: %d", node->slot_num);
    print("\nDriver Name: %s", node->driver_name);
    print("Vehicle Number: %s", node->vehicle_num);
    return;
}