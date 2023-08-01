#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "finder.h"

int main(void)
{
    struct Map baseMap = populateMap();
    struct Route blueRoute = getBlueRoute();
    struct Route greenRoute = getGreenRoute();
    struct Route yellowRoute = getYellowRoute();
    struct Map routeMap = addRoute(&baseMap, &blueRoute);
    routeMap = addRoute(&routeMap, &greenRoute);
    routeMap = addRoute(&routeMap, &yellowRoute);
    routeMap = addRoute(&routeMap, &blueRoute); 

    struct Shipment myShipment;
    int weight;
    float boxSize;
    char destination[3];

    while (1)
    {
        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        scanf("%d %f %s", &weight, &boxSize, destination);

        if (weight == 0 && boxSize == 0 && destination[0] == 'x')
            break;

        myShipment.weight = weight;

        if (weight < 1 || weight > 1000)
        {
            printf("Invalid weight (must be 1-1000 Kg.)\n");
            continue;
        }

        if (!validCargo(boxSize))
            continue;

        char row, col;
        if (destination[0] >= 'A' && destination[0] <= 'Z')
        {
            row = destination[0] - 'A';
            if (destination[1] >= '0' && destination[1] <= '9' && destination[2] == '\0')
            {
                col = destination[1] - '0';
                if (row >= 0 && row < routeMap.numRows && col >= 0 && col < routeMap.numCols)
                {
                    //struct Point dest = {row, col};
                    int size = 0;
                    struct Route *validRoutes[MAX_ROUTE] = {0};
                    findValidTruckPaths(myShipment, routeMap.trucks[0], &routeMap, validRoutes, &size);
                    findValidTruckPaths(myShipment, routeMap.trucks[1], &routeMap, validRoutes, &size);
                    findValidTruckPaths(myShipment, routeMap.trucks[2], &routeMap, validRoutes, &size);

                    int shortestRouteIndex = getBestRoute(validRoutes, myShipment, size);

                    if (shortestRouteIndex != -1)
                    {
                        struct Route shortestRoute = *validRoutes[shortestRouteIndex];
                        printf("Ship on ");
                        if (shortestRoute.routeSymbol == BLUE)
                            printf("BLUE LINE");
                        else if (shortestRoute.routeSymbol == GREEN)
                            printf("GREEN LINE");
                        else if (shortestRoute.routeSymbol == YELLOW)
                            printf("YELLOW LINE");
                        printf(", no diversion\n");
                    }
                    else
                    {
                        printf("No valid route found to the destination\n");
                    }
                }
                else
                {
                    printf("Invalid destination\n");
                }
            }
            else
            {
                printf("Invalid destination\n");
            }
        }
        else
        {
            printf("Invalid destination\n");
        }
    }

    printf("Thanks for shipping with Seneca!\n");
    return 0;
}
