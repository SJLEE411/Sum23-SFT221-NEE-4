#include <stdio.h>
#include "mapping.h"
#include "finder.h"

// Define a function to perform integration testing
void integrationTest()
{
    // Populate the map
    struct Map baseMap = populateMap();

    // Get routes
    struct Route blueRoute = getBlueRoute();
    struct Route greenRoute = getGreenRoute();
    struct Route yellowRoute = getYellowRoute();

    // Add routes to the map
    struct Map routeMap = addRoute(&baseMap, &blueRoute);
    routeMap = addRoute(&routeMap, &greenRoute);
    routeMap = addRoute(&routeMap, &yellowRoute);

    // Create a shipment and test functions
    struct Shipment myShipment;
    myShipment.destination.row = 10;
    myShipment.destination.col = 10;
    myShipment.weight = 500;
    float boxSize = 0.5;

    // Find valid truck paths
    struct Route validRoutes[MAX_ROUTE];
    int size = 0;
    findValidTruckPaths(myShipment, routeMap.trucks[0], &routeMap, validRoutes, &size);
    findValidTruckPaths(myShipment, routeMap.trucks[1], &routeMap, validRoutes, &size);
    findValidTruckPaths(myShipment, routeMap.trucks[2], &routeMap, validRoutes, &size);

    // Get the best route
    int shortestRouteIndex = getBestRoute(validRoutes, myShipment, size);

    if (shortestRouteIndex != -1)
    {
        struct Route shortestRoute = validRoutes[shortestRouteIndex];
        printf("Best route to destination:\n");
        printRoute(shortestRoute, myShipment);
    }
    else
    {
        printf("No valid route found to the destination\n");
    }
}

int main(void)
{
    integrationTest();
    return 0;
}
