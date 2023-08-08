#include <stdio.h>
#include "finder.h"

int main() {
    struct Map map;
    // Initialize the map with appropriate values

    struct Shipment shipment;
    // Initialize the shipment with appropriate values

    struct Truck truck;
    // Initialize the truck with appropriate values

    struct Route routes[MAX_ROUTE];
    int size = 0;

    // Call the integration functions for testing

    // Test findValidTruckPaths
    findValidTruckPaths(shipment, truck, &map, routes, &size);

    // Test getBestRoute
    int bestRouteIndex = getBestRoute(routes, shipment, size);

    // Test isTruckOverloaded
    int overloaded = isTruckOverloaded(truck, shipment);
    printf("Is truck overloaded? %s\n", overloaded ? "Yes" : "No");

    // Test isBoxSizeExceeded
    float boxSize = 0.4; // Set an appropriate box size
    int boxSizeExceeded = isBoxSizeExceeded(truck, boxSize);
    printf("Does box size exceed truck capacity? %s\n", boxSizeExceeded ? "Yes" : "No");

    // Test validCargo
    float testBoxSize = 0.25; // Set a test box size
    int isValidCargo = validCargo(testBoxSize);
    printf("Is box size valid? %s\n", isValidCargo ? "Yes" : "No");

    return 0;
}
