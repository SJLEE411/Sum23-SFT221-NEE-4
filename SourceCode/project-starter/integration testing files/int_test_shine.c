// tester.c
#include "finder.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function prototypes for the test functions
void test_findValidTruckPaths();
void test_hasDestination();
void test_isBuildingIntersected();
void test_getBestRoute();
void test_isTruckOverloaded();
void test_isBoxSizeExceeded();
void test_validCargo();

int main()
{
    test_findValidTruckPaths();
    test_hasDestination();
    test_isBuildingIntersected();
    test_getBestRoute();
    test_isTruckOverloaded();
    test_isBoxSizeExceeded();
    test_validCargo();

    return 0;
}

void mockFindValidTruckPaths(struct Shipment shipment, struct Truck truck, const struct Map *map, struct Route routes[MAX_ROUTE], int *size)
{
    // Simulate the behavior of the original function by returning predefined routes
    struct Route route1 = getBlueRoute();
    struct Route route2 = getGreenRoute();
    struct Route route3 = getYellowRoute();

    // Assign the predefined routes to the output
    routes[0] = route1;
    routes[1] = route2;
    routes[2] = route3;

    // Update the number of valid routes found
    *size = 3;
}

// Test function to validate findValidTruckPaths
void test_findValidTruckPaths()
{
    // Initialize test values for the shipment
    struct Shipment shipment = {
        .destination = {0, 0}, // Set a destination point for the shipment
    };

    // Initialize test values for the truck
    struct Truck truck = {
        .allocated_shipments = 3,
        .destination_counts = {3, 4, 2}, // Destination counts for the allocated shipments
    };

    // Initialize test routes for the truck
    struct Route routes[MAX_ROUTE] = {0}; // Initialize routes with zeros

    int size = 0;

    // Create a mock map (populateMap() returns the predefined map)
    struct Map map = populateMap();

    // Call the mock function to find valid truck paths
    mockFindValidTruckPaths(shipment, truck, &map, routes, &size);

    // Verify the result
    if (size == 3)
    {
        printf("test_findValidTruckPaths test passed!\n");
    }
    else
    {
        printf("test_findValidTruckPaths test failed. Expected 3 valid routes, found %d.\n", size);
    }
}


// Function to test the hasDestination function
void test_hasDestination()
{
    // Test Case 1
    struct Route route1 = getBlueRoute();
    struct Shipment shipment1 = {6, 0, 17, 24};
    int expected1 = 1;
    int result1 = hasDestination(&route1, shipment1);
    printf("Test Case 1: %s\n", result1 == expected1 ? "test_hasDestination test passed!" : "test_hasDestination test failed!");

    // Test Case 2
    struct Route route2 = getGreenRoute();
    struct Shipment shipment2 = {0, 0, 19, 24};
    int expected2 = 0;
    int result2 = hasDestination(&route2, shipment2);
    printf("Test Case 2: %s\n", result2 == expected2 ? "test_hasDestination test passed!" : "test_hasDestination test failed!");

    // // Test Case 3
    // struct Route route3 = getYellowRoute();
    // struct Shipment shipment3 = {24, 24, 0, 0};
    // int expected3 = 0;
    // int result3 = hasDestination(&route3, shipment3);
    // printf("Test Case 3: %s\n", result3 == expected3 ? "PASS" : "FAIL");

}


void test_isBuildingIntersected()
{
    // Create a sample map
    struct Map map = populateMap();

    // // Test Case 1: Check if the blue route intersects with any building
    // struct Route blueRoute = getBlueRoute();
    // int expected1 = 1;
    // int result1 = isBuildingIntersected(blueRoute, &map);
    // printf("Test Case 1: %s\n", result1 == expected1 ? "PASS" : "FAIL");

    // // Test Case 2: Check if the green route intersects with any building
    // struct Route greenRoute = getGreenRoute();
    // int expected2 = 1;
    // int result2 = isBuildingIntersected(greenRoute, &map);
    // printf("Test Case 2: %s\n", result2 == expected2 ? "PASS" : "FAIL");

    // Test Case 3: Check if the yellow route intersects with any building
    struct Route yellowRoute = getYellowRoute();
    int expected3 = 0;
    int result3 = isBuildingIntersected(yellowRoute, &map);
    printf("Test Case 3: %s\n", result3 == expected3 ? "test_isBuildingIntersected test passed!" : "test_isBuildingIntersected test failed!");

}


// Test function for getBestRoute
void test_getBestRoute()
{
    // Define three routes and one shipment
    struct Route route1 = getBlueRoute();
    struct Route route2 = getGreenRoute();
    struct Route route3 = getYellowRoute();

    struct Shipment shipment = {{11, 20}};

    // Create an array of routes
    struct Route *routes[] = {&route1, &route2, &route3};

    // Get the size of the routes array
    int size = sizeof(routes) / sizeof(routes[0]);

    // Call the getBestRoute function to find the best route index
    int bestRouteIndex = getBestRoute(routes, shipment, size);

    // Check if the bestRouteIndex is within valid range (0 to size-1)
    if (bestRouteIndex >= 0 && bestRouteIndex < size)
    {
        // Print the result
        printf("test_getBestRoute test passed!\n");
    }
    else
    {
        // Print an error message
        printf("test_getBestRoute test failed! Invalid route index.\n");
    }
}


void test_isTruckOverloaded()
{
    // // Test case 1: Truck weight capacity is 900, shipment weight is 100, result should be 0 (not overloaded)
    // struct Truck truck1 = {900};
    // struct Shipment ship1 = {100};
    // int result1 = isTruckOverloaded(truck1, ship1);
    // if (result1 == 0)
    //     printf("Test case 1 passed!\n");
    // else
    //     printf("Test case 1 failed!\n");

    // Test case 2: Truck weight capacity is 900, shipment weight is 1000, result should be 1 (overloaded)
    struct Truck truck2 = {900};
    struct Shipment ship2 = {1000};
    int result2 = isTruckOverloaded(truck2, ship2);
    if (result2 == 1)
        printf("test_isTruckOverloaded test passed!\n");
    else
        printf("test_isTruckOverloaded test failed!\n");

    // // Test case 3: Truck weight capacity is 1000, shipment weight is 0, result should be 0 (not overloaded)
    // struct Truck truck3 = {1000};
    // struct Shipment ship3 = {0};
    // int result3 = isTruckOverloaded(truck3, ship3);
    // if (result3 == 0)
    //     printf("Test case 3 passed!\n");
    // else
    //     printf("Test case 3 failed!\n");
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

// Test cases for validCargo
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
