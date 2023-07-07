#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"

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
	printMap(&routeMap, 1, 1);

	return 0;
}
