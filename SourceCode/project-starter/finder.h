#ifndef FINDER_H
#define FINDER_H
#include <stdio.h>
#include "mapping.h"


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
// void findValidTruckPaths(struct Shipment shipment, struct Truck truck, const struct Map *map, struct Route *routes[MAX_ROUTE], int *size);
void findValidTruckPaths(struct Shipment shipment,struct Truck truck, const struct Route *routes[MAX_ROUTE], const struct Map *map, int *size);
/**
 * Function: getBestRoute
 * - Finds the index of the route with the shortest distance among the valid routes in the "routes" array.
 * @param routes - Array of Route structs containing all the valid routes.
 * @param shipment - Shipment struct containing the destination coordinates (row and column) of the shipment.
 * @param size - Number of valid routes in the "routes" array.
 * @returns - int, the index of the route in the "routes" array with the shortest distance. Returns -1 if no valid route is found.
 */

int hasDestination(const struct Route *route, struct Shipment shipment);

/**
 * Function: printRoute
 * - Prints the points (coordinates) of a route to the console.
 * @param route - Route struct containing the points (coordinates) of the route.
 * @param shipment - Shipment struct containing the destination coordinates (row and column) of the shipment.
 * @returns - void, does not return a value, only prints to the console.
 */
void printRoute(struct Route route, struct Shipment shipment);

/*
checks if a given route intersects with any buildings on the map.
route (const struct Route): The route to check for intersections with buildings.
map (const struct Map *): A pointer to the Map structure containing the buildings on the map.
returns an integer value: 1 if the route intersects with a building, and 0 if it does not
*/
int isBuildingIntersected(const struct Route route, const struct Map *map);

/*
finds the index of the route with the shortest distance among the valid routes in the routes array that reach the given shipment destination.
routes (struct Route *[MAX_ROUTE]): An array of pointers to Route structures representing different routes
shipment (struct Shipment): A Shipment struct containing the destination coordinates (row and column) of the shipment.
size (int): An integer representing the number of valid routes in the routes array.
returns an integer value, which is the index of the route in the routes array with the shortest distance. If no valid route is found, the function returns -1.
*/
int getBestRoute(struct Route *routes[MAX_ROUTE], struct Shipment shipment, int size);

// This function checks whether a truck is overloaded after adding a shipment to it.
// It takes two parameters, 'truck', which represents the truck with its weight capacity,
// and 'ship', which represents the shipment with its weight.
// If the truck's weight capacity is less than or equal to 1000, it adds the weight of the shipment to the truck's capacity
// and then checks if the updated capacity is still less than or equal to 1000.
// If it is, the function returns 1 (true), indicating that the truck is not overloaded.
// Otherwise, it returns 0 (false), indicating that the truck is overloaded.
int isTruckOverloaded(struct Truck truck, struct Shipment ship);

// This function checks whether a truck's volume capacity is exceeded after adding a box to it.
// It takes two parameters, 'truck', which represents the truck with its volume capacity,
// and 'boxSize', which represents the size of the box to be added.
// If the truck's volume capacity is less than or equal to 36, it adds the size of the box to the truck's capacity
// and then checks if the updated capacity is still less than or equal to 36.
// If it is, the function returns 1 (true), indicating that the box can be added without exceeding the truck's volume capacity.
// Otherwise, it returns 0 (false), indicating that the box size exceeds the truck's capacity.
int isBoxSizeExceeded(struct Truck truck, float boxSize);

// This function checks whether a given box size is valid or not.
// It takes a parameter 'boxsize', which represents the size of the box to be checked.
// The function defines three constant values 'minSize', 'halfSize', and 'maxSize' representing the valid box sizes.
// It then compares the given 'boxsize' with these constants.
// If 'boxsize' matches any of the valid sizes, the function prints "valid" and returns 1 (true), indicating that the box size is valid.
// Otherwise, it prints "invalid" and returns 0 (false), indicating that the box size is not valid.
int validCargo(float boxsize);

void postCommitHook();
void preCommitHook();
#endif // FINDER_H
