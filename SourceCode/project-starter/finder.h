#ifndef FINDER_H
#define FINDER_H

#include "mapping.h"
struct Truck {
    int truck_id;
    float weight_capacity;
    float volume_capacity;
    int allocated_shipments;
    int* destination_counts;
};

struct Building {
    int building_id;
    float x;
    float y;
    int is_obstacle;
    int* adjacency_matrix;
};

struct PathRequest {
    int start_building_id;
    int destination_building_id;
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
void findValidTruckPaths(struct Shipment shipment, struct Truck truck, const struct Map* map, struct Route* routes[MAX_ROUTE], int* size);


/**
 * Function: getBestRoute
 * - Finds the index of the route with the shortest distance among the valid routes in the "routes" array.
 * @param routes - Array of Route structs containing all the valid routes.
 * @param shipment - Shipment struct containing the destination coordinates (row and column) of the shipment.
 * @param size - Number of valid routes in the "routes" array.
 * @returns - int, the index of the route in the "routes" array with the shortest distance. Returns -1 if no valid route is found.
 */
int findBestRoute(struct Route routes[MAX_ROUTE], struct Shipment shipment, int size);


/**
 * Function: hasDestination
 * - Checks if the given route contains the destination coordinates of the shipment.
 * @param route - Pointer to a Route struct representing a calculated route.
 * @param shipment - Shipment struct containing the destination coordinates (row and column) of the shipment.
 * @returns - int, 1 if the destination is in the route, 0 if not.
*/
int hasDestination(struct Route* route, struct Shipment shipment);


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
int isBuildingIntersected(const struct Route route, const struct Map* map);


#endif  // FINDER_H
