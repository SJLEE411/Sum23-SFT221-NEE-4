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

	 struct Truck myTruck = {800, 30.0};
    struct Shipment myShipment = {200};

	    //validCargo function
   int isValid;
    do {
        float boxSizeToCheck;
        printf("Enter cargo: ");
        scanf("%f", &boxSizeToCheck);
        isValid = validCargo(boxSizeToCheck);
    } while (isValid != 1);


	     //isBoxSizeExceeded function
        int boxExceeded;
    do {
        float boxToAdd;
        
        printf("Enter box size: ");
        scanf("%f", &boxToAdd); // Corrected the scanf statement
        
        boxExceeded = isBoxSizeExceeded(myTruck, boxToAdd);
        if (boxExceeded) {
            printf("Box can be added without exceeding the truck's volume capacity.\n");
        } else {
            printf("Box size exceeds the truck's volume capacity.\n");
        }
    } while (boxExceeded != 1);
    
    //isTruckOverloaded function
	int truckOverloaded;
	do{
    truckOverloaded = isTruckOverloaded(myTruck, myShipment);
    if (truckOverloaded) {
        printf("Truck is overloaded.\n");
    } else {
        printf("Truck is not overloaded.\n");
    }

	}while(truckOverloaded != 1);

	printMap(&routeMap, 1, 1);

	return 0;


}
