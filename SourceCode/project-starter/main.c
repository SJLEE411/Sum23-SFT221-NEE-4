#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "finder.h"

// int main(void)
// {
// 	struct Map baseMap = populateMap();
// 	struct Route blueRoute = getBlueRoute();
// 	struct Route greenRoute = getGreenRoute();
// 	struct Route yellowRoute = getYellowRoute();
// 	struct Map routeMap = addRoute(&baseMap, &blueRoute);
// 	routeMap = addRoute(&routeMap, &greenRoute);
// 	routeMap = addRoute(&routeMap, &yellowRoute);
// 	routeMap = addRoute(&routeMap, &blueRoute);

// 	 struct Truck myTruck = {800, 30.0};
//     struct Shipment myShipment = {200};

// 	    //validCargo function
//    int isValid;
//     do {
//         float boxSizeToCheck;
//         printf("Enter cargo: ");
//         scanf("%f", &boxSizeToCheck);
//         isValid = validCargo(boxSizeToCheck);
//     } while (isValid != 1);

// 	     //isBoxSizeExceeded function
//         int boxExceeded;
//     do {
//         float boxToAdd;

//         printf("Enter box size: ");
//         scanf("%f", &boxToAdd); // Corrected the scanf statement

//         boxExceeded = isBoxSizeExceeded(myTruck, boxToAdd);
//         if (boxExceeded) {
//             printf("Box can be added without exceeding the truck's volume capacity.\n");
//         } else {
//             printf("Box size exceeds the truck's volume capacity.\n");
//         }
//     } while (boxExceeded != 1);

//     //isTruckOverloaded function
// 	int truckOverloaded;
// 	do{
//     truckOverloaded = isTruckOverloaded(myTruck, myShipment);
//     if (truckOverloaded) {
//         printf("Truck is overloaded.\n");
//     } else {
//         printf("Truck is not overloaded.\n");
//     }

// 	}while(truckOverloaded != 1);

// 	printMap(&routeMap, 1, 1);

// 	return 0;

// }

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
    const struct Route **validRoutes[MAX_ROUTE] = {0};

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

        int row, col;
        if (destination[0] >= 'A' && destination[0] <= 'Z')
        {
            row = destination[0] - 'A';
            if (destination[1] >= '0' && destination[1] <= '9' && destination[2] == '\0')
            {
                col = destination[1] - '0';
                if (row >= 0 && row < routeMap.numRows && col >= 0 && col < routeMap.numCols)
                {
                    struct Point dest = {row, col};
                    int size = 0;
                    struct Route *validRoutes[MAX_ROUTE] = {0};
                    // findValidTruckPaths(myShipment, validRoutes, &size, &routeMap);
                    // int size = 0;
                    findValidTruckPaths(myShipment, (const struct Route **)validRoutes, &size, &routeMap);

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
