// Including Header File
#include"Header_File.h"

// Function to Convert String Data to Integer
int str_to_int(char *string, unsigned int *number)
{
    if(('\0' == *string) || ('\n' == *string)) {
        return FAIL;
    }

    while(('\0' != *string) && ('\n' != *string)){
        if(('0' <= *string) && ('9' >= *string)) {
            *number = (*number * 10) + (*string - '0');
        } else {
            return FAIL;
        }
        string++;
    }

    return SUCCESS;
}