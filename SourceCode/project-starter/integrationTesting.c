#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "finder.h"

// #1 Test cases for isTruckOverloaded
void integrationTest_isTruckOverloaded()
{
    // Test case 1: Truck's weight capacity is not exceeded
    struct Truck truck1 = { 800 };
    struct Shipment shipment1 = { 200 }; 
    int result1 = isTruckOverloaded(truck1, shipment1);
    printf("Test case 1: Expected: 1, Result: %d\n", result1);

    // Test case 2: Truck's weight capacity is exactly 1000
    struct Truck truck2 = { 1000 }; 
    struct Shipment shipment2 = { 0 }; 
    int result2 = isTruckOverloaded(truck2, shipment2);
    printf("Test case 2: Expected: 1, Result: %d\n", result2);

    // Test case 3: Truck's weight capacity is exceeded
    struct Truck truck3 = { 700 }; 
    struct Shipment shipment3 = { 350 };
    int result3 = isTruckOverloaded(truck3, shipment3);
    printf("Test case 3: Expected: 0, Result: %d\n", result3);

    // Test case 4: Truck's weight capacity is exactly 1000, and shipment weight exceeds it
    struct Truck truck4 = { 1000 }; 
    struct Shipment shipment4 = { 1500 }; 
    int result4 = isTruckOverloaded(truck4, shipment4);
    printf("Test case 4: Expected: 0, Result: %d\n", result4);
}

// #2 Test cases for isBoxSizeExceeded
void integrationTest_isBoxSizeExceeded()
{
    // Test case 1: Box size doesn't exceed the truck's capacity
    struct Truck truck1 = { 20.0f }; 
    float boxSize1 = 10.0f;
    int result1 = isBoxSizeExceeded(truck1, boxSize1);
    printf("Test case 1: Expected: 1, Result: %d\n", result1);

    // Test case 2: Box size exactly matches the truck's capacity
    struct Truck truck2 = { 10.0f }; 
    float boxSize2 = 10.0f; 
    int result2 = isBoxSizeExceeded(truck2, boxSize2);
    printf("Test case 2: Expected: 1, Result: %d\n", result2);

    // Test case 3: Box size exceeds the truck's capacity
    struct Truck truck3 = { 5.0f }; 
    float boxSize3 = 10.0f; 
    int result3 = isBoxSizeExceeded(truck3, boxSize3);
    printf("Test case 3: Expected: 0, Result: %d\n", result3);

    // Test case 4: Truck's capacity is exactly 36.0
    struct Truck truck4 = { 36.0f };
    float boxSize4 = 5.0f; 
    int result4 = isBoxSizeExceeded(truck4, boxSize4);
    printf("Test case 4: Expected: 1, Result: %d\n", result4);

    // Test case 5: Truck's capacity is exactly 36.0, and box size exceeds it
    struct Truck truck5 = { 36.0f }; 
    float boxSize5 = 50.0f; 
    int result5 = isBoxSizeExceeded(truck5, boxSize5);
    printf("Test case 5: Expected: 0, Result: %d\n\n", result5);
}

// #3. Test cases for validCargo
void integrationTest_validCargo()
{
    // Test case 1: Valid box size (0.25)
    float boxSize6 = 0.25;
    int result6 = validCargo(boxSize6);
    printf("Test case 1: Expected: 1, Result: %d\n", result6);

    // Test case 2: Valid box size (0.5)
    float boxSize7 = 0.5;
    int result7 = validCargo(boxSize7);
    printf("Test case 2: Expected: 1, Result: %d\n", result7);

    // Test case 3: Valid box size (1.0)
    float boxSize8 = 1.0;
    int result8 = validCargo(boxSize8);
    printf("Test case 3: Expected: 1, Result: %d\n", result8);

    // Test case 4: Invalid box size (0.3)
    float boxSize9 = 0.3;
    int result9 = validCargo(boxSize9);
    printf("Test case 4: Expected: 0, Result: %d\n", result9);

    // Test case 5: Invalid box size (1.5)
    float boxSize10 = 1.5;
    int result10 = validCargo(boxSize10);
    printf("Test case 5: Expected: 0, Result: %d\n", result10);
}

