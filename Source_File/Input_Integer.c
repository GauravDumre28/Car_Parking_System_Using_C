/* File Contains Function to Validate the Input as Integer */

#include"Header_File.h"

int input_integer(unsigned int *number)
{
    // Declaring Variables
    char str[MAX] = "";
    
    // Taing Input for as String from Stdin File
    if(NULL == fgets(str, MAX, stdin))
    {
        print("\n\n--> Error: fgets");
        return FAIL;
    }

    // Calling Function to Convert & Validate Integer
    if(FAIL == str_to_int(str, number))
    {
        print("\n\n--> Error: String is Empty / Non-Integer\n");
        return FAIL;
    }

    return SUCCESS;
}