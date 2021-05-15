/* File Contains Function to Manage User Interaction
 * Returns: FAIL on Exceeding Invalid Choice; 
 *      Otherwise SUCCESS.
 */

#include"Header_File.h"

int switch_case(int **park_array, NODE *parking_details)
{
    // Declaring Variables
    unsigned int choice = 0;
    int error = 0;

    // Loop to Manage User Interaction
    do {
        // Condition to Limit Invalid User Input
        if(3 == error) {
            return FAIL;
        }

        print("\n----------------------------------------\n");
        choice = 0;
        print("\n1. Park Car");
        print("\n2. Deport Car");
        print("\n3. Search Car");
        print("\n4. Parking Summary");
        print("\n5. Parking Record");
        print("\n11. Exit");
        print("\n\nEnter Choice: ");

        // Taking Input for User Choice
        if(FAIL == input_integer(&choice)) {
            print("\n\n--> Error: Choice Input");
        } 
        // print("\nUser Input: %d\n", choice);

        __fpurge(stdin);

        // Switch Case to Perform Operation as per User 
        switch (choice) {
            case 1:
                print("\n\n\t-- Parking Car--\n");
                print("----------------------------------------\n");
                // Calling Function to Park Car
                parking_details = park_car(park_array, parking_details);
                
                // Condition to Verify Car is Parked or Not
                if(NULL == parking_details) {
                    print("\nAlert: Unable to Park Car.\n");
                }
                break;

            case 2:
                //////////////////////////////////////////////////
                // Error in Deport Car while using Veicle Numer //
                //////////////////////////////////////////////////
                print("\n\n\t-- Deport Car --\n");
                // Calling Function to Depart Car
                parking_details = deport_car(park_array, parking_details);

                if(NULL == parking_details) {
                    print("\nAlert: Record Not Found / Error Limit Exceeds\n");
                }
                break;
            
            case 3:
                print("\n\n\t-- Search Car --\n");
                // Calling Function to Search Car
                if(NULL == search_car(park_array, parking_details)) {
                    print("\nAlert: Record Not Found / Error Limit Exceeds\n");
                }
                break;
            
            case 4:
                print("\n\n\t-- Parking Summary --\n");
                print("----------------------------------------\n");
                // Calling Function to Print Parking Summary
                print_array(park_array);
                break;
            
            case 5:
                print("\n\n\t-- Parking Record --\n");
                print("----------------------------------------\n");
                // Calling Function to Print Parking Record
                if(NULL == display_records(parking_details)) {
                    print("\nAlert: Parking Records are not Available\n");
                }
                break;
            
            default:
                if(11 != choice) {
                    print("\nInvalid Choice\n");
                    error++;
                } 
        }

        print("\n----------------------------------------\n");
    } while(11 != choice);

    return SUCCESS;
}