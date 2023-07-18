#ifndef FINDER_H
#define FINDER_H
#include <stdio.h>
#include "mapping.h"
struct Truck
{
    int truck_id;
    float weight_capacity;
    float volume_capacity;
    int allocated_shipments;
    int *destination_counts;
};
struct Shipment
{
    float weight;
    float volume;
    struct Point destination;
};
// Milestone 3_ Function Specification
/**
 * Function: findValidTruckPaths
 * - Populates the "routes" array with routes that reach the given shipment destination.
 * @param shipment - Shipment struct containing the destination coordinates (row and column) of the shipment.
 * @param truck - Truck struct containing the route the truck travels on the map.
 * @param map - Map struct containing all the points (squares) in the map.
 * @param routes - Array of pointers to Route structs to store the valid routes.
 * @param size - Pointer to an integer to store the number of valid routes.
 * @returns - void, populates the "routes" array and updates the "size" variable.
 */
void findValidTruckPaths(struct Shipment shipment, struct Truck truck, const struct Map *map, struct Route *routes[MAX_ROUTE], int *size);

/**
 * Function: getBestRoute
 * - Finds the index of the route with the shortest distance among the valid routes in the "routes" array.
 * @param routes - Array of Route structs containing all the valid routes.
 * @param shipment - Shipment struct containing the destination coordinates (row and column) of the shipment.
 * @param size - Number of valid routes in the "routes" array.
 * @returns - int, the index of the route in the "routes" array with the shortest distance. Returns -1 if no valid route is found.
 */

int hasDestination(struct Route *route, struct Shipment shipment);

/**
 * Function: printRoute
 * - Prints the points (coordinates) of a route to the console.
 * @param route - Route struct containing the points (coordinates) of the route.
 * @param shipment - Shipment struct containing the destination coordinates (row and column) of the shipment.
 * @returns - void, does not return a value, only prints to the console.
 */
void printRoute(struct Route route, struct Shipment shipment);

/**
 * Function: isBuildingIntersected
 * - Checks if a given route intersects with any buildings on the map.
 * @param route - Route struct to check for intersections with buildings.
 * @param map - Map struct containing the buildings on the map.
 * @returns - int, 1 if the route intersects with a building, 0 if not.
 */
int isBuildingIntersected(const struct Route route, const struct Map *map);

int isTruckOverloaded(Truck truck, Shipment ship);

int isBoxSizeExceeded(Truck truck, float boxSize);

int vaildCargo(float boxsize);

#endif // FINDER_H
