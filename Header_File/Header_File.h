// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

// Constatnts
#define print printf
#define MAX 20
#define SUCCESS 0
#define FAIL 1

// Global Variables
unsigned int floors;
unsigned int parking;

// Structure to Store Car Parking Data
typedef struct LL_Node{
    struct LL_Node *prev;
    char *driver_name;
    char *vehicle_num;
    unsigned int floor_num;
    unsigned int slot_num;
    struct LL_Node *next;
} NODE;

// Function to Convert String Data to Integer
int str_to_int(char*, unsigned int*);

// Function to Validate the Input as Integer
int input_integer(unsigned int *);

// Function to Create Array to Store Parking Position
int **car_parking_array();

//Function to Free Array of Parking Position
void free_park_array(int **);

// File Contains Function to Print Array
void print_array(int **);

// Function to Manage User Interaction 
int switch_case(int **, NODE *);

// Function to Store Parking Details
NODE *park_car(int **, NODE *);

// Function to Insert Parking Details
int parking_details(int **, NODE *);

// Function to Display Parking Records
NODE *display_records(NODE *);

// Function to Delete All Records
NODE *delete_record(NODE *);

// Function to Insert Parking Details
int slot_availability(int **, NODE *);

//Function to Search Parked Car
NODE *search_car(int **, NODE *);

//Function to Search Parked Car Based on Park Slot
NODE *search_park_slot(int **, NODE *);

//Function to Search Parked Car Based on Vehicle Number
NODE *search_vehicle_number(int **, NODE *);

// Function to Move Out Parked Car
NODE *depart_car(int **, NODE *);