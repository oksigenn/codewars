#include <stdlib.h>
#include <string.h>
/*https://www.codewars.com/kata/550f22f4d758534c1100025a
5 kyu
*/

char* search_key(char array[][2][10], const char *key) {
    for (int i = 0; i < 4; i++) {
        if (strcmp(array[i][0], key) == 0) {
            return array[i][1];
        }
    }
    return NULL;
}

const char** dirReduc(const char *const array[], int length_in, int *length_out) {
    char opposite[4][2][10] = {{"NORTH", "SOUTH"}, {"SOUTH", "NORTH"}, {"EAST", "WEST"}, {"WEST", "EAST"}};
    
    const char **stack = malloc(length_in * sizeof(char *));
    int index = 0;

    for (int i = 0; i < length_in; i++) {
        if (index > 0 && strcmp(stack[index - 1], search_key(opposite, array[i])) == 0) {
            index--;
        } else {
            stack[index++] = array[i];
        }
    }

    *length_out = index;
    return stack;
}
