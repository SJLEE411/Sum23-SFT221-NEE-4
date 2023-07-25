#include <stdio.h>
#include "mapping.h"

// Test Case 1 : findValidTruckPaths()
void test_addRoute()
{
    struct Map map = populateMap();
    struct Map mapWithRoute;
    struct Route route = { 'X', 1, 1, 5, 'E' };

    mapWithRoute = addRoute(&map, &route);

    // Verify if the first character of the route is correctly added to the map
    if (mapWithRoute.squares[1][1] == 'X')
        printf("addRoute test case1 passed!\n");
    else
        printf("addRoute test case1 failed!\n");
}



int main()
{
    test_addRoute();
    return 0;
}
