#include <stdio.h>
#include "mapping.h"


// Test case for add_route()
// August 8 fixed from
/*
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
*/
void test_addRoute()
{
    struct Map map = populateMap();
    struct Map mapWithRoute;
    struct Route route = { 0 }; // Initialize route with default values
    route.numPoints = 4;
    route.routeSymbol = 'X';
    route.points[0] = (struct Point){ 1, 1 };
    route.points[1] = (struct Point){ 1, 2 };
    route.points[2] = (struct Point){ 1, 3 };
    route.points[3] = (struct Point){ 1, 4 };

    mapWithRoute = addRoute(&map, &route);

    // Verify if the route symbol is correctly added to the map
    if (mapWithRoute.squares[1][1] == 'X')
        printf("addRoute test case passed!\n");
    else
        printf("addRoute test case failed!\n");
}

int main()
{
    test_addRoute();
    return 0;
}
