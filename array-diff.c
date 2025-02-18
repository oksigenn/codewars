#include <stdio.h>
#include <stdlib.h>

/*https://www.codewars.com/kata/523f5d21c841566fde000009
6 kyu
*/

int in_array(const int *array, size_t len, int expected) {
    for (size_t i = 0; i < len; i++) {
        if (array[i] == expected) {
            return 1;
        }
    }
    return 0;
}

int* array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {
    int *result = (int *)malloc(n1 * sizeof(int));
    if (!result) return NULL;

    *z = 0;
    for (size_t i = 0; i < n1; i++) {
        if (!in_array(arr2, n2, arr1[i])) {
            result[*z] = arr1[i];
            (*z)++;
        }
    }

    return realloc(result, (*z) * sizeof(int));
}