// #4. Test cases for getBestRoute
void integrationTest_getBestRoute()
{
    // Test case 1: Single route, shortest distance
    struct Point point1 = { 0, 0 };
    struct Point point2 = { 3, 4 };
    struct Point point3 = { 5, 5 };
    struct Route route1 = { {point1, point2, point3}, 3 }; // Route with three points
    struct Route* routes1[MAX_ROUTE] = { &route1 };
    struct Shipment shipment1 = { 0, 0, {5, 5} };
    int size1 = 1;

    int result1 = getBestRoute(routes1, shipment1, size1);
    printf("Test case 1: Expected: 0, Result: %d\n", result1);

    // Test case 2: Multiple routes, different distances
    struct Point point4 = { 0, 0 };
    struct Point point5 = { 1, 1 };
    struct Point point6 = { 3, 3 };
    struct Point point7 = { 5, 5 };
    struct Route route2 = { {point4, point5, point6}, 3 }; // Route with three points
    struct Route route3 = { {point7, point4, point5, point6}, 4 }; // Route with four points
    struct Route* routes2[MAX_ROUTE] = { &route2, &route3 };
    struct Shipment shipment2 = { 0, 0, {5, 5} };
    int size2 = 2;

    int result2 = getBestRoute(routes2, shipment2, size2);
    printf("Test case 2: Expected: 1, Result: %d\n", result2);
}

// #5. Test cases for isBuildingIntersected
void integrationTest_isBuildingIntersected()
{
    // Test case 1: Route does not intersect with any buildings
    struct Point point1 = { 0, 0 };
    struct Point point2 = { 1, 1 };
    struct Point point3 = { 2, 2 };
    struct Route route1 = { {point1, point2, point3}, 3 }; // Route with three points
    struct Map map1 = {
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        }
    };

    int result1 = isBuildingIntersected(route1, &map1);
    printf("Test case 1: Expected: 0, Result: %d\n", result1);

    // Test case 2: Route intersects with a building
    struct Point point4 = { 1, 1 };
    struct Point point5 = { 2, 2 };
    struct Point point6 = { 1, 2 };
    struct Route route2 = { {point4, point5, point6}, 3 }; // Route with three points
    struct Map map2 = {
        {
            {0, 0, 0},
            {0, 2, 0},
            {0, 0, 0}
        }
    };

    int result2 = isBuildingIntersected(route2, &map2);
    printf("Test case 2: Expected: 1, Result: %d\n", result2);
}

// #6. Test cases for hasDestination
void integrationTest_hasDestination()
{
    // Test case 1: Shipment destination is present in the route
    struct Point point1 = { 0, 0 };
    struct Point point2 = { 1, 1 };
    struct Point point3 = { 2, 2 };
    struct Point destination1 = { 2, 2 };
    struct Route route1 = { {point1, point2, point3}, 3 }; // Route with three points
    struct Shipment shipment1 = { 0, 0, destination1 };

    int result1 = hasDestination(&route1, shipment1);
    printf("Test case 1: Expected: 1, Result: %d\n", result1);

    // Test case 2: Shipment destination is not present in the route
    struct Point point4 = { 1, 1 };
    struct Point point5 = { 2, 2 };
    struct Point point6 = { 1, 2 };
    struct Point destination2 = { 0, 0 };
    struct Route route2 = { {point4, point5, point6}, 3 }; // Route with three points
    struct Shipment shipment2 = { 0, 0, destination2 };

    int result2 = hasDestination(&route2, shipment2);
    printf("Test case 2: Expected: 0, Result: %d\n", result2);
}

// #7. Test cases for printRoute
void integrationTest_printRoute()
{
    // Test case 1: Route with three points and a destination
    struct Point point1 = { 0, 0 };
    struct Point point2 = { 1, 1 };
    struct Point point3 = { 2, 2 };
    struct Point destination1 = { 2, 2 };
    struct Route route1 = { {point1, point2, point3}, 3 }; // Route with three points
    struct Shipment shipment1 = { 0, 0, destination1 };

    printf("Test case 1:\n");
    printRoute(route1, shipment1);

    // Test case 2: Route with four points and a destination
    struct Point point4 = { 1, 1 };
    struct Point point5 = { 2, 2 };
    struct Point point6 = { 1, 2 };
    struct Point point7 = { 2, 1 };
    struct Point destination2 = { 2, 1 };
    struct Route route2 = { {point4, point5, point6, point7}, 4 }; // Route with four points
    struct Shipment shipment2 = { 0, 0, destination2 };

    printf("Test case 2:\n");
    printRoute(route2, shipment2);
}

int main()
{
    printf("#1.Test cases for isTruckOverloaded\n");
    integrationTest_isTruckOverloaded();
    printf("\n");

    printf("#2.Test cases for isBoxSizeExceeded\n");
    integrationTest_isBoxSizeExceeded();
    printf("\n");

    printf("#3.Test cases for validCargo\n");
    integrationTest_validCargo();
    printf("\n");

    printf("#4.Test cases for getBestRoute\n");
    integrationTest_getBestRoute();
    printf("\n");

    printf("#5.Test cases for isBuildingIntersected\n");
    integrationTest_isBuildingIntersected();
    printf("\n");

    printf("#6.Test cases for hasDestination\n");
    integrationTest_hasDestination();
    printf("\n");

    printf("#7.Test cases for printRoute\n");
    integrationTest_printRoute();
    return 0;
}
