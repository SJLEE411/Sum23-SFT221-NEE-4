#include "finder.h"
#include <stdlib.h>
#include <limits.h>

// Function to find valid truck paths that reach the given shipment destination
void findValidTruckPaths(struct Shipment shipment, struct Truck truck, const struct Map *map, struct Route routes[MAX_ROUTE], int *size)
{
    int count = 0;
    for (int i = 0; i < truck.allocated_shipments; i++)
    {
        // Check if the truck's destination count matches the shipment's destination
        if (truck.destination_counts[i] == hasDestination(&routes[i], shipment))
        {
            // Check if the route intersects with buildings on the map
            if (!isBuildingIntersected(routes[i], map))
            {
                routes[count++] = routes[i];
            }
        }
    }              // zxczxc
    *size = count; // Update the number of valid routes found
}

// Function to check if a route has the given shipment destination
int hasDestination(const struct Route *route, struct Shipment shipment)
{
    for (int i = 0; i < route->numPoints; i++)
    {
        // Check if the current point in the route matches the shipment's destination
        if (route->points[i].row == shipment.destination.row && route->points[i].col == shipment.destination.col)
        {
            return 1; // The route has the shipment's destination
        }
    }
    return 0; // The route does not have the shipment's destination
}

// Function to print the points (coordinates) of a route
void printRoute(struct Route route, struct Shipment shipment)
{
    printf("Route to Shipment (Destination: (%d, %d)):\n", shipment.destination.row, shipment.destination.col);
    for (int i = 0; i < route.numPoints; i++)
    {
        printf("(%d, %d) ", route.points[i].row, route.points[i].col);
    }
    printf("\n");
}

// Function to check if a given route intersects with any buildings on the map
int isBuildingIntersected(const struct Route route, const struct Map *map)
{
    for (int i = 0; i < route.numPoints; i++)
    {
        // Check if the point in the route is a building on the map
        if (map->squares[route.points[i].row][route.points[i].col] == 2)
        {
            return 1; // The route intersects with a building
        }
    }
    return 0; // The route does not intersect with any buildings
}

// Function to get the index of the route with the shortest distance among valid routes
int getBestRoute(struct Route *routes[MAX_ROUTE], struct Shipment shipment, int size)
{
    int shortestDistance = INT_MAX;
    int shortestIndex = -1;

    for (int i = 0; i < size; i++)
    {
        // Calculate the distance from the route's starting point to the shipment's destination
        int routeDistance = distance(&routes[i]->points[0], &shipment.destination);
        if (routeDistance < shortestDistance)
        {
            // Update the shortest distance and corresponding index
            shortestDistance = routeDistance;
            shortestIndex = i;
        }
    }

    return shortestIndex; // Return the index of the route with the shortest distance
}

// This function checks whether a truck is overloaded after adding a shipment to it.
// It takes two parameters, 'truck', which represents the truck with its weight capacity,
// and 'ship', which represents the shipment with its weight.
// If the truck's weight capacity is less than or equal to 1000, it adds the weight of the shipment to the truck's capacity
// and then checks if the updated capacity is still less than or equal to 1000.
// If it is, the function returns 1 (true), indicating that the truck is not overloaded.
// Otherwise, it returns 0 (false), indicating that the truck is overloaded.
int isTruckOverloaded(struct Truck truck, struct Shipment ship)
{
    int result = 0;

    if (truck.weight_capacity <= 1000)
    {
        truck.weight_capacity += ship.weight;

        if (truck.weight_capacity <= 1000)
        {
            result = 1;
        }
    }

    return result;
}

// This function checks whether a truck's volume capacity is exceeded after adding a box to it.
// It takes two parameters, 'truck', which represents the truck with its volume capacity,
// and 'boxSize', which represents the size of the box to be added.
// If the truck's volume capacity is less than or equal to 36, it adds the size of the box to the truck's capacity
// and then checks if the updated capacity is still less than or equal to 36.
// If it is, the function returns 1 (true), indicating that the box can be added without exceeding the truck's volume capacity.
// Otherwise, it returns 0 (false), indicating that the box size exceeds the truck's capacity.
int isBoxSizeExceeded(struct Truck truck, float boxSize)
{
    int result = 0;

    if (truck.volume_capacity <= 36)
    {
        truck.volume_capacity += boxSize;

        if (truck.volume_capacity <= 36)
        {
            result = 1;
        }
    }

    return result;
}

// This function checks whether a given box size is valid or not.
// It takes a parameter 'boxsize', which represents the size of the box to be checked.
// The function defines three constant values 'minSize', 'halfSize', and 'maxSize' representing the valid box sizes.
// It then compares the given 'boxsize' with these constants.
// If 'boxsize' matches any of the valid sizes, the function prints "valid" and returns 1 (true), indicating that the box size is valid.
// Otherwise, it prints "invalid" and returns 0 (false), indicating that the box size is not valid.
int validCargo(float boxsize)
{
    const double minSize = 0.25;
    const double halfSize = 0.5;
    const double maxSize = 1.0;
    int result = 0;

    if (boxsize == minSize || boxsize == halfSize || boxsize == maxSize)
    {
        // printf("Box size is valid.\n"); // Corrected the printf statement
        result = 1;
    }
    else
    {
        printf("Box size is not valid.\n");
    }

    return result;
}

void postCommitHook()
{

    printf("This edit is to test post commit hook");
}

void preCommitHook()
{
    printf("another test");
}