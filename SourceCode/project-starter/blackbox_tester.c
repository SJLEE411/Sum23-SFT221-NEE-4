#include <stdio.h>
#include "mapping.h"

// Test Case 1: populateMap()
void test_populateMap()
{
    struct Map map = populateMap();
    // Verify the number of rows and columns
    if (map.numRows == 25 && map.numCols == 25)
        printf("populateMap test case 1 passed!\n");
    else
        printf("populateMap test case 1 failed!\n");
}
// Test Case 1: printMap()
void test_printMap() {
    struct Map map = populateMap();

    // Test Case 1
    printf("printMap test case 1:\n");
    printMap(&map, 1, 1);  // Start row with 1 and column with 'A'
    // Check if the row starts with 1
    if (map.squares[3][0] == '1')  // Adjust the index to [0][0]
        printf("Row starts with 1.\n");
    else
        printf("Row does not start with 1.\n");
    // Check if the column starts with 'A'
    if (map.squares[0][3] == 'A')  // Adjust the index to [0][1]
        printf("Column starts with 'A'.\n");
    else
        printf("Column does not start with 'A'.\n");
}

int main()
{
    test_populateMap(); 
    test_printMap();
    return 0;
}
