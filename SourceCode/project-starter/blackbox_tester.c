#include <stdio.h>
#include "mapping.h"

// Test Case 1: populateMap()
void test_populateMap()
{
    struct Map map = populateMap();

    // Verify the number of rows and columns
    if (map.numRows == 25 && map.numCols == 25)
        printf("populateMap test passed!\n");
    else
        printf("populateMap test failed!\n");
        printf("\n");
}



// Test 2: printMap() // DEF1 and DEF2 has been resolved with new testing functions
// Helper function to check if the map coordinates are correct
int checkMapCoordinates(const struct Map* map) {
    int rowMax = map->numRows;
    int colMax = map->numCols;

    for (int r = 0; r < rowMax; r++) {
        if (r + 1 < 1 || r + 1 > 25) {
            printf("Row coordinate out of range: %d\n", r + 1);
            return 0;
        }
        for (int c = 0; c < colMax; c++) {
            if (c < 0 || c >= 25) {
                printf("Column coordinate out of range: %d\n", c);
                return 0;
            }
        }
    }
    return 1;
}

// Helper function to print the map
void testPrintMap(const struct Map* map) {
    char sym[] = " XB?G?.?Y?-?*?+?P";
    int rowMax = map->numRows;

    printf("%4s", " ");
    for (int c = 0; c < map->numCols; c++) {
        printf("%c", 'A' + c);
    }
    printf("\n");
    printf("%4s", " ");
    for (int c = 0; c < map->numCols; c++) {
        printf("-");
    }
    printf("\n");

    for (int r = 1; r <= rowMax; r++) {
        printf("%3d|", r);
        for (int c = 0; c < map->numCols; c++) {
            printf("%c", sym[map->squares[r - 1][c]]);
        }
        printf("\n");
    }
}

// Test printMap function
void test_printMap() {
    // Test case 1: base1 = 1, alphaCols = 1
    struct Map map1 = populateMap();
    printf("*** PrintMap Test case 1:\n");
    printMap(&map1, 1, 1);
    printf("\n");
    if (checkMapCoordinates(&map1))
        printf(": printMap Test case 1 passed!\n\n");
    else
        printf(": printMap Test case 1 failed!\n\n");

    // Test case 2: base1 = 10, alphaCols = 0
    struct Map map2 = populateMap();
    printf("*** PrintMap Test case 2:\n");
    printMap(&map2, 10, 0);
    printf("\n");
    if (!checkMapCoordinates(&map2))
        printf(": printMap Test case 2 passed!\n\n");
    else
        printf(": printMap Test case 2 failed!\n\n");

    // Test case 3: base1 = 20, alphaCols = 1
    struct Map map3 = populateMap();
    printf("*** PrintMap Test case 3:\n");
    printMap(&map3, 20, 1);
    printf("\n");
    if (!checkMapCoordinates(&map3))
        printf(": printMap Test case 3 passed!\n\n");
    else
        printf(": printMap Test case 3 failed!\n\n");
}

int main() {

    test_populateMap();
    test_printMap();
    return 0;
}