#define _CRT_SECURE_NO_WARNINGS
#include "finder.h"
#include "mapping.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void test_hasDestination();
void test_isTruckOverloaded();
void test_isBoxSizeExceeded();
void test_validCargo();


int main()
{
    test_hasDestination();
    test_isTruckOverloaded();
    test_isBoxSizeExceeded();
    test_validCargo();

    return 0;
}

// Test cases for hasDestination
// August 8 fixed from    
/*
    void test_hasDestination()
    {
        // Define and initialize the necessary structures and variables for testing
        struct Shipment shipment;
        shipment.destination.row = 5;
        shipment.destination.col = 5;

        struct Route route;
        // Initialize the route as required for testing

        // Test the function
        int result = hasDestination(&route, shipment);

        // Print the results
        printf("test_hasDestination ");
        if (result == 1)
        {
            printf("test passed!\n");
        }
        else
        {
            printf("test failed!\n");
        }
    }
*/
void test_hasDestination()
{
    struct Shipment shipment;
    shipment.destination.row = 5;
    shipment.destination.col = 5;

    struct Route route;
    route.numPoints = 3; 
    route.points[0] = (struct Point){ 3, 3 };
    route.points[1] = (struct Point){ 4, 4 };
    route.points[2] = (struct Point){ 5, 5 }; 

    // Test the function
    int result = hasDestination(&route, shipment);

    // Print the results
    printf("test_hasDestination ");
    if (result == 1)
    {
        printf("test passed!\n");
    }
    else
    {
        printf("test failed!\n");
    }
}

// Test cases for isTruckOverloaded
void test_isTruckOverloaded()
{
    // Define and initialize the necessary structures and variables for testing
    struct Truck truck;
    // Initialize the truck as required for testing

    struct Shipment ship;
    // Initialize the shipment as required for testing

    // Test the function
    int result = isTruckOverloaded(truck, ship);

    // Print the results
    printf("test_isTruckOverloaded ");
    if (result == 1)
    {
        printf("test passed!\n");
    }
    else
    {
        printf("test failed!\n");
    }
}

// Test cases for isBoxSizeExceeded
void test_isBoxSizeExceeded()
{
    // Define and initialize the necessary structures and variables for testing
    struct Truck truck;
    // Initialize the truck as required for testing

    float boxSize = 5.0; // Set the boxSize value as required for testing

    // Test the function
    int result = isBoxSizeExceeded(truck, boxSize);

    // Print the results
    printf("test_isBoxSizeExceeded ");
    if (result == 1)
    {
        printf("test passed!\n");
    }
    else
    {
        printf("test failed!\n");
    }
}


// Test cases for vaildCargo
void test_validCargo()
{
    // Define and initialize the necessary structures and variables for testing
    float boxSize = 0.5; // Set the boxSize value as required for testing

    // Test the function
    int result = validCargo(boxSize);

    // Print the results
    printf("test_validCargo ");
    if (result == 1)
    {
        printf("test passed!\n");
    }
    else
    {
        printf("test failed!\n");
    }
}

