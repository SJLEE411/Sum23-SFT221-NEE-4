#include "finder.h"
#include <stdlib.h>
#include <limits.h>

// Function to find valid truck paths that reach the given shipment destination
void findValidTruckPaths(struct Shipment shipment, struct Truck truck, const struct Map *map, struct Route *routes[MAX_ROUTE], int *size)
{
    int count = 0;
    for (int i = 0; i < truck.allocated_shipments; i++)
    {
        // Check if the truck's destination count matches the shipment's destination
        if (truck.destination_counts[i] == hasDestination(&routes[i], shipment, size, map))
        {
            // Check if the route intersects with buildings on the map
            routes[count++] = &routes[i];
        }
    }
    *size = count; // Update the number of valid routes found
}

// Function to check if a route has the given shipment destination
int hasDestination(const struct Route *route, const struct Shipment shipment, int size, const struct Map *map)
{
    for (int i = 0; i < route->numPoints; i++)
    {
        // Check if any point in the route matches the shipment's destination
        if (eqPt(route->points[i], shipment.destination))
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